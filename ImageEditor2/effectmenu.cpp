#include "effectmenu.h"
#include "ui_effectmenu.h"

EffectMenu::EffectMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EffectMenu)
{
    ui->setupUi(this);

    connect(ui->OnlyRedButton, &QPushButton::clicked, [this]{

        Settings::IconProcessing ? emit ButtonClick(OnlyRed) : emit ButtonClick(Effects::OnlyRed(this->image));
    });
    connect(ui->OnlyGreenButton, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(OnlyGreen) : emit ButtonClick(Effects::OnlyGreen(this->image));
    });
    connect(ui->OnlyBlueButton, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(OnlyBlue) : emit ButtonClick(Effects::OnlyBlue(this->image));
    });
    connect(ui->HalfToneButton, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(HalfTone) : emit ButtonClick(Effects::Halftone(this->image));
    });
    connect(ui->NegativeButton, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(Negative) : emit ButtonClick(Effects::Nega(this->image));
    });
    connect(ui->InversionVDownToUp, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(VDownToUp) : emit ButtonClick(SymmetricInvers::V_DOWN(this->image));
    });
    connect(ui->InversionVUpToDown, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(VUpToDown) : emit ButtonClick(SymmetricInvers::V_UP(this->image));
    });
    connect(ui->InversionHLeftToRight, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(HRightToLeft) : emit ButtonClick(SymmetricInvers::H_LEFT(this->image));
    });
    connect(ui->InversionHRightToLeft, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(HLeftToRight) : emit ButtonClick(SymmetricInvers::H_RIGHT(this->image));
    });
    connect(ui->SaltAndPepper, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(SaltAndPepper) : emit ButtonClick(Effects::salt_and_pepper(this->image, ui->SaltAndPepperNoise->value()));
    });
    connect(ui->SaltAndPepperB, &QPushButton::clicked, [this]{
        Settings::IconProcessing ? emit ButtonClick(SaltAndPepperB) : emit ButtonClick(Effects::salt_and_pepperB(this->image, ui->SaltAndPepperNoise->value()));
    });

    connect(ui->SaltAndPepperNoise,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), [=](int i){
        if(Settings::IconProcessing)
        {
            SaltAndPepper = Effects::salt_and_pepper(this->image, ui->SaltAndPepperNoise->value());
            QImage SAP = SaltAndPepper.scaled(ui->SaltAndPepper->width(),ui->SaltAndPepper->height(), Qt::IgnoreAspectRatio);
            SaltAndPepperB = Effects::salt_and_pepperB(this->image, ui->SaltAndPepperNoise->value());
            QImage SAPB = SaltAndPepperB.scaled(ui->SaltAndPepperB->width(),ui->SaltAndPepperB->height(), Qt::IgnoreAspectRatio);
            ui->SaltAndPepper->setIcon(QIcon(QPixmap::fromImage(SAP)));
            ui->SaltAndPepper->setIconSize(QSize(ui->SaltAndPepper->width(),ui->SaltAndPepper->height()));
            ui->SaltAndPepperB->setIcon(QIcon(QPixmap::fromImage(SAPB)));
            ui->SaltAndPepperB->setIconSize(QSize(ui->SaltAndPepperB->width(),ui->SaltAndPepperB->height()));
        }
        else
        {
            SaltAndPepper = Effects::salt_and_pepper(this->image, ui->SaltAndPepperNoise->value());
            SaltAndPepperB = Effects::salt_and_pepperB(this->image, ui->SaltAndPepperNoise->value());
        }
    });

    ui->OnlyRedButton->setToolTip("Только красный");
    ui->OnlyGreenButton->setToolTip("Только зеленый");
    ui->OnlyBlueButton->setToolTip("Только синий");
    ui->HalfToneButton->setToolTip("Полутоновый");
    ui->NegativeButton->setToolTip("Негатив");
    ui->InversionVDownToUp->setToolTip("Инверсия снизу вверх");
    ui->InversionVUpToDown->setToolTip("Инверсия сверху вниз");
    ui->InversionHLeftToRight->setToolTip("Инверсия Слева на право");
    ui->InversionHRightToLeft->setToolTip("Инверсия Справа на лево");
    ui->SaltAndPepper->setToolTip("Соль и перец однополярный");
    ui->SaltAndPepperB->setToolTip("Соль и перец биполярный");
    ui->SaltAndPepperNoise->setToolTip("Соль и перец уровень шума [128;128000]");
}

void EffectMenu::setImage(QImage img)
{
    this->image = img;
    if(Settings::IconProcessing)
        iconImageStyle();
    else
        resetImageStyle();
};

void EffectMenu::iconImageStyle()
{
    OnlyRed = Effects::OnlyRed(this->image);
    QImage red = OnlyRed.scaled(ui->OnlyRedButton->width(),ui->OnlyRedButton->height(), Qt::IgnoreAspectRatio);
    OnlyGreen = Effects::OnlyGreen(this->image);
    QImage green = OnlyGreen.scaled(ui->OnlyRedButton->width(),ui->OnlyRedButton->height(), Qt::IgnoreAspectRatio);
    OnlyBlue = Effects::OnlyBlue(this->image);
    QImage blue = OnlyBlue.scaled(ui->OnlyRedButton->width(),ui->OnlyRedButton->height(), Qt::IgnoreAspectRatio);
    HalfTone = Effects::Halftone(this->image);
    QImage halftone = HalfTone.scaled(ui->OnlyRedButton->width(),ui->OnlyRedButton->height(), Qt::IgnoreAspectRatio);
    Negative = Effects::Nega(this->image);
    QImage negative = Negative.scaled(ui->OnlyRedButton->width(),ui->OnlyRedButton->height(), Qt::IgnoreAspectRatio);
    VUpToDown = SymmetricInvers::V_UP(this->image);
    QImage inversV_UP = VUpToDown.scaled(ui->OnlyRedButton->width(),ui->OnlyRedButton->height(), Qt::IgnoreAspectRatio);
    VDownToUp = SymmetricInvers::V_DOWN(this->image);
    QImage inversV_DOWN = VDownToUp.scaled(ui->OnlyRedButton->width(),ui->OnlyRedButton->height(), Qt::IgnoreAspectRatio);
    HRightToLeft = SymmetricInvers::H_LEFT(this->image);
    QImage inversH_LEFT = HRightToLeft.scaled(ui->OnlyRedButton->width(),ui->OnlyRedButton->height(), Qt::IgnoreAspectRatio);
    HLeftToRight = SymmetricInvers::H_RIGHT(this->image);
    QImage inversH_RIGHT = HLeftToRight.scaled(ui->OnlyRedButton->width(),ui->OnlyRedButton->height(), Qt::IgnoreAspectRatio);
    SaltAndPepper = Effects::salt_and_pepper(this->image, ui->SaltAndPepperNoise->value());
    QImage SAP = SaltAndPepper.scaled(ui->SaltAndPepper->width(),ui->SaltAndPepper->height(), Qt::IgnoreAspectRatio);
    SaltAndPepperB = Effects::salt_and_pepperB(this->image, ui->SaltAndPepperNoise->value());
    QImage SAPB = SaltAndPepperB.scaled(ui->SaltAndPepperB->width(),ui->SaltAndPepperB->height(), Qt::IgnoreAspectRatio);
    ui->OnlyRedButton->setText("");
    ui->OnlyRedButton->setIcon(QIcon(QPixmap::fromImage(red)));
    ui->OnlyRedButton->setIconSize(QSize(ui->OnlyRedButton->width(),ui->OnlyRedButton->height()));
    ui->OnlyGreenButton->setText("");
    ui->OnlyGreenButton->setIcon(QIcon(QPixmap::fromImage(green)));
    ui->OnlyGreenButton->setIconSize(QSize(ui->OnlyRedButton->width(),ui->OnlyRedButton->height()));
    ui->OnlyBlueButton->setText("");
    ui->OnlyBlueButton->setIcon(QIcon(QPixmap::fromImage(blue)));
    ui->OnlyBlueButton->setIconSize(QSize(ui->OnlyRedButton->width(),ui->OnlyRedButton->height()));
    ui->HalfToneButton->setText("");
    ui->HalfToneButton->setIcon(QIcon(QPixmap::fromImage(halftone)));
    ui->HalfToneButton->setIconSize(QSize(ui->HalfToneButton->width(),ui->HalfToneButton->height()));
    ui->NegativeButton->setText("");
    ui->NegativeButton->setIcon(QIcon(QPixmap::fromImage(negative)));
    ui->NegativeButton->setIconSize(QSize(ui->NegativeButton->width(),ui->NegativeButton->height()));
    ui->InversionVUpToDown->setText("");
    ui->InversionVUpToDown->setIcon(QIcon(QPixmap::fromImage(inversV_UP)));
    ui->InversionVUpToDown->setIconSize(QSize(ui->InversionVUpToDown->width(),ui->InversionVUpToDown->height()));
    ui->InversionVDownToUp->setText("");
    ui->InversionVDownToUp->setIcon(QIcon(QPixmap::fromImage(inversV_DOWN)));
    ui->InversionVDownToUp->setIconSize(QSize(ui->InversionVDownToUp->width(),ui->InversionVDownToUp->height()));
    ui->InversionHLeftToRight->setText("");
    ui->InversionHLeftToRight->setIcon(QIcon(QPixmap::fromImage(inversH_LEFT)));
    ui->InversionHLeftToRight->setIconSize(QSize(ui->InversionHLeftToRight->width(),ui->InversionHLeftToRight->height()));
    ui->InversionHRightToLeft->setText("");
    ui->InversionHRightToLeft->setIcon(QIcon(QPixmap::fromImage(inversH_RIGHT)));
    ui->InversionHRightToLeft->setIconSize(QSize(ui->InversionHRightToLeft->width(),ui->InversionHRightToLeft->height()));
    ui->SaltAndPepper->setText("");
    ui->SaltAndPepper->setIcon(QIcon(QPixmap::fromImage(SAP)));
    ui->SaltAndPepper->setIconSize(QSize(ui->SaltAndPepper->width(),ui->SaltAndPepper->height()));
    ui->SaltAndPepperB->setText("");
    ui->SaltAndPepperB->setIcon(QIcon(QPixmap::fromImage(SAPB)));
    ui->SaltAndPepperB->setIconSize(QSize(ui->SaltAndPepperB->width(),ui->SaltAndPepperB->height()));
}

int EffectMenu::SaltAndPepperNoiseGet()
{
    return ui->SaltAndPepperNoise->value();
}

void EffectMenu::resetImageStyle()
{
    ui->OnlyRedButton->setText("Только красный");
    ui->OnlyRedButton->setIcon(QIcon());
    ui->OnlyGreenButton->setText("Только зеленый");
    ui->OnlyGreenButton->setIcon(QIcon());
    ui->OnlyBlueButton->setText("Только синий");
    ui->OnlyBlueButton->setIcon(QIcon());
    ui->HalfToneButton->setText("Полутоновый");
    ui->HalfToneButton->setIcon(QIcon());
    ui->NegativeButton->setText("Негатив");
    ui->NegativeButton->setIcon(QIcon());
    ui->InversionVUpToDown->setText("Инверсия сверху вниз");
    ui->InversionVUpToDown->setIcon(QIcon());
    ui->InversionVDownToUp->setText("Инверсия снизу вверх");
    ui->InversionVDownToUp->setIcon(QIcon());
    ui->InversionHLeftToRight->setText("Инверсия Слева на право");
    ui->InversionHLeftToRight->setIcon(QIcon());
    ui->InversionHRightToLeft->setText("Инверсия Справа на лево");
    ui->InversionHRightToLeft->setIcon(QIcon());
    ui->SaltAndPepper->setText("Соль и перец однополярный");
    ui->SaltAndPepper->setIcon(QIcon());
    ui->SaltAndPepperB->setText("Соль и перец биполярный");
    ui->SaltAndPepperB->setIcon(QIcon());
}

EffectMenu::~EffectMenu()
{
    delete ui;
}
