#include "fileinform.h"
#include "ui_fileinform.h"

FileInform::FileInform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileInform)
{
    ui->setupUi(this);
    connect(ui->EditX, &QLineEdit::editingFinished, [this]{ EnabledChangeColor(); });
    connect(ui->EditY, &QLineEdit::editingFinished, [this]{ EnabledChangeColor(); });
}

void FileInform::SetMetaData(QImage image, QString file)
{
    this->img = image;
    QFileInfo fill(file);
    ui->NameFile->setText(fill.fileName());
    ui->Pixels->setText(QString::number(img.width()) + "x" + QString::number(img.height()) + " " + QString::number(fill.size()/1024) + "KB " + QString::number(img.depth()) + "bit");
    ui->PixelsColvo->setText(QString::number(img.width()*img.height()) + "pix");
    ui->FilePath->setText(fill.filePath());
}

void FileInform::EnabledChangeColor()
{
    bool checkX, checkY;
    QString x_str = ui->EditX->text(), y_str= ui->EditY->text();
    int x = x_str.toInt(&checkX,10), y = y_str.toInt(&checkY, 10);
    if(checkX && checkY && x >= 0 && y >= 0 && x <= this->img.width() && y <= this->img.height())
    {
        emit PushPixelColor(x,y);
    }
}


void FileInform::showPixelColor(int r,int g,int b)
{
    ui->label_R->setText("R " + QString::number(r));
    ui->label_G->setText("G " + QString::number(g));
    ui->label_B->setText("G " + QString::number(b));
}

FileInform::~FileInform()
{
    delete ui;
}
