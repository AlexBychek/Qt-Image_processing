/********************************************************************************
** Form generated from reading UI file 'histogramequalization.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAMEQUALIZATION_H
#define UI_HISTOGRAMEQUALIZATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_HistogramEqualization
{
public:
    QGridLayout *gridLayout_5;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QCustomPlot *ImageGistogram;
    QLabel *WorkImage;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QCustomPlot *ProcessedImageGistogram;
    QLabel *ProcessedImage;
    QWidget *widget;
    QGridLayout *gridLayout_4;
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
    QCheckBox *LegendHide;
    QComboBox *ColorComponent;
    QSlider *ParamSlider;
    QPushButton *Reload;
    QPushButton *SetCustomMasks;
    QPushButton *CompareProcAndOrig;
    QCheckBox *MixHisto;
    QComboBox *EffectBox;
    QPushButton *GetNormalImage;

    void setupUi(QDialog *HistogramEqualization)
    {
        if (HistogramEqualization->objectName().isEmpty())
            HistogramEqualization->setObjectName(QString::fromUtf8("HistogramEqualization"));
        HistogramEqualization->resize(1086, 538);
        gridLayout_5 = new QGridLayout(HistogramEqualization);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        splitter = new QSplitter(HistogramEqualization);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setFrameShape(QFrame::NoFrame);
        splitter->setFrameShadow(QFrame::Plain);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setOpaqueResize(true);
        splitter->setChildrenCollapsible(true);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ImageGistogram = new QCustomPlot(groupBox);
        ImageGistogram->setObjectName(QString::fromUtf8("ImageGistogram"));

        gridLayout->addWidget(ImageGistogram, 0, 0, 1, 1);

        WorkImage = new QLabel(groupBox);
        WorkImage->setObjectName(QString::fromUtf8("WorkImage"));

        gridLayout->addWidget(WorkImage, 1, 0, 1, 1);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        ProcessedImageGistogram = new QCustomPlot(groupBox_2);
        ProcessedImageGistogram->setObjectName(QString::fromUtf8("ProcessedImageGistogram"));

        gridLayout_2->addWidget(ProcessedImageGistogram, 0, 0, 1, 1);

        ProcessedImage = new QLabel(groupBox_2);
        ProcessedImage->setObjectName(QString::fromUtf8("ProcessedImage"));

        gridLayout_2->addWidget(ProcessedImage, 1, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_2);

        splitter->addWidget(layoutWidget);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(250, 0));
        widget->setMaximumSize(QSize(250, 1000000));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(200, 0));
        groupBox_3->setMaximumSize(QSize(250, 200));
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


        gridLayout_4->addWidget(groupBox_3, 4, 0, 1, 2);

        LegendHide = new QCheckBox(widget);
        LegendHide->setObjectName(QString::fromUtf8("LegendHide"));

        gridLayout_4->addWidget(LegendHide, 3, 0, 1, 1);

        ColorComponent = new QComboBox(widget);
        ColorComponent->addItem(QString());
        ColorComponent->addItem(QString());
        ColorComponent->addItem(QString());
        ColorComponent->setObjectName(QString::fromUtf8("ColorComponent"));
        ColorComponent->setEnabled(true);
        ColorComponent->setMaximumSize(QSize(250, 25));
        ColorComponent->setEditable(false);

        gridLayout_4->addWidget(ColorComponent, 1, 0, 1, 2);

        ParamSlider = new QSlider(widget);
        ParamSlider->setObjectName(QString::fromUtf8("ParamSlider"));
        ParamSlider->setEnabled(false);
        ParamSlider->setMinimumSize(QSize(240, 0));
        ParamSlider->setMaximumSize(QSize(240, 20));
        ParamSlider->setMaximum(50);
        ParamSlider->setValue(20);
        ParamSlider->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(ParamSlider, 6, 0, 1, 1);

        Reload = new QPushButton(widget);
        Reload->setObjectName(QString::fromUtf8("Reload"));
        Reload->setEnabled(true);
        Reload->setMinimumSize(QSize(120, 0));
        Reload->setMaximumSize(QSize(120, 25));

        gridLayout_4->addWidget(Reload, 9, 0, 1, 1);

        SetCustomMasks = new QPushButton(widget);
        SetCustomMasks->setObjectName(QString::fromUtf8("SetCustomMasks"));
        SetCustomMasks->setMinimumSize(QSize(240, 0));
        SetCustomMasks->setMaximumSize(QSize(240, 25));

        gridLayout_4->addWidget(SetCustomMasks, 5, 0, 1, 1);

        CompareProcAndOrig = new QPushButton(widget);
        CompareProcAndOrig->setObjectName(QString::fromUtf8("CompareProcAndOrig"));
        CompareProcAndOrig->setMaximumSize(QSize(16777215, 25));

        gridLayout_4->addWidget(CompareProcAndOrig, 2, 1, 1, 1);

        MixHisto = new QCheckBox(widget);
        MixHisto->setObjectName(QString::fromUtf8("MixHisto"));

        gridLayout_4->addWidget(MixHisto, 2, 0, 1, 1);

        EffectBox = new QComboBox(widget);
        EffectBox->addItem(QString());
        EffectBox->addItem(QString());
        EffectBox->addItem(QString());
        EffectBox->addItem(QString());
        EffectBox->addItem(QString());
        EffectBox->addItem(QString());
        EffectBox->addItem(QString());
        EffectBox->addItem(QString());
        EffectBox->addItem(QString());
        EffectBox->setObjectName(QString::fromUtf8("EffectBox"));
        EffectBox->setEnabled(true);
        EffectBox->setMaximumSize(QSize(250, 25));

        gridLayout_4->addWidget(EffectBox, 0, 0, 1, 2);

        GetNormalImage = new QPushButton(widget);
        GetNormalImage->setObjectName(QString::fromUtf8("GetNormalImage"));
        GetNormalImage->setMinimumSize(QSize(120, 0));
        GetNormalImage->setMaximumSize(QSize(120, 25));

        gridLayout_4->addWidget(GetNormalImage, 9, 1, 1, 1);

        splitter->addWidget(widget);

        gridLayout_5->addWidget(splitter, 0, 0, 1, 1);


        retranslateUi(HistogramEqualization);

        QMetaObject::connectSlotsByName(HistogramEqualization);
    } // setupUi

    void retranslateUi(QDialog *HistogramEqualization)
    {
        HistogramEqualization->setWindowTitle(QCoreApplication::translate("HistogramEqualization", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("HistogramEqualization", "Histo.. OrigImage", nullptr));
        WorkImage->setText(QCoreApplication::translate("HistogramEqualization", "OrigImage", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("HistogramEqualization", "Histo.. ProcessedImage", nullptr));
        ProcessedImage->setText(QCoreApplication::translate("HistogramEqualization", "ProcessedImage", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("HistogramEqualization", "\320\234\320\260\321\201\320\272\320\260", nullptr));
        LegendHide->setText(QCoreApplication::translate("HistogramEqualization", "HideLegend", nullptr));
        ColorComponent->setItemText(0, QCoreApplication::translate("HistogramEqualization", "\320\232\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        ColorComponent->setItemText(1, QCoreApplication::translate("HistogramEqualization", "\320\227\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));
        ColorComponent->setItemText(2, QCoreApplication::translate("HistogramEqualization", "\320\241\320\270\320\275\320\270\320\271", nullptr));

        Reload->setText(QCoreApplication::translate("HistogramEqualization", "Reload", nullptr));
        SetCustomMasks->setText(QCoreApplication::translate("HistogramEqualization", "SetCustomMasks", nullptr));
        CompareProcAndOrig->setText(QCoreApplication::translate("HistogramEqualization", "\320\241\321\200\320\260\320\262\320\275\320\270\321\202\321\214 \321\201 \320\276\321\200\320\270\320\263", nullptr));
        MixHisto->setText(QCoreApplication::translate("HistogramEqualization", "MixHisto", nullptr));
        EffectBox->setItemText(0, QCoreApplication::translate("HistogramEqualization", "\320\255\320\272\320\262\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        EffectBox->setItemText(1, QCoreApplication::translate("HistogramEqualization", "\320\243\321\201\321\200\320\265\320\264\320\275\321\217\321\216\321\211\320\270\320\271 \321\204\320\270\320\273\321\214\321\202\321\200", nullptr));
        EffectBox->setItemText(2, QCoreApplication::translate("HistogramEqualization", "\320\244\320\270\320\273\321\214\321\202\321\200 \320\223\320\260\321\203\321\201\321\201\320\260", nullptr));
        EffectBox->setItemText(3, QCoreApplication::translate("HistogramEqualization", "\320\244\320\270\320\273\321\214\321\202\321\200 \320\233\320\260\320\277\320\273\320\260\321\201\320\260", nullptr));
        EffectBox->setItemText(4, QCoreApplication::translate("HistogramEqualization", "\320\223\321\200\320\260\320\264\320\270\320\265\320\275\321\202\320\275\321\213\320\271 \321\204\320\270\320\273\321\214\321\202\321\200", nullptr));
        EffectBox->setItemText(5, QCoreApplication::translate("HistogramEqualization", "\320\234\320\265\320\264\320\270\320\260\320\275\320\275\321\213\320\271 \321\204\320\270\320\273\321\214\321\202\321\200 (3\321\2053)", nullptr));
        EffectBox->setItemText(6, QCoreApplication::translate("HistogramEqualization", "\320\234\320\265\320\264\320\270\320\260\320\275\320\275\321\213\320\271 \321\204\320\270\320\273\321\214\321\202\321\200 (\320\232\321\200\320\265\321\201\321\202)", nullptr));
        EffectBox->setItemText(7, QCoreApplication::translate("HistogramEqualization", "\320\220\320\264\320\260\320\277\321\202\320\270\320\262\320\275\321\213\320\271 \320\234\320\265\320\264\320\270\320\260\320\275\320\275\321\213\320\271 \321\204\320\270\320\273\321\214\321\202\321\200 (3\321\2053)", nullptr));
        EffectBox->setItemText(8, QCoreApplication::translate("HistogramEqualization", "\320\220\320\264\320\260\320\277\321\202\320\270\320\262\320\275\321\213\320\271 \320\234\320\265\320\264\320\270\320\260\320\275\320\275\321\213\320\271 \321\204\320\270\320\273\321\214\321\202\321\200 (\320\232\321\200\320\265\321\201\321\202)", nullptr));

        GetNormalImage->setText(QCoreApplication::translate("HistogramEqualization", "GetNormImage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistogramEqualization: public Ui_HistogramEqualization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAMEQUALIZATION_H
