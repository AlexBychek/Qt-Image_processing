/********************************************************************************
** Form generated from reading UI file 'linearfiltering.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEARFILTERING_H
#define UI_LINEARFILTERING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LinearFiltering
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *NolinearGroupBox;
    QGridLayout *gridLayout_2;
    QPushButton *MedSqFilter;
    QPushButton *MedCrsFilter;
    QPushButton *AMedSqFilter;
    QPushButton *AMedCrsFilter;
    QGroupBox *LinearGroupBox;
    QGridLayout *gridLayout;
    QPushButton *GaussFilter;
    QPushButton *LaplasFilter;
    QPushButton *GradFilter;
    QPushButton *MidFilter;

    void setupUi(QWidget *LinearFiltering)
    {
        if (LinearFiltering->objectName().isEmpty())
            LinearFiltering->setObjectName(QString::fromUtf8("LinearFiltering"));
        LinearFiltering->resize(348, 718);
        gridLayout_3 = new QGridLayout(LinearFiltering);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        NolinearGroupBox = new QGroupBox(LinearFiltering);
        NolinearGroupBox->setObjectName(QString::fromUtf8("NolinearGroupBox"));
        gridLayout_2 = new QGridLayout(NolinearGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        MedSqFilter = new QPushButton(NolinearGroupBox);
        MedSqFilter->setObjectName(QString::fromUtf8("MedSqFilter"));
        MedSqFilter->setMinimumSize(QSize(150, 150));
        MedSqFilter->setMaximumSize(QSize(150, 150));

        gridLayout_2->addWidget(MedSqFilter, 0, 0, 1, 1);

        MedCrsFilter = new QPushButton(NolinearGroupBox);
        MedCrsFilter->setObjectName(QString::fromUtf8("MedCrsFilter"));
        MedCrsFilter->setMinimumSize(QSize(150, 150));
        MedCrsFilter->setMaximumSize(QSize(150, 150));

        gridLayout_2->addWidget(MedCrsFilter, 0, 1, 1, 1);

        AMedSqFilter = new QPushButton(NolinearGroupBox);
        AMedSqFilter->setObjectName(QString::fromUtf8("AMedSqFilter"));
        AMedSqFilter->setMinimumSize(QSize(150, 150));
        AMedSqFilter->setMaximumSize(QSize(150, 150));

        gridLayout_2->addWidget(AMedSqFilter, 1, 0, 1, 1);

        AMedCrsFilter = new QPushButton(NolinearGroupBox);
        AMedCrsFilter->setObjectName(QString::fromUtf8("AMedCrsFilter"));
        AMedCrsFilter->setMinimumSize(QSize(150, 150));
        AMedCrsFilter->setMaximumSize(QSize(150, 150));

        gridLayout_2->addWidget(AMedCrsFilter, 1, 1, 1, 1);


        gridLayout_3->addWidget(NolinearGroupBox, 1, 0, 1, 1);

        LinearGroupBox = new QGroupBox(LinearFiltering);
        LinearGroupBox->setObjectName(QString::fromUtf8("LinearGroupBox"));
        gridLayout = new QGridLayout(LinearGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        GaussFilter = new QPushButton(LinearGroupBox);
        GaussFilter->setObjectName(QString::fromUtf8("GaussFilter"));
        GaussFilter->setMinimumSize(QSize(150, 150));
        GaussFilter->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(GaussFilter, 0, 1, 1, 1);

        LaplasFilter = new QPushButton(LinearGroupBox);
        LaplasFilter->setObjectName(QString::fromUtf8("LaplasFilter"));
        LaplasFilter->setMinimumSize(QSize(150, 150));
        LaplasFilter->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(LaplasFilter, 1, 0, 1, 1);

        GradFilter = new QPushButton(LinearGroupBox);
        GradFilter->setObjectName(QString::fromUtf8("GradFilter"));
        GradFilter->setMinimumSize(QSize(150, 150));
        GradFilter->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(GradFilter, 1, 1, 1, 1);

        MidFilter = new QPushButton(LinearGroupBox);
        MidFilter->setObjectName(QString::fromUtf8("MidFilter"));
        MidFilter->setMinimumSize(QSize(150, 150));
        MidFilter->setMaximumSize(QSize(150, 150));

        gridLayout->addWidget(MidFilter, 0, 0, 1, 1);


        gridLayout_3->addWidget(LinearGroupBox, 0, 0, 1, 1);


        retranslateUi(LinearFiltering);

        QMetaObject::connectSlotsByName(LinearFiltering);
    } // setupUi

    void retranslateUi(QWidget *LinearFiltering)
    {
        LinearFiltering->setWindowTitle(QCoreApplication::translate("LinearFiltering", "Form", nullptr));
        NolinearGroupBox->setTitle(QCoreApplication::translate("LinearFiltering", "\320\235\320\265\320\273\320\270\320\275\320\265\320\271\320\275\321\213\320\265", nullptr));
        MedSqFilter->setText(QCoreApplication::translate("LinearFiltering", "\320\234\320\265\320\264\320\270\320\260\320\275\320\275\321\213\320\271 \320\232\320\262\320\260\320\264\321\200\320\260\321\202(3\321\2053)", nullptr));
        MedCrsFilter->setText(QCoreApplication::translate("LinearFiltering", "\320\234\320\265\320\264\320\270\320\260\320\275\320\275\321\213\320\271 \320\232\321\200\320\265\321\201\321\202(3\321\2053)", nullptr));
        AMedSqFilter->setText(QCoreApplication::translate("LinearFiltering", "\320\220\320\234\320\265\320\264\320\270\320\260\320\275\320\275\321\213\320\271 \320\232\320\262\320\260\320\264\321\200\320\260\321\202(3\321\2053)", nullptr));
        AMedCrsFilter->setText(QCoreApplication::translate("LinearFiltering", "\320\220\320\234\320\265\320\264\320\270\320\260\320\275\320\275\321\213\320\271 \320\232\321\200\320\265\321\201\321\202(3\321\2053)", nullptr));
        LinearGroupBox->setTitle(QCoreApplication::translate("LinearFiltering", "\320\233\320\270\320\275\320\265\320\271\320\275\321\213\320\265", nullptr));
        GaussFilter->setText(QCoreApplication::translate("LinearFiltering", "\320\223\320\260\321\203\321\201\321\201", nullptr));
        LaplasFilter->setText(QCoreApplication::translate("LinearFiltering", "\320\233\320\260\320\277\320\273\320\260\321\201", nullptr));
        GradFilter->setText(QCoreApplication::translate("LinearFiltering", "\320\223\321\200\320\260\320\264\320\260\321\206\320\270\321\217", nullptr));
        MidFilter->setText(QCoreApplication::translate("LinearFiltering", "\320\243\321\201\321\200\320\265\320\264\320\275\321\217\321\216\321\211\320\270\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LinearFiltering: public Ui_LinearFiltering {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEARFILTERING_H
