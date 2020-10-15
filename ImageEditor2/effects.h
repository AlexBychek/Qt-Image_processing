#ifndef EFFECTS_H
#define EFFECTS_H

#include <QImage>
#include <QtMath>
#include <QDateTime>

class Effects
{
public:
    static QImage OnlyRed(QImage);
    static QImage OnlyGreen(QImage);
    static QImage OnlyBlue(QImage);

    static QImage Halftone(QImage);
    static QImage Nega(QImage);

    static QImage Brightness(QImage,int);
    static QImage Contrast(QImage,int);
    static QImage GammaCorrection(QImage,int);

    static QImage salt_and_pepper(QImage, int);

    static QImage salt_and_pepperB(QImage, int);
};

static int randomBetween(int low, int high, int seed)
{
    qsrand(seed);
    return (qrand() % ((high + 1) - low) + low);
}

static int randomBetween(int low, int high)
{
    return (qrand() % ((high + 1) - low) + low);
}

#endif // EFFECTS_H
