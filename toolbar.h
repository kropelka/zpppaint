#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QObject>
#include "tool.h"
#include <QVector>
#include <QToolBar>
#include "colorpicker.h"
#include "pencil.h"
#include "brush.h"
#include "fill.h"
#include<QActionGroup>
#include "paste.h"
#include "clipcopy.h"
#include "line.h"

class Toolbar : public QObject
{
    Q_OBJECT
public:
    QVector<Tool> toolset;
    void addTool(Tool& tool);
    Toolbar();
    QToolBar *get();
    ColorPicker colorPicker;
    QAction *colorPickAct, *pencilAct, *brushAct, *fillAct, *pasteAct, *copyAct, *lineAct;
    Pencil pencil;
    Brush brush;
    Fill fill;
    Paste paste;
    ClipCopy copy;
    Line line;
    QActionGroup *toolGroup;
public slots:
    void showColorDialog();
};

#endif // TOOLBAR_H
