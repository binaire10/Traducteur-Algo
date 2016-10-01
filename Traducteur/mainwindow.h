#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QShortcut>
#include "highlighter.h"
#include "editor.h"
#include <QDialog>

namespace Ui {
class MainWindow;
class SetupDialog;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void Convert();
    void Compile();
    void Executer(int);
    void readInput();
    void writeConsole();
    void CloseProc();
    void FocusSet();
    void ChangeOption();
    void SetCompilo();

private:
    Ui::MainWindow *ui;
    Ui::SetupDialog *diag;
    QDialog m_FenDiag;
    Highlighter *m_highlighter;
    CodeEditor *m_Editor;
    QProcess m_App;
    QShortcut *m_Enter;
    QShortcut *m_Escape;
    QShortcut *m_CtrlB;
    QShortcut *m_CtrlR;
    //QThread outsideProcess;
    QString m_Gcc;
    QStringList m_GccArg;
};

#endif // MAINWINDOW_H
