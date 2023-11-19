#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>
#include <QHBoxLayout>

#include "targetpage.h"
#include "checkpage.h"

class TabWidget : public QTabWidget {
private:
    TargetPage page_target;
    CheckPage page_check;

private:
    void initPages();

public:
    TabWidget();
};

#endif // TABWIDGET_H
