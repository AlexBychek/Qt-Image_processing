#ifndef HISTOGRAMEQUALIZATION_H
#define HISTOGRAMEQUALIZATION_H

#include <QDialog>
#include <QtGlobal>
#include "qcustomplot.h"
#include "linerfilter.h"
#include "settings.h"

namespace Ui {
class HistogramEqualization;
}

class HistogramEqualization : public QDialog
{
    Q_OBJECT

public:
    explicit HistogramEqualization(QWidget *parent = nullptr);
    ~HistogramEqualization();
    void SetImageFromWorkForm(QImage);

    void GetHistogramWorkImage(QImage img, QCustomPlot *CPlot, QString);
    void NormalisedImage(QString);

    void Median3x3(QString);
    void MedianCross(QString);
    void AdaptiveMedian3x3(QString);
    void AdaptiveMedianCross(QString);

    void setFilter(QString, QString);
    void MaskFilters(std::vector<std::vector<double>>,int, QString);
    void ShowMask(std::vector<std::vector<double>>);
    double summ(std::vector<double> v, int s, int e);
    void customfilter();

    bool textecvdouble(QString str)
    {
        bool check;
        double value = str.toDouble(&check);
        return check;
    }

    int curr();

signals:
    void GetNormalImage(QImage);
private slots:
    void setFilter(int);

private:
    Ui::HistogramEqualization *ui;
    QImage WorkImage;
    QImage ProcessedImage;
    QVector<double> RW,BW,GW;
    QVector<double> Normal;
protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // HISTOGRAMEQUALIZATION_H
