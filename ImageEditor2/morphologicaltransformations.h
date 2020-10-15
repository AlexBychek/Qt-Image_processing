#ifndef MORPHOLOGICALTRANSFORMATIONS_H
#define MORPHOLOGICALTRANSFORMATIONS_H

#include <QWidget>
#include "morphological.h"
#include "settings.h"

#include <QFileDialog>
#include "FileDailog.h"

namespace Ui {
class MorphologicalTransformations;
}

class MorphologicalTransformations : public QWidget
{
    Q_OBJECT

public:
    explicit MorphologicalTransformations(QWidget *parent = nullptr);
    ~MorphologicalTransformations();
    void iconImageStyle();
    void resetImageStyle();
    void setImage(QImage);
    void reload();
signals:
    void ButtonClick(QImage);
private:
    Ui::MorphologicalTransformations *ui;
    QImage image, BW, Erosion, Dilation, Closing, Opening;

};

#endif // MORPHOLOGICALTRANSFORMATIONS_H
