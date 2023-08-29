#ifndef MYWIDGET_H
#define MYWIDGET_H

#include<QWidget>
#include<QPushButton>
#include<QPainter>
#include<QPainterPath>
#include<QDebug>
#include<QMouseEvent>
#include<QBrush>
//#define max  500


#define radius 10           //棋子半径
#define Space  20          //棋盘间隔
#define broad_length   32  //棋盘长度
#define broad_width    40  //棋盘宽度


namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:

    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

    int pos_x;                 //鼠标点击的x坐标
    int pos_y;                 //鼠标点击的y坐标
    int quantity=0;

    QPoint point[5000];
    int length=0;

    int vertical=1;
    int level=2;
    int oblique_left=3;
    int oblique_rigth=4;

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void draw_broad();
    void Play_Chess();
    void judge_to_win(QPoint &add,int dir);

signals:
    void tigger();

public slots:
    void setwindow();


private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
