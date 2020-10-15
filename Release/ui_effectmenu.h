/********************************************************************************
** Form generated from reading UI file 'effectmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EFFECTMENU_H
#define UI_EFFECTMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EffectMenu
{
public:
    QGridLayout *gridLayout;
    QPushButton *OnlyBlueButton;
    QPushButton *HalfToneButton;
    QPushButton *InversionVUpToDown;
    QPushButton *InversionVDownToUp;
    QPushButton *OnlyRedButton;
    QPushButton *InversionHRightToLeft;
    QPushButton *NegativeButton;
    QPushButton *InversionHLeftToRight;
    QPushButton *OnlyGreenButton;
    QPushButton *SaltAndPepper;
    QPushButton *SaltAndPepperB;
    QSpinBox *SaltAndPepperNoise;

    void setupUi(QWidget *EffectMenu)
    {
        if (EffectMenu->objectName().isEmpty())
            EffectMenu->setObjectName(QString::fromUtf8("EffectMenu"));
        EffectMenu->resize(325, 1140);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EffectMenu->sizePolicy().hasHeightForWidth());
        EffectMenu->setSizePolicy(sizePolicy);
        EffectMenu->setMinimumSize(QSize(150, 0));
        gridLayout = new QGridLayout(EffectMenu);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        OnlyBlueButton = new QPushButton(EffectMenu);
        OnlyBlueButton->setObjectName(QString::fromUtf8("OnlyBlueButton"));
        OnlyBlueButton->setMinimumSize(QSize(150, 150));
        OnlyBlueButton->setMaximumSize(QSize(150, 150));
        OnlyBlueButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(OnlyBlueButton, 2, 0, 1, 1);

        HalfToneButton = new QPushButton(EffectMenu);
        HalfToneButton->setObjectName(QString::fromUtf8("HalfToneButton"));
        HalfToneButton->setMinimumSize(QSize(150, 150));
        HalfToneButton->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(HalfToneButton, 2, 1, 1, 1);

        InversionVUpToDown = new QPushButton(EffectMenu);
        InversionVUpToDown->setObjectName(QString::fromUtf8("InversionVUpToDown"));
        InversionVUpToDown->setMinimumSize(QSize(150, 150));
        InversionVUpToDown->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(InversionVUpToDown, 4, 1, 1, 1);

        InversionVDownToUp = new QPushButton(EffectMenu);
        InversionVDownToUp->setObjectName(QString::fromUtf8("InversionVDownToUp"));
        InversionVDownToUp->setMinimumSize(QSize(150, 150));
        InversionVDownToUp->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(InversionVDownToUp, 6, 0, 1, 1);

        OnlyRedButton = new QPushButton(EffectMenu);
        OnlyRedButton->setObjectName(QString::fromUtf8("OnlyRedButton"));
        OnlyRedButton->setMinimumSize(QSize(150, 150));
        OnlyRedButton->setMaximumSize(QSize(150, 150));
        OnlyRedButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(OnlyRedButton, 0, 0, 1, 1);

        InversionHRightToLeft = new QPushButton(EffectMenu);
        InversionHRightToLeft->setObjectName(QString::fromUtf8("InversionHRightToLeft"));
        InversionHRightToLeft->setMinimumSize(QSize(150, 150));
        InversionHRightToLeft->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(InversionHRightToLeft, 8, 0, 1, 1);

        NegativeButton = new QPushButton(EffectMenu);
        NegativeButton->setObjectName(QString::fromUtf8("NegativeButton"));
        NegativeButton->setMinimumSize(QSize(150, 150));
        NegativeButton->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(NegativeButton, 4, 0, 1, 1);

        InversionHLeftToRight = new QPushButton(EffectMenu);
        InversionHLeftToRight->setObjectName(QString::fromUtf8("InversionHLeftToRight"));
        InversionHLeftToRight->setMinimumSize(QSize(150, 150));
        InversionHLeftToRight->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(InversionHLeftToRight, 6, 1, 1, 1);

        OnlyGreenButton = new QPushButton(EffectMenu);
        OnlyGreenButton->setObjectName(QString::fromUtf8("OnlyGreenButton"));
        OnlyGreenButton->setMinimumSize(QSize(150, 150));
        OnlyGreenButton->setMaximumSize(QSize(150, 150));
        OnlyGreenButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(OnlyGreenButton, 0, 1, 1, 1);

        SaltAndPepper = new QPushButton(EffectMenu);
        SaltAndPepper->setObjectName(QString::fromUtf8("SaltAndPepper"));
        SaltAndPepper->setEnabled(true);
        SaltAndPepper->setMinimumSize(QSize(150, 150));
        SaltAndPepper->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(SaltAndPepper, 8, 1, 1, 1);

        SaltAndPepperB = new QPushButton(EffectMenu);
        SaltAndPepperB->setObjectName(QString::fromUtf8("SaltAndPepperB"));
        SaltAndPepperB->setMinimumSize(QSize(150, 150));
        SaltAndPepperB->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(SaltAndPepperB, 9, 0, 1, 1);

        SaltAndPepperNoise = new QSpinBox(EffectMenu);
        SaltAndPepperNoise->setObjectName(QString::fromUtf8("SaltAndPepperNoise"));
        SaltAndPepperNoise->setMinimumSize(QSize(0, 25));
        SaltAndPepperNoise->setMinimum(256);
        SaltAndPepperNoise->setMaximum(128000);

        gridLayout->addWidget(SaltAndPepperNoise, 9, 1, 1, 1);


        retranslateUi(EffectMenu);

        QMetaObject::connectSlotsByName(EffectMenu);
    } // setupUi

    void retranslateUi(QWidget *EffectMenu)
    {
        EffectMenu->setWindowTitle(QCoreApplication::translate("EffectMenu", "Form", nullptr));
        OnlyBlueButton->setText(QCoreApplication::translate("EffectMenu", "\320\242\320\276\320\273\321\214\320\272\320\276 \321\201\320\270\320\275\320\270\320\271", nullptr));
        HalfToneButton->setText(QCoreApplication::translate("EffectMenu", "\320\237\320\276\320\273\321\203\321\202\320\276\320\275\320\276\320\262\321\213\320\271", nullptr));
        InversionVUpToDown->setText(QCoreApplication::translate("EffectMenu", "\320\230\320\275\320\262\320\265\321\200\321\201\320\270\321\217 \321\201\320\262\320\265\321\200\321\205\321\203 \320\262\320\275\320\270\320\267", nullptr));
        InversionVDownToUp->setText(QCoreApplication::translate("EffectMenu", "\320\230\320\275\320\262\320\265\321\200\321\201\320\270\321\217 \321\201\320\275\320\270\320\267\321\203 \320\262\320\262\320\265\321\200\321\205", nullptr));
        OnlyRedButton->setText(QCoreApplication::translate("EffectMenu", "\320\242\320\276\320\273\321\214\320\272\320\276 \320\272\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        InversionHRightToLeft->setText(QCoreApplication::translate("EffectMenu", "\320\230\320\275\320\262\320\265\321\200\321\201\320\270\321\217 \320\241\320\277\321\200\320\260\320\262\320\260 \320\275\320\260 \320\273\320\265\320\262\320\276", nullptr));
        NegativeButton->setText(QCoreApplication::translate("EffectMenu", "\320\235\320\265\320\263\320\260\321\202\320\270\320\262", nullptr));
        InversionHLeftToRight->setText(QCoreApplication::translate("EffectMenu", "\320\230\320\275\320\262\320\265\321\200\321\201\320\270\321\217 \320\241\320\273\320\265\320\262\320\260 \320\275\320\260 \320\277\321\200\320\260\320\262\320\276", nullptr));
        OnlyGreenButton->setText(QCoreApplication::translate("EffectMenu", "\320\242\320\276\320\273\321\214\320\272\320\276 \320\267\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));
        SaltAndPepper->setText(QCoreApplication::translate("EffectMenu", "\320\241\320\276\320\273\321\214 \320\270 \320\277\320\265\321\200\320\265\321\206 \320\276\320\264\320\275\320\276\320\277\320\276\320\273\321\217\321\200\320\275\321\213\320\271", nullptr));
        SaltAndPepperB->setText(QCoreApplication::translate("EffectMenu", "\320\241\320\276\320\273\321\214 \320\270 \320\277\320\265\321\200\320\265\321\206 \320\261\320\270\320\277\320\276\320\273\321\217\321\200\320\275\321\213\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EffectMenu: public Ui_EffectMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EFFECTMENU_H
