#include "history.h"

history::history()
{
pos =0;
}

void history::add(QString name,QPixmap pix)
{
    if(pos<9)
    {
        p[pos] = pix;
        s[pos] = name;
        pos++;
    }
    else
    {
        for(int i=1;i<10;i++)
        {
            p[i-1]= p[i];
            s[i-1] =s[i];
        }
        p[pos] = pix;
        s[pos] = name;

    }

}


