#ifndef LINERFILTER_H
#define LINERFILTER_H

#include <QImage>

class LinerFilter
{
public:
    QImage static MaskFilters(QImage,std::vector<std::vector<double>>,int);
    QImage static NormalisedImage(QImage);
    QImage static Median3x3(QImage, QString);
    QImage static MedianCross(QImage, QString);
    QImage static Laplas(QImage);
    QImage static Gradient(QImage);
};

#endif // LINERFILTER_H
