#include "toolbar.h"
#include<QToolBar>
#include<QtDebug>
#include<QStyle>

void Toolbar::addTool(Tool tool)
{
    toolset.push_back(tool);
}

Toolbar::Toolbar()
{
    Tool tool1, tool2;
    tool1.name = "Ołówek";
    tool1.icon = QIcon(":/icons/pencil.png");
    tool2.name = "Pędzel";
    tool2.icon = QIcon(":/icons/paintbrush.png");
    addTool(tool1); addTool(tool2);
}

QToolBar* Toolbar::get()
{
    QToolBar *toolbar = new QToolBar("Przybornik");
    QActionGroup *toolGroup = new QActionGroup(this);
    for(auto& t : toolset)
    {
        QAction* action = new QAction(t.icon, t.name);
        toolbar->addAction(action);
        toolGroup->addAction(action);
    }
    toolGroup->actions().first()->setChecked(true);
    return toolbar;
}
