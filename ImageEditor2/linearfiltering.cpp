#include "linearfiltering.h"
#include "ui_linearfiltering.h"

LinearFiltering::LinearFiltering(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LinearFiltering)
{
    ui->setupUi(this);

    connect(ui->MidFilter, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(MidFilter) : emit ButtonClick(LinerFilter::MaskFilters(this->image, Settings::Mid, 25));
    });
    connect(ui->GaussFilter, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(GaussFilter) : emit ButtonClick(LinerFilter::MaskFilters(this->image, Settings::Gauss, 1));
    });
    connect(ui->LaplasFilter, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(LaplasFilter) : emit ButtonClick(LinerFilter::MaskFilters(this->image, Settings::Laplas, 1));
    });
    connect(ui->GradFilter, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(GradFilter) : emit ButtonClick(LinerFilter::MaskFilters(this->image, Settings::Grad, 1));
    });
    connect(ui->MedSqFilter, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(MedSqFilter) : emit ButtonClick(LinerFilter::Median3x3(this->image,"Normal"));
    });
    connect(ui->AMedSqFilter, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(AMedSqFilter) : emit ButtonClick(LinerFilter::Median3x3(this->image,"Adaptive"));
    });
    connect(ui->MedCrsFilter, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(MedCrsFilter) : emit ButtonClick(LinerFilter::MedianCross(this->image,"Normal"));
    });
    connect(ui->AMedCrsFilter, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(AMedCrsFilter) : emit ButtonClick(LinerFilter::MedianCross(this->image,"Adaptive"));
    });

    ui->MidFilter->setToolTip("Усредняющий фильтр");
    ui->GaussFilter->setToolTip("Фильтр Гаусса");
    ui->LaplasFilter->setToolTip("Фильтр Лапласа");
    ui->GradFilter->setToolTip("Градиентный фильтр");
    ui->MedSqFilter->setToolTip("Медианный квадрат");
    ui->AMedSqFilter->setToolTip("Адаптивный Медианный квадрат");
    ui->MedCrsFilter->setToolTip("Медианный крест");
    ui->AMedCrsFilter->setToolTip("Адаптивный Медианный крест");
}

LinearFiltering::~LinearFiltering()
{
    delete ui;
}

void LinearFiltering::reload()
{
    if(Settings::IconProcessing)
    {
        LaplasFilter = LinerFilter::MaskFilters(this->image, Settings::Laplas, 1);
        QImage Laplas = LaplasFilter.scaled(ui->LaplasFilter->width(),ui->LaplasFilter->height(), Qt::IgnoreAspectRatio);
        ui->LaplasFilter->setText("");
        ui->LaplasFilter->setIcon(QIcon(QPixmap::fromImage(Laplas)));
        ui->LaplasFilter->setIconSize(QSize(ui->LaplasFilter->width(),ui->LaplasFilter->height()));
    }
}

void LinearFiltering::setImage(QImage img)
{
    this->image = img;
    Settings::IconProcessing ? iconImageStyle() : resetImageStyle();
}

void LinearFiltering::iconImageStyle()
{
    MidFilter = LinerFilter::MaskFilters(this->image, Settings::Mid, 25);
    GaussFilter = LinerFilter::MaskFilters(this->image, Settings::Gauss, 1);
    LaplasFilter = LinerFilter::MaskFilters(this->image, Settings::Laplas, 1);
    GradFilter = LinerFilter::MaskFilters(this->image, Settings::Grad, 1);
    MedSqFilter = LinerFilter::Median3x3(this->image,"Normal");
    AMedSqFilter = LinerFilter::Median3x3(this->image,"Adaptive");
    MedCrsFilter = LinerFilter::MedianCross(this->image,"Normal");
    AMedCrsFilter = LinerFilter::MedianCross(this->image,"Adaptive");

    QImage Mid = MidFilter.scaled(ui->MidFilter->width(),ui->MidFilter->height(), Qt::IgnoreAspectRatio);
    QImage Gauss = GaussFilter.scaled(ui->GaussFilter->width(),ui->GaussFilter->height(), Qt::IgnoreAspectRatio);
    QImage Laplas = LaplasFilter.scaled(ui->LaplasFilter->width(),ui->LaplasFilter->height(), Qt::IgnoreAspectRatio);
    QImage Grad = GradFilter.scaled(ui->GradFilter->width(),ui->GradFilter->height(), Qt::IgnoreAspectRatio);
    QImage MedSq = MedSqFilter.scaled(ui->MedSqFilter->width(),ui->MedSqFilter->height(), Qt::IgnoreAspectRatio);
    QImage AMedSq = AMedSqFilter.scaled(ui->AMedSqFilter->width(),ui->AMedSqFilter->height(), Qt::IgnoreAspectRatio);
    QImage MedCrs = MedCrsFilter.scaled(ui->MedCrsFilter->width(),ui->MedCrsFilter->height(), Qt::IgnoreAspectRatio);
    QImage AMedCrs = AMedCrsFilter.scaled(ui->AMedCrsFilter->width(),ui->AMedCrsFilter->height(), Qt::IgnoreAspectRatio);

    ui->MidFilter->setText("");
    ui->MidFilter->setIcon(QIcon(QPixmap::fromImage(Mid)));
    ui->MidFilter->setIconSize(QSize(ui->MidFilter->width(),ui->MidFilter->height()));
    ui->GaussFilter->setText("");
    ui->GaussFilter->setIcon(QIcon(QPixmap::fromImage(Gauss)));
    ui->GaussFilter->setIconSize(QSize(ui->GaussFilter->width(),ui->GaussFilter->height()));
    ui->LaplasFilter->setText("");
    ui->LaplasFilter->setIcon(QIcon(QPixmap::fromImage(Laplas)));
    ui->LaplasFilter->setIconSize(QSize(ui->LaplasFilter->width(),ui->LaplasFilter->height()));
    ui->GradFilter->setText("");
    ui->GradFilter->setIcon(QIcon(QPixmap::fromImage(Grad)));
    ui->GradFilter->setIconSize(QSize(ui->GradFilter->width(),ui->GradFilter->height()));
    ui->MedSqFilter->setText("");
    ui->MedSqFilter->setIcon(QIcon(QPixmap::fromImage(MedSq)));
    ui->MedSqFilter->setIconSize(QSize(ui->MedSqFilter->width(),ui->MedSqFilter->height()));
    ui->AMedSqFilter->setText("");
    ui->AMedSqFilter->setIcon(QIcon(QPixmap::fromImage(AMedSq)));
    ui->AMedSqFilter->setIconSize(QSize(ui->AMedSqFilter->width(),ui->AMedSqFilter->height()));
    ui->MedCrsFilter->setText("");
    ui->MedCrsFilter->setIcon(QIcon(QPixmap::fromImage(MedCrs)));
    ui->MedCrsFilter->setIconSize(QSize(ui->MedCrsFilter->width(),ui->MedCrsFilter->height()));
    ui->AMedCrsFilter->setText("");
    ui->AMedCrsFilter->setIcon(QIcon(QPixmap::fromImage(AMedCrs)));
    ui->AMedCrsFilter->setIconSize(QSize(ui->AMedCrsFilter->width(),ui->AMedCrsFilter->height()));
}

void LinearFiltering::resetImageStyle()
{
    ui->MidFilter->setText("Усредняющий");
    ui->MidFilter->setIcon(QIcon());
    ui->GaussFilter->setText("Гаусс");
    ui->GaussFilter->setIcon(QIcon());
    ui->LaplasFilter->setText("Лаплас");
    ui->LaplasFilter->setIcon(QIcon());
    ui->GradFilter->setText("Градация");
    ui->GradFilter->setIcon(QIcon());
    ui->MedSqFilter->setText("Медианный Квадрат(3х3)");
    ui->MedSqFilter->setIcon(QIcon());
    ui->AMedSqFilter->setText("АМедианный Квадрат(3х3)");
    ui->AMedSqFilter->setIcon(QIcon());
    ui->MedCrsFilter->setText("Медианный крест(3х3)");
    ui->MedCrsFilter->setIcon(QIcon());
    ui->AMedCrsFilter->setText("АМедианный Крест(3х3)");
    ui->AMedCrsFilter->setIcon(QIcon());
}
