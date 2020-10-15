/********************************************************************************
** Form generated from reading UI file 'logwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWINDOW_H
#define UI_LOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_LogWindow
{
public:
    QGridLayout *gridLayout;
    QTextEdit *TextLog;
    QHBoxLayout *horizontalLayout;
    QPushButton *SaveButton;
    QPushButton *ClearButton;
    QPushButton *CloseButton;

    void setupUi(QDialog *LogWindow)
    {
        if (LogWindow->objectName().isEmpty())
            LogWindow->setObjectName(QString::fromUtf8("LogWindow"));
        LogWindow->resize(500, 300);
        gridLayout = new QGridLayout(LogWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        TextLog = new QTextEdit(LogWindow);
        TextLog->setObjectName(QString::fromUtf8("TextLog"));

        gridLayout->addWidget(TextLog, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        SaveButton = new QPushButton(LogWindow);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));

        horizontalLayout->addWidget(SaveButton);

        ClearButton = new QPushButton(LogWindow);
        ClearButton->setObjectName(QString::fromUtf8("ClearButton"));

        horizontalLayout->addWidget(ClearButton);

        CloseButton = new QPushButton(LogWindow);
        CloseButton->setObjectName(QString::fromUtf8("CloseButton"));

        horizontalLayout->addWidget(CloseButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(LogWindow);

        QMetaObject::connectSlotsByName(LogWindow);
    } // setupUi

    void retranslateUi(QDialog *LogWindow)
    {
        LogWindow->setWindowTitle(QCoreApplication::translate("LogWindow", "LogWindow", nullptr));
        SaveButton->setText(QCoreApplication::translate("LogWindow", "SaveToFile", nullptr));
        ClearButton->setText(QCoreApplication::translate("LogWindow", "Clear", nullptr));
        CloseButton->setText(QCoreApplication::translate("LogWindow", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogWindow: public Ui_LogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWINDOW_H
