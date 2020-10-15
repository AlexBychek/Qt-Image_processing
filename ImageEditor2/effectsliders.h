#ifndef EFFECTSLIDERS_H
#define EFFECTSLIDERS_H

#include <QWidget>
#include "effects.h"

namespace Ui {
class EffectSliders;
}

class EffectSliders : public QWidget
{
    Q_OBJECT

public:
    explicit EffectSliders(QWidget *parent = nullptr);
    ~EffectSliders();

    void setImage(QImage);
signals:
    void SliderChanged(QImage);
    void SliderReleased();
private:
    Ui::EffectSliders *ui;
    QImage image;
};

#endif // EFFECTSLIDERS_H
