#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    connect(ui->IconProcessing, &QCheckBox::stateChanged, [&](int i){
        IconProcessing =  i == 2 ? true : i == 0 ? false : NULL;
        emit chageStateIcon();
    });

    connect(ui->HalfGamma, &QCheckBox::stateChanged, [&](int i){
        HalfGamma = i == 2 ?  true : i == 0 ? false : NULL;
    });

    connect(ui->LaplasSLider, &QSlider::valueChanged, [&](int i){
        double B = (double)i / 10;
        double Q = 1.0 + 4.0 * B;
        double q = -B;

        Laplas = { { 0.0,  q,  0.0},
                   {  q,   Q,   q},
                   { 0.0,  q,  0.0}
                 };

        emit chageState();
        ui->SliderValue->setText(QString::number((double)(i/10.0)));

    });

    connect(ui->GammaSLider, &QSlider::valueChanged, [&](int i){
        Gamma = (double)i/10.0;
        emit chageState();
        ui->GammaValue->setText(QString::number((double)(i/10.0)));

    });

    ui->IconProcessing->setToolTip("Эксперементальная функция!!! Большие трудозатраты пк ");
    ui->LaplasSLider->setToolTip("Регулеровка четкости Лаплас");
    ui->GammaSLider->setToolTip("Коэффициент ЧБ");
    ui->HalfGamma->setToolTip("ЧБ для полутона");
}

Settings::~Settings()
{
    delete ui;
}

double Settings::Gamma{ 0.3 };

bool Settings::IconProcessing{ false };

bool Settings::HalfGamma { true };

std::vector<std::vector<double>> Settings::Mid{ {1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1} };

std::vector<std::vector<double>> Settings::Gauss{ {0.000789, 0.006581, 0.013347, 0.006581 ,0.000789},
                                                          {0.006581, 0.054901, 0.111345 ,0.054901 ,0.006581},
                                                          {0.013347, 0.111345, 0.225821 ,0.111345 ,0.013347},
                                                          {0.006581, 0.054901, 0.111345 ,0.054901 ,0.006581},
                                                          {0.000789, 0.006581, 0.013347 ,0.006581 ,0.000789} };

std::vector<std::vector<double>> Settings::Laplas{ { 0.0,  -2.0,  0.0},
                                                 {-2.0,   9.0, -2.0},
                                                 { 0.0,  -2.0,  0.0}
                                               };

std::vector<std::vector<double>> Settings::Grad{ {1.0,  1.0, -1.0},
                                                 {1.0, -2.0, -1.0},
                                                 {1.0,  1.0, -1.0}
                                               };
