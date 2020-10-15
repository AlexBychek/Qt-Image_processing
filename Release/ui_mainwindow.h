/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "fileinform.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *OpenAction;
    QAction *actionSaveAs;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionZoom_In_25;
    QAction *actionZoom_Out_25;
    QAction *actionNormal_Size;
    QAction *actionFit_to_Window;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionNext;
    QAction *actionBack;
    QAction *actionRestart;
    QAction *actionLogs;
    QAction *actionHistogramEqualization;
    QAction *actionHistogramEqualizationChecked;
    QAction *actionFileInfo;
    QAction *actionSettins;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QSplitter *splitter;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *Histogram;
    QGridLayout *gridLayout_5;
    QWidget *HistogramWidget;
    QTabWidget *EffectTab;
    QWidget *EffectTab1;
    QGridLayout *gridLayout_3;
    QSplitter *splitter_2;
    QScrollArea *EffectScroll;
    QWidget *scrollAreaWidgetContents_2;
    FileInform *FileInf;
    QWidget *tab_2;
    QGridLayout *gridLayout_6;
    QScrollArea *LinerFilterScrollArea;
    QWidget *scrollAreaWidgetContents_4;
    QWidget *tab_4;
    QGridLayout *gridLayout_7;
    QScrollArea *MorphologicalScrollArea;
    QWidget *scrollAreaWidgetContents_5;
    QWidget *tab_3;
    QGridLayout *gridLayout_8;
    QScrollArea *AAScrollArea;
    QWidget *scrollAreaWidgetContents_6;
    QWidget *SliderTab;
    QGridLayout *gridLayout_4;
    QScrollArea *EffectSlidersScroll;
    QWidget *scrollAreaWidgetContents_3;
    QMenuBar *menubar;
    QMenu *menuOpen;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuAbout;
    QMenu *menuTools;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1326, 796);
        MainWindow->setMinimumSize(QSize(800, 500));
        OpenAction = new QAction(MainWindow);
        OpenAction->setObjectName(QString::fromUtf8("OpenAction"));
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        actionSaveAs->setEnabled(false);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionCopy->setEnabled(false);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionZoom_In_25 = new QAction(MainWindow);
        actionZoom_In_25->setObjectName(QString::fromUtf8("actionZoom_In_25"));
        actionZoom_In_25->setEnabled(false);
        actionZoom_Out_25 = new QAction(MainWindow);
        actionZoom_Out_25->setObjectName(QString::fromUtf8("actionZoom_Out_25"));
        actionZoom_Out_25->setEnabled(false);
        actionNormal_Size = new QAction(MainWindow);
        actionNormal_Size->setObjectName(QString::fromUtf8("actionNormal_Size"));
        actionNormal_Size->setEnabled(false);
        actionFit_to_Window = new QAction(MainWindow);
        actionFit_to_Window->setObjectName(QString::fromUtf8("actionFit_to_Window"));
        actionFit_to_Window->setCheckable(true);
        actionFit_to_Window->setChecked(false);
        actionFit_to_Window->setEnabled(true);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout->setCheckable(false);
        actionAbout->setChecked(false);
        actionNext = new QAction(MainWindow);
        actionNext->setObjectName(QString::fromUtf8("actionNext"));
        actionNext->setEnabled(false);
        actionBack = new QAction(MainWindow);
        actionBack->setObjectName(QString::fromUtf8("actionBack"));
        actionBack->setEnabled(false);
        actionRestart = new QAction(MainWindow);
        actionRestart->setObjectName(QString::fromUtf8("actionRestart"));
        actionRestart->setEnabled(false);
        actionLogs = new QAction(MainWindow);
        actionLogs->setObjectName(QString::fromUtf8("actionLogs"));
        actionHistogramEqualization = new QAction(MainWindow);
        actionHistogramEqualization->setObjectName(QString::fromUtf8("actionHistogramEqualization"));
        actionHistogramEqualization->setCheckable(false);
        actionHistogramEqualization->setChecked(false);
        actionHistogramEqualization->setEnabled(true);
        actionHistogramEqualizationChecked = new QAction(MainWindow);
        actionHistogramEqualizationChecked->setObjectName(QString::fromUtf8("actionHistogramEqualizationChecked"));
        actionHistogramEqualizationChecked->setCheckable(true);
        actionHistogramEqualizationChecked->setChecked(true);
        actionFileInfo = new QAction(MainWindow);
        actionFileInfo->setObjectName(QString::fromUtf8("actionFileInfo"));
        actionSettins = new QAction(MainWindow);
        actionSettins->setObjectName(QString::fromUtf8("actionSettins"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setMinimumSize(QSize(50, 50));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 900, 688));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        Histogram = new QWidget();
        Histogram->setObjectName(QString::fromUtf8("Histogram"));
        gridLayout_5 = new QGridLayout(Histogram);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        HistogramWidget = new QWidget(Histogram);
        HistogramWidget->setObjectName(QString::fromUtf8("HistogramWidget"));

        gridLayout_5->addWidget(HistogramWidget, 0, 0, 1, 1);

        tabWidget->addTab(Histogram, QString());
        splitter->addWidget(tabWidget);
        EffectTab = new QTabWidget(splitter);
        EffectTab->setObjectName(QString::fromUtf8("EffectTab"));
        EffectTab->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EffectTab->sizePolicy().hasHeightForWidth());
        EffectTab->setSizePolicy(sizePolicy);
        EffectTab->setMinimumSize(QSize(380, 0));
        EffectTab->setMaximumSize(QSize(240, 16777215));
        EffectTab->setLayoutDirection(Qt::LeftToRight);
        EffectTab->setTabPosition(QTabWidget::North);
        EffectTab->setTabShape(QTabWidget::Rounded);
        EffectTab->setElideMode(Qt::ElideNone);
        EffectTab1 = new QWidget();
        EffectTab1->setObjectName(QString::fromUtf8("EffectTab1"));
        gridLayout_3 = new QGridLayout(EffectTab1);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        splitter_2 = new QSplitter(EffectTab1);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        EffectScroll = new QScrollArea(splitter_2);
        EffectScroll->setObjectName(QString::fromUtf8("EffectScroll"));
        EffectScroll->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 356, 434));
        EffectScroll->setWidget(scrollAreaWidgetContents_2);
        splitter_2->addWidget(EffectScroll);
        FileInf = new FileInform(splitter_2);
        FileInf->setObjectName(QString::fromUtf8("FileInf"));
        FileInf->setMinimumSize(QSize(0, 250));
        FileInf->setMaximumSize(QSize(16777215, 150));
        splitter_2->addWidget(FileInf);

        gridLayout_3->addWidget(splitter_2, 0, 0, 1, 1);

        EffectTab->addTab(EffectTab1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_6 = new QGridLayout(tab_2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        LinerFilterScrollArea = new QScrollArea(tab_2);
        LinerFilterScrollArea->setObjectName(QString::fromUtf8("LinerFilterScrollArea"));
        LinerFilterScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 356, 688));
        LinerFilterScrollArea->setWidget(scrollAreaWidgetContents_4);

        gridLayout_6->addWidget(LinerFilterScrollArea, 0, 0, 1, 1);

        EffectTab->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_7 = new QGridLayout(tab_4);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        MorphologicalScrollArea = new QScrollArea(tab_4);
        MorphologicalScrollArea->setObjectName(QString::fromUtf8("MorphologicalScrollArea"));
        MorphologicalScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_5"));
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 356, 688));
        MorphologicalScrollArea->setWidget(scrollAreaWidgetContents_5);

        gridLayout_7->addWidget(MorphologicalScrollArea, 0, 0, 1, 1);

        EffectTab->addTab(tab_4, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_8 = new QGridLayout(tab_3);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        AAScrollArea = new QScrollArea(tab_3);
        AAScrollArea->setObjectName(QString::fromUtf8("AAScrollArea"));
        AAScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_6 = new QWidget();
        scrollAreaWidgetContents_6->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_6"));
        scrollAreaWidgetContents_6->setGeometry(QRect(0, 0, 356, 688));
        AAScrollArea->setWidget(scrollAreaWidgetContents_6);

        gridLayout_8->addWidget(AAScrollArea, 0, 0, 1, 1);

        EffectTab->addTab(tab_3, QString());
        SliderTab = new QWidget();
        SliderTab->setObjectName(QString::fromUtf8("SliderTab"));
        gridLayout_4 = new QGridLayout(SliderTab);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        EffectSlidersScroll = new QScrollArea(SliderTab);
        EffectSlidersScroll->setObjectName(QString::fromUtf8("EffectSlidersScroll"));
        EffectSlidersScroll->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 356, 688));
        EffectSlidersScroll->setWidget(scrollAreaWidgetContents_3);

        gridLayout_4->addWidget(EffectSlidersScroll, 0, 0, 1, 1);

        EffectTab->addTab(SliderTab, QString());
        splitter->addWidget(EffectTab);

        gridLayout_2->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1326, 21));
        menuOpen = new QMenu(menubar);
        menuOpen->setObjectName(QString::fromUtf8("menuOpen"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOpen->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuOpen->addAction(OpenAction);
        menuOpen->addAction(actionSaveAs);
        menuOpen->addSeparator();
        menuOpen->addAction(actionExit);
        menuEdit->addAction(actionBack);
        menuEdit->addAction(actionNext);
        menuEdit->addAction(actionRestart);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuView->addAction(actionZoom_In_25);
        menuView->addAction(actionZoom_Out_25);
        menuView->addAction(actionNormal_Size);
        menuView->addSeparator();
        menuView->addAction(actionFit_to_Window);
        menuAbout->addAction(actionAbout);
        menuTools->addAction(actionLogs);
        menuTools->addAction(actionSettins);
        menuTools->addSeparator();
        menuTools->addAction(actionHistogramEqualizationChecked);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        EffectTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        OpenAction->setText(QCoreApplication::translate("MainWindow", "Open...", nullptr));
        actionSaveAs->setText(QCoreApplication::translate("MainWindow", "Save As...", nullptr));
        actionSaveAs->setIconText(QCoreApplication::translate("MainWindow", "Save Ass", nullptr));
        actionCopy->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        actionPaste->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
        actionZoom_In_25->setText(QCoreApplication::translate("MainWindow", "Zoom In (25%)", nullptr));
        actionZoom_Out_25->setText(QCoreApplication::translate("MainWindow", "Zoom Out (25%)", nullptr));
        actionNormal_Size->setText(QCoreApplication::translate("MainWindow", "Normal Size", nullptr));
        actionFit_to_Window->setText(QCoreApplication::translate("MainWindow", "Fit to Window", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionNext->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        actionBack->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        actionRestart->setText(QCoreApplication::translate("MainWindow", "Restart", nullptr));
        actionLogs->setText(QCoreApplication::translate("MainWindow", "Logs", nullptr));
        actionHistogramEqualization->setText(QCoreApplication::translate("MainWindow", "HistogramEqualization", nullptr));
        actionHistogramEqualizationChecked->setText(QCoreApplication::translate("MainWindow", "HistogramEqualizationChecked", nullptr));
        actionFileInfo->setText(QCoreApplication::translate("MainWindow", "FileInfo", nullptr));
        actionSettins->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Image", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Histogram), QCoreApplication::translate("MainWindow", "Histogram", nullptr));
        EffectTab->setTabText(EffectTab->indexOf(EffectTab1), QCoreApplication::translate("MainWindow", "\320\255\321\204\321\204\320\265\320\272\321\202\321\213", nullptr));
        EffectTab->setTabText(EffectTab->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\320\233\320\270\320\275\320\265\320\271\320\275\320\260\321\217 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        EffectTab->setTabText(EffectTab->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\320\234\320\276\321\200\321\204\320\276\320\273\320\276\320\263\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \320\277\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        EffectTab->setTabText(EffectTab->indexOf(tab_3), QCoreApplication::translate("MainWindow", "AA", nullptr));
        EffectTab->setTabText(EffectTab->indexOf(SliderTab), QCoreApplication::translate("MainWindow", "\320\241\320\273\320\260\320\271\320\264\320\265\321\200\321\213", nullptr));
        menuOpen->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
