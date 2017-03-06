#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    download =new Downloader(this);
    connect(download,SIGNAL(server_data(QString)),this,SLOT(server_data_slot(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::server_data_slot(QString msg)
{
    QString dmsg="";
    QStringList list=msg.split("\n",QString::SkipEmptyParts);
    foreach (QString data,list){
        QStringList plist=data.split(":",QString::SkipEmptyParts);
            if( plist[0].startsWith("Water"))
                ui->lcdNumber->display(plist[1].toInt());
            else if ( plist[0].startsWith("Time")){
                int sec=plist[1].trimmed().toInt();
               ui->timeEdit->setTime(QTime(sec/60,sec%60) );}
            else if( plist[0].startsWith("Server"))
                dmsg+="Server Hit: " +plist[1] +"\n";
            else if ( plist[0].startsWith("Mode"))
                 dmsg+="Mode: " +plist[1] +"\n";
            else if( plist[0].startsWith("Status"))
                switch (plist[1].trimmed().toInt()) {
                case 0:ui->radioButton->setChecked(true);
                    break;
                case 1:ui->radioButton_2->setChecked(true);
                    break;
                default:
                    break;
                }
            else if ( plist[0].startsWith("Sonar"))
                 dmsg+="Sonar Control: " +plist[1] +"\n";



    }

    ui->plainTextEdit->setPlainText(dmsg);
}

void MainWindow::on_MotorOn_clicked()
{
//    send data to motor:on
    download->SendCommand("on");
}

void MainWindow::on_MotorOFF_clicked()
{
    //    send data to motor:on
        download->SendCommand("off");
}
