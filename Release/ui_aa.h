/********************************************************************************
** Form generated from reading UI file 'aa.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AA_H
#define UI_AA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AA
{
public:
    QGridLayout *gridLayout;
    QComboBox *AAStep;
    QHBoxLayout *horizontalLayout;
    QRadioButton *Bl1;
    QRadioButton *Bl2;
    QRadioButton *BC;
    QPushButton *SSAA_Button;
    QPushButton *Upscale1;
    QPushButton *Upscale2;
    QPushButton *Upscale3;

    void setupUi(QWidget *AA)
    {
        if (AA->objectName().isEmpty())
            AA->setObjectName(QString::fromUtf8("AA"));
        AA->resize(324, 536);
        gridLayout = new QGridLayout(AA);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        AAStep = new QComboBox(AA);
        AAStep->addItem(QString());
        AAStep->addItem(QString());
        AAStep->addItem(QString());
        AAStep->addItem(QString());
        AAStep->setObjectName(QString::fromUtf8("AAStep"));

        gridLayout->addWidget(AAStep, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Bl1 = new QRadioButton(AA);
        Bl1->setObjectName(QString::fromUtf8("Bl1"));
        Bl1->setMaximumSize(QSize(16777215, 50));
        Bl1->setChecked(false);

        horizontalLayout->addWidget(Bl1);

        Bl2 = new QRadioButton(AA);
        Bl2->setObjectName(QString::fromUtf8("Bl2"));
        Bl2->setMaximumSize(QSize(16777215, 50));
        Bl2->setChecked(true);

        horizontalLayout->addWidget(Bl2);

        BC = new QRadioButton(AA);
        BC->setObjectName(QString::fromUtf8("BC"));
        BC->setMaximumSize(QSize(16777215, 50));

        horizontalLayout->addWidget(BC);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 2);

        SSAA_Button = new QPushButton(AA);
        SSAA_Button->setObjectName(QString::fromUtf8("SSAA_Button"));
        SSAA_Button->setMinimumSize(QSize(150, 150));
        SSAA_Button->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(SSAA_Button, 2, 0, 1, 1);

        Upscale1 = new QPushButton(AA);
        Upscale1->setObjectName(QString::fromUtf8("Upscale1"));
        Upscale1->setMinimumSize(QSize(150, 150));
        Upscale1->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(Upscale1, 3, 0, 1, 1);

        Upscale2 = new QPushButton(AA);
        Upscale2->setObjectName(QString::fromUtf8("Upscale2"));
        Upscale2->setMinimumSize(QSize(150, 150));
        Upscale2->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(Upscale2, 3, 1, 1, 1);

        Upscale3 = new QPushButton(AA);
        Upscale3->setObjectName(QString::fromUtf8("Upscale3"));
        Upscale3->setMinimumSize(QSize(150, 150));
        Upscale3->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(Upscale3, 4, 0, 1, 1);


        retranslateUi(AA);

        QMetaObject::connectSlotsByName(AA);
    } // setupUi

    void retranslateUi(QWidget *AA)
    {
        AA->setWindowTitle(QCoreApplication::translate("AA", "Form", nullptr));
        AAStep->setItemText(0, QCoreApplication::translate("AA", "2", nullptr));
        AAStep->setItemText(1, QCoreApplication::translate("AA", "3", nullptr));
        AAStep->setItemText(2, QCoreApplication::translate("AA", "4", nullptr));
        AAStep->setItemText(3, QCoreApplication::translate("AA", "8", nullptr));

        Bl1->setText(QCoreApplication::translate("AA", "BLinType1", nullptr));
        Bl2->setText(QCoreApplication::translate("AA", "BLinType2", nullptr));
        BC->setText(QCoreApplication::translate("AA", "BCubType", nullptr));
        SSAA_Button->setText(QCoreApplication::translate("AA", "SSAA", nullptr));
        Upscale1->setText(QCoreApplication::translate("AA", "Upscale 1", nullptr));
        Upscale2->setText(QCoreApplication::translate("AA", "Upscale 2", nullptr));
        Upscale3->setText(QCoreApplication::translate("AA", "Upscale 3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AA: public Ui_AA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AA_H
