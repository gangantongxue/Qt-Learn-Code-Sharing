#include "ShapeWidget.h"
#include<QMouseEvent>
#include<QPainter>
#include<QPixmap>
#include<QBitmap>

ShapeWidget::ShapeWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    QPixmap pix;
    //Ϊpix���ͼƬ��0��ʾ����Ĭ�ϸ�ʽ����Ϊ��ȡͼƬ�ķ�ʽ
    pix.load("312.png", 0, Qt::AvoidDither | Qt::ThresholdDither | Qt::ThresholdAlphaDither);
    resize(pix.size());
    //Ϊ�ռ�����һ�����֣���ס��ѡ��������Ĳ���ʹ�俴����͸��
    setMask(QBitmap(pix.mask()));
}

ShapeWidget::~ShapeWidget()
{}

void ShapeWidget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
    if (event->button() == Qt::RightButton) {
        close();
    }
}

void ShapeWidget::mouseMoveEvent(QMouseEvent* event) {
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}

void ShapeWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap("312.png"));
}
