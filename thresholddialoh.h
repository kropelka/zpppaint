#ifndef THRESHOLDDIALOH_H
#define THRESHOLDDIALOH_H

#include <QDialog>

namespace Ui {
class thresholdDialoh;
}

class ThresholdDialoh : public QDialog
{
    Q_OBJECT

public:
    explicit ThresholdDialoh(QWidget *parent = 0);
    ~ThresholdDialoh();

public slots:
    int setU();

private:
    Ui::thresholdDialoh *ui;
};

#endif // THRESHOLDDIALOH_H
