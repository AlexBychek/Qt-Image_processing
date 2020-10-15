#ifndef FILEINFORM_H
#define FILEINFORM_H

#include <QWidget>
#include <QFileInfo>
namespace Ui {
class FileInform;
}

class FileInform : public QWidget
{
    Q_OBJECT

public:
    explicit FileInform(QWidget *parent = nullptr);
    ~FileInform();
    void SetMetaData(QImage,QString);

    void EnabledChangeColor();
    void showPixelColor(int,int,int);
signals:
    void PushPixelColor(int,int);

private:
    Ui::FileInform *ui;
    QImage img;
};

#endif // FILEINFORM_H
