/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

//ens.casali.me

#include "highlighter.h"

//! [0]
Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;


    //! [5]
    functionFormat.setFontItalic(true);
    functionFormat.setForeground(Qt::blue);
    rule.pattern = QRegExp("\\b[A-Za-z0-9_]+[ ]*(?=\\()");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatternsStructure;
    keywordPatternsStructure << "\\bfbouclen\\b" << "\\bdeclarer\\b" << "\\brenvoie\\b"
                        << "\\bboucle\\b" << "\\bin\\b" << "\\bout\\b" << "\\bin_out\\b"
                        << "\\bsi\\b" << "\\bsinon\\b" << "\\bsinon_si\\b" << "\\bfsi\\b"
                        << "\\bpour\\b"  << "\\bfboucle\\b" << "\\btant_que\\b"
                        << "\\bfaire\\b" << "\\bffaire\\b"  << "\\bdebut\\b" << "\\bfin\\b"
                           ;
    for(const QString &pattern : keywordPatternsStructure)
    {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }
    QStringList keywordPatternsBuitinFunction;
    keywordPatternsBuitinFunction << "\\btolower\\b" << "\\btoupper\\b"  << "\\bsucc\\b"
                       << "\\brang\\b"  << "\\bmodulo\\b"  << "\\btaille\\b"
                       << "\\ballonger\\b" << "\\bredimensionner\\b" << "\\bsaisir\\b"
                       << "\\bafficher\\b" << "\\btolower\\b" << "\\btolower\\b"
                       << "\\bRand\\b"
                          ;

    keywordFormat.setForeground(Qt::red);

    for(const QString &pattern : keywordPatternsBuitinFunction)
    {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    keywordFormat.setForeground(Qt::darkGreen);

    QStringList keywordPatternsType;
    keywordPatternsType << "\\bprocedure\\b" << "\\bfonction\\b" << "\\balgorithme\\b"
                         << "\\bcaractere\\b" << "\\bentier\\b" << "\\bstring\\b" << "\\bentier_naturel\\b"
                         << "\\breel\\b" << "\\bbooleen\\b" << "\\bvrai\\b" << "\\bfaux\\b";

    for(const QString &pattern : keywordPatternsType)
    {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    keywordFormat.setForeground(Qt::darkMagenta);
    QStringList keywordPatternsMagenta;
    keywordPatternsMagenta << "\\bvariant_de\\b"  << "\\btableau_de\\b" << "\\bET_ALORS\\b" << "\\bOU_SINON\\b"
                           << "\\bsortie\\b" << "\\bcontinue\\b" << "\\bNON\\b" << "\\bligne_suivante\\b"
                           << "\\bne_vaut_pas\\b" << "\\bvaut\\n" << "\\bET\\b" << "\\bOU\\b" << "\\bET_ALORS\\b"
                           << "\\bOU_SINON\\b"
                              ;

    for(const QString &pattern : keywordPatternsMagenta)
    {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    //! [3]
    singleLineCommentFormat.setForeground(Qt::red);
    rule.pattern = QRegExp("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    //! [4]
    quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegExp("\".*\"");
    rule.pattern.setMinimal(true);
    rule.format = quotationFormat;
    highlightingRules.append(rule);
    //! [4]
}
//! [6]

//! [7]
void Highlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
    //! [7] //! [8]
    setCurrentBlockState(0);
}
//! [11]
