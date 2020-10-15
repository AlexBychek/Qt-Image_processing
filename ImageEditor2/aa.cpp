#include "aa.h"
#include "ui_aa.h"


AA::AA(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AA)
{
    ui->setupUi(this);

    ui->Upscale1->setToolTip("Билинейная интерполяция 1 вариант");
    ui->Upscale2->setToolTip("Билинейная интерполяция 2 вариант");
    ui->Upscale2->setToolTip("Бикубическая интерполяция");
    ui->SSAA_Button->setToolTip("Избыточная выборка сглаживания");


    connect(ui->SSAA_Button, &QPushButton::clicked, [this]{
        int i;
        if(ui->Bl1->isChecked())
            i = 0;
        else if(ui->Bl2->isChecked())
            i = 1;
        else
            i = 2;

        emit ButtonClick(SSAA::Supersample(ui->AAStep->currentText().toInt(), image, i));
    });

    connect(ui->Upscale1, &QPushButton::clicked, [this]{
        emit ButtonClick(SSAA::bilinear_interpolation1(ui->AAStep->currentText().toInt(), image));
    });

    connect(ui->Upscale2, &QPushButton::clicked, [this]{
        emit ButtonClick(SSAA::bilinear_interpolation2(ui->AAStep->currentText().toInt(), image));
    });

    connect(ui->Upscale3, &QPushButton::clicked, [this]{
        emit ButtonClick(SSAA::bicubic_interpolation(ui->AAStep->currentText().toInt(), image));
    });

}


void AA::setImage(QImage img)
{
    this->image = img;
}

AA::~AA()
{
    delete ui;
}
