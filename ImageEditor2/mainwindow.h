#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QScrollArea>
#include <QPrinter>
#include <QDebug>

#include "effectmenu.h"
#include "linearfiltering.h"
#include "effectsliders.h"
#include "logwindow.h"
#include "histogramequalization.h"
#include "settings.h"
#include "morphologicaltransformations.h"
#include "aa.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool saveFile(const QString &fileName);
    bool loadFile(const QString &);
    void setImage(const QImage &newImage, bool);
    void setEffectNoSaveImage(const QImage &image);
    void updateActions();
    void open();
    void saveAs();
    void print();
    void copy();
    void paste();
    void zoomIn();
    void zoomOut();
    void normalSize();
    void fitToWindow();
    void about();
    void adjustScrollBar(QScrollBar *scrollBar, double factor);
    void scaleImage(double factor);

    void backImage();
    void nextImage();
    void Reestablish();
private slots:
    void on_OpenAction_triggered();
private:
    Ui::MainWindow *ui;

    EffectMenu *effectMenu;
    LinearFiltering *linerFiltering;
    EffectSliders *effectSliders;
    LogWindow *logWindow;
    HistogramEqualization *histogram;
    Settings *setting;
    MorphologicalTransformations *morphological;
    AA *aa;


#ifndef QT_NO_PRINTER
    QPrinter printer;
#endif
    QImage image;
    QImage buckup;
    QImage work_image;
    QImage released;
    QString file_path;
    bool back;
    bool next;

    QVector<QImage> BackList;
    int CurrentListItem;
    QLabel *imageLabel;
    double scaleFactor = 1;
};
#endif // MAINWINDOW_H
