#include "toolbar.h"
#include<QToolBar>
#include<QtDebug>
#include<QStyle>

void Toolbar::addTool(Tool& tool)
{
    toolset.push_back(tool);
}

Toolbar::Toolbar()
{
    colorPicker.color = QColor("black");

    /*
    Tool tool1, tool2, tool3;
    tool1.name = "Ołówek";
    tool1.icon = QIcon(":/icons/pencil.png");
    tool2.name = "Pędzel";
    tool2.icon = QIcon(":/icons/paintbrush.png");
    tool3.name = "Wykrywanie krawędzi";
    tool3.icon = QIcon(":/icons/pen.png"); //tymczasowo ikonka długopisu


    addTool(tool1); addTool(tool2); addTool(tool3);
    */
}

QToolBar* Toolbar::get()
{
    QToolBar *toolbar = new QToolBar("Przybornik");

    colorPickAct = new QAction(colorPicker.icon, colorPicker.name);
    QPixmap pixmap(32, 32);
    pixmap.fill(colorPicker.color);
    QIcon pickerIcon(pixmap);
    colorPickAct->setIcon(pickerIcon);

    pencilAct = new QAction(pencil.icon, pencil.name);
    brushAct = new QAction(brush.icon, brush.name);
    fillAct = new QAction(fill.icon, fill.name);
    pasteAct = new QAction(paste.icon, paste.name);
    copyAct = new QAction(copy.icon, copy.name);
    lineAct = new QAction(line.icon, line.name);

    toolbar->addAction(colorPickAct);
    toolbar->addAction(pencilAct);
    toolbar->addAction(brushAct);
    toolbar->addAction(fillAct);
    toolbar->addAction(pasteAct);
    toolbar->addAction(copyAct);
    toolbar->addAction(lineAct);

    pencilAct->setCheckable(true);
    brushAct->setCheckable(true);
    fillAct->setCheckable(true);
    pasteAct->setCheckable(true);
    copyAct->setCheckable(true);
    lineAct->setCheckable(true);

    toolGroup = new QActionGroup(this);
    toolGroup->addAction(pencilAct);
    toolGroup->addAction(brushAct);
    toolGroup->addAction(fillAct);
    toolGroup->addAction(pasteAct);
    toolGroup->addAction(copyAct);
    toolGroup->addAction(lineAct);
    pencilAct->setChecked(true);

    connect(colorPickAct, &QAction::triggered, this, &Toolbar::showColorDialog);

    return toolbar;
}

void Toolbar::showColorDialog()
{
    colorPicker.showColorDialog();
    QPixmap pixmap(32, 32);
    pixmap.fill(colorPicker.color);
    QIcon pickerIcon(pixmap);
    colorPickAct->setIcon(pickerIcon);
}
