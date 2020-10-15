/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QGridLayout *gridLayout;
    QCheckBox *IconProcessing;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLineEdit *Mask00;
    QLineEdit *Mask01;
    QLineEdit *Mask02;
    QLineEdit *Mask03;
    QLineEdit *Mask04;
    QLineEdit *Mask10;
    QLineEdit *Mask11;
    QLineEdit *Mask12;
    QLineEdit *Mask13;
    QLineEdit *Mask14;
    QLineEdit *Mask20;
    QLineEdit *Mask21;
    QLineEdit *Mask22;
    QLineEdit *Mask23;
    QLineEdit *Mask24;
    QLineEdit *Mask30;
    QLineEdit *Mask31;
    QLineEdit *Mask32;
    QLineEdit *Mask33;
    QLineEdit *Mask34;
    QLineEdit *Mask40;
    QLineEdit *Mask41;
    QLineEdit *Mask42;
    QLineEdit *Mask43;
    QLineEdit *Mask44;
    QSplitter *splitter;
    QSlider *LaplasSLider;
    QLabel *SliderValue;
    QHBoxLayout *horizontalLayout;
    QCheckBox *HalfGamma;
    QSplitter *splitter_3;
    QSlider *GammaSLider;
    QLabel *GammaValue;

    void setupUi(QWidget *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(334, 285);
        gridLayout = new QGridLayout(Settings);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        IconProcessing = new QCheckBox(Settings);
        IconProcessing->setObjectName(QString::fromUtf8("IconProcessing"));
        IconProcessing->setChecked(false);

        gridLayout->addWidget(IconProcessing, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(Settings);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setEnabled(false);
        groupBox_3->setMinimumSize(QSize(200, 0));
        groupBox_3->setMaximumSize(QSize(16666666, 16666666));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        Mask00 = new QLineEdit(groupBox_3);
        Mask00->setObjectName(QString::fromUtf8("Mask00"));

        gridLayout_3->addWidget(Mask00, 0, 0, 1, 1);

        Mask01 = new QLineEdit(groupBox_3);
        Mask01->setObjectName(QString::fromUtf8("Mask01"));

        gridLayout_3->addWidget(Mask01, 0, 1, 1, 1);

        Mask02 = new QLineEdit(groupBox_3);
        Mask02->setObjectName(QString::fromUtf8("Mask02"));

        gridLayout_3->addWidget(Mask02, 0, 2, 1, 1);

        Mask03 = new QLineEdit(groupBox_3);
        Mask03->setObjectName(QString::fromUtf8("Mask03"));

        gridLayout_3->addWidget(Mask03, 0, 3, 1, 1);

        Mask04 = new QLineEdit(groupBox_3);
        Mask04->setObjectName(QString::fromUtf8("Mask04"));

        gridLayout_3->addWidget(Mask04, 0, 4, 1, 1);

        Mask10 = new QLineEdit(groupBox_3);
        Mask10->setObjectName(QString::fromUtf8("Mask10"));

        gridLayout_3->addWidget(Mask10, 1, 0, 1, 1);

        Mask11 = new QLineEdit(groupBox_3);
        Mask11->setObjectName(QString::fromUtf8("Mask11"));

        gridLayout_3->addWidget(Mask11, 1, 1, 1, 1);

        Mask12 = new QLineEdit(groupBox_3);
        Mask12->setObjectName(QString::fromUtf8("Mask12"));

        gridLayout_3->addWidget(Mask12, 1, 2, 1, 1);

        Mask13 = new QLineEdit(groupBox_3);
        Mask13->setObjectName(QString::fromUtf8("Mask13"));

        gridLayout_3->addWidget(Mask13, 1, 3, 1, 1);

        Mask14 = new QLineEdit(groupBox_3);
        Mask14->setObjectName(QString::fromUtf8("Mask14"));

        gridLayout_3->addWidget(Mask14, 1, 4, 1, 1);

        Mask20 = new QLineEdit(groupBox_3);
        Mask20->setObjectName(QString::fromUtf8("Mask20"));

        gridLayout_3->addWidget(Mask20, 2, 0, 1, 1);

        Mask21 = new QLineEdit(groupBox_3);
        Mask21->setObjectName(QString::fromUtf8("Mask21"));

        gridLayout_3->addWidget(Mask21, 2, 1, 1, 1);

        Mask22 = new QLineEdit(groupBox_3);
        Mask22->setObjectName(QString::fromUtf8("Mask22"));

        gridLayout_3->addWidget(Mask22, 2, 2, 1, 1);

        Mask23 = new QLineEdit(groupBox_3);
        Mask23->setObjectName(QString::fromUtf8("Mask23"));

        gridLayout_3->addWidget(Mask23, 2, 3, 1, 1);

        Mask24 = new QLineEdit(groupBox_3);
        Mask24->setObjectName(QString::fromUtf8("Mask24"));

        gridLayout_3->addWidget(Mask24, 2, 4, 1, 1);

        Mask30 = new QLineEdit(groupBox_3);
        Mask30->setObjectName(QString::fromUtf8("Mask30"));

        gridLayout_3->addWidget(Mask30, 3, 0, 1, 1);

        Mask31 = new QLineEdit(groupBox_3);
        Mask31->setObjectName(QString::fromUtf8("Mask31"));

        gridLayout_3->addWidget(Mask31, 3, 1, 1, 1);

        Mask32 = new QLineEdit(groupBox_3);
        Mask32->setObjectName(QString::fromUtf8("Mask32"));

        gridLayout_3->addWidget(Mask32, 3, 2, 1, 1);

        Mask33 = new QLineEdit(groupBox_3);
        Mask33->setObjectName(QString::fromUtf8("Mask33"));

        gridLayout_3->addWidget(Mask33, 3, 3, 1, 1);

        Mask34 = new QLineEdit(groupBox_3);
        Mask34->setObjectName(QString::fromUtf8("Mask34"));

        gridLayout_3->addWidget(Mask34, 3, 4, 1, 1);

        Mask40 = new QLineEdit(groupBox_3);
        Mask40->setObjectName(QString::fromUtf8("Mask40"));

        gridLayout_3->addWidget(Mask40, 4, 0, 1, 1);

        Mask41 = new QLineEdit(groupBox_3);
        Mask41->setObjectName(QString::fromUtf8("Mask41"));

        gridLayout_3->addWidget(Mask41, 4, 1, 1, 1);

        Mask42 = new QLineEdit(groupBox_3);
        Mask42->setObjectName(QString::fromUtf8("Mask42"));

        gridLayout_3->addWidget(Mask42, 4, 2, 1, 1);

        Mask43 = new QLineEdit(groupBox_3);
        Mask43->setObjectName(QString::fromUtf8("Mask43"));

        gridLayout_3->addWidget(Mask43, 4, 3, 1, 1);

        Mask44 = new QLineEdit(groupBox_3);
        Mask44->setObjectName(QString::fromUtf8("Mask44"));

        gridLayout_3->addWidget(Mask44, 4, 4, 1, 1);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 1);

        splitter = new QSplitter(Settings);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        LaplasSLider = new QSlider(splitter);
        LaplasSLider->setObjectName(QString::fromUtf8("LaplasSLider"));
        LaplasSLider->setMaximumSize(QSize(16777215, 50));
        LaplasSLider->setMaximum(300);
        LaplasSLider->setSingleStep(10);
        LaplasSLider->setValue(20);
        LaplasSLider->setOrientation(Qt::Horizontal);
        splitter->addWidget(LaplasSLider);
        SliderValue = new QLabel(splitter);
        SliderValue->setObjectName(QString::fromUtf8("SliderValue"));
        SliderValue->setMaximumSize(QSize(16777215, 50));
        splitter->addWidget(SliderValue);

        gridLayout->addWidget(splitter, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        HalfGamma = new QCheckBox(Settings);
        HalfGamma->setObjectName(QString::fromUtf8("HalfGamma"));
        HalfGamma->setMaximumSize(QSize(16777215, 50));
        HalfGamma->setChecked(true);

        horizontalLayout->addWidget(HalfGamma);

        splitter_3 = new QSplitter(Settings);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        GammaSLider = new QSlider(splitter_3);
        GammaSLider->setObjectName(QString::fromUtf8("GammaSLider"));
        GammaSLider->setMaximumSize(QSize(16777215, 50));
        GammaSLider->setMaximum(10);
        GammaSLider->setSingleStep(1);
        GammaSLider->setPageStep(1);
        GammaSLider->setValue(3);
        GammaSLider->setOrientation(Qt::Horizontal);
        splitter_3->addWidget(GammaSLider);
        GammaValue = new QLabel(splitter_3);
        GammaValue->setObjectName(QString::fromUtf8("GammaValue"));
        GammaValue->setMaximumSize(QSize(16777215, 50));
        splitter_3->addWidget(GammaValue);

        horizontalLayout->addWidget(splitter_3);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);


        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QWidget *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "Form", nullptr));
        IconProcessing->setText(QCoreApplication::translate("Settings", "\320\237\320\276\320\272\320\260\320\267\321\213\320\262\320\260\321\202\321\214 \320\270\320\272\320\276\320\275\320\272\320\270 \320\275\320\260 \320\232\320\275\320\276\320\277\320\272\320\260\321\205 (\320\255\321\201\320\277\320\265\321\200\320\265\320\274\320\265\320\275\321\202\320\260\320\273\321\214\320\275\320\276)", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Settings", "\320\234\320\260\321\201\320\272\320\260", nullptr));
        SliderValue->setText(QCoreApplication::translate("Settings", "2", nullptr));
        HalfGamma->setText(QString());
        GammaValue->setText(QCoreApplication::translate("Settings", "0.3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
