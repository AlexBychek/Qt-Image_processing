/********************************************************************************
** Form generated from reading UI file 'morphologicaltransformations.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MORPHOLOGICALTRANSFORMATIONS_H
#define UI_MORPHOLOGICALTRANSFORMATIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MorphologicalTransformations
{
public:
    QGridLayout *gridLayout;
    QPushButton *BWButton;
    QPushButton *NotButton;
    QPushButton *OrButton;
    QPushButton *AndButton;
    QPushButton *XorButton;
    QPushButton *DilationButton;
    QPushButton *ErosionButton;
    QPushButton *ClosingButton;
    QPushButton *OpeningButton;

    void setupUi(QWidget *MorphologicalTransformations)
    {
        if (MorphologicalTransformations->objectName().isEmpty())
            MorphologicalTransformations->setObjectName(QString::fromUtf8("MorphologicalTransformations"));
        MorphologicalTransformations->resize(324, 843);
        gridLayout = new QGridLayout(MorphologicalTransformations);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        BWButton = new QPushButton(MorphologicalTransformations);
        BWButton->setObjectName(QString::fromUtf8("BWButton"));
        BWButton->setMinimumSize(QSize(150, 150));
        BWButton->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(BWButton, 0, 0, 1, 1);

        NotButton = new QPushButton(MorphologicalTransformations);
        NotButton->setObjectName(QString::fromUtf8("NotButton"));
        NotButton->setMinimumSize(QSize(150, 150));
        NotButton->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(NotButton, 1, 0, 1, 1);

        OrButton = new QPushButton(MorphologicalTransformations);
        OrButton->setObjectName(QString::fromUtf8("OrButton"));
        OrButton->setMinimumSize(QSize(150, 150));
        OrButton->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(OrButton, 1, 1, 1, 1);

        AndButton = new QPushButton(MorphologicalTransformations);
        AndButton->setObjectName(QString::fromUtf8("AndButton"));
        AndButton->setMinimumSize(QSize(150, 150));
        AndButton->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(AndButton, 2, 0, 1, 1);

        XorButton = new QPushButton(MorphologicalTransformations);
        XorButton->setObjectName(QString::fromUtf8("XorButton"));
        XorButton->setMinimumSize(QSize(150, 150));
        XorButton->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(XorButton, 2, 1, 1, 1);

        DilationButton = new QPushButton(MorphologicalTransformations);
        DilationButton->setObjectName(QString::fromUtf8("DilationButton"));
        DilationButton->setMinimumSize(QSize(150, 150));
        DilationButton->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(DilationButton, 3, 0, 1, 1);

        ErosionButton = new QPushButton(MorphologicalTransformations);
        ErosionButton->setObjectName(QString::fromUtf8("ErosionButton"));
        ErosionButton->setMinimumSize(QSize(150, 150));
        ErosionButton->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(ErosionButton, 3, 1, 1, 1);

        ClosingButton = new QPushButton(MorphologicalTransformations);
        ClosingButton->setObjectName(QString::fromUtf8("ClosingButton"));
        ClosingButton->setMinimumSize(QSize(150, 150));
        ClosingButton->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(ClosingButton, 4, 0, 1, 1);

        OpeningButton = new QPushButton(MorphologicalTransformations);
        OpeningButton->setObjectName(QString::fromUtf8("OpeningButton"));
        OpeningButton->setMinimumSize(QSize(150, 150));
        OpeningButton->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(OpeningButton, 4, 1, 1, 1);


        retranslateUi(MorphologicalTransformations);

        QMetaObject::connectSlotsByName(MorphologicalTransformations);
    } // setupUi

    void retranslateUi(QWidget *MorphologicalTransformations)
    {
        MorphologicalTransformations->setWindowTitle(QCoreApplication::translate("MorphologicalTransformations", "Form", nullptr));
        BWButton->setText(QCoreApplication::translate("MorphologicalTransformations", "BW", nullptr));
        NotButton->setText(QCoreApplication::translate("MorphologicalTransformations", "Not", nullptr));
        OrButton->setText(QCoreApplication::translate("MorphologicalTransformations", "Or", nullptr));
        AndButton->setText(QCoreApplication::translate("MorphologicalTransformations", "And", nullptr));
        XorButton->setText(QCoreApplication::translate("MorphologicalTransformations", "Xor", nullptr));
        DilationButton->setText(QCoreApplication::translate("MorphologicalTransformations", "Dilation", nullptr));
        ErosionButton->setText(QCoreApplication::translate("MorphologicalTransformations", "Erosion", nullptr));
        ClosingButton->setText(QCoreApplication::translate("MorphologicalTransformations", "Closing", nullptr));
        OpeningButton->setText(QCoreApplication::translate("MorphologicalTransformations", "Opening", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MorphologicalTransformations: public Ui_MorphologicalTransformations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MORPHOLOGICALTRANSFORMATIONS_H
