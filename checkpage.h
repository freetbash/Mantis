#ifndef CHECKPAGE_H
#define CHECKPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLineEdit>

class CheckPage : public QWidget {

private:
    QVBoxLayout layout;

    QHBoxLayout top_layout;
    QWidget top;
    QTextEdit input;
    QTextEdit result;

    QGridLayout bottom_layout;
    QWidget bottom;
    QLineEdit url_path;

    void initUI();
    void handle();
public:
    CheckPage(QWidget *parent = nullptr);
    ~CheckPage();

};

bool checkWeb(QString url, QString path);
#endif // CHECKPAGE_H
