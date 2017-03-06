#include "mainwindow.h"
#include <QApplication>
#include "downloader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Downloader download;
    download.doDownload();

    return a.exec();
}
