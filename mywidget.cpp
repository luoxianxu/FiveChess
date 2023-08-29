#include "mywidget.h"
#include "ui_mywidget.h"
#include<QPushButton>
#include<QPainter>
#include<QMouseEvent>
#include<QDebug>
#include<QRect>
#include<QPen>
#include<QBrush>
#include<QMessageBox>

int flag_arr[broad_length*Space][broad_width*Space]={0};

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    resize(640,640);
    connect(this,&MyWidget::tigger,this,&MyWidget::setwindow);

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::paintEvent(QPaintEvent *)
{
    draw_broad();
    Play_Chess();
    update();
}

void MyWidget::mousePressEvent(QMouseEvent *event){
    int x=event->x()%20;
    int y=event->y()%20;
    if(x<radius)
        pos_x=event->x()-x;
    else if(x>=Space-radius)
        pos_x=event->x()+Space-x;
    if(y<radius)
        pos_y=event->y()-y;
    else if(y>=Space-radius)
        pos_y=event->y()+Space-y;
    qDebug()<<pos_x;
    qDebug()<<pos_y;
    if(flag_arr[pos_x][pos_y]==0){
        point[length++]=QPoint(pos_x,pos_y);
        if(length%2==0)
            flag_arr[pos_x][pos_y]=1;
        else flag_arr[pos_x][pos_y]=2;
    }
    else qDebug()<<"此处已被下子！";
    judge_to_win(point[length-1],level);
    judge_to_win(point[length-1],vertical);
    judge_to_win(point[length-1],oblique_left);
    judge_to_win(point[length-1],oblique_rigth);

}

void MyWidget::draw_broad(){
    QPainter painter(this);
    QBrush brush;
    resize(640,640);
    for(int i=0;i<broad_length;i++)
    {
        for(int j=0;j<broad_width;j++)
            painter.drawLine(i*Space,0,i*Space,j*Space);
        painter.drawLine(0,i*Space,640,i*Space);
    }
}

void MyWidget::Play_Chess(){
    QPainter painter(this);
    QBrush brush;
    for(int i=0;i<length;i++){
        if(i%2==0)
            brush.setColor(Qt::black);
        else brush.setColor(Qt::white);
        brush.setStyle(Qt::SolidPattern);
        painter.setBrush(brush);
        painter.drawEllipse(point[i],radius-2,radius-2);
    }
}

void MyWidget::judge_to_win(QPoint &add,int dir){
    int x=add.rx();
    int y=add.ry();
    int flag=flag_arr[x][y];

    int num_level=1;
    switch(dir){
        case 1:
            y+=Space;
            while(flag_arr[x][y]==flag)
            {
                qDebug()<<"x="<<x;
                qDebug()<<"y="<<y;
                qDebug()<<flag;
                num_level++;
                qDebug()<<num_level;
                y+=Space;
                if(num_level>=5){
                    if(flag==1)
                        qDebug()<<"white win!";
                    if(flag==2)
                        qDebug()<<"black win!";
                    emit tigger();
                }

            }
            y=add.ry()-Space;
            while(flag_arr[x][y]==flag){
                qDebug()<<"x="<<x;
                qDebug()<<"y="<<y;
                qDebug()<<flag;
                num_level++;
                y-=Space;
                if(num_level>=5){
                    if(flag==1)
                        qDebug()<<"white win!";
                    if(flag==2)
                        qDebug()<<"black win!";
                    emit tigger();
                }
            }
        break;
        case 2:
            x+=Space;
            while(flag_arr[x][y]==flag)
            {
                qDebug()<<"x="<<x;
                qDebug()<<"y="<<y;
                qDebug()<<flag;
                num_level++;
                x+=Space;
                if(num_level>=5){
                    if(flag==1)
                        qDebug()<<"white win!";
                    if(flag==2)
                        qDebug()<<"black win!";
                    emit tigger();
                }
            }
            x=add.rx()-Space;
            while(flag_arr[x][y]==flag){
                qDebug()<<"x="<<x;
                qDebug()<<"y="<<y;
                qDebug()<<flag;
                num_level++;
                x-=Space;
                if(num_level>=5){
                    if(flag==1)
                        qDebug()<<"white win!";
                    if(flag==2)
                        qDebug()<<"black win!";
                    emit tigger();
                }
            }
        break;
        case 3:
            x+=Space;
            y+=Space;
            while(flag_arr[x][y]==flag)
            {
                qDebug()<<"x="<<x;
                qDebug()<<"y="<<y;
                qDebug()<<flag;
                num_level++;
                x+=Space;
                y+=Space;
                if(num_level>=5){
                    if(flag==1)
                        qDebug()<<"white win!";
                    if(flag==2)
                        qDebug()<<"black win!";
                    emit tigger();
                }
            }
            x=add.rx()-Space;
            y=add.ry()-Space;
            while(flag_arr[x][y]==flag){
                qDebug()<<"x="<<x;
                qDebug()<<"y="<<y;
                qDebug()<<flag;
                num_level++;
                x-=Space;
                y-=Space;
                if(num_level>=5){
                    if(flag==1)
                        qDebug()<<"white win!";
                    if(flag==2)
                        qDebug()<<"black win!";
                    emit tigger();
                }
            }
        break;
        case 4:
            x+=Space;
            y-=Space;
            while(flag_arr[x][y]==flag)
            {
                qDebug()<<"x="<<x;
                qDebug()<<"y="<<y;
                qDebug()<<flag;
                num_level++;
                x+=Space;
                y-=Space;
                if(num_level>=5){
                    if(flag==1)
                        qDebug()<<"white win!";
                    if(flag==2)
                        qDebug()<<"black win!";
                    emit tigger();
                }
            }
            x=add.rx()-Space;
            y=add.ry()+Space;
            while(flag_arr[x][y]==flag){
                qDebug()<<"x="<<x;
                qDebug()<<"y="<<y;
                qDebug()<<flag;
                num_level++;
                x-=Space;
                y+=Space;
                if(num_level>=5){
                    if(flag==1)
                        qDebug()<<"white win!";
                    if(flag==2)
                        qDebug()<<"black win!";
                    emit tigger();
                }
            }
        break;
    }
//    connect(this,&MyWidget::tigger,this,&MyWidget::setwindow);
}

void MyWidget::setwindow(){
    QMessageBox *box=new QMessageBox;
    box->setButtonText(1,"确认");
    box->setWindowTitle("注意");
    box->setText("游戏结束");
    connect(box,&QMessageBox::buttonClicked,this,&MyWidget::close);
    box->show();
}
