#include <cstdlib>
#include <QDialog>
#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "plotter.h"
#include "sculptor.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	ui->horizontalSliderDimensionX->setValue(0);
    ui->horizontalSliderDimensionX->setMaximum(ui->widgetPlotter->getDimX() - 1);
    ui->horizontalSliderDimensionY->setValue(0);
    ui->horizontalSliderDimensionY->setMaximum(ui->widgetPlotter->getDimY() - 1);
    ui->horizontalSliderDimensionZ->setValue(0);
    ui->horizontalSliderDimensionZ->setMaximum(ui->widgetPlotter->getDimZ() - 1);

    ui->horizontalSliderRadius->setValue(0);
    ui->horizontalSliderRadius->setMaximum(ui->widgetPlotter->getMinDim() / 2 - 1);

    ui->horizontalSliderRadiusX->setValue(0);
    ui->horizontalSliderRadiusX->setMaximum((ui->widgetPlotter->getDimX() / 2) - 1);
    ui->horizontalSliderRadiusY->setValue(0);
    ui->horizontalSliderRadiusY->setMaximum((ui->widgetPlotter->getDimY() / 2) - 1);
    ui->horizontalSliderRadiusZ->setValue(0);
    ui->horizontalSliderRadiusZ->setMaximum((ui->widgetPlotter->getDimZ() / 2) - 1);

    ui->horizontalSliderDepth->setValue(0);
    ui->horizontalSliderDepth->setMaximum(ui->widgetPlotter->getDimZ() - 1);
	
	// Desenho
    connect(ui->actionPutVoxel,
                    SIGNAL(triggered(bool)),
                    ui->widgetPlotter,
                    SLOT(putVoxel()));

    connect(ui->actionCutVoxel,
                    SIGNAL(triggered(bool)),
                    ui->widgetPlotter,
                    SLOT(cutVoxel()));

    connect(ui->actionPutBox,
                    SIGNAL(triggered(bool)),
                    ui->widgetPlotter,
                    SLOT(putBox()));

    connect(ui->actionCutBox,
                    SIGNAL(triggered(bool)),
                    ui->widgetPlotter,
                    SLOT(cutBox()));

    connect(ui->actionPutSphere,
                    SIGNAL(triggered(bool)),
                    ui->widgetPlotter,
                    SLOT(putSphere()));

    connect(ui->actionCutSphere,
                    SIGNAL(triggered(bool)),
                    ui->widgetPlotter,
                    SLOT(cutSphere()));

    connect(ui->actionPutEllipsoid,
                    SIGNAL(triggered(bool)),
                    ui->widgetPlotter,
                    SLOT(putEllipsoid()));

    connect(ui->actionCutEllipsoid,
                    SIGNAL(triggered(bool)),
                    ui->widgetPlotter,
                    SLOT(cutEllipsoid()));
	// Dimensões da caixa e raios das esferas e elipsóides
    connect(ui->horizontalSliderDimensionX,
                    SIGNAL(valueChanged(int)),
                    ui->widgetPlotter,
                    SLOT(changeDimensionX(int)));

    connect(ui->horizontalSliderDimensionY,
                    SIGNAL(valueChanged(int)),
                    ui->widgetPlotter,
                    SLOT(changeDimensionY(int)));

    connect(ui->horizontalSliderDimensionZ,
                    SIGNAL(valueChanged(int)),
                    ui->widgetPlotter,
                    SLOT(changeDimensionZ(int)));

    connect(ui->horizontalSliderRadius,
                    SIGNAL(valueChanged(int)),
                    ui->widgetPlotter,
                    SLOT(changeRadius(int)));

    connect(ui->horizontalSliderRadiusX,
                    SIGNAL(valueChanged(int)),
                    ui->widgetPlotter,
                    SLOT(changeRadiusX(int)));

    connect(ui->horizontalSliderRadiusY,
                    SIGNAL(valueChanged(int)),
                    ui->widgetPlotter,
                    SLOT(changeRadiusY(int)));

    connect(ui->horizontalSliderRadiusZ,
                    SIGNAL(valueChanged(int)),
                    ui->widgetPlotter,
                    SLOT(changeRadiusZ(int)));
	// Cores
    connect(ui->horizontalSliderRed,
                    SIGNAL(valueChanged(int)),
                    ui->widgetPlotter,
                    SLOT(changeRed(int)));
					
    connect(ui->horizontalSliderRed,
                    SIGNAL(valueChanged(int)),
                    ui->widgetSelectedColor,
                    SLOT(selectedRed(int)));
					
    connect(ui->horizontalSliderGreen,
                    SIGNAL(valueChanged(int)),
                    ui->widgetPlotter,
                    SLOT(changeGreen(int)));
					
    connect(ui->horizontalSliderGreen,
                    SIGNAL(valueChanged(int)),
                    ui->widgetSelectedColor,
                    SLOT(selectedGreen(int)));
					
    connect(ui->horizontalSliderBlue,
                    SIGNAL(valueChanged(int)),
                    ui->widgetPlotter,
                    SLOT(changeBlue(int)));

    connect(ui->horizontalSliderBlue,
                    SIGNAL(valueChanged(int)),
                    ui->widgetSelectedColor,
                    SLOT(selectedBlue(int)));
					
    connect(ui->horizontalSliderAlpha,
                    SIGNAL(valueChanged(int)),
                    ui->widgetPlotter,
                    SLOT(changeAlpha(int)));
					
    connect(ui->horizontalSliderAlpha,
                    SIGNAL(valueChanged(int)),
                    ui->widgetSelectedColor,
                    SLOT(selectedAlpha(int)));					
	// Profundidade
    connect(ui->horizontalSliderDepth,
                    SIGNAL(valueChanged(int)),
                    ui->widgetPlotter,
                    SLOT(changeDepth(int)));
	// Novo arquivo e salvar
    connect(ui->actionNew,
                    SIGNAL(triggered(bool)),
                    ui->widgetPlotter,
                    SLOT(newSculptor()));
					
	connect(ui->actionNew,
					SIGNAL(triggered(bool)),
					this,
					SLOT(updateSliders()));
					
	connect(ui->actionSave,
					SIGNAL(triggered(bool)),
					ui->widgetPlotter,
					SLOT(saveFile()));	
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::updateSliders(){
    ui->horizontalSliderDimensionX->setValue(0);
    ui->horizontalSliderDimensionX->setMaximum(ui->widgetPlotter->getDimX() - 1);
    ui->horizontalSliderDimensionY->setValue(0);
    ui->horizontalSliderDimensionY->setMaximum(ui->widgetPlotter->getDimY() - 1);
    ui->horizontalSliderDimensionZ->setValue(0);
    ui->horizontalSliderDimensionZ->setMaximum(ui->widgetPlotter->getDimZ() - 1);

    ui->horizontalSliderRadius->setValue(0);
    ui->horizontalSliderRadius->setMaximum(ui->widgetPlotter->getMinDim() / 2 - 1);

    ui->horizontalSliderRadiusX->setValue(0);
    ui->horizontalSliderRadiusX->setMaximum((ui->widgetPlotter->getDimX() / 2) - 1);
    ui->horizontalSliderRadiusY->setValue(0);
    ui->horizontalSliderRadiusY->setMaximum((ui->widgetPlotter->getDimY() / 2) - 1);
    ui->horizontalSliderRadiusZ->setValue(0);
    ui->horizontalSliderRadiusZ->setMaximum((ui->widgetPlotter->getDimZ() / 2) - 1);

    ui->horizontalSliderDepth->setValue(0);
    ui->horizontalSliderDepth->setMaximum(ui->widgetPlotter->getDimZ() - 1);	
}

void MainWindow::on_actionExit_triggered(){
	QMessageBox msgBox;
	QString mensagem = "Tem certeza que deseja sair?";
	QString titulo = "Sair - Escultor 3D";
	
	msgBox.setWindowTitle(titulo);
	msgBox.setIcon(QMessageBox::Question);
	msgBox.setText(mensagem);
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Cancel);
	
	if(msgBox.exec() == QMessageBox::Ok){
		exit(0);
	}
}
