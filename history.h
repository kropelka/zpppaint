#ifndef HISTORY_H
#define HISTORY_H

#include <QObject>
#include <QMainWindow>
#include <QWidget>
#include <QPixmap>
class history
{
public:
    QPixmap p[10];
    QString s[10];
    int pos;
    history();
    void add(QString name,QPixmap pix);
};

#endif // HISTORY_H
