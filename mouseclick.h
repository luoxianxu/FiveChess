#ifndef MOUSECLICK_H
#define MOUSECLICK_H

#include<mywidget.h>
class MyWidget:public mouseclick{
    Q_OBJECT
public:
    explicit mouseclick(QWidget *parent = 0);
         ~mouseclick();
protected:
    virtual void mousePressEvent(QMouseEvent *event);
signals:
    void mouseclicked();
};

#endif // MOUSECLICK_H
