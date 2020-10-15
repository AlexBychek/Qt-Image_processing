#include "linerfilter.h"

QImage LinerFilter::MaskFilters(QImage img, std::vector<std::vector<double>> mask_array, int SUB)
{
    int start_end_pos = mask_array.size() == 5 ? 2 : mask_array.size() == 3 ? 1 : 0;

    QImage ProcessedImage = img;
        int r,g,b;

    for(int i = start_end_pos; i < ProcessedImage.width()-start_end_pos;i++)
        for(int j = start_end_pos; j < ProcessedImage.height()-start_end_pos;j++)
        {
            r = 0;g = 0; b = 0;
            for(int l = 0; l < mask_array.size(); l++)
                for(int k = 0; k < mask_array[l].size(); k++)
                {
                    QColor clr(img.pixel(i-(start_end_pos-k), j-(start_end_pos-l)));
                    r += clr.red()*mask_array[l][k]; g += clr.green()*mask_array[l][k]; b += clr.blue()*mask_array[l][k];
                }
        ProcessedImage.setPixel(i,j,qRgb(r/SUB>255?255:r/SUB<0?0:r/SUB,
                                         g/SUB>255?255:g/SUB<0?0:g/SUB,
                                         b/SUB>255?255:b/SUB<0?0:b/SUB));
        }

    return ProcessedImage;
}

QImage LinerFilter::Median3x3(QImage img, QString type)
{
    QImage ProcessedImage = img;
    QColor *pix = new QColor[9];
    std::vector<int> vecR, vecG, vecB;

       for (int x = 1; x < ProcessedImage.width() - 1; x++) {
           for (int y = 1; y < ProcessedImage.height() - 1; y++)
           {
               pix[0] = QColor(ProcessedImage.pixel(x - 1, y - 1));
               pix[1] = QColor(ProcessedImage.pixel(x - 1, y));
               pix[2] = QColor(ProcessedImage.pixel(x - 1, y + 1));
               pix[3] = QColor(ProcessedImage.pixel(x, y + 1));
               pix[4] = QColor(ProcessedImage.pixel(x + 1, y + 1));
               pix[5] = QColor(ProcessedImage.pixel(x + 1, y));
               pix[6] = QColor(ProcessedImage.pixel(x + 1, y - 1));
               pix[7] = QColor(ProcessedImage.pixel(x, y - 1));
               pix[8] = QColor(ProcessedImage.pixel(x, y));

               for (int k = 0; k<9; k++) {
                   vecR.push_back(pix[k].red());
                   vecG.push_back(pix[k].green());
                   vecB.push_back(pix[k].blue());
               }

               qSort(vecR.begin(), vecR.end());
               qSort(vecG.begin(), vecG.end());
               qSort(vecB.begin(), vecB.end());

               QColor imgRgb;

               if(type == "Normal")
               imgRgb.setRgb(vecR.at(4), vecG.at(4), vecB.at(4));
               else if(type == "Adaptive")
               {
               QRgb mediana(qRgb(vecR.at(4),vecG.at(4),vecB.at(4)));
               QRgb minimum(qRgb(vecR.at(0),vecG.at(0),vecB.at(0)));
               QRgb maximum(qRgb(vecR.at(8),vecG.at(8),vecB.at(8)));

               if(maximum > ProcessedImage.pixel(x, y) && ProcessedImage.pixel(x, y) > minimum)
                    imgRgb.setRgb(ProcessedImage.pixel(x, y));
               if(ProcessedImage.pixel(x, y) == maximum || ProcessedImage.pixel(x, y) == minimum)
                   imgRgb.setRgb(mediana);
               }

               ProcessedImage.setPixel(x, y, imgRgb.rgb());
               vecR.clear();
               vecG.clear();
               vecB.clear();
           }
       }
    return ProcessedImage;
}

QImage LinerFilter::MedianCross(QImage img, QString type)
{
    QImage ProcessedImage = img;
    QColor *pix = new QColor[5];
    std::vector<int> vecR, vecG, vecB;

       for (int x = 1; x < ProcessedImage.width() - 1; x++) {
           for (int y = 1; y < ProcessedImage.height() - 1; y++)
           {
               pix[0] = QColor(ProcessedImage.pixel(x, y));
               pix[1] = QColor(ProcessedImage.pixel(x, y + 1));
               pix[2] = QColor(ProcessedImage.pixel(x, y - 1));
               pix[3] = QColor(ProcessedImage.pixel(x + 1, y));
               pix[4] = QColor(ProcessedImage.pixel(x - 1, y));

               for (int k = 0; k<5; k++) {
                   vecR.push_back(pix[k].red());
                   vecG.push_back(pix[k].green());
                   vecB.push_back(pix[k].blue());
               }

               qSort(vecR.begin(), vecR.end());
               qSort(vecG.begin(), vecG.end());
               qSort(vecB.begin(), vecB.end());

               QColor imgRgb;

               if(type == "Normal")
               imgRgb.setRgb(vecR.at(2), vecG.at(2), vecB.at(2));
               else if(type == "Adaptive")
               {
               QRgb mediana(qRgb(vecR.at(2),vecG.at(2),vecB.at(2)));
               QRgb minimum(qRgb(vecR.at(0),vecG.at(0),vecB.at(0)));
               QRgb maximum(qRgb(vecR.at(4),vecG.at(4),vecB.at(4)));

               if(maximum > ProcessedImage.pixel(x, y) && ProcessedImage.pixel(x, y) > minimum)
                    imgRgb.setRgb(ProcessedImage.pixel(x, y));
               if(ProcessedImage.pixel(x, y) == maximum || ProcessedImage.pixel(x, y) == minimum)
                   imgRgb.setRgb(mediana);
               }

               ProcessedImage.setPixel(x, y, imgRgb.rgb());
               vecR.clear();
               vecG.clear();
               vecB.clear();
           }
       }
    return ProcessedImage;
}
