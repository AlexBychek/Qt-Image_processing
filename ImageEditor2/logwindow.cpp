#include "logwindow.h"
#include "ui_logwindow.h"

LogWindow::LogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogWindow)
{
    ui->setupUi(this);
    connect(ui->ClearButton, &QPushButton::clicked, ui->TextLog, &QTextEdit::clear );
}

void LogWindow::addlog(QString log)
{
    this->logList.append(log);
    ui->TextLog->append(log);
}

LogWindow::~LogWindow()
{
    delete ui;
}
