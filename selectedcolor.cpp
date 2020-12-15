#include "selectedcolor.h"
#include <QPainter>
#include <QBrush>
#include <QPen>

SelectedColor::SelectedColor(QWidget *parent) : QWidget(parent){
    r = 0;
    g = 0;
    b = 0;
    a = 255;
}

void SelectedColor::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(r, g, b, a));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(0, 0, 0));
    pen.setWidth(2);

    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRect(0, 0, width(), height());
}

void SelectedColor::selectedRed(int red){
    r = red;
    repaint();
}

void SelectedColor::selectedGreen(int green){
    g = green;
    repaint();
}

void SelectedColor::selectedBlue(int blue){
    b = blue;
    repaint();
}

void SelectedColor::selectedAlpha(int alpha){
    a = alpha;
    repaint();
}
