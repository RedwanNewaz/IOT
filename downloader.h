#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QDebug>
#include <QTimer>
#include <QString>
#include <QHttpMultiPart>


class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = 0);

    void doDownload();
    void SendCommand(QString cmd);

signals:
    void server_data(QString);
public slots:
    void replyFinished (QNetworkReply *reply);
    void TimerUpdate();

private:
   QNetworkAccessManager *manager;
   QTimer *timer;

};
#endif
