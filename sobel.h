#ifndef SOBEL_H
#define SOBEL_H

#include <QWidget>


/*
 *  Implementacja algorytmu wykrywania krawędzi Sobel'a
*/

class Sobel
{
    Q_OBJECT
public:
    explicit Sobel();
    void loadImage(const QString& filename);
    void copyImage(QImage source);
    void findMax();
    void findMin();
    void scaleValues();
    void convert2Mono();
    void edgeDetection();

protected:
    QImage im,imOut;

private:
    int imageSize;
    int minVal, maxVal;

signals:

public slots:
};

#endif // SOBEL_H
