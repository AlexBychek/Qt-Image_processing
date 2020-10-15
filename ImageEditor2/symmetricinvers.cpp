#include "symmetricinvers.h"

QImage SymmetricInvers::V_UP(QImage img)
{
    for(int i = 0; i < img.height() / 2; i++)
        for(int j = 0; j < img.width(); j++)
            img.setPixel(j,img.height() - (i + 1), img.pixel(j,i));
    return img;
}

QImage SymmetricInvers::V_DOWN(QImage img)
{
    for(int i = img.height() / 2; i < img.height(); i++)
        for(int j = 0; j < img.width(); j++)
            img.setPixel(j,img.height() - (i + 1), img.pixel(j,i));
    return img;
}

QImage SymmetricInvers::H_LEFT(QImage img)
{
    for(int i = 0; i < img.height(); i++)
        for(int j = 0; j < img.width() / 2; j++)
            img.setPixel(img.width() - (j + 1),i, img.pixel(j,i));
    return img;
}

QImage SymmetricInvers::H_RIGHT(QImage img)
{
    for(int i = 0; i < img.height(); i++)
        for(int j = img.width() / 2; j < img.width(); j++)
            img.setPixel(img.width() - (j + 1),i, img.pixel(j,i));
    return img;
}
