/********************************************************************************
** Form generated from reading UI file 'fileinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEINFO_H
#define UI_FILEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_FileInfo
{
public:
    QGridLayout *gridLayout;
    QLabel *FilePath;
    QLabel *NameFile;
    QLabel *Pixels;
    QLabel *PixelsColvo;

    void setupUi(QDialog *FileInfo)
    {
        if (FileInfo->objectName().isEmpty())
            FileInfo->setObjectName(QString::fromUtf8("FileInfo"));
        FileInfo->resize(168, 150);
        FileInfo->setMinimumSize(QSize(0, 150));
        FileInfo->setMaximumSize(QSize(800, 200));
        gridLayout = new QGridLayout(FileInfo);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        FilePath = new QLabel(FileInfo);
        FilePath->setObjectName(QString::fromUtf8("FilePath"));
        FilePath->setMinimumSize(QSize(150, 40));
        FilePath->setMaximumSize(QSize(400, 40));

        gridLayout->addWidget(FilePath, 3, 0, 1, 1);

        NameFile = new QLabel(FileInfo);
        NameFile->setObjectName(QString::fromUtf8("NameFile"));
        NameFile->setMinimumSize(QSize(150, 40));
        NameFile->setMaximumSize(QSize(400, 40));

        gridLayout->addWidget(NameFile, 0, 0, 1, 1);

        Pixels = new QLabel(FileInfo);
        Pixels->setObjectName(QString::fromUtf8("Pixels"));
        Pixels->setMinimumSize(QSize(150, 40));
        Pixels->setMaximumSize(QSize(400, 40));

        gridLayout->addWidget(Pixels, 1, 0, 1, 1);

        PixelsColvo = new QLabel(FileInfo);
        PixelsColvo->setObjectName(QString::fromUtf8("PixelsColvo"));
        PixelsColvo->setMinimumSize(QSize(150, 40));
        PixelsColvo->setMaximumSize(QSize(400, 40));

        gridLayout->addWidget(PixelsColvo, 2, 0, 1, 1);


        retranslateUi(FileInfo);

        QMetaObject::connectSlotsByName(FileInfo);
    } // setupUi

    void retranslateUi(QDialog *FileInfo)
    {
        FileInfo->setWindowTitle(QCoreApplication::translate("FileInfo", "Dialog", nullptr));
        FilePath->setText(QCoreApplication::translate("FileInfo", "FilePath", nullptr));
        NameFile->setText(QCoreApplication::translate("FileInfo", "NameFile", nullptr));
        Pixels->setText(QCoreApplication::translate("FileInfo", "Pixels", nullptr));
        PixelsColvo->setText(QCoreApplication::translate("FileInfo", "PixelsCol-vo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileInfo: public Ui_FileInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEINFO_H
