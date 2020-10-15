#include "histogramequalization.h"
#include "ui_histogramequalization.h"

HistogramEqualization::HistogramEqualization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistogramEqualization)
{
    ui->setupUi(this);

    connect(ui->Reload, &QPushButton::clicked, [this]{ SetImageFromWorkForm(WorkImage); });
    connect(ui->GetNormalImage, &QPushButton::clicked, [this]{ emit GetNormalImage(ProcessedImage); });
    connect(ui->EffectBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), [=]( int ix ) { setFilter(ix); });
    connect(ui->ParamSlider, &QSlider::valueChanged, [this]{ setFilter(ui->EffectBox->currentIndex()); });
    connect(ui->SetCustomMasks, &QPushButton::clicked, [this]{ customfilter(); });

    connect(ui->MixHisto, &QCheckBox::stateChanged, [this](int state){
    if(state == 0 && ui->ProcessedImageGistogram->graphCount() == 2)   
    {
        if(ui->ProcessedImageGistogram->graph(0)->name() == "Оригинал")
        {
              ui->ProcessedImageGistogram->graph(0)->setName(ui->ProcessedImageGistogram->graph(1)->name());
              ui->ProcessedImageGistogram->graph(0)->setData(ui->ProcessedImageGistogram->graph(1)->data());
        }
        ui->ProcessedImageGistogram->removeGraph(1);
    }
        ui->ProcessedImageGistogram->replot();
    });

    connect(ui->LegendHide, &QCheckBox::stateChanged, [this](int state){
    if(state == 2)
    {
        ui->ImageGistogram->legend->setVisible(false);
        ui->ProcessedImageGistogram->legend->setVisible(false);
        ui->ImageGistogram->replot();
        ui->ProcessedImageGistogram->replot();
    }else
    {
        ui->ImageGistogram->legend->setVisible(true);
        ui->ProcessedImageGistogram->legend->setVisible(true);
        ui->ImageGistogram->replot();
        ui->ProcessedImageGistogram->replot();
    }
    });

    connect(ui->CompareProcAndOrig, &QPushButton::clicked, [this]{
    if(ui->ImageGistogram->graphCount() == ui->ProcessedImageGistogram->graphCount())
    {
        ui->ProcessedImageGistogram->addGraph();

        ui->ProcessedImageGistogram->graph(ui->ProcessedImageGistogram->graphCount()-1)->setData(ui->ProcessedImageGistogram->graph(0)->data());
        ui->ProcessedImageGistogram->graph(ui->ProcessedImageGistogram->graphCount()-1)->setName(ui->ProcessedImageGistogram->graph(0)->name());
        ui->ProcessedImageGistogram->graph(ui->ProcessedImageGistogram->graphCount()-1)->setPen(QColor(255, 0, 0));

        ui->ProcessedImageGistogram->graph(0)->setData(ui->ImageGistogram->graph(0)->data());
        ui->ProcessedImageGistogram->graph(0)->setName("Оригинал");
        ui->ProcessedImageGistogram->replot();
        ui->ProcessedImageGistogram->update();

        ui->MixHisto->setChecked(true);
    }
    });

    connect(ui->ColorComponent, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), [=]( int ix ) {
        ui->ImageGistogram->clearGraphs();
        ui->ImageGistogram->clearItems();

        GetHistogramWorkImage(WorkImage, ui->ImageGistogram,"Оригинал");
        emit ui->EffectBox->currentIndexChanged(ui->EffectBox->currentIndex());
    });
}

void HistogramEqualization::customfilter()
{
        bool fifth = false;

    if(textecvdouble(ui->Mask00->text()) && textecvdouble(ui->Mask01->text()) && textecvdouble(ui->Mask02->text()) && textecvdouble(ui->Mask03->text()) && textecvdouble(ui->Mask04->text()))
        if(textecvdouble(ui->Mask40->text()) && textecvdouble(ui->Mask41->text()) && textecvdouble(ui->Mask42->text()) && textecvdouble(ui->Mask43->text()) && textecvdouble(ui->Mask44->text()))
            if(textecvdouble(ui->Mask10->text()) && textecvdouble(ui->Mask20->text()) && textecvdouble(ui->Mask30->text()))
               if(textecvdouble(ui->Mask14->text()) && textecvdouble(ui->Mask24->text()) && textecvdouble(ui->Mask34->text()))  
                   if(ui->Mask00->text().toInt() != 0 && ui->Mask01->text().toInt() != 0 && ui->Mask02->text().toInt() != 0 && ui->Mask03->text().toInt() != 0 && ui->Mask04->text().toInt() != 0)
                       if(ui->Mask40->text().toInt() != 0 && ui->Mask41->text().toInt() != 0 && ui->Mask42->text().toInt() != 0 && ui->Mask43->text().toInt() != 0 && ui->Mask44->text().toInt() != 0)
                           if(ui->Mask10->text().toInt() != 0 && ui->Mask20->text().toInt() != 0 && ui->Mask30->text().toInt() != 0)
                              if(ui->Mask14->text().toInt() != 0 && ui->Mask24->text().toInt() != 0 && ui->Mask34->text().toInt() != 0)
                                    fifth = true;




    if( textecvdouble(ui->Mask11->text()) && textecvdouble(ui->Mask11->text()) && textecvdouble(ui->Mask11->text()) && textecvdouble(ui->Mask11->text()) &&
        textecvdouble(ui->Mask11->text()) && textecvdouble(ui->Mask11->text()) && textecvdouble(ui->Mask11->text()) && textecvdouble(ui->Mask11->text()) && textecvdouble(ui->Mask11->text()) )
        {
            if(fifth)
            {
                std::vector<std::vector<double>> mask {
                    {ui->Mask00->text().toDouble(), ui->Mask01->text().toDouble(), ui->Mask02->text().toDouble(), ui->Mask03->text().toDouble(), ui->Mask04->text().toDouble()},
                    {ui->Mask10->text().toDouble(), ui->Mask11->text().toDouble(), ui->Mask12->text().toDouble(), ui->Mask13->text().toDouble(), ui->Mask14->text().toDouble()},
                    {ui->Mask20->text().toDouble(), ui->Mask21->text().toDouble(), ui->Mask22->text().toDouble(), ui->Mask23->text().toDouble(), ui->Mask24->text().toDouble()},
                    {ui->Mask30->text().toDouble(), ui->Mask31->text().toDouble(), ui->Mask32->text().toDouble(), ui->Mask33->text().toDouble(), ui->Mask34->text().toDouble()},
                    {ui->Mask40->text().toDouble(), ui->Mask41->text().toDouble(), ui->Mask42->text().toDouble(), ui->Mask43->text().toDouble(), ui->Mask44->text().toDouble()}
                    };

                this->ShowMask(mask);
                this->MaskFilters(mask,1, "Ручная маска 5x5");
            }
            else
            {
                std::vector<std::vector<double>> mask{
                    {ui->Mask11->text().toDouble(), ui->Mask12->text().toDouble(),ui->Mask13->text().toDouble()},
                    {ui->Mask21->text().toDouble(),ui->Mask22->text().toDouble(),ui->Mask23->text().toDouble()},
                    {ui->Mask31->text().toDouble(),ui->Mask32->text().toDouble(),ui->Mask33->text().toDouble()}
                };

                this->ShowMask(mask);
                this->MaskFilters(mask,1, "Ручная маска 3x3");
            }
        }
}

int HistogramEqualization::curr()
{
    return ui->EffectBox->currentIndex();
}

void HistogramEqualization::setFilter(int i)
{
    i == 0 ? NormalisedImage("Нормализация") :
    i == 1 ? MaskFilters(Settings::Mid,25, "Усредненный") :
    i == 2 ? MaskFilters(Settings::Gauss,1, "Гаусса") :
    i == 3 ? MaskFilters(Settings::Laplas,1,"Лаплас") :
    i == 4 ? MaskFilters(Settings::Grad,1,"Градиент") :
    i == 5 ? setFilter("Медианный (3х3)", "Median3x3") :
    i == 6 ? setFilter("Медианный (Крест)", "MedianCross") :
    i == 7 ? setFilter("Адаптивный Медианный (3х3)", "AdaptiveMedian3x3") :
             setFilter("Адаптивный Медианный (Крест)", "AdaptiveMedianCross");
}
HistogramEqualization::~HistogramEqualization()
{
    delete ui;
}

void HistogramEqualization::SetImageFromWorkForm(QImage img)
{
    this->WorkImage = img;
    ui->WorkImage->setPixmap(QPixmap::fromImage(img.scaled(ui->WorkImage->width(), ui->WorkImage->height(), Qt::KeepAspectRatio)));
    ui->ImageGistogram->clearGraphs();
    ui->ImageGistogram->clearItems();
    GetHistogramWorkImage(this->WorkImage, ui->ImageGistogram,"Оригинал");
    setFilter(ui->EffectBox->currentIndex());
}

void HistogramEqualization::GetHistogramWorkImage(QImage img, QCustomPlot *CPlot, QString name)
{
    QVector<double> R(256,0),G(256,0),B(256,0), x;

    for(int i = 0; i < 256; i++)
        x.push_back(i);

    for(int i = 0; i < img.height(); i++)
        for(int j = 0; j < img.width(); j++)
        {
            QRgb pixel_start{ img.pixel(j,i) };
            QColor a(pixel_start);
            R[a.red()]++;
            G[a.green()]++;
            B[a.blue()]++;
        }

    RW = R;
    GW = G;
    BW = B;

    if(CPlot->graphCount() == 1 && !ui->MixHisto->isChecked())
        CPlot->clearGraphs();

    if(CPlot->graphCount() == 2 && ui->MixHisto->isChecked())
            CPlot->removeGraph(1);

    if(CPlot->graphCount() == 0)
          CPlot->addGraph();
    else if(ui->MixHisto->isChecked() && CPlot->graphCount() == 1)
          CPlot->addGraph();

    if(ui->ColorComponent->currentIndex() == 0)
    {
        auto result = std::minmax_element(R.begin(), R.end());
        double YR = *result.second;

        if(CPlot->graphCount() == 2)
           CPlot->graph(CPlot->graphCount()-1)->setPen(QColor(255, 0, 0));

        CPlot->graph(CPlot->graphCount()-1)->setData(x, R);
        CPlot->graph(CPlot->graphCount()-1)->setName(name);
        CPlot->yAxis->setLabel("R");
        CPlot->yAxis->setRange(0, YR);
        CPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));

        if(!ui->LegendHide->isChecked())
            CPlot->legend->setVisible(true);
    }
    else if(ui->ColorComponent->currentIndex() == 1)
    {
        auto result = std::minmax_element(G.begin(), G.end());
        double YG = *result.second;

        if(CPlot->graphCount() == 2)
           CPlot->graph(CPlot->graphCount()-1)->setPen(QColor(255, 0, 0));

        CPlot->graph(CPlot->graphCount()-1)->setData(x, G);
        CPlot->graph(CPlot->graphCount()-1)->setName(name);
        CPlot->yAxis->setLabel("G");
        CPlot->yAxis->setRange(0, YG);
        CPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));

        if(!ui->LegendHide->isChecked())
            CPlot->legend->setVisible(true);

    }else
    {
        auto result = std::minmax_element(B.begin(), B.end());
        double YB = *result.second;

        if(CPlot->graphCount() == 2)
           CPlot->graph(CPlot->graphCount()-1)->setPen(QColor(255, 0, 0));

        CPlot->graph(CPlot->graphCount()-1)->setData(x, B);
        CPlot->graph(CPlot->graphCount()-1)->setName(name);
        CPlot->yAxis->setLabel("B");
        CPlot->yAxis->setRange(0, YB);
        CPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));

        if(!ui->LegendHide->isChecked())
            CPlot->legend->setVisible(true);
    }
        CPlot->xAxis->setLabel("x");
        CPlot->xAxis->setRange(0, 255);
        CPlot->replot();
}

void HistogramEqualization::NormalisedImage(QString name)
{
    std::vector<double> Normalise(256,0);
    ProcessedImage = WorkImage;

    for(int i = 0; i < RW.size(); i++)
        Normalise[i] = 255.0*RW[i]/( ProcessedImage.width()*ProcessedImage.height());

    double sum = 0;
    std::accumulate(Normalise.begin(), Normalise.end(), sum);

    std::vector<int> Cum_gisto(256,0);

    for(int i = 0; i < 256;i++)
    {
        double buffer = summ(Normalise, 0,i);
        Cum_gisto[i] = (int)(buffer + 0.5);
    }

    for(int i = 0; i < ProcessedImage.height(); i++)
    {
        QRgb *line = reinterpret_cast<QRgb *>(ProcessedImage.scanLine(i));
        for(int j = 0; j < ProcessedImage.width(); j++)
        {
            *line++ = ui->ColorComponent->currentIndex() == 0 ?
                      qRgb(Cum_gisto[qRed(*line)],Cum_gisto[qRed(*line)],Cum_gisto[qRed(*line)]) :
                      ui->ColorComponent->currentIndex() == 1 ?
                      qRgb(Cum_gisto[qGreen(*line)],Cum_gisto[qGreen(*line)],Cum_gisto[qGreen(*line)]) :
                      qRgb(Cum_gisto[qBlue(*line)],Cum_gisto[qBlue(*line)],Cum_gisto[qBlue(*line)]);
        }

    }
    ui->ProcessedImage->setPixmap(QPixmap::fromImage(this->ProcessedImage.scaled(ui->ProcessedImage->width(), ui->ProcessedImage->height(), Qt::KeepAspectRatio)));
    this->GetHistogramWorkImage(ProcessedImage, ui->ProcessedImageGistogram,name);
}

double HistogramEqualization::summ(std::vector<double> v, int s, int e)
{
    double sum = 0;
    for(int i = s; i < e; i++)
        sum+= v[i];
    return sum;
}

void HistogramEqualization::setFilter(QString name, QString filter)
{
    this->ProcessedImage = filter == "Median3x3" ? LinerFilter::Median3x3(this->WorkImage, "Normal") :
                           filter == "MedianCross" ? LinerFilter::MedianCross(this->WorkImage, "Normal") :
                           filter == "AdaptiveMedian3x3" ? LinerFilter::Median3x3(this->WorkImage, "Adaptive") :
                           filter == "AdaptiveMedianCross" ? this->ProcessedImage = LinerFilter::MedianCross(this->WorkImage, "Adaptive") : this->ProcessedImage;

    ui->ProcessedImage->setPixmap(QPixmap::fromImage(this->ProcessedImage.scaled(ui->ProcessedImage->width(), ui->ProcessedImage->height(), Qt::KeepAspectRatio)));
    this->GetHistogramWorkImage(ProcessedImage, ui->ProcessedImageGistogram,name);
}

void HistogramEqualization::MaskFilters(std::vector<std::vector<double>> mask_array, int SUB, QString name)
{
    ShowMask(mask_array);
    ProcessedImage = LinerFilter::MaskFilters(WorkImage, mask_array, SUB);
    ui->ProcessedImage->setPixmap(QPixmap::fromImage(this->ProcessedImage.scaled(ui->ProcessedImage->width(), ui->ProcessedImage->height(), Qt::KeepAspectRatio)));
    GetHistogramWorkImage(ProcessedImage, ui->ProcessedImageGistogram,name);
}

void HistogramEqualization::ShowMask(std::vector<std::vector<double>> mask)
{

    if(mask.size() == 5){
        ui->Mask00->setText(QString::number(mask[0][0]));
        ui->Mask01->setText(QString::number(mask[0][1]));
        ui->Mask02->setText(QString::number(mask[0][2]));
        ui->Mask03->setText(QString::number(mask[0][3]));
        ui->Mask04->setText(QString::number(mask[0][3]));
        ui->Mask10->setText(QString::number(mask[1][0]));
        ui->Mask11->setText(QString::number(mask[1][1]));
        ui->Mask12->setText(QString::number(mask[1][2]));
        ui->Mask13->setText(QString::number(mask[1][3]));
        ui->Mask14->setText(QString::number(mask[1][4]));
        ui->Mask20->setText(QString::number(mask[2][0]));
        ui->Mask21->setText(QString::number(mask[2][1]));
        ui->Mask22->setText(QString::number(mask[2][2]));
        ui->Mask23->setText(QString::number(mask[2][3]));
        ui->Mask24->setText(QString::number(mask[2][4]));
        ui->Mask30->setText(QString::number(mask[3][0]));
        ui->Mask31->setText(QString::number(mask[3][1]));
        ui->Mask32->setText(QString::number(mask[3][2]));
        ui->Mask33->setText(QString::number(mask[3][3]));
        ui->Mask34->setText(QString::number(mask[3][4]));
        ui->Mask40->setText(QString::number(mask[4][0]));
        ui->Mask41->setText(QString::number(mask[4][1]));
        ui->Mask42->setText(QString::number(mask[4][2]));
        ui->Mask43->setText(QString::number(mask[4][3]));
        ui->Mask44->setText(QString::number(mask[4][4]));
    }else if(mask.size() == 3)
    {
        ui->Mask00->setText("");ui->Mask01->setText("");ui->Mask02->setText("");ui->Mask03->setText("");ui->Mask04->setText("");
        ui->Mask40->setText("");ui->Mask41->setText("");ui->Mask42->setText("");ui->Mask43->setText("");ui->Mask44->setText("");
        ui->Mask10->setText("");ui->Mask24->setText("");ui->Mask30->setText("");ui->Mask34->setText("");ui->Mask14->setText("");ui->Mask20->setText("");
        ui->Mask11->setText(QString::number(mask[0][0]));
        ui->Mask12->setText(QString::number(mask[0][1]));
        ui->Mask13->setText(QString::number(mask[0][2]));
        ui->Mask21->setText(QString::number(mask[1][0]));
        ui->Mask22->setText(QString::number(mask[1][1]));
        ui->Mask23->setText(QString::number(mask[1][2]));
        ui->Mask31->setText(QString::number(mask[2][0]));
        ui->Mask32->setText(QString::number(mask[2][1]));
        ui->Mask33->setText(QString::number(mask[2][2]));
    }
}

void HistogramEqualization::resizeEvent(QResizeEvent *event)
{
    ui->WorkImage->setPixmap(QPixmap::fromImage(WorkImage.scaled(ui->WorkImage->width(), ui->WorkImage->height(), Qt::KeepAspectRatio)));
    ui->ProcessedImage->setPixmap(QPixmap::fromImage(ProcessedImage.scaled(ui->WorkImage->width(), ui->WorkImage->height(), Qt::KeepAspectRatio)));
}
