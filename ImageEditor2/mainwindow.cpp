#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QClipboard>
#include <QColorSpace>
#include <QDir>
#include <QFileDialog>
#include <QImageReader>
#include <QImageWriter>
#include <QLabel>
#include <QMenuBar>
#include <QMessageBox>
#include <QMimeData>
#include <QPainter>
#include <QScreen>
#include <QScrollArea>
#include <QScrollBar>
#include <QStandardPaths>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), imageLabel(new QLabel)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CurrentListItem = 0;
    scaleFactor = 1.0;

    back = false;
    next = false;

    effectMenu = new EffectMenu(ui->EffectScroll);
    linerFiltering = new LinearFiltering(ui->LinerFilterScrollArea);
    morphological = new MorphologicalTransformations(ui->MorphologicalScrollArea);

    setting = new Settings();

    effectSliders = new EffectSliders(ui->EffectSlidersScroll);
    logWindow = new LogWindow(this);
    histogram = new HistogramEqualization(this);
    aa = new AA(this);


    QGridLayout *gr = new QGridLayout;
    gr->addWidget(histogram);
    ui->HistogramWidget->setLayout(gr);

    ui->EffectScroll->setWidget(effectMenu);
    ui->EffectScroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    ui->EffectSlidersScroll->setWidget(effectSliders);
    ui->EffectSlidersScroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    ui->LinerFilterScrollArea->setWidget(linerFiltering);
    ui->LinerFilterScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    ui->MorphologicalScrollArea->setWidget(morphological);
    ui->MorphologicalScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    ui->AAScrollArea->setWidget(aa);
    ui->AAScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    ui->scrollArea->setBackgroundRole(QPalette::Dark);
    ui->scrollArea->setWidget(imageLabel);
    ui->scrollArea->setVisible(false);

    resize(QGuiApplication::primaryScreen()->availableSize() * 3 / 5);

    ui->OpenAction->setShortcut(QKeySequence::Open);

    ui->actionSaveAs->setEnabled(false);
    ui->actionCopy->setShortcut(QKeySequence::Copy);
    ui->actionCopy->setEnabled(false);
    ui->actionPaste->setShortcut(QKeySequence::Paste);
    ui->actionZoom_In_25->setShortcut(QKeySequence::ZoomIn);
    ui->actionZoom_In_25->setEnabled(false);
    ui->actionZoom_Out_25->setShortcut(QKeySequence::ZoomOut);
    ui->actionZoom_Out_25->setEnabled(false);
    ui->actionNormal_Size ->setShortcut(tr("Ctrl+S"));
    ui->actionNormal_Size ->setEnabled(false);
    ui->actionFit_to_Window->setEnabled(false);
    ui->actionFit_to_Window->setCheckable(true);
    ui->actionFit_to_Window->setShortcut(tr("Ctrl+F"));
    ui->actionBack->setShortcut(tr("Ctrl+Shift+B"));
    ui->actionBack->setEnabled(false);
    ui->actionNext->setShortcut(tr("Ctrl+Shift+N"));
    ui->actionNext->setEnabled(false);
    ui->actionRestart->setShortcut(tr("Ctrl+Shift+R"));
    ui->actionRestart->setEnabled(false);
    ui->actionLogs->setShortcut(tr("Ctrl+L"));
    ui->actionHistogramEqualization->setShortcut(tr("Ctrl+H"));
    ui->actionHistogramEqualizationChecked->setShortcut(tr("Ctrl+Shift+H"));

    connect(effectMenu, &EffectMenu::ButtonClick, [&](QImage img){
        logWindow->addlog("Применен фильтр");
        setImage(img, true);
    });

    connect(linerFiltering, &LinearFiltering::ButtonClick, [&](QImage img){
        setImage(img, true);
    });

    connect(morphological, &MorphologicalTransformations::ButtonClick, [&](QImage img)
    {
        setImage(img, true);
    });

    connect(aa, &AA::ButtonClick, [&](QImage img)
    {
        setImage(img, true);
    });

    connect(ui->actionSaveAs, &QAction::triggered, [this]{ saveAs(); });
    connect(ui->actionCopy, &QAction::triggered, [this]{ copy(); });
    connect(ui->actionPaste, &QAction::triggered, [this]{ paste(); });
    connect(ui->actionZoom_In_25, &QAction::triggered, [this]{ zoomIn(); });
    connect(ui->actionZoom_Out_25, &QAction::triggered, [this]{ zoomOut(); });
    connect(ui->actionNormal_Size, &QAction::triggered, [this]{ normalSize(); });
    connect(ui->actionFit_to_Window, &QAction::triggered, [this]{ fitToWindow(); });
    connect(ui->actionExit, &QAction::triggered, [this]{ QWidget::close(); });
    connect(ui->actionSettins, &QAction::triggered, [this]{ setting->show(); });


    connect(effectSliders, &EffectSliders::SliderChanged, [this](QImage img){
        work_image = image;
        setImage(img, false);
        released = image;
        image = work_image;
        effectSliders->setImage(image);
    });
    connect(effectSliders, &EffectSliders::SliderReleased, [this]{ setImage(released, true); });
    connect(ui->actionBack, &QAction::triggered, [this]{ backImage(); });
    connect(ui->actionNext, &QAction::triggered, [this]{ nextImage(); });
    connect(ui->actionRestart, &QAction::triggered, [this]{ Reestablish(); });
    connect(ui->actionLogs, &QAction::triggered, [this]{ logWindow->show(); });


    connect(histogram, &HistogramEqualization::GetNormalImage, [this](const QImage img){ setImage(img, true); });

    connect(setting, &Settings::chageState, [this]
    {
        linerFiltering->reload();
        morphological->reload();

        if(histogram->curr() == 3)
        {
            histogram->ShowMask(Settings::Laplas);
            histogram->MaskFilters(Settings::Laplas,1,"Лаплас");
        }

    });

    connect(setting, &Settings::chageStateIcon, [this]
    {
        linerFiltering->setImage(this->image);
        effectMenu->setImage(this->image);
        morphological->setImage(this->image);

    });

    connect(ui->FileInf, &FileInform::PushPixelColor, [this](int x, int y){
        ui->FileInf->showPixelColor(qRed(this->image.pixel(x,y)), qGreen(this->image.pixel(x,y)), qBlue(this->image.pixel(x,y)));
    });

}

bool MainWindow::loadFile(const QString &fileName)
{
    file_path = fileName;
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull()) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2")
                                 .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
        logWindow->addlog("Cannot load");
        return false;
    }
    BackList.clear();
    setImage(newImage, true);

    setWindowFilePath(fileName);

    const QString message = tr("Opened \"%1\", %2x%3, Depth: %4")
        .arg(QDir::toNativeSeparators(fileName)).arg(image.width()).arg(image.height()).arg(image.depth());
    logWindow->addlog(message);
    statusBar()->showMessage(message);
    return true;
}


void MainWindow::setImage(const QImage &newImage, bool save)
{
    image = newImage;
    linerFiltering->setImage(image);
    effectMenu->setImage(image);
    morphological->setImage(image);
    effectSliders->setImage(image);
    aa->setImage(image);

    if(save)
    {
        if(BackList.size() == 0)
        {
            this->buckup = image;
            this->BackList.push_back(image);
            CurrentListItem = BackList.size();

        }
        else if(CurrentListItem != BackList.size() && (back != true && next != true))
        {
            BackList.resize(CurrentListItem);
            BackList.push_back(image);
            CurrentListItem = BackList.size();
        }
        else if(back != true && next != true)
        {
                BackList.push_back(image);
                CurrentListItem = BackList.size();
        }
    }
    back = false;
    next = false;
    ui->FileInf->SetMetaData(image, file_path);
    if (image.colorSpace().isValid())
        image.convertToColorSpace(QColorSpace::SRgb);
    imageLabel->setPixmap(QPixmap::fromImage(image));

    scaleFactor = 1.0;

    ui->scrollArea->setVisible(true);
    ui->actionFit_to_Window->setEnabled(true);
    updateActions();

    if (!(ui->actionFit_to_Window->isChecked()))
        imageLabel->adjustSize();

    fitToWindow();

    if(ui->actionHistogramEqualizationChecked->isChecked())
        this->histogram->SetImageFromWorkForm(this->image);


}


void MainWindow::setEffectNoSaveImage(const QImage &image)
{
    work_image = this->image;
}

void MainWindow::open()
{
    QFileDialog dialog(this, tr("Open File"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);

    while (dialog.exec() == QDialog::Accepted && !loadFile(dialog.selectedFiles().first())) {}
}

MainWindow::~MainWindow()
{
    delete ui;
    delete effectMenu;
   delete effectSliders;
}

void MainWindow::on_OpenAction_triggered()
{
    open();
}

void MainWindow::print()
{
    Q_ASSERT(imageLabel->pixmap());

        QPainter painter(&printer);
        QRect rect = painter.viewport();
        QSize size = imageLabel->pixmap()->size();
        size.scale(rect.size(), Qt::KeepAspectRatio);
        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
        painter.setWindow(imageLabel->pixmap()->rect());
        painter.drawPixmap(0, 0, *imageLabel->pixmap());
}

bool MainWindow::saveFile(const QString &fileName)
{
    QImageWriter writer(fileName);

    if (!writer.write(image)) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot write %1: %2")
                                 .arg(QDir::toNativeSeparators(fileName)), writer.errorString());
        return false;
    }
    const QString message = tr("Wrote \"%1\"").arg(QDir::toNativeSeparators(fileName));
    statusBar()->showMessage(message);
    return true;
}

void MainWindow::saveAs()
{
    QFileDialog dialog(this, tr("Save File As"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptSave);

    while (dialog.exec() == QDialog::Accepted && !saveFile(dialog.selectedFiles().first())) {}
}


void MainWindow::fitToWindow()
{
    bool fitToWindow = ui->actionFit_to_Window->isChecked();
    ui->scrollArea->setWidgetResizable(fitToWindow);

    if (!fitToWindow)
        normalSize();

    updateActions();
}

void MainWindow::zoomIn(){
    logWindow->addlog("Изображение увеличено на 25%");
    scaleImage(1.25);
}
void MainWindow::zoomOut(){
    logWindow->addlog("Изображение уменьшено на 25%");
    scaleImage(0.8);
}
void MainWindow::normalSize(){
    logWindow->addlog("Изображение вернули в исходное состояние");
    imageLabel->adjustSize();
    scaleFactor = 1.0;
}

void MainWindow::scaleImage(double factor)
{
    Q_ASSERT(imageLabel->pixmap());
    scaleFactor *= factor;
    imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());

    adjustScrollBar(ui->scrollArea->horizontalScrollBar(), factor);
    adjustScrollBar(ui->scrollArea->verticalScrollBar(), factor);

    ui->actionZoom_In_25->setEnabled(scaleFactor < 3.0);
    ui->actionZoom_Out_25->setEnabled(scaleFactor > 0.333);
}

void MainWindow::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value()
                            + ((factor - 1) * scrollBar->pageStep()/2)));
}

void MainWindow::updateActions()
{
    ui->actionSaveAs->setEnabled(!image.isNull());
    ui->actionCopy->setEnabled(!image.isNull());
    ui->actionZoom_In_25->setEnabled(!ui->actionFit_to_Window->isChecked());
    ui->actionZoom_Out_25->setEnabled(!ui->actionFit_to_Window->isChecked());
    ui->actionNormal_Size->setEnabled(!ui->actionFit_to_Window->isChecked());
    ui->actionBack->setEnabled(true);
    ui->actionNext->setEnabled(true);
    ui->actionRestart->setEnabled(true);
    ui->EffectTab->setEnabled(true);
}

void MainWindow::copy()
{
#ifndef QT_NO_CLIPBOARD
    QGuiApplication::clipboard()->setImage(image);
#endif // !QT_NO_CLIPBOARD
}

#ifndef QT_NO_CLIPBOARD
static QImage clipboardImage()
{
    if (const QMimeData *mimeData = QGuiApplication::clipboard()->mimeData()) {
        if (mimeData->hasImage()) {
            const QImage image = qvariant_cast<QImage>(mimeData->imageData());
            if (!image.isNull())
                return image;
        }
    }
    return QImage();
}
#endif // !QT_NO_CLIPBOARD

void MainWindow::paste()
{
#ifndef QT_NO_CLIPBOARD
    const QImage newImage = clipboardImage();
    if (newImage.isNull()) {
        statusBar()->showMessage(tr("No image in clipboard"));
    } else {
        BackList.clear();
        setImage(newImage, true);
        setWindowFilePath(QString());
        const QString message = tr("Obtained image from clipboard, %1x%2, Depth: %3")
            .arg(newImage.width()).arg(newImage.height()).arg(newImage.depth());
        statusBar()->showMessage(message);
    }
#endif // !QT_NO_CLIPBOARD
}

void MainWindow::backImage()
{
    if(BackList.size() > 1 && CurrentListItem > 1)
    {
        back = true;
        CurrentListItem--;
        image = BackList[CurrentListItem-1];
        logWindow->addlog("CurrentListItem = " + QString::number(CurrentListItem) + " BackList.size = " + QString::number(BackList.size()));
        setImage(image,true);
    }
}

void MainWindow::nextImage()
{
    if(CurrentListItem < BackList.size())
    {
        next = true;
        CurrentListItem++;
        image = BackList[CurrentListItem-1];
        logWindow->addlog("CurrentListItem = " + QString::number(CurrentListItem) + " BackList.size = " + QString::number(BackList.size()));
        setImage(image,true);
    }
}

void MainWindow::Reestablish()
{
    BackList.clear();
    setImage(buckup,true);
    logWindow->addlog("Изображение восстановленно");

}
