#include "effectsliders.h"
#include "ui_effectsliders.h"

EffectSliders::EffectSliders(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EffectSliders)
{
    ui->setupUi(this);

    connect(ui->BrightnessSlider, &QSlider::valueChanged, [this](const int &SliderValue){
        this->emit SliderChanged(Effects::Brightness(image,SliderValue)); ui->BrightnessValue->setNum(SliderValue);
    });
    connect(ui->ContrastSlider, &QSlider::valueChanged, [this](const int &SliderValue){
        this->emit SliderChanged(Effects::Contrast(image,SliderValue)); ui->ContrastValue->setNum(SliderValue);
    });
    connect(ui->GammaSlider, &QSlider::valueChanged, [this](const int &SliderValue){
        this->emit SliderChanged(Effects::GammaCorrection(image,SliderValue)); ui->GammaValue->setNum( (double)(SliderValue / 100.0));
    });


    connect(ui->BrightnessSlider, &QSlider::sliderReleased, [this]{ this->emit SliderReleased();});
    connect(ui->ContrastSlider, &QSlider::sliderReleased, [this]{ this->emit SliderReleased();});
    connect(ui->GammaSlider, &QSlider::sliderReleased, [this]{ this->emit SliderReleased(); });
}

void EffectSliders::setImage(QImage img)
{
    this->image = img;
};

EffectSliders::~EffectSliders()
{
    delete ui;
}
