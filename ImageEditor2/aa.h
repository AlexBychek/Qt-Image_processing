#ifndef AA_H
#define AA_H

#include <QWidget>
#include "ssaa.h"

namespace Ui {
class AA;
}

class AA : public QWidget
{
    Q_OBJECT

public:
    explicit AA(QWidget *parent = nullptr);
    ~AA();

    void setImage(QImage);
signals:
    void ButtonClick(QImage);
private:
    Ui::AA *ui;
    QImage image;
};

#endif // AA_H
