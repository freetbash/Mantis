#include "tabwidget.h"




void TabWidget::initPages() {
    this->setStyleSheet("QTabBar::tab { width: 150px; height: 30px; }");
    this->addTab(&this->page_target, "&Target");
    this->addTab(&this->page_check, "Check");
//    this->addTab(&this->page_getflag, "&Get Flag");
//    this->addTab(&this->page_submitflag, "&Submit Flag");


}




TabWidget::TabWidget() {
    this->initPages();

}


