#include "mouseclick.h"
void mouseclick::mouseclick(){

}
void mouseclick::~mouseclick(){

}
void mouseclick::mouseclicked(){
    int x=event->x()%20;
    int y=event->y()%20;
    if(x<=radius)
        pos_x=event->x()-x;
    else if(x>=Space-radius)
        pos_x=event->x()+Space-x;
    if(y<=radius)
        pos_y=event->y()-y;
    else if(y>=Space-radius)
        pos_y=event->y()+Space-y;
}

void mouseclick::mousePressEvent(QMouseEvent *event){
    if(event->button==Qt::LeftButton)
    {
        emit mouseclicked();
    }
}
