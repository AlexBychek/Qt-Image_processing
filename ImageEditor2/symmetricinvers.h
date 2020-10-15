#ifndef SYMMETRICINVERS_H
#define SYMMETRICINVERS_H


#include <QImage>
#include <QDebug>

class SymmetricInvers
{
public:
    static QImage V_UP(QImage);
    static QImage V_DOWN(QImage);
    static QImage H_LEFT(QImage);
    static QImage H_RIGHT(QImage);
};
#endif // SYMMETRICINVERS_H
