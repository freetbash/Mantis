#include "targetpage.h"
#include <QLabel>
#include <QPushButton>
#include <QObject>

TargetPage::TargetPage(QWidget *parent)
    : QWidget{parent}
{
    this->initUI();
    this->initTabs();
}

void TargetPage::initUI() {

    this->result.setAcceptRichText(false);
    // layout
    this->setLayout(&this->layout);
    this->layout.addWidget(&this->result);
    this->layout.addWidget(&this->tabs);

}

void TargetPage::initTabs() {
    this->single_ip.setTargetPage(this);
    this->tabs.addTab(&this->single_ip, "Single IP");
    this->segment_ip.setTargetPage(this);
    this->tabs.addTab(&this->segment_ip, "Segment IP");
}

void TargetPage::setResult(QString str) {
    this->result.setPlainText(str);

}

TargetPage::~TargetPage(){

}


SingleIPPage::SingleIPPage(){
    this->initUI();
}
void SingleIPPage::setTargetPage(TargetPage *targetpage){
    this->targetpage = targetpage;
}

void SingleIPPage::initUI() {
    // widget
    this->ip_edit.setPlaceholderText("192.168.0.103");
    this->port_begin.setPlaceholderText("8001");
    this->port_end.setPlaceholderText("8010");
    QLabel *ip = new QLabel("IP");
    QLabel *port_begin = new QLabel("Port Begin");
    QLabel *port_end = new QLabel("Port End");
    QPushButton *generate = new QPushButton("Generate");


    this->http.setText("http://");
    this->https.setText("https://");

    // layout
    this->setLayout(&this->layout);
    this->layout.addWidget(&this->http, 0, 0, 1, 1);
    this->layout.addWidget(&this->https,0, 1, 1, 1);

    this->layout.addWidget(ip, 1, 0, 1, 1);
    this->layout.addWidget(&this->ip_edit, 1 , 1 , 1 ,1);

    this->layout.addWidget(port_begin, 2, 0, 1, 1);
    this->layout.addWidget(&this->port_begin, 2, 1, 1, 1);

    this->layout.addWidget(port_end, 3, 0, 1, 1);
    this->layout.addWidget(&this->port_end, 3, 1, 1, 1);

    this->layout.addWidget(generate, 4, 0, 1, 2);

    QObject::connect(generate, &QPushButton::clicked, this, &SingleIPPage::generate);
}

void SingleIPPage::generate() {
    QString res;
    QString prefix = "";
    int port_begin, port_end;

    if (this->http.isChecked()) {
        prefix = "http://";
    }

    if (this->https.isChecked()) {
        prefix = "https://";
    }

    port_begin = this->port_begin.text().toInt();
    port_end = this->port_end.text().toInt();

    for (int i = port_begin; i < port_end; ++i) {
        res += prefix + this->ip_edit.text() + ":" + QString::number(i) + "\n";
    }
    res += prefix + this->ip_edit.text() + ":" + QString::number(port_end);


    this->targetpage->setResult(res);
}

SingleIPPage::~SingleIPPage() {

}

SegmentIPPage::SegmentIPPage(){
    this->initUI();
}

void SegmentIPPage::setTargetPage(TargetPage *targetpage){
    this->targetpage = targetpage;
}

void SegmentIPPage::initUI(){

    // widget
    this->port_edit.setPlaceholderText("8001");
    this->ip_prefix.setPlaceholderText("192.168.0");
    this->suffix_begin.setPlaceholderText("1");
    this->suffix_end.setPlaceholderText("255");
    QLabel *ip = new QLabel("IP Prefix");
    QLabel *suffix_beigin= new QLabel("Suffix Begin");
    QLabel *suffix_end = new QLabel("Suffix End");
    QLabel *port = new QLabel("Port");
    QPushButton *generate = new QPushButton("Generate");


    this->http.setText("http://");
    this->https.setText("https://");

    // layout
    this->setLayout(&this->layout);
    this->layout.addWidget(&this->http, 0, 0, 1, 1);
    this->layout.addWidget(&this->https,0, 1, 1, 1);

    this->layout.addWidget(port, 0, 2, 1, 1);
    this->layout.addWidget(&this->port_edit, 0, 3, 1, 1);

    this->layout.addWidget(ip, 1, 0, 1, 1);
    this->layout.addWidget(&this->ip_prefix, 1 , 1 , 1 ,4);

    this->layout.addWidget(suffix_beigin, 2, 0, 1, 1);
    this->layout.addWidget(&this->suffix_begin, 2, 1, 1, 4);

    this->layout.addWidget(suffix_end, 3, 0, 1, 1);
    this->layout.addWidget(&this->suffix_end, 3, 1, 1, 4);

    this->layout.addWidget(generate, 4, 0, 1, 4);

    QObject::connect(generate, &QPushButton::clicked, this, &SegmentIPPage::generate);

}

void SegmentIPPage::generate() {
    QString res;
    QString prefix;
    QString port = this->port_edit.text();
    int begin = this->suffix_begin.text().toInt();
    int end = this->suffix_end.text().toInt();

    if (!port.isEmpty()) {
        port = ":" + port;
    }

    if (this->http.isChecked()) {
        prefix = "http://";
    }

    if (this->https.isChecked()) {
        prefix = "https://";
    }

    for (int i=begin; i < end; ++i) {
        res += prefix + this->ip_prefix.text() + "." + QString::number(i) + port + "\n";
    }
    res += prefix + this->ip_prefix.text() + "." + QString::number(end) + port;

    this->targetpage->setResult(res);

}

SegmentIPPage::~SegmentIPPage(){

}
