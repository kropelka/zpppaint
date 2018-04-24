#include "sobel.h"

Sobel::Sobel()
{

}

void Sobel::loadImage(const QString &filename)
{
    im.load(filename);
}

void Sobel::copyImage(QImage source)
{
    im = source;
    imageSize = im.width() * im.height();
}

void Sobel::convert2Mono()
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

void Sobel::findMax()
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

void Sobel::findMin()
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

void Sobel::scaleValues()
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

void Sobel::edgeDetection()
{
    int tab[imageSize];
    int tab2[imageSize];
    int x = 0, y = 0;
    int xG = 0, yG = 0;
    int width;
    int tmpColor;
    QColor color;

    width = im.width();

    QImage tmpImage(im.width(),im.height(),QImage::Format_RGB32);

    tmpImage = im;

    for(unsigned int k = 0; k < im.width(); k++){
        for(unsigned int l = 0; l < im.height(); l++){
            color = tmpImage.pixelColor(k,l);
            tab[(l+(k*width))] = color.red();
        }
    }

    for(unsigned int i = 0; i < imageSize; i++){
        x = i % width;

        if(i != 0 && x == 0){

            y++;

        }

        if(x < (width - 1) && y < (height - 1)
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

    for(unsigned int i = 0; i < im.width(); i++){
        for(unsigned int j = 0; j < im.height(); j++){
            tmpColor = tab2[(j+(i*width))];
            color.setRgb(tmpColor,tmpColor,tmpColor);
            tmpImage.setPixelColor(i,j,color);
        }
    }

    imOut = tmpImage;

}




