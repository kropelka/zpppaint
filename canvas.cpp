﻿#include "canvas.h"
#include "pencil.h"
#include <iostream>


Canvas::Canvas(QWidget *parent)
{
    currentTool = new Pencil(); // nawet jeżeli coś pójdzie nie tak, to jako fallback będzie zwykły ołówek
}

void Canvas::loadImage(const QString &filename)
{
    image.load(filename);
}

void Canvas::newImage(int width, int height)
{
    QImage newImage(width,height, QImage::Format_RGB32);
    newImage.fill(Qt::white);
    image = newImage;
}

int Canvas::getWidth()
{
    return image.width();
}

int Canvas::getHeight()
{
    return image.height();
}

void Canvas::detectEdges()
{
    copyImage(image);
    scaleValues(false);
    edgeDetection();
    image = imOut;
    update();
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    lastPoint = event->pos();
    currentlyDrawing = true;
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() && currentlyDrawing)
    {
        currentTool->draw(image, lastPoint, event->pos());
        //painter.drawPoint(lastPoint);
        update(QRect(lastPoint, event->pos()).normalized());
        lastPoint = event->pos();
        update();  //dzięki temu updatowi nie ma przerw pomiędzy rysowanymi liniami
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->buttons() && currentlyDrawing)
    {
        //QPainter painter(&image);
        //painter.drawLine(lastPoint, event->pos());
        currentTool->draw(image, lastPoint, event->pos());
        update(QRect(lastPoint, event->pos()).normalized());
        lastPoint = event->pos();
    }
    currentlyDrawing = false;
}

void Canvas::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
}

void Canvas::copyImage(QImage source)
{
    im = source;
    im.convertToFormat(QImage::Format_RGB32);
}

void Canvas::convert2Mono()
{
    QColor rgb;
    int r,g,b;
    int grey;

    for(unsigned int i = 0; i < im.width(); i++){
        for(unsigned int j = 0; j < im.height(); j++){
            rgb = im.pixelColor(i,j);
            r = rgb.red();
            g = rgb.green();
            b = rgb.blue();
            grey = round((r+g+b)/3);
            rgb.setRed(grey);
            rgb.setGreen(grey);
            rgb.setBlue(grey);
        }
    }

}

void Canvas::findMax()
{
    QColor rgb;
    int grey;
    int max = 0;

    for(unsigned int i = 0; i < im.width(); i++){
        for(unsigned int j = 0; j < im.height(); j++){
            rgb = im.pixelColor(i,j);
            grey = rgb.red();
            if (grey > max){
                max = grey;
            }
        }
    }

    maxVal = max;
}

void Canvas::findMin()
{
    QColor rgb;
    int grey;
    int min = 255;

    for(unsigned int i = 0; i < im.width(); i++){
        for(unsigned int j = 0; j < im.height(); j++){
            rgb = im.pixelColor(i,j);
            grey = rgb.red();
            if (grey < min){
                min = grey;
            }
        }
    }

    minVal = min;
}

void Canvas::scaleValues(bool mono)
{
    double tmp;
    int newValue;
    QColor color;

    convert2Mono();
    findMin();
    findMax();

    for(unsigned int i = 0; i < im.width(); i++){
        for(unsigned int j = 0; j < im.height(); j++){
            color = im.pixelColor(i,j);
            tmp = (double)(color.red() - minVal)/(maxVal - minVal);
            newValue = round(tmp*255);
            color.setRgb(newValue,newValue,newValue);
            im.setPixelColor(i,j,color);
        }
    }

    if (mono == true){
        image = im;
        update();
    }
}

void Canvas::edgeDetection()
{
    std::vector <std::vector< unsigned char >> tab;
    std::vector <std::vector< unsigned char >> tab2;
    std::vector < unsigned char > tmp;
    int xG = 0, yG = 0;
    int width,height;
    int tmpColor;
    QColor color;

    width = im.width();
    height = im.height();

    QImage tmpImage(im.width(),im.height(),QImage::Format_RGB32);

    tmpImage = im;

    for(unsigned int k = 0; k < width; k++){
        for(unsigned int l = 0; l < height; l++){
            color = tmpImage.pixelColor(k,l);
            tmp.push_back(static_cast<unsigned char>(color.red()));
        }
        tab.push_back(tmp);
        tab2.push_back(tmp);
        tmp.clear();
    }

    for(unsigned int i = 0; i < width; i++){
        for(unsigned int j = 0; j < height; j++){

            if((i<(width-1)) && (j < (height -1))
                    && (i > 0) && (j > 0)){

                xG = (tab[i+1][j-1]
                        + (2* tab[i+1][j])
                        + tab[i+1][j+1]
                            - tab[i-1][j-1]
                                - (2* tab[i-1][j])
                                - tab[i-1][j+1]);

                yG = (tab[i-1][j+1]
                        + (2* tab[i][j+1])
                        + tab[i+1][j+1]
                            - tab[i-1][j-1]
                                - (2* tab[i][j-1])
                                - tab[i+1][j-1]);

                tmpColor = sqrt((xG * xG) + (yG * yG));

                if (tmpColor > 255){
                    tmpColor = 255;
                }

                tab2[i][j] = tmpColor;
            } else{
                tmpColor = 0;
                tab2[i][j] = tmpColor;
            }

        }
    }

    for(unsigned int i = 0; i < width; i++){
        for(unsigned int j = 0; j < height; j++){
            tmpColor = tab2[i][j];
            color.setRgb(tmpColor,tmpColor,tmpColor);
            tmpImage.setPixelColor(i,j,color);
         }
    }


    imOut = tmpImage;
}

void Canvas::setCurrentTool(Tool *tool)
{
    currentTool = tool;
}



