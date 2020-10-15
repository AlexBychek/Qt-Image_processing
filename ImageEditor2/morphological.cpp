#include "morphological.h"

QImage morphological::Binary(QImage img)
{
    img = Settings::HalfGamma ? Effects::Halftone(img) : img;
    for(int i = 0; i < img.height(); i++)
    {
        QRgb * line = reinterpret_cast<QRgb *>(img.scanLine(i));
        for(int j = 0; j < img.width(); j++)
            *line++ = qRgb((double)(qRed(*line))/255.0<Settings::Gamma ? 0 : 255,
                           (double)(qGreen(*line))/255.0<Settings::Gamma ? 0 : 255,
                           (double)(qBlue(*line))/255.0<Settings::Gamma ? 0 : 255);

    }
    return img;
}

QImage morphological::Not(QImage img)
{
    for(int i = 0; i < img.height(); i++)
    {
        QRgb * line = reinterpret_cast<QRgb *>(img.scanLine(i));
        for(int j = 0; j < img.width(); j++)
            *line++ = ~*line;
    }
    return img;
}

QImage morphological::Or(QImage img1, QImage img2)
{
    if(img1.width() == img2.width() && img1.height() == img2.height())
        for(int y = 0; y < img1.height(); ++y)
        {
            QRgb *line1 = reinterpret_cast<QRgb *>(img1.scanLine(y));
            QRgb *line2 = reinterpret_cast<QRgb *>(img2.scanLine(y));
            for(int x = 0; x < img1.width(); ++x )
                *line1++ |= *line2++;
        }

    return img1;
}

QImage morphological::And(QImage img1, QImage img2)
{
    if(img1.width() == img2.width() && img1.height() == img2.height())
        for(int y = 0; y < img1.height(); ++y)
            {
                QRgb *line1 = reinterpret_cast<QRgb *>(img1.scanLine(y));
                QRgb *line2 = reinterpret_cast<QRgb *>(img2.scanLine(y));
                for(int x = 0; x < img1.width(); ++x )
                    *line1++ &= *line2++;
            }

        return img1;
}

QImage morphological::Xor(QImage img1, QImage img2)
{
    if(img1.width() == img2.width() && img1.height() == img2.height())
            for(int y = 0; y < img1.height(); ++y)
            {
                QRgb *line1 = reinterpret_cast<QRgb *>(img1.scanLine(y));
                QRgb *line2 = reinterpret_cast<QRgb *>(img2.scanLine(y));

                for(int x = 0; x < img1.width(); ++x )
                    *line1++ ^= *line2++;
            }
        return img1;
}

QImage morphological::Erosion(QImage img)
{

    QImage proc = img;

    double B_all_RED = 0.0;
    double B_all_GREEN = 0.0;
    double B_all_BLUE = 0.0;
    for(int y = 1; y < img.height()-1; ++y)
    {
        for(int x = 1; x < img.width()-1; ++x)
        {
            B_all_RED = 0.0;
            B_all_GREEN = 0.0;
            B_all_BLUE = 0.0;

            for(int l = 0; l < 3; ++l)
                for(int k = 0; k < 3; ++k)
                {
                    B_all_RED += qRed(img.pixel(x-(1-l),y-(1-k)))/255.0;
                    B_all_GREEN += qGreen(img.pixel(x-(1-l),y-(1-k)))/255.0;
                    B_all_BLUE += qBlue(img.pixel(x-(1-l),y-(1-k)))/255.0;

                    if( B_all_RED < 9 &&
                        B_all_GREEN < 9 &&
                        B_all_BLUE < 9 )
                        proc.setPixel(x,y,qRgb(0,0,0));
                    else
                        proc.setPixel(x,y,qRgb(255,255,255));
                }
        }
    }

    return proc;
}

QImage morphological::Dilation(QImage img)
{
    QImage proc = img;

    double B_all_RED = 0.0;
    double B_all_GREEN = 0.0;
    double B_all_BLUE = 0.0;
    for(int y = 1; y < img.height()-1; ++y)
    {
        for(int x = 1; x < img.width()-1; ++x)
        {
            B_all_RED = 0.0;
            B_all_GREEN = 0.0;
            B_all_BLUE = 0.0;

            for(int l = 0; l < 3; ++l)
                for(int k = 0; k < 3; ++k)
                {
                    B_all_RED += qRed(img.pixel(x-(1-l),y-(1-k)))/255.0;
                    B_all_GREEN += qGreen(img.pixel(x-(1-l),y-(1-k)))/255.0;
                    B_all_BLUE += qBlue(img.pixel(x-(1-l),y-(1-k)))/255.0;

                    if( B_all_RED > 0 &&
                        B_all_GREEN > 0 &&
                        B_all_BLUE > 0 )
                        proc.setPixel(x,y,qRgb(255,255,255));
                    else
                        proc.setPixel(x,y,qRgb(0,0,0));
                }
        }
    }

    return proc;
}
