#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMouseEvent>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    setAttribute(Qt::WA_TranslucentBackground);
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QPixmap pix;
    pix.load("F:/QT_test/06_Shape/Image/OnePiece.png");
    p.drawPixmap(0, 0, width(), height(), pix);
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    if (Qt::RightButton == e->button())
    {
        //如果是右键，就关闭当前窗口
        this->close();
    }
    else if (Qt::LeftButton == e->button())
    {
        //求坐标差值
        //当前点击的坐标 - 窗口左上角坐标
        point = e->globalPos() - this->frameGeometry().topLeft();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() & Qt::LeftButton)
    {
        move(e->globalPos() - point);
    }
}

Widget::~Widget()
{
    delete ui;
}
