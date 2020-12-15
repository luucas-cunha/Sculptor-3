#include "dialog.h"
#include "ui_dialog.h"
#include <algorithm>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog(){
    delete ui;
}

int Dialog::getDimX(){
    return ui->horizontalSliderX->value();
}

int Dialog::getDimY(){
    return ui->horizontalSliderY->value();
}

int Dialog::getDimZ(){
    return ui->horizontalSliderZ->value();
}


