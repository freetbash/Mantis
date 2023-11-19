#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>
#include "tabwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
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
