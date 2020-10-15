#ifndef SSAA_H
#define SSAA_H

#include <QImage>
#include <QDebug>
#include <math.h>

#define A(a) a > 255 ? 255 : a < 0 ? 0 : a

class SSAA
{
public:
     QImage static bilinear_interpolation1(int, QImage);
     QImage static bilinear_interpolation2(int, QImage);
     QImage static bicubic_interpolation(int, QImage);

     QImage static Low_pass_filters(int, QImage, QImage);

     QImage static Supersample(int, QImage, int);

     float static Lerp(float s, float e, float t);
     float static Blerp(float c00, float c10, float c01, float c11, float tx, float ty);
     float static cubic_hermite(float A, float B, float C, float D, float t);
     QRgb static sample_bicubic(QImage source_image, float u, float v);

};


#endif // SSAA_H
