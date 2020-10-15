#ifndef EFFECTMENU_H
#define EFFECTMENU_H

#include <QWidget>
#include "effects.h"
#include "symmetricinvers.h"
#include "settings.h"

namespace Ui {
class EffectMenu;
}
class EffectMenu : public QWidget
{
    Q_OBJECT
public:
    explicit EffectMenu(QWidget *parent = nullptr);
    ~EffectMenu();

    void setImage(QImage);
    void iconImageStyle();
    int SaltAndPepperNoiseGet();
    void resetImageStyle();
signals:
    void ButtonClick(QImage);
private:
    Ui::EffectMenu *ui;
    QImage image;
    QImage OnlyRed, OnlyGreen, OnlyBlue, HalfTone, Negative, VUpToDown, VDownToUp, HLeftToRight, HRightToLeft, SaltAndPepper, SaltAndPepperB;
};

#endif // EFFECTMENU_H
