#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QRect>
#include<QDesktopWidget>
#include<QLabel>
#include<QDebug>
#include<QVBoxLayout>
#include "newfiledialog.h"
#include "sobel.h"

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
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);

    openAct = new QAction("&Otwórz", this);
    openAct->setIcon(QIcon::fromTheme("document-open"));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);

    fileMenu->addAction(openAct);
    fileMenu->addAction(newAct);

    canvas->newImage(800,600); //przy starcie aplikacji wyrysowuje pustą białą kartkę
}

void MainWindow::createToolbar()
{
    addToolBar(toolbar.get());
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
