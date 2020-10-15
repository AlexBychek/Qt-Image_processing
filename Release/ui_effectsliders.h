/********************************************************************************
** Form generated from reading UI file 'effectsliders.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EFFECTSLIDERS_H
#define UI_EFFECTSLIDERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EffectSliders
{
public:
    QGridLayout *gridLayout;
    QGroupBox *ContrastBox;
    QGridLayout *gridLayout_2;
    QSlider *ContrastSlider;
    QLabel *ContrastBorder;
    QLabel *ContrastValue;
    QGroupBox *BrightnessBox;
    QGridLayout *gridLayout_3;
    QSlider *BrightnessSlider;
    QLabel *BrightnessBorder;
    QLabel *BrightnessValue;
    QGroupBox *GammaBox;
    QGridLayout *gridLayout_4;
    QSlider *GammaSlider;
    QLabel *GammaBorder;
    QLabel *GammaValue;

    void setupUi(QWidget *EffectSliders)
    {
        if (EffectSliders->objectName().isEmpty())
            EffectSliders->setObjectName(QString::fromUtf8("EffectSliders"));
        EffectSliders->resize(750, 503);
        gridLayout = new QGridLayout(EffectSliders);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ContrastBox = new QGroupBox(EffectSliders);
        ContrastBox->setObjectName(QString::fromUtf8("ContrastBox"));
        ContrastBox->setMaximumSize(QSize(16777215, 100));
        gridLayout_2 = new QGridLayout(ContrastBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        ContrastSlider = new QSlider(ContrastBox);
        ContrastSlider->setObjectName(QString::fromUtf8("ContrastSlider"));
        ContrastSlider->setMinimumSize(QSize(0, 50));
        ContrastSlider->setMinimum(-255);
        ContrastSlider->setMaximum(255);
        ContrastSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(ContrastSlider, 0, 0, 1, 2);

        ContrastBorder = new QLabel(ContrastBox);
        ContrastBorder->setObjectName(QString::fromUtf8("ContrastBorder"));
        ContrastBorder->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(ContrastBorder, 1, 0, 1, 1);

        ContrastValue = new QLabel(ContrastBox);
        ContrastValue->setObjectName(QString::fromUtf8("ContrastValue"));
        ContrastValue->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(ContrastValue, 1, 1, 1, 1);


        gridLayout->addWidget(ContrastBox, 0, 0, 1, 1);

        BrightnessBox = new QGroupBox(EffectSliders);
        BrightnessBox->setObjectName(QString::fromUtf8("BrightnessBox"));
        BrightnessBox->setMaximumSize(QSize(16777215, 100));
        gridLayout_3 = new QGridLayout(BrightnessBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        BrightnessSlider = new QSlider(BrightnessBox);
        BrightnessSlider->setObjectName(QString::fromUtf8("BrightnessSlider"));
        BrightnessSlider->setMinimumSize(QSize(0, 50));
        BrightnessSlider->setMinimum(-255);
        BrightnessSlider->setMaximum(255);
        BrightnessSlider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(BrightnessSlider, 0, 0, 1, 2);

        BrightnessBorder = new QLabel(BrightnessBox);
        BrightnessBorder->setObjectName(QString::fromUtf8("BrightnessBorder"));
        BrightnessBorder->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(BrightnessBorder, 1, 0, 1, 1);

        BrightnessValue = new QLabel(BrightnessBox);
        BrightnessValue->setObjectName(QString::fromUtf8("BrightnessValue"));
        BrightnessValue->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(BrightnessValue, 1, 1, 1, 1);


        gridLayout->addWidget(BrightnessBox, 1, 0, 1, 1);

        GammaBox = new QGroupBox(EffectSliders);
        GammaBox->setObjectName(QString::fromUtf8("GammaBox"));
        GammaBox->setMaximumSize(QSize(16777215, 100));
        gridLayout_4 = new QGridLayout(GammaBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        GammaSlider = new QSlider(GammaBox);
        GammaSlider->setObjectName(QString::fromUtf8("GammaSlider"));
        GammaSlider->setMinimumSize(QSize(0, 50));
        GammaSlider->setMinimum(1);
        GammaSlider->setMaximum(700);
        GammaSlider->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(GammaSlider, 0, 0, 1, 2);

        GammaBorder = new QLabel(GammaBox);
        GammaBorder->setObjectName(QString::fromUtf8("GammaBorder"));
        GammaBorder->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(GammaBorder, 1, 0, 1, 1);

        GammaValue = new QLabel(GammaBox);
        GammaValue->setObjectName(QString::fromUtf8("GammaValue"));
        GammaValue->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(GammaValue, 1, 1, 1, 1);


        gridLayout->addWidget(GammaBox, 2, 0, 1, 1);


        retranslateUi(EffectSliders);

        QMetaObject::connectSlotsByName(EffectSliders);
    } // setupUi

    void retranslateUi(QWidget *EffectSliders)
    {
        EffectSliders->setWindowTitle(QCoreApplication::translate("EffectSliders", "Form", nullptr));
        ContrastBox->setTitle(QCoreApplication::translate("EffectSliders", "\320\232\320\276\320\275\321\202\321\200\320\260\321\201\321\202", nullptr));
        ContrastBorder->setText(QCoreApplication::translate("EffectSliders", "-255 - 255", nullptr));
        ContrastValue->setText(QCoreApplication::translate("EffectSliders", "0", nullptr));
        BrightnessBox->setTitle(QCoreApplication::translate("EffectSliders", "\320\257\321\200\320\272\320\276\321\201\321\202\321\214", nullptr));
        BrightnessBorder->setText(QCoreApplication::translate("EffectSliders", "-255 - 255", nullptr));
        BrightnessValue->setText(QCoreApplication::translate("EffectSliders", "0", nullptr));
        GammaBox->setTitle(QCoreApplication::translate("EffectSliders", "\320\223\320\260\320\274\320\274\320\260 \320\272\320\276\321\200\321\200\320\265\320\272\321\206\320\270\321\217", nullptr));
        GammaBorder->setText(QCoreApplication::translate("EffectSliders", "0.01-7.00", nullptr));
        GammaValue->setText(QCoreApplication::translate("EffectSliders", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EffectSliders: public Ui_EffectSliders {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EFFECTSLIDERS_H
