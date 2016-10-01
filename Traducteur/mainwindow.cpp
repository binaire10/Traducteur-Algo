#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_setup.h"
#include <MyValidator/MyValidator.hpp>
#include "LecteurCode.h"
#include <QDebug>
#include <sstream>
#include <QtWidgets>
#include <QDataStream>
#include <QTextEdit>
#include <CAgloException.h>
#include <MyParse/LexicalParseur.h>

using namespace std;
using namespace binaire;
using namespace System;
using namespace ElementAlgorithmique;
using namespace InstructionAvance;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), diag(new Ui::SetupDialog), m_FenDiag(this) , m_highlighter(nullptr), m_Gcc("g++"), m_GccArg(QStringList() << "-static-libstdc++" << "-std=c++11" << "$OUTPUT" << "-o" << "lapp")
{
    ui->setupUi(this);
    diag->setupUi(&m_FenDiag);
    m_Editor = new CodeEditor;
    ui->horizontalLayout->addWidget(m_Editor);

    connect(ui->actionCpp, &QAction::triggered, this, &MainWindow::Convert);
    connect(ui->actionExecuter, &QAction::triggered, this, &MainWindow::Compile);
    connect(ui->actionConfigurer, &QAction::triggered, this, &MainWindow::ChangeOption);
    connect(&m_App, &QProcess::readyRead, this, &MainWindow::readInput);
    connect(diag->pushButton, &QAbstractButton::clicked, this, &MainWindow::SetCompilo);

    QFont font;
    font.setFamily("DejaVu Sans Mono");
    font.setFixedPitch(true);
    font.setPointSize(10);

    QFontMetrics metrics(font);
    m_Editor->setTabStopWidth(4 * metrics.width(' '));

    m_Editor->setFont(font);
    ui->Result->setFont(font);

    m_highlighter = new Highlighter(m_Editor->document());
    m_Enter = new QShortcut(QKeySequence(Qt::Key_Return), this);
}

MainWindow::~MainWindow()
{
    //delete highlighter;
    delete ui;
}

void MainWindow::readInput()
{
    ui->Result->setPlainText(ui->Result->document()->toPlainText() + m_App.readAllStandardOutput());
    QByteArray input(m_App.readAllStandardError());
    if(input.size() != 0)
    {
        QMessageBox::critical(this, "Cerr", input);
    }
}

void MainWindow::writeConsole()
{
    ui->Result->setPlainText(ui->Result->document()->toPlainText() + ui->lineEdit->text() + '\n');
    m_App.waitForBytesWritten();
    m_App.write(ui->lineEdit->text().toLocal8Bit() + '\n');
    ui->lineEdit->clear();
}

void MainWindow::CloseProc()
{
    ui->lineEdit->setEnabled(false);
    disconnect(&m_App, (void(QProcess::*)(int))&QProcess::finished, this, &MainWindow::CloseProc);
    disconnect(m_Enter, &QShortcut::activated, this, &MainWindow::writeConsole);
}

void MainWindow::FocusSet()
{
    ui->lineEdit->setFocus();
}

void MainWindow::ChangeOption()
{
    diag->compilateurLineEdit->setText(m_Gcc);
    QString value;
    for(const QString &Value: m_GccArg)
    {
        if(!Value.isEmpty())
            value += Value + ' ';
    }/*
    if(value.size() != 0)
        value.remove(1,value.size()-1);*/
    diag->argumentLineEdit->setText(value);
    value.clear();

    m_FenDiag.exec();
    if(m_FenDiag.result() != QDialog::Accepted)
            return;
    m_Gcc = diag->compilateurLineEdit->text();
    m_GccArg = diag->argumentLineEdit->text().split(' ');

    for(QStringList::iterator i(m_GccArg.begin()) ; i != m_GccArg.end() ; ++i)
        if(i->isEmpty())
        {
            i = m_GccArg.erase(i);
            i = m_GccArg.begin();
        }
}

void MainWindow::SetCompilo()
{
    diag->compilateurLineEdit->setText(QFileDialog::getOpenFileName(this, "g++"));
}

void MainWindow::Convert()
{
    ui->Result->setPalette(QPalette(Qt::white));
    QFont font;
    font.setFamily("DejaVu Sans Mono");
    font.setFixedPitch(true);
    font.setPointSize(10);
    ui->Result->setTextColor(Qt::black);


    stringstream getCode;
    try
    {
        string AllCode(m_Editor->document()->toPlainText().toStdString() + '\n');

        list<std::pair<unsigned, StringRef> > CodeLine;

        unsigned iLine(0);
        for(string::const_iterator i(std::find(AllCode.cbegin(), AllCode.cend(), '\n')), last(AllCode.cbegin()) ; i!= AllCode.cend() ; i = std::find(i, AllCode.cend(), '\n'))
        {
            ++iLine;
            if(hasInto(last, i, MyWord, MySymbole))
                CodeLine.push_back({iLine, StringRef(last, i)});
            ++i;
            last = i;
        }


        LecteurCode reader;
        reader.readCode(CodeLine);
        reader.ToCppCode(getCode);
        //ui->CppEditor->document()->setPlainText(QString::fromStdString(getCode.str()));
    }
    catch(const CAgloException &error)
    {
        m_Editor->errorLineNumberAreaWidth(error.Line());
        QMessageBox::critical(this, "Reader Error", error.what());
    }
    catch(const std::exception &error)
    {
        QMessageBox::critical(this, "Reader Error", error.what());
    }
    catch(...)
    {
        QMessageBox::critical(this, "Reader Error", "Inconue");
    }

    ui->Result->setText(QString::fromStdString(getCode.str()));

}

void MainWindow::Compile()
{
    ui->Result->setPalette(QPalette(Qt::black));
    QFont font;
    font.setFamily("DejaVu Sans Mono");
    font.setFixedPitch(true);
    font.setPointSize(10);
    ui->Result->setTextColor(Qt::green);

    QString OFile(QFileDialog::getSaveFileName(this, "File Save", "main.cpp", "C++ File (*.cpp)"));
    if(OFile.size() == 0)
        return;
    if(!QRegExp(".*.cpp").exactMatch(OFile))
        OFile+= ".cpp";

    QFile CppCode(OFile);
    if(!CppCode.open(QFile::Truncate | QFile::WriteOnly))
    {
        QMessageBox::critical(this, "File", QString::fromStdWString(L"Le fichier ne peut pas être ouvert"));
        return;
    }

    stringstream getCode;
    try
    {
        string AllCode(m_Editor->document()->toPlainText().toStdString() + '\n');

        list<std::pair<unsigned, StringRef> > CodeLine;

        unsigned iLine(1);
        for(string::const_iterator i(std::find(AllCode.cbegin(), AllCode.cend(), '\n')), last(AllCode.cbegin()) ; i!= AllCode.cend() ; i = std::find(i, AllCode.cend(), '\n'))
        {
            ++iLine;
            if(hasInto(last, i, MyWord, MySymbole))
                CodeLine.push_back({iLine, StringRef(last, i)});
            ++i;
            last = i;
        }


        LecteurCode reader;
        reader.readCode(CodeLine);
        reader.ToCppCode(getCode);
        CppCode.write(getCode.str().data(), getCode.str().size());
        //ui->CppEditor->document()->setPlainText(QString::fromStdString(getCode.str()));
    }
    catch(const CAgloException &error)
    {
        m_Editor->errorLineNumberAreaWidth(error.Line());
        QMessageBox::critical(this, "Reader Error", error.what());
    }
    catch(const std::exception &error)
    {
        QMessageBox::critical(this, "Reader Error", error.what());
    }
    catch(...)
    {
        QMessageBox::critical(this, "Reader Error", "Inconue");
    }
    CppCode.close();

    for(QString &Value: m_GccArg)
    {
        if(Value == "$OUTPUT")
            Value = OFile;
    }

    m_App.start('"'+m_Gcc+'"', m_GccArg);

    for(QString &Value: m_GccArg)
    {
        if(Value == OFile)
            Value = "$OUTPUT";
    }

    QString value;
    for(const QString &Value: m_App.arguments())
    {
            value += ' ' + Value;
    }

    ui->Result->setText(m_App.program() + value);

    connect(&m_App, (void(QProcess::*)(int))&QProcess::finished, this, &MainWindow::Executer);
}

void MainWindow::Executer(int gccExit)
{
    disconnect(&m_App, (void(QProcess::*)(int))&QProcess::finished, this, &MainWindow::Executer);
    if(gccExit != 0)
    {
        QMessageBox ::critical(this, "Build Faild", "Echec de compilation");
        CloseProc();
        return;
    }
    connect(&m_App, (void(QProcess::*)(int))&QProcess::finished, this, &MainWindow::CloseProc);
    ui->Result->setPlainText(ui->Result->document()->toPlainText() + '\n');

    m_App.start('"'+QDir::current().filePath("lapp")+'"');

    QString value;
    for(const QString &Value: m_App.arguments())
    {
            value += ' ' + Value;
    }

    ui->Result->setText(m_App.program() + value +'\n');
    ui->lineEdit->setEnabled(true);
    ui->lineEdit->setFocus();


    connect(m_Enter, &QShortcut::activated, this, &MainWindow::writeConsole);
}
