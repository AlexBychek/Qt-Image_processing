#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QDialog>

namespace Ui {
class LogWindow;
}

class LogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LogWindow(QWidget *parent = nullptr);
    ~LogWindow();

public slots:
    void addlog(QString);

private:
    Ui::LogWindow *ui;
    QStringList logList;
};

#endif // LOGWINDOW_H
