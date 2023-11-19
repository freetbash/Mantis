#include "checkpage.h"
#include <QLabel>
#include <QPushButton>
#include <QObject>
#include <QString>
#include <QList>


CheckPage::CheckPage(QWidget *parent)
    : QWidget{parent}
{
    this->initUI();
}

void CheckPage::initUI() {
    // layout

    this->setLayout(&this->layout);
    this->layout.addWidget(&this->top);
    this->layout.addWidget(&this->bottom);
    this->top.setLayout(&this->top_layout);
    this->bottom.setLayout(&this->bottom_layout);

    // widget
    this->input.setAcceptRichText(false);
    this->result.setAcceptRichText(false);
    this->top_layout.addWidget(&this->input);
    this->top_layout.addWidget(&this->result);
    this->input.setPlaceholderText("http://192.168.0.103:8001\nhttp://192.168.0.103:8002\nhttp://192.168.0.103:8003\nhttp://192.168.0.103:8004\nhttp://192.168.0.103:8005\nhttp://192.168.0.103:8006\nhttp://192.168.0.103:8007\nhttp://192.168.0.103:8008\nhttp://192.168.0.103:8009\nhttp://192.168.0.103:8010");

    QLabel *url_path = new QLabel("Url Path");
    this->url_path.setPlaceholderText("/app1/admin1");
    this->bottom_layout.addWidget(url_path, 0, 0, 1, 1);
    this->bottom_layout.addWidget(&this->url_path, 0, 1, 1, 1);


    QPushButton *handle = new QPushButton("Handle");
    this->bottom_layout.addWidget(handle, 0, 2, 1, 1);

    QObject::connect(handle, &QPushButton::clicked, this, &CheckPage::handle);

}

void CheckPage::handle() {
    QString res;
    QString path = this->url_path.text();
    QList<QString> urls;

    QString url_list = this->input.toPlainText();
    urls = url_list.split("\n");


    for (int i=0; i < urls.length()-1; ++i) {

        if (checkWeb(urls[i], path)) {
            res += urls[i] + "\n";
        }
    }

    if (checkWeb(urls[urls.length()-1], path)) {
        res += urls[urls.length()-1];
    }

    this->result.setPlainText(res);
}

#include <QCoreApplication>
#include <QtNetwork>
#include <QDebug>

bool checkWeb(QString url, QString path) {
    url = url + path;
    QNetworkAccessManager manager;
    QNetworkRequest request;

    request.setUrl(QUrl(url));

    QEventLoop loop;
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);

    QNetworkReply* reply = manager.get(request);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        return true;
    } else if (reply->error() == QNetworkReply::ContentNotFoundError) {
        return false;
    } else {
        return false;
    }
}

CheckPage::~CheckPage() {

}
