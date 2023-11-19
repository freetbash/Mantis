#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>
#include <QString>
#include "tabwidget.h"

const QString version = "0.0.1";

class MainWindow : public QMainWindow{
private:
    QMenuBar menu_bar;
    QStatusBar status_bar;
    TabWidget tabs;

private:
    void setUI();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
