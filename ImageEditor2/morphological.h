#ifndef MORPHOLOGICAL_H
#define MORPHOLOGICAL_H

#include <QImage>
#include <QDebug>
#include "settings.h"
#include "effects.h"
class morphological
{
public:
    QImage static Binary(QImage);

    QImage static Erosion(QImage);
    QImage static Dilation(QImage);
    QImage static Disclosure();
    QImage static Closing();

    QImage static Not(QImage);
    QImage static Or(QImage, QImage);
    QImage static And(QImage, QImage);
    QImage static Xor(QImage, QImage);
};

#endif // MORPHOLOGICAL_H
