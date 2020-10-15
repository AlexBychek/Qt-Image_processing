#include "morphologicaltransformations.h"
#include "ui_morphologicaltransformations.h"

#include <QStandardPaths>
#include <QImageWriter>
#include <QImageReader>

MorphologicalTransformations::MorphologicalTransformations(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MorphologicalTransformations)
{
    ui->setupUi(this);

    ui->BWButton->setToolTip("ЧБ фильтр");
    ui->DilationButton->setToolTip("Дилатация");
    ui->ErosionButton->setToolTip("Эрозия");
    ui->ClosingButton->setToolTip("Закрытие");
    ui->OpeningButton->setToolTip("Открытие");


    connect(ui->BWButton, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(BW) : emit ButtonClick(morphological::Binary(image));
    });
    connect(ui->NotButton, &QPushButton::clicked, [this]{
        emit ButtonClick(morphological::Not(image));
    });
    connect(ui->AndButton, &QPushButton::clicked, [this]{
        QFileDialog dialog(this, tr("Open File"));
        initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);
        QImage file;
        while (dialog.exec() == QDialog::Accepted && !file.load(dialog.selectedFiles().first())) {}
        emit ButtonClick(morphological::And(image, file));
    });
    connect(ui->XorButton, &QPushButton::clicked, [this]{
        QFileDialog dialog(this, tr("Open File"));
        initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);
        QImage file;
        while (dialog.exec() == QDialog::Accepted && !file.load(dialog.selectedFiles().first())) {}
        emit ButtonClick(morphological::Xor(image, file));
    });
    connect(ui->OrButton, &QPushButton::clicked, [this]{
        QFileDialog dialog(this, tr("Open File"));
        initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);
        QImage file;
        while (dialog.exec() == QDialog::Accepted && !file.load(dialog.selectedFiles().first())) {}
        emit ButtonClick(morphological::Or(image, file));
    });

    connect(ui->DilationButton, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(Dilation) : emit ButtonClick(morphological::Dilation(image));
    });

    connect(ui->ErosionButton, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(Erosion) : emit ButtonClick(morphological::Erosion(image));
    });

    connect(ui->ClosingButton, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(Closing) : emit ButtonClick(morphological::Erosion(morphological::Dilation(image)));
    });

    connect(ui->OpeningButton, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(Opening) : emit ButtonClick(morphological::Dilation(morphological::Erosion(image)));
    });

}

MorphologicalTransformations::~MorphologicalTransformations()
{
    delete ui;
}

void MorphologicalTransformations::setImage(QImage img)
{
    this->image = img;
    Settings::IconProcessing ? iconImageStyle() : resetImageStyle();
};

void MorphologicalTransformations::reload()
{
    if(Settings::IconProcessing)
    {
        BW = morphological::Binary(image);
        QImage Bw = BW.scaled(ui->BWButton->width(),ui->BWButton->height(), Qt::IgnoreAspectRatio);
        ui->BWButton->setText("");
        ui->BWButton->setIcon(QIcon(QPixmap::fromImage(Bw)));
        ui->BWButton->setIconSize(QSize(ui->BWButton->width(),ui->BWButton->height()));
    }
}

void MorphologicalTransformations::iconImageStyle()
{
    BW = morphological::Binary(image);
    QImage Bw = BW.scaled(ui->BWButton->width(),ui->BWButton->height(), Qt::IgnoreAspectRatio);
    ui->BWButton->setText("");
    ui->BWButton->setIcon(QIcon(QPixmap::fromImage(Bw)));
    ui->BWButton->setIconSize(QSize(ui->BWButton->width(),ui->BWButton->height()));

    Erosion = morphological::Erosion(image);
    Dilation= morphological::Dilation(image);

    QImage Er = Erosion.scaled(ui->ErosionButton->width(),ui->ErosionButton->height(), Qt::IgnoreAspectRatio);
    QImage Dl = Dilation.scaled(ui->DilationButton->width(),ui->DilationButton->height(), Qt::IgnoreAspectRatio);

    ui->ErosionButton->setText("");
    ui->ErosionButton->setIcon(QIcon(QPixmap::fromImage(Er)));
    ui->ErosionButton->setIconSize(QSize(ui->ErosionButton->width(),ui->ErosionButton->height()));
    ui->DilationButton->setText("");
    ui->DilationButton->setIcon(QIcon(QPixmap::fromImage(Dl)));
    ui->DilationButton->setIconSize(QSize(ui->DilationButton->width(),ui->DilationButton->height()));


    Closing = morphological::Erosion(morphological::Dilation(image));
    Opening = morphological::Dilation(morphological::Erosion(image));

    QImage Cl = Closing.scaled(ui->ClosingButton->width(),ui->ClosingButton->height(), Qt::IgnoreAspectRatio);
    QImage Op = Opening.scaled(ui->OpeningButton->width(),ui->OpeningButton->height(), Qt::IgnoreAspectRatio);

    ui->ClosingButton->setText("");
    ui->ClosingButton->setIcon(QIcon(QPixmap::fromImage(Cl)));
    ui->ClosingButton->setIconSize(QSize(ui->ClosingButton->width(),ui->ClosingButton->height()));
    ui->OpeningButton->setText("");
    ui->OpeningButton->setIcon(QIcon(QPixmap::fromImage(Op)));
    ui->OpeningButton->setIconSize(QSize(ui->OpeningButton->width(),ui->OpeningButton->height()));
}

void MorphologicalTransformations::resetImageStyle()
{
    ui->BWButton->setText("BW");
    ui->BWButton->setIcon(QIcon());
    ui->DilationButton->setText("Dilation");
    ui->DilationButton->setIcon(QIcon());
    ui->ErosionButton->setText("Erosion");
    ui->ErosionButton->setIcon(QIcon());
    ui->ClosingButton->setText("Closing");
    ui->ClosingButton->setIcon(QIcon());
    ui->OpeningButton->setText("Opening");
    ui->OpeningButton->setIcon(QIcon());
}
