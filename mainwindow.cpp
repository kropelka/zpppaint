#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QRect>
#include<QDesktopWidget>
#include<QLabel>
#include<QDebug>
#include<QVBoxLayout>
#include "newfiledialog.h"
#include "pencil.h"
#include "brush.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    QRect screenSize = QDesktopWidget().availableGeometry(this);
    this->resize(QSize(screenSize.width() * 0.6, screenSize.height() * 0.6));

    canvas = new Canvas(this);
    setCentralWidget(canvas);

    createMenu();
    createToolbar();

}

MainWindow::~MainWindow()
{
}

void MainWindow::createMenu()
{
    fileMenu = menuBar()->addMenu("&Plik");
    newAct = new QAction("&Nowy", this);
    openAct = new QAction("&Otwórz", this);
    openAct->setIcon(QIcon::fromTheme("document-open"));

    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);
    connect(openAct, &QAction::triggered, this, &MainWindow::open);

    fileMenu->addAction(openAct);
    fileMenu->addAction(newAct);

    /* zanim zrobi się ładny przybornik, to opcja wyboru narzędzia w menu */
    toolMenu = menuBar()->addMenu("&Narzędzie");
    pencilAct = new QAction("&Ołówek", this);
    brushAct = new QAction("&Pędzel");
    pencilAct->setCheckable(true);
    brushAct->setCheckable(true);
    toolMenu->addAction(pencilAct);
    toolMenu->addAction(brushAct);
    toolGroup = new QActionGroup(this);
    toolGroup->addAction(pencilAct);
    toolGroup->addAction(brushAct);
    pencilAct->setChecked(true);

    connect(pencilAct, &QAction::triggered, this, &MainWindow::selectPencil);
    connect(brushAct, &QAction::triggered, this, &MainWindow::selectBrush);

    editMenu = menuBar()->addMenu("&Edytuj");
    edgeAct = new QAction("Wykryj krawędzie",this);
    monoAct = new QAction("Konwersja monochromatyczna",this);
    editMenu->addAction(edgeAct);
    editMenu->addAction(monoAct);

    connect(edgeAct, &QAction::triggered, this, &MainWindow::edgeDetect);
    connect(monoAct, &QAction::triggered, this, &MainWindow::Mono);

    canvas->newImage(600,600); //przy starcie aplikacji wyrysowuje pustą białą kartkę
}

void MainWindow::selectPencil()
{
    canvas->setCurrentTool(new Pencil());
}

void MainWindow::selectBrush()
{
    canvas->setCurrentTool(new Brush());
}

void MainWindow::createToolbar()
{
    addToolBar(toolbar.get());
}

void MainWindow::edgeDetect()
{
    canvas->detectEdges();
}

void MainWindow::Mono()
{
    canvas->scaleValues(true);
}

void MainWindow::open()
{
    QString filename = QFileDialog::getOpenFileName(this, "Otwórz obraz", ".", "Obrazy (*.png *.jpg *.bmp");
    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        canvas->loadImage(filename);
    }
}

void MainWindow::newFile()
{
    NewFileDialog dialog;
    dialog.exec();
}
