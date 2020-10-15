#include "ssaa.h"

#define color_array(a) { qRed(a), qGreen(a), qBlue(a) }

float SSAA::cubic_hermite(float A, float B, float C, float D, float t) {

    float a = -A / 2.0f + (3.0f*B) / 2.0f - (3.0f*C) / 2.0f + D / 2.0f;
    float b = A - (5.0f*B) / 2.0f + 2.0f*C - D / 2.0f;
    float c = -A / 2.0f + C / 2.0f;
    float d = B;

    return a * t*t*t + b * t*t + c * t + d;
}

QRgb SSAA::sample_bicubic(QImage source_image, float u, float v) {

    float x = (u * source_image.width()) - 0.5;
    int xint = int(x);
    float xfract = x - floor(x);

    float y = (v * source_image.height()) - 0.5;
    int yint = int(y);
    float yfract = y - floor(y);

        QRgb p00 = source_image.pixel(xint - 1, yint - 1);
        QRgb p10 = source_image.pixel(xint + 0, yint - 1);
        QRgb p20 = source_image.pixel(xint + 1, yint - 1);
        QRgb p30 = source_image.pixel(xint + 2, yint - 1);

        QRgb p01 = source_image.pixel(xint - 1, yint + 0);
        QRgb p11 = source_image.pixel(xint + 0, yint + 0);
        QRgb p21 = source_image.pixel(xint + 1, yint + 0);
        QRgb p31 = source_image.pixel(xint + 2, yint + 0);

        QRgb p02 = source_image.pixel(xint - 1, yint + 1);
        QRgb p12 = source_image.pixel(xint + 0, yint + 1);
        QRgb p22 = source_image.pixel(xint + 1, yint + 1);
        QRgb p32 = source_image.pixel(xint + 2, yint + 1);

        QRgb p03 = source_image.pixel(xint - 1, yint + 2);
        QRgb p13 = source_image.pixel(xint + 0, yint + 2);
        QRgb p23 = source_image.pixel(xint + 1, yint + 2);
        QRgb p33 = source_image.pixel(xint + 2, yint + 2);

        float red, green, blue;

        float col0 = cubic_hermite(qRed(p00), qRed(p10), qRed(p20), qRed(p30), xfract);
        float col1 = cubic_hermite(qRed(p01), qRed(p11), qRed(p21), qRed(p31), xfract);
        float col2 = cubic_hermite(qRed(p02), qRed(p12), qRed(p22), qRed(p32), xfract);
        float col3 = cubic_hermite(qRed(p03), qRed(p13), qRed(p23), qRed(p33), xfract);

        red = cubic_hermite(col0, col1, col2, col3, yfract);

        col0 = cubic_hermite(qGreen(p00), qGreen(p10), qGreen(p20), qGreen(p30), xfract);
        col1 = cubic_hermite(qGreen(p01), qGreen(p11), qGreen(p21), qGreen(p31), xfract);
        col2 = cubic_hermite(qGreen(p02), qGreen(p12), qGreen(p22), qGreen(p32), xfract);
        col3 = cubic_hermite(qGreen(p03), qGreen(p13), qGreen(p23), qGreen(p33), xfract);

        green = cubic_hermite(col0, col1, col2, col3, yfract);

        col0 = cubic_hermite(qBlue(p00), qBlue(p10), qBlue(p20), qBlue(p30), xfract);
        col1 = cubic_hermite(qBlue(p01), qBlue(p11), qBlue(p21), qBlue(p31), xfract);
        col2 = cubic_hermite(qBlue(p02), qBlue(p12), qBlue(p22), qBlue(p32), xfract);
        col3 = cubic_hermite(qBlue(p03), qBlue(p13), qBlue(p23), qBlue(p33), xfract);

        blue = cubic_hermite(col0, col1, col2, col3, yfract);

        QRgb sample = qRgb(A(red), A(green), A(blue));

        return sample;
    }


QImage SSAA::bilinear_interpolation1(int ssaa, QImage image)
{
    int oldw = image.width(),oldh = image.height() , neww = oldw * ssaa, newh = oldh * ssaa;
    QImage bilinear_interpolation(neww, newh, QImage::Format_RGB32);

    int i, j;
    int h, w;
    float t;
    float u;
    float tmp;
    float d1, d2, d3, d4;
    QRgb p1, p2, p3, p4;

    int red, green, blue;

    for (j = 0; j < newh; j++) {
        tmp = (float) (j) / (float) (newh - 1) * (oldh - 1);
        h = (int) floor(tmp);
        if (h < 0) {
            h = 0;
        } else {
            if (h >= oldh - 1) {
                h = oldh - 2;
            }
        }
        u = tmp - h;

        for (i = 0; i < neww; i++) {

            tmp = (float) (i) / (float) (neww - 1) * (oldw - 1);
            w = (int) floor(tmp);
            if (w < 0) {
                w = 0;
            } else {
                if (w >= oldw - 1) {
                    w = oldw - 2;
                }
            }
            t = tmp - w;

            d1 = (1 - t) * (1 - u);
            d2 = t * (1 - u);
            d3 = t * u;
            d4 = (1 - t) * u;

            p1 = image.pixel(w,h);;
            p2 = image.pixel(w,h+1);;
            p3 = image.pixel(w+1,h+1);;
            p4 = image.pixel(w+1,h);;

            blue =
            blue = qBlue(p1) *d1 + qBlue(p2) *d2 + qBlue(p3) *d3 + qBlue(p4) *d4;
            green = qGreen(p1) * d1 + qGreen(p1) * d2 + qGreen(p1) * d3 + qGreen(p1) * d4;
            red = qRed(p1) * d1 + qRed(p1) * d2 + qRed(p1) * d3 + qRed(p1) * d4;

            bilinear_interpolation.setPixel(i,j,qRgb(A(red),A(green),A(blue)));
        }
    }
    return bilinear_interpolation;
}

float SSAA::Lerp(float s, float e, float t) {
    return s + (e - s) * t;
}

float SSAA::Blerp(float c00, float c10, float c01, float c11, float tx, float ty) {
    return Lerp(Lerp(c00, c10, tx), Lerp(c01, c11, tx), ty);
}


QImage SSAA::bilinear_interpolation2(int ssaa, QImage image)
{
    int oldw = image.width(),oldh = image.height() , neww = oldw * ssaa, newh = oldh * ssaa;
    QImage bilinear_interpolation(neww, newh, QImage::Format_RGB32);


    for (int x = 0; x < neww; x++) {
        for (int y = 0; y < newh; y++) {
            float gx = ((float)x) / neww * (oldw - 1);
            float gy = ((float)y) / newh * (oldh - 1);
            int gxi = (int)gx;
            int gyi = (int)gy;

            QColor c00 = image.pixel(gxi, gyi);
            QColor c10 = image.pixel(gxi + 1, gyi);
            QColor c01 = image.pixel(gxi, gyi + 1);
            QColor c11 = image.pixel(gxi + 1, gyi + 1);

            int red = (int)Blerp(c00.red(), c10.red(), c01.red(), c11.red(), gx - gxi, gy - gyi);
            int green = (int)Blerp(c00.green(), c10.green(), c01.green(), c11.green(), gx - gxi, gy - gyi);
            int blue = (int)Blerp(c00.blue(), c10.blue(), c01.blue(), c11.blue(), gx - gxi, gy - gyi);
            QRgb rgb = qRgb(red, green, blue);
            bilinear_interpolation.setPixel(x, y, rgb);
        }
    }
    return bilinear_interpolation;
}



QImage SSAA::bicubic_interpolation(int ssaa, QImage image)
{
    long oldw = image.width(), oldh = image.height(), neww = oldw * ssaa, newh = oldh * ssaa;
    QImage bicubic_interpolation(neww, newh, QImage::Format_RGB32);



    for (int y = 0; y < bicubic_interpolation.height(); y++) {

        float v = (float)y / (float)(bicubic_interpolation.height() - 1);

        for (int x = 0; x < bicubic_interpolation.width(); ++x) {

            float u = (float)x / (float)(bicubic_interpolation.width() - 1);
            QRgb sample = sample_bicubic(image, u, v);

            bicubic_interpolation.setPixel(x,y, sample);

        }
    }

    return bicubic_interpolation;
}

QImage SSAA::Low_pass_filters(int ssaa, QImage image, QImage buffer)
{
    double r = ssaa, s = ssaa;

    int red{0}, green{0}, blue{0};
    int g = 0;

    float wx;
    float wy;
    float n;
    for(int y = 0; y < image.height(); ++y)
    {
        for(int x = 0; x < image.width(); ++x)
        {
            red = 0; green = 0; blue = 0;
            n = 0;

            for(int k =y*r; k<(y+1)*r; ++k){
                if(k<y*r)
                {
                    wx=k-y*r+1;
                }else
                {
                    if(k+1>(y+1)*r)
                         wx = (y+1)*r-k;
                     else
                         wx = 1;
                }
                for(int l=x*s; l<(x+1)*s; ++l){
                    if(l<x*s){
                        wy = l-x*s+1;
                    }else{
                        if(l+1>(x+1)*s)
                            wy = (x+1)*s-l;
                        else
                            wy = 1;
                    }
                    n+=wy*wx;
                    red += wx*wy*buffer.pixelColor(l, k).red();
                    green += wx*wy*buffer.pixelColor(l, k).green();
                    blue += wx*wy*buffer.pixelColor(l, k).blue();
                }

            }
            image.setPixel(x,y, qRgb(red/n,green/n,blue/n));
        }
    }

    return image;
}

QImage SSAA::Supersample(int ssaa, QImage image, int i)
{

    QImage buffer;

    if(i == 0)
        buffer = bilinear_interpolation1(ssaa, image);
    else if(i == 1)
        buffer = bilinear_interpolation2(ssaa, image);
    else
        buffer = bicubic_interpolation(ssaa, image);

    QImage sa(image.width(), image.height(), QImage::Format_RGB32);



    return Low_pass_filters(ssaa, sa, buffer);
}
