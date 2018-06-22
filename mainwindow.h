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
    QAction *newAct, *openAct, *saveAct;

    QMenu *toolMenu;
    QAction *pencilAct, *brushAct;
    QActionGroup *toolGroup;

    QMenu *editMenu;
    QAction *edgeAct, *monoAct, *scaleAct, *fastMonoAct, *mixerMonoKolorAct, *ThresholdAct, *SettColorAct, *InverseColorAct, *BrightAct, *ContrastAct, *GammaAct;

    void createMenu();
    void createToolbar();

    void selectBrush();
    void selectPencil();
private slots:
    void open();
    void save();
    void newFile();
    void createImg(int x, int y);
    void scaleImg();
    void edgeDetect();
    void Mono();
    void FastMono();
    void MonoKolor();
    void Threshold();
    void SettColor();
    void InverseColor();
    void Bright();
    void Contrasst();
    void Gammma();
};

#endif // MAINWINDOW_H
