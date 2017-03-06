#include "downloader.h"

Downloader::Downloader(QObject *parent) :
    QObject(parent)
{
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(TimerUpdate()));
    timer->start(5000);
}

void Downloader::doDownload()
{
    manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));

    manager->get(QNetworkRequest(QUrl("http://192.168.0.105/status")));
}

void Downloader::SendCommand(QString cmd)
{
    qDebug()<<"Cmd sent: "<<cmd;


    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    QHttpPart textPart;
    textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("motor; name=\"off\""));
    textPart.setBody(cmd.toUtf8());

    multiPart->append(textPart);

    QUrl url("http://192.168.0.105/command");
    QNetworkRequest request(url);

    QNetworkAccessManager manager;
    QNetworkReply *reply = manager.post(request, multiPart);
    multiPart->setParent(reply); // delete the multiPart with the reply
    // here connect signals etc.

}

void Downloader::replyFinished (QNetworkReply *reply)
{
    if(reply->error())
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }
    else
    {
        QString data(reply->readAll());
//        qDebug()<<data;
        emit server_data(data);
    }

    reply->deleteLater();
}

void Downloader::TimerUpdate()
{
    doDownload();
}
