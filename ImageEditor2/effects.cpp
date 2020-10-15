#include "effects.h"

QImage Effects::OnlyRed(QImage img)
{
    for(int i = 0; i < img.height(); i++)
    {
        QRgb * line = reinterpret_cast<QRgb *>(img.scanLine(i));
        for(int j = 0; j < img.width(); j++)
            *line++ = qRgb(qRed(*line),0,0);
    }
    return img;
}

QImage Effects::OnlyGreen(QImage img)
{
    for(int i = 0; i < img.height(); i++)
    {
        QRgb * line = reinterpret_cast<QRgb *>(img.scanLine(i));
        for(int j = 0; j < img.width(); j++)
            *line++ = qRgb(0,qGreen(*line),0);
    }
    return img;
}

QImage Effects::OnlyBlue(QImage img)
{
    for(int i = 0; i < img.height(); i++)
    {
        QRgb * line = reinterpret_cast<QRgb *>(img.scanLine(i));
        for(int j = 0; j < img.width(); j++)
            *line++ = qRgb(0,0,qBlue(*line));
    }
    return img;
}

QImage Effects::Halftone(QImage img)
{
    for(int i = 0; i < img.height(); i++)
    {
        QRgb * line = reinterpret_cast<QRgb *>(img.scanLine(i));
        for(int j = 0; j < img.width(); j++)
            *line++ = qRgb(0.21*qRed(*line)+0.72*qGreen(*line)+0.07*qBlue(*line),0.21*qRed(*line)+0.72*qGreen(*line)+0.07*qBlue(*line),0.21*qRed(*line)+0.72*qGreen(*line)+0.07*qBlue(*line));
    }
    return img;
}

QImage Effects::Nega(QImage img)
{
    for(int i = 0; i < img.height(); i++)
    {
        QRgb * line = reinterpret_cast<QRgb *>(img.scanLine(i));
        for(int j = 0; j < img.width(); j++)
            *line++ = qRgb(abs(255-qRed(*line)),abs(255-qGreen(*line)),abs(255-qBlue(*line)));
    }
    return img;
}

QImage Effects::Brightness(QImage img,int br)
{
    for(int i = 0; i < img.height(); i++)
    {
        QRgb * line = reinterpret_cast<QRgb *>(img.scanLine(i));
        for(int j = 0; j < img.width(); j++)
        {
            *line++ = qRgb(qRed(*line)+br>255?255:qRed(*line)+br<0?0:qRed(*line)+br,
                           qGreen(*line)+br>255?255:qGreen(*line)+br<0?0:qGreen(*line)+br,
                           qBlue(*line)+br>255?255:qBlue(*line)+br<0?0:qBlue(*line)+br);
        }
    }
    return img;

}

QImage Effects::Contrast(QImage img, int C)
{
    double F = (259.0*(C+255.0)) / ( 255.0*(259.0-C) );
    for(int i = 0; i < img.height(); i++)
    {
        QRgb * line = reinterpret_cast<QRgb *>(img.scanLine(i));
        for(int j = 0; j < img.width(); j++)
            *line++ = qRgb((F*(qRed(*line)-128)+128)>255?255:(F*(qRed(*line)-128)+128)<0?0:(F*(qRed(*line)-128)+128),
                           (F*(qGreen(*line)-128)+128)>255?255:(F*(qGreen(*line)-128)+128)<0?0:(F*(qGreen(*line)-128)+128),
                           (F*(qBlue(*line)-128)+128)>255?255:(F*(qBlue(*line)-128)+128)<0?0:(F*(qBlue(*line)-128)+128));
    }
    return img;
}

QImage Effects::GammaCorrection(QImage img, int exp_)
{
     double gammaCorrection = 1 / (exp_ / 100.0);
     for(int i = 0; i < img.height(); i++)
     {
         QRgb * line = reinterpret_cast<QRgb *>(img.scanLine(i));
         for(int j = 0; j < img.width(); j++)
             *line++ = qRgb(255 * pow((qRed(*line) / 255.0), gammaCorrection),
                            255 * pow((qGreen(*line) / 255.0), gammaCorrection),
                            255 * pow((qBlue(*line) / 255.0), gammaCorrection));
     }
     return img;
}

QImage Effects::salt_and_pepper(QImage img, int noise)
{
    for (int x = 0; x <noise; ++x) {
        img.setPixel(randomBetween(1, img.width()-2),
                          randomBetween(1, img.height()-2),
                          qRgb(0,0,0));
        img.setPixel(randomBetween(1, img.width()-2),
                          randomBetween(1, img.height()-2),
                          qRgb(255,255,255));
    }

    return img;
}

QImage Effects::salt_and_pepperB(QImage img, int noise)
{
    int i,j;
    for (int x = 0; x <noise; ++x) {
        i = randomBetween(1, img.width()-3);
        j = randomBetween(1, img.height()-3);

        img.setPixel(i,j, qRgb(255,255,255));
        img.setPixel(i+1,j+1, qRgb(0,0,0));
        img.setPixel(i-1,j-1, qRgb(0,0,0));
    }

    return img;
}
