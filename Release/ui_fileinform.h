/********************************************************************************
** Form generated from reading UI file 'fileinform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEINFORM_H
#define UI_FILEINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileInform
{
public:
    QGridLayout *gridLayout;
    QLabel *NameFile;
    QLabel *Pixels;
    QLabel *PixelsColvo;
    QLabel *FilePath;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *EditX;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *EditY;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_R;
    QLabel *label_G;
    QLabel *label_B;

    void setupUi(QWidget *FileInform)
    {
        if (FileInform->objectName().isEmpty())
            FileInform->setObjectName(QString::fromUtf8("FileInform"));
        FileInform->resize(315, 300);
        FileInform->setMinimumSize(QSize(0, 150));
        FileInform->setMaximumSize(QSize(16777215, 400));
        gridLayout = new QGridLayout(FileInform);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        NameFile = new QLabel(FileInform);
        NameFile->setObjectName(QString::fromUtf8("NameFile"));
        NameFile->setMinimumSize(QSize(150, 40));
        NameFile->setMaximumSize(QSize(400, 40));

        gridLayout->addWidget(NameFile, 0, 0, 1, 1);

        Pixels = new QLabel(FileInform);
        Pixels->setObjectName(QString::fromUtf8("Pixels"));
        Pixels->setMinimumSize(QSize(150, 40));
        Pixels->setMaximumSize(QSize(400, 40));

        gridLayout->addWidget(Pixels, 1, 0, 1, 1);

        PixelsColvo = new QLabel(FileInform);
        PixelsColvo->setObjectName(QString::fromUtf8("PixelsColvo"));
        PixelsColvo->setMinimumSize(QSize(150, 40));
        PixelsColvo->setMaximumSize(QSize(400, 40));

        gridLayout->addWidget(PixelsColvo, 2, 0, 1, 1);

        FilePath = new QLabel(FileInform);
        FilePath->setObjectName(QString::fromUtf8("FilePath"));
        FilePath->setMinimumSize(QSize(150, 40));
        FilePath->setMaximumSize(QSize(400, 40));

        gridLayout->addWidget(FilePath, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FileInform);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        EditX = new QLineEdit(FileInform);
        EditX->setObjectName(QString::fromUtf8("EditX"));

        horizontalLayout->addWidget(EditX);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(FileInform);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        EditY = new QLineEdit(FileInform);
        EditY->setObjectName(QString::fromUtf8("EditY"));

        horizontalLayout_2->addWidget(EditY);


        gridLayout->addLayout(horizontalLayout_2, 5, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_R = new QLabel(FileInform);
        label_R->setObjectName(QString::fromUtf8("label_R"));

        horizontalLayout_3->addWidget(label_R);

        label_G = new QLabel(FileInform);
        label_G->setObjectName(QString::fromUtf8("label_G"));

        horizontalLayout_3->addWidget(label_G);

        label_B = new QLabel(FileInform);
        label_B->setObjectName(QString::fromUtf8("label_B"));

        horizontalLayout_3->addWidget(label_B);


        gridLayout->addLayout(horizontalLayout_3, 6, 0, 1, 1);


        retranslateUi(FileInform);

        QMetaObject::connectSlotsByName(FileInform);
    } // setupUi

    void retranslateUi(QWidget *FileInform)
    {
        FileInform->setWindowTitle(QCoreApplication::translate("FileInform", "Form", nullptr));
        NameFile->setText(QCoreApplication::translate("FileInform", "NameFile", nullptr));
        Pixels->setText(QCoreApplication::translate("FileInform", "Pixels", nullptr));
        PixelsColvo->setText(QCoreApplication::translate("FileInform", "PixelsCol-vo", nullptr));
        FilePath->setText(QCoreApplication::translate("FileInform", "FilePath", nullptr));
        label->setText(QCoreApplication::translate("FileInform", "X", nullptr));
        label_2->setText(QCoreApplication::translate("FileInform", "Y", nullptr));
        label_R->setText(QCoreApplication::translate("FileInform", "R", nullptr));
        label_G->setText(QCoreApplication::translate("FileInform", "G", nullptr));
        label_B->setText(QCoreApplication::translate("FileInform", "B", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileInform: public Ui_FileInform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEINFORM_H
