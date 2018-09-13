#ifndef CANVAS_H
#define CANVAS_H
#include<QWidget>
#include<QImage>
#include<QPainter>
#include<QRect>
#include<QPaintEvent>
#include<QPoint>
#include "tool.h"
#include "colorpicker.h"

class Canvas : public QWidget
{
    Q_OBJECT
public:
    Canvas(QWidget *parent = 0);
    void loadImage(const QString& filename);
    void saveImage();
    void newImage(int width, int height);
    int getWidth();
    int getHeight();
    void detectEdges();
    void copyImage(QImage source);
    void resizeImage(int x, int y);
    void findMax();
    void findMin();
    void scaleValues(bool mono);
    void convert2Mono();
    void edgeDetection();
    void convert2FastMono();
    void mixerMonoKolor(int setr, int setg, int setb, int setu);
    void thresholding(int u);
    void SettingColor(int setr, int setg, int setb);
    void InversingColor();
    void Brightness(int jasnosc);
    void Contrast(int kontrast);
    void Gamma(int gamma);
    void setCurrentTool(Tool *tool);
    Tool *getCurrentTool();
    ColorPicker *colorPicker;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    QImage im,imOut;
    int minVal, maxVal;
    QImage image;
    QPoint lastPoint;
    bool currentlyDrawing;
    Tool *currentTool;
};

#endif // CANVAS_H
