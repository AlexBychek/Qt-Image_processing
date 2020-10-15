#ifndef LINEARFILTERING_H
#define LINEARFILTERING_H

#include <QWidget>
#include "histogramequalization.h"
#include "linerfilter.h"
#include "settings.h"

namespace Ui {
class LinearFiltering;
}

class LinearFiltering : public QWidget
{
    Q_OBJECT

public:
    explicit LinearFiltering(QWidget *parent = nullptr);
    ~LinearFiltering();
    void iconImageStyle();
    void resetImageStyle();
    void setImage(QImage);

signals:
    void ButtonClick(QImage);
public slots:
    void reload();

private:
    Ui::LinearFiltering *ui;
    QImage image;

    QImage MidFilter, GaussFilter, LaplasFilter, GradFilter, MedSqFilter, AMedSqFilter, MedCrsFilter, AMedCrsFilter;
};


#endif // LINEARFILTERING_H
