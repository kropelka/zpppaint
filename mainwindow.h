#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "canvas.h"
#include<QMenu>
#include<QAction>
#include "toolbar.h"
#include<QScrollArea>
#include<QActionGroup>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Toolbar toolbar;
    Canvas *canvas;
    QScrollArea *scrollArea;

    QMenu *fileMenu;
    QAction *newAct, *openAct, *saveAct, *edgeAct;

    QMenu *toolMenu;
    QAction *pencilAct, *brushAct;
    QActionGroup *toolGroup;

    void createMenu();
    void createToolbar();

    void selectBrush();
    void selectPencil();
private slots:
    void open();
    void newFile();
    void edgeDetect();
};

#endif // MAINWINDOW_H
