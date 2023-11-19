#ifndef TARGETPAGE_H
#define TARGETPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTextEdit>
#include <QTabWidget>
#include <QCheckBox>
#include <QLineEdit>
#include <QString>
class TargetPage;
class SingleIPPage;
class SegmentIPPage;


class SingleIPPage : public QWidget {
private:
    TargetPage *targetpage;
    QGridLayout layout;
    QCheckBox http;
    QCheckBox https;
    QLineEdit ip_edit;
    QLineEdit port_begin;
    QLineEdit port_end;

    void initUI();
    void generate();
public:
    void setTargetPage(TargetPage *targetpage);
    SingleIPPage();
    ~SingleIPPage();
};

class SegmentIPPage : public QWidget {
private:
    TargetPage *targetpage;
    QGridLayout layout;
    QCheckBox http;
    QCheckBox https;
    QLineEdit ip_prefix;
    QLineEdit suffix_begin;
    QLineEdit suffix_end;
    QLineEdit port_edit;

    void initUI();
    void generate();
public:
    void setTargetPage(TargetPage *targetpage);
    SegmentIPPage();
    ~SegmentIPPage();
};


class TargetPage : public QWidget {
private:
    QVBoxLayout layout;
    QTextEdit result;
    QTabWidget tabs;


    SingleIPPage single_ip; // ip:port
    SegmentIPPage segment_ip; // ip-ip


    void initUI();
    void initTabs();
public:
    TargetPage(QWidget *parent = nullptr);
    ~TargetPage();
    void setResult(QString str);

};

#endif // TARGETPAGE_H
