#include "canvas.h"
#include "pencil.h"


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
    scaleValues();
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
    imageSize = im.width() * im.height();
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

void Canvas::scaleValues()
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
            color.setRed(newValue);
            color.setGreen(newValue);
            color.setBlue(newValue);
            im.setPixelColor(i,j,color);
        }
    }
}

void Canvas::edgeDetection()
{
    int * tab = new int[imageSize];
    int * tab2 = new int[imageSize];
    int x = 0, y = 0;
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
            tab[(l+(k*width))] = color.red();
        }
    }

    for(unsigned int i = 0; i < imageSize; i++){
        x = i % width;

        if(i != 0 && x == 0){

            y++;

        }

        if((x < (width - 1)) && (y < (height - 1))
                && (y > 0) && (x > 0)){

            xG = (tab[(x+1) + ((y-1) * width)]
                         + (2 * tab[(x+1) + (y * width)])
                         + tab[(x+1) + ((y+1) * width)]
                                  - tab[(x-1) + ((y-1) * width)]
                                           - (2 * tab[(x-1) + (y * width)])
                                           - tab[(x-1) + ((y+1) * width)]);

            yG = (tab[(x-1) + ((y+1) * width)]
                         + (2 * tab[(x) + ((y + 1) * width)])
                         + tab[(x+1) + ((y+1) * width)]
                                  - tab[(x-1) + ((y-1) * width)]
                                           - (2 * tab[(x) + ((y-1) * width)])
                                           - tab[(x+1) + ((y-1) * width)]);

            tmpColor = sqrt((xG * xG) + (yG * yG));
            tab2[i] = tmpColor;
        }else{
            tmpColor = 0;
            tab2[i] = tmpColor;
        }

    }

    for(unsigned int i = 0; i < width; i++){
        for(unsigned int j = 0; j < height; j++){
            tmpColor = tab2[(j+(i*width))];
            color.setRgb(tmpColor,tmpColor,tmpColor);
            tmpImage.setPixelColor(i,j,color);
        }
    }

    delete [] tab;
    delete [] tab2;

    imOut = tmpImage;
}

void Canvas::setCurrentTool(Tool *tool)
{
    currentTool = tool;
}



