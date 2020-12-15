#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QMessageBox>
#include <QString>
#include <QMouseEvent>
#include <QDialog>
#include <algorithm>
#include "plotter.h"
#include "dialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sculptor.h"

Plotter::Plotter(QWidget *parent) : QWidget(parent){
    dimX = 30;
    dimY = 30;
    dimZ = 30;

    s = new Sculptor(dimX, dimY, dimZ);

    boxSizeX  = 0;
    boxSizeY = 0;
    boxSizeZ = 0;
    radius = 0;
    radiusX = 0;
    radiusY = 0;
    radiusZ = 0;
	slice = 0;
	
    r = 0;
    g = 0;
    b = 0;
    a = 255;

    action = 0;
}

void Plotter::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(255, 255, 255));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(0, 0, 0));
    pen.setWidth(2);

	if(dimX == dimY){
		painter.translate(0, height());
		painter.scale(1.0, -1.0);		
	}
	
    painter.setBrush(brush);
    painter.setPen(pen);

    v.clear();

    v = s->createGrid(slice);

    int dim1 = width() / v[0].size();
    int dim2 = height() / v.size();

    if(dim1 > dim2){
        cellSize = dim2;
    } else {
        cellSize = dim1;
    }

    for(unsigned int x = 0; x < v.size(); x++){
        for(unsigned int y = 0; y < v[0].size(); y++){
            painter.drawRect(x * cellSize, y * cellSize, cellSize, cellSize);
        }
    }
	
    for(unsigned int x = 0; x < v.size(); x++){
        for(unsigned int y = 0; y < v[0].size(); y++){
            if(v[x][y].isOn){
                brush.setColor(QColor(v[x][y].r, v[x][y].g, v[x][y].b, v[x][y].a));
                brush.setStyle(Qt::SolidPattern);
                painter.setBrush(brush);
                painter.drawEllipse(x * cellSize, y * cellSize, cellSize, cellSize);
            }
        }
    }
}

void Plotter::mouseMoveEvent(QMouseEvent *event){
    mouseX = (event->x()) / cellSize;
    mouseY = (event->y()) / cellSize;
	
	if(dimX == dimY){
		posX = mouseX;
		posY = dimY - mouseY - 1;
		posZ = slice;	
	} else {
		posX = mouseX;
		posY = mouseY;
		posZ = slice;		
	}
	
    draw(action, mousePressed);
}

void Plotter::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        mousePressed = true;
        mouseX = (event->x()) / cellSize;
        mouseY = (event->y()) / cellSize;
		
		if(dimX == dimY){
			posX = mouseX;
			posY = dimY - mouseY - 1;
			posZ = slice;	
		} else {
			posX = mouseX;
			posY = mouseY;
			posZ = slice;		
		}		

        draw(action, mousePressed);
    }
}

void Plotter::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        mousePressed = false;
    }
}

void Plotter::draw(int action, bool mousePressed){
    if(mousePressed){
        switch(action){
            case 1: // putVoxel
				s->setColor(r, g, b, a);
				s->putVoxel(posX, posY, posZ);  
            break;
            case 2: // cutVoxel
				s->cutVoxel(posX, posY, posZ); 
            break;
            case 3: // putBox
				if(boxSizeX > 0 && boxSizeY > 0 && boxSizeZ > 0) {
					s->setColor(r, g, b, a);
					s->putBox(posX, (posX + boxSizeX) - 1, posY, (posY - boxSizeY) - 1, posZ, (posZ + boxSizeZ) - 1);
				}
            break;
            case 4: // cutBox
				if(boxSizeX > 0 && boxSizeY > 0 && boxSizeZ > 0){
					s->cutBox(posX, (posX + boxSizeX) - 1, posY, (posY - boxSizeY) - 1, posZ, (posZ + boxSizeZ) - 1);
				}     
            break;
            case 5: // putSphere
				if(radius > 0){
					s->setColor(r, g, b, a);
					s->putSphere(posX, posY, posZ, radius);
				}
            break;
            case 6: // cutSphere
				if(radius > 0){
					s->cutSphere(posX, posY, posZ, radius);
				}
            break;
            case 7: // putEllipsoid
				if(radiusX > 0 && radiusY > 0 && radiusZ > 0){
					s->setColor(r, g, b, a);
					s->putEllipsoid(posX, posY, posZ, radiusX, radiusY, radiusZ);
				}
            break;
            case 8: // cutEllipsoid
				if(radiusX > 0 && radiusY > 0 && radiusZ > 0){
					s->cutEllipsoid(posX, posY, posZ, radiusX, radiusY, radiusZ);
				}
        }
        repaint();
    }
}

int Plotter::getDimX(){
	return dimX;
}

int Plotter::getDimY(){
	return dimY;
}

int Plotter::getDimZ(){
	return dimZ;
}

int Plotter::getMinDim(){
	return std::min(std::min(dimX, dimY), dimZ);
}

void Plotter::changeDimensionX(int x){
    boxSizeX = x;
}

void Plotter::changeDimensionY(int y){
    boxSizeY = y;
}

void Plotter::changeDimensionZ(int z){
    boxSizeZ = z;
}

void Plotter::changeRadius(int r){
    radius = r;
}

void Plotter::changeRadiusX(int rx){
    radiusX = rx;
}

void Plotter::changeRadiusY(int ry){
    radiusY = ry;
}

void Plotter::changeRadiusZ(int rz){
    radiusZ = rz;
}

void Plotter::putVoxel(){
    action = 1;
}

void Plotter::cutVoxel(){
    action = 2;
}

void Plotter::putBox(){
    action = 3;
}

void Plotter::cutBox(){
    action = 4;
}

void Plotter::putSphere(){
    action = 5;
}

void Plotter::cutSphere(){
    action = 6;
}

void Plotter::putEllipsoid(){
    action = 7;
}

void Plotter::cutEllipsoid(){
    action = 8;
}

void Plotter::changeRed(int red){
    r = red;
}

void Plotter::changeGreen(int green){
    g = green;
}

void Plotter::changeBlue(int blue){
    b = blue;
}

void Plotter::changeAlpha(int alpha){
    a = alpha;
}

void Plotter::changeDepth(int depth){
    slice = depth;
    repaint();
}

void Plotter::newSculptor(){
    Dialog d;
	QMessageBox msgBox;
	QString mensagem = "O antigo escultor será descartado.";
	QString pergunta = "Deseja continuar?";
	QString titulo = "Novo escultor - Escultor 3D";
	
	msgBox.setWindowTitle(titulo);
	msgBox.setIcon(QMessageBox::Question);
	msgBox.setText(mensagem);
	msgBox.setInformativeText(pergunta);
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Cancel);

	if(msgBox.exec() == QMessageBox::Ok){
		if(d.exec() == QDialog::Accepted){
			s->~Sculptor();

			dimX = d.getDimX();
			dimY = d.getDimY();
			dimZ = d.getDimZ();

			s = new Sculptor(dimX, dimY, dimZ);
			
			slice = 0;
			
			repaint();
		}
	}
}

void Plotter::saveFile(){
	QMessageBox msgBox;
	QString mensagem = "Arquivo salvo com sucesso!";
	QString titulo = "Salvar arquivo - Escultor 3D";
	msgBox.setWindowTitle(titulo);
	msgBox.setIcon(QMessageBox::Information);
	msgBox.setText(mensagem);
	msgBox.exec();
	
	s->writeOFF("C:/Users/Lucas/Documents/Projetos/Escultor3/arquivo.off");
}