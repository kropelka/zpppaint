#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QObject>
#include "tool.h"
#include <QVector>
#include <QToolBar>
class Toolbar : QObject
{
    Q_OBJECT
public:
    QVector<Tool> toolset;
    void addTool(Tool tool);
    Toolbar();
    QToolBar *get();
};

#endif // TOOLBAR_H
