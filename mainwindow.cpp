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
#include "mixerdialog.h"
#include "thresholddialoh.h"
#include "selectcolordialog.h"
#include "brightnessdialog.h"
#include "contrastdialog.h"
#include "gammadialog.h"
#include "fill.h"
#include "clipcopy.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    QRect screenSize = QDesktopWidget().availableGeometry(this);
    this->resize(QSize(screenSize.width() * 0.6, screenSize.height() * 0.6));

    canvas = new Canvas(this);
    setCentralWidget(canvas);

    createMenu();
    createToolbar();
    canvas->colorPicker = &(toolbar.colorPicker);

}

MainWindow::~MainWindow()
{
}

void MainWindow::selectColor()
{
    //canvas->getCurrentTool()->showColorDialog();
}

void MainWindow::selectFill()
{
    canvas->setCurrentTool(new Fill());
}

void MainWindow::createMenu()
{
    fileMenu = menuBar()->addMenu("&Plik");
    newAct = new QAction("&Nowy", this);
    openAct = new QAction("&Otwórz", this);
    openAct->setIcon(QIcon::fromTheme("document-open"));
    saveAct = new QAction("Zapisz", this);

    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);
    connect(openAct, &QAction::triggered, this, &MainWindow::open);
    connect(saveAct, &QAction::triggered, this, &MainWindow::save);

    fileMenu->addAction(openAct);
    fileMenu->addAction(newAct);
    fileMenu->addAction(saveAct);

    editMenu = menuBar()->addMenu("&Edytuj");
    edgeAct = new QAction("Wykryj krawędzie",this);
    monoAct = new QAction("Konwersja monochromatyczna",this);
    scaleAct = new QAction("Skaluj obraz", this);
    fastMonoAct = new QAction("Szybka konwersja monochromatyczna",this);
    mixerMonoKolorAct = new QAction("Miksowanie koloru i monochromatycznosci");
    SettColorAct = new QAction("Wybor skladowej koloru");
    InverseColorAct = new QAction("Inwersja kolorow");
    ThresholdAct = new QAction("Progowanie");
    BrightAct = new QAction("Zmiana jasnosci");
    ContrastAct = new QAction("Zmiana kontrastu");
    GammaAct = new QAction("Zmiana gammy");


    editMenu->addAction(edgeAct);
    editMenu->addAction(monoAct);
    editMenu->addAction(scaleAct);
    editMenu->addAction(fastMonoAct);
    editMenu->addAction(mixerMonoKolorAct);
    editMenu->addAction(ThresholdAct);
    editMenu->addAction(SettColorAct);
    editMenu->addAction(InverseColorAct);
    editMenu->addAction(BrightAct);
    editMenu->addAction(ContrastAct);
    editMenu->addAction(GammaAct);

    connect(edgeAct, &QAction::triggered, this, &MainWindow::edgeDetect);
    connect(monoAct, &QAction::triggered, this, &MainWindow::Mono);
    connect(scaleAct, &QAction::triggered, this, &MainWindow::scaleImg);
    connect(fastMonoAct, &QAction::triggered, this, &MainWindow::FastMono);
    connect(mixerMonoKolorAct, &QAction::triggered, this, &MainWindow::MonoKolor);
    connect(ThresholdAct, &QAction::triggered, this, &MainWindow::Threshold);
    connect(SettColorAct, &QAction::triggered, this, &MainWindow::SettColor);
    connect(InverseColorAct, &QAction::triggered, this, &MainWindow::InverseColor);
    connect(BrightAct, &QAction::triggered, this, &MainWindow::Bright);
    connect(ContrastAct, &QAction::triggered, this, &MainWindow::Contrasst);
    connect(GammaAct, &QAction::triggered, this, &MainWindow::Gammma);


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

    pencilAct = toolbar.pencilAct;
    brushAct = toolbar.brushAct;
    fillAct = toolbar.fillAct;
    pasteAct = toolbar.pasteAct;
    copyAct = toolbar.copyAct;
    lineAct = toolbar.lineAct;


    connect(pencilAct, &QAction::triggered, this, &MainWindow::selectPencil);
    connect(brushAct, &QAction::triggered, this, &MainWindow::selectBrush);
    //connect(colorAct, &QAction::triggered, this, &MainWindow::selectColor);
    connect(fillAct, &QAction::triggered, this, &MainWindow::selectFill);
    connect(pasteAct, &QAction::triggered, this, &MainWindow::selectPaste);
    connect(copyAct, &QAction::triggered, this, &MainWindow::selectCopy);
    connect(lineAct, &QAction::triggered, this, &MainWindow::selectLine);

}

void MainWindow::selectCopy()
{
    canvas->setCurrentTool(new ClipCopy());
}

void MainWindow::selectLine()
{
    canvas->setCurrentTool(new Line());
}

void MainWindow::selectPaste()
{
    canvas->setCurrentTool(new Paste());
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

void MainWindow::save()
{
    canvas->saveImage();
}

void MainWindow::newFile()
{
    //NewFileDialog dialog;
    //dialog.exec();
    canvas->newImage(600,600);
}

void MainWindow::scaleImg()
{
    canvas->resizeImage(100,100);
}

void MainWindow::createImg(int x, int y)
{
    canvas->newImage(x,y);
}

void MainWindow::FastMono()
{
    canvas->convert2FastMono();
}

void MainWindow::MonoKolor()
{
    MixerDialog mixerDialog;
    mixerDialog.setModal(true);

    int r,g,b,u;

    if(mixerDialog.exec()==1){
        r = mixerDialog.setR();
        g = mixerDialog.setG();
        b = mixerDialog.setB();
        u = mixerDialog.setU();
        canvas->mixerMonoKolor(r,g,b,u);
    }
}

void MainWindow::Threshold()
{
    ThresholdDialoh threshhold;
    threshhold.setModal(true);

    int u;

    if(threshhold.exec()==1){
        u = threshhold.setU();
        canvas->thresholding(u);
    }
}

void MainWindow::SettColor()
{
    selectColorDialog select;
    select.setModal(true);

    int r,g,b;

    if(select.exec()==1){
        r = select.setR();
        g = select.setG();
        b = select.setB();
        canvas->SettingColor(r,g,b);
    }
}

void MainWindow::InverseColor()
{
    canvas->InversingColor();
}

void MainWindow::Bright()
{
    BrightnessDialog brightness;
    brightness.setModal(true);

    int br;

    if(brightness.exec()==1){
        br = brightness.setBr();
        canvas->Brightness(br);
    }
}

void MainWindow::Contrasst()
{
    ContrastDialog contrast;
    contrast.setModal(true);

    int k;

    if(contrast.exec()==1){
        k = contrast.setK();
        canvas->Contrast(k);
    }
}

void MainWindow::Gammma()
{
    GammaDialog gamma;
    gamma.setModal(true);

    int gam;

    if(gamma.exec()==1){
        gam = gamma.setGam();
        canvas->Gamma(gam);
    }
}
