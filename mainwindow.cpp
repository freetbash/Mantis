#include "mainwindow.h"
#include <QHBoxLayout>

void MainWindow::setUI(){
    this->setGeometry(100, 100, 600, 500);
    this->setMenuBar(&this->menu_bar);
    this->setStatusBar(&this->status_bar);
    this->setCentralWidget(&this->tabs);

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setUI();

}

MainWindow::~MainWindow()
{
}

