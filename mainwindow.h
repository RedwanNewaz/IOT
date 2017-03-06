#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStringList>
#include<QTime>
#include "downloader.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Downloader *download;

public slots:
    void server_data_slot(QString);
private slots:
    void on_MotorOn_clicked();
    void on_MotorOFF_clicked();
};

#endif // MAINWINDOW_H
