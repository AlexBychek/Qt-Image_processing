#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT
public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

    static bool IconProcessing; 
    static bool HalfGamma;
    static std::vector<std::vector<double>> Mid;
    static std::vector<std::vector<double>> Gauss;
    static std::vector<std::vector<double>> Laplas;
    static std::vector<std::vector<double>> Grad;
    static double Gamma;
signals:
    void chageState();
    void chageStateIcon();
private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
