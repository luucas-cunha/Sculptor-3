#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny;
    nz = _nz;

    if(nx <= 0 || ny <= 0 || nz <= 0){
        nx = 0;
        ny = 0;
        nz = 0;
    }

    v = new Voxel**[nx];

    if(v == nullptr){
        std::cout << "v não armazenado" << std::endl;
        exit(0);
    }

    v[0]= new Voxel*[nx * ny];

    if(v[0] == nullptr){
        std::cout <<"v[0] não armazenado" <<std::endl;
        exit(0);
    }

    v[0][0]= new Voxel[nx * ny * nz];

    if(v[0][0] == nullptr){
        std::cout << "v[0][0] não armazenado" << std::endl;
        exit(0);
    }

    int x, y, z;

    for(x = 0; x < nx; x++){
        if(x < (nx - 1)){
            v[x + 1] = v[x] + ny;
        }

        for(y = 0; y < ny; y++){
            if((y == ny - 1) && (x != (nx - 1))){
                v[x + 1][0] = v[x][y] + nz;
            } else {
                v[x][y + 1] = v[x][y] + nz;
            }

            for(z = 0; z < nz; z++){
                v[x][y][z].isOn = false;
            }
        }
    }
}

Sculptor::~Sculptor(){
    if(nx == 0 || ny == 0 || nz == 0){
        return;
    }

    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}

void Sculptor::setColor(float _r, float _g, float _b, float alpha){
    r = _r;
    g = _g;
    b = _b;
    a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z){
    if ((x >= nx) || (y >= ny) || (z >= nz)){
        return;
    }
    if ((x < 0) || (y < 0) || (z < 0)){
        return;
    }

    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].isOn = true;
}

void Sculptor::cutVoxel(int x, int y, int z){
    if ((x >= nx) || (y >= ny) || (z >= nz)){
        return;
    }
    if ((x < 0) || (y < 0) || (z < 0)){
        return;
    }
	
    if(v[x][y][z].isOn == true){
        v[x][y][z].isOn = false;
    }
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    int x, y, z;
    int aux = 0;

    if(x0 > x1){
        aux = x0;
        x0 = x1;
        x1 = aux;
    }

    if(y0 > y1){
        aux = y0;
        y0 = y1;
        y1 = aux;
    }

    if(z0 > z1){
        aux = z0;
        z0 = z1;
        z1 = aux;
    }

    if(x0 < 0){
        x0 = 0;
    }

    for(x = x0; x <= x1; x++){
        for(y = y0; y <= y1; y++){
            for(z = z0; z <= z1; z++){
                putVoxel(x, y, z);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    int x, y, z;
    int aux = 0;

    if(x0 > x1){
        aux = x0;
        x0 = x1;
        x1 = aux;
    }

    if(y0 > y1){
        aux = y0;
        y0 = y1;
        y1 = aux;
    }

    if(z0 > z1){
        aux = z0;
        z0 = z1;
        z1 = aux;
    }

    if(x0 < 0){
        x0 = 0;
    }

    for(x = x0; x <= x1; x++){
        for(y = y0; y <= y1; y++){
            for(z = z0; z <= z1; z++){
                cutVoxel(x, y, z);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    int x, y, z;
    float aux;

    for(x = 0; x < nx; x++){
        for(y = 0; y < ny; y++){
            for(z = 0; z < nz; z++){
                aux = ((float) pow((x - xcenter), 2) / pow(radius, 2)) + ((float) pow((y - ycenter), 2) / pow(radius, 2)) + ((float) pow((z - zcenter), 2) / pow(radius, 2));

                if(aux <= 1.0){
                    putVoxel(x, y, z);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    int x, y, z;
    float aux;

    for(x = 0; x < nx; x++){
        for(y = 0; y < ny; y++){
            for(z = 0; z < nz; z++){
                 aux = ((float) pow((x - xcenter), 2) / pow(radius, 2)) + ((float) pow((y - ycenter), 2) / pow(radius, 2)) + ((float) pow((z - zcenter), 2) / pow(radius, 2));

                 if(aux <= 1.0){
                     cutVoxel(x, y, z);
                 }
             }
         }
     }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    int x, y, z;
    float aux;

    for(x = 0; x < nx; x++){
        for(y = 0; y < ny; y++){
            for(z = 0; z < nz; z++){
                aux = ((float) pow((x - xcenter), 2) / pow(rx, 2)) + ((float) pow((y - ycenter), 2) / pow(ry, 2)) + ((float) pow((z - zcenter), 2) / pow(rz, 2));

                if(aux <= 1.0){
                    putVoxel(x, y, z);
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    int x, y, z;
    float aux;

    for(x = 0; x < nx; x++){
        for(y = 0; y < ny; y++){
            for(z = 0; z < nz; z++){
                aux = ((float) pow((x - xcenter), 2) / pow(rx, 2)) + ((float) pow((y - ycenter), 2) / pow(ry, 2)) + ((float) pow((z - zcenter), 2) / pow(rz, 2));

                if(aux <= 1.0){
                    cutVoxel(x, y, z);
                }
            }
        }
    }
}

std::vector<std::vector<Voxel>> Sculptor::createGrid(int slice){
	std::vector<std::vector<Voxel>> matriz;
    std::vector<Voxel> linha;
	int x, y;
	
    linha.resize(ny);

    for(x = 0; x < nx; x++){
        for (y = 0; y < ny; ++y) {
            linha[y].r = v[x][y][slice].r;
            linha[y].g = v[x][y][slice].g;
            linha[y].b = v[x][y][slice].b;
            linha[y].a = v[x][y][slice].a;
            linha[y].isOn = v[x][y][slice].isOn;
        }

        matriz.push_back(linha);
    }
	
	linha.clear();
	
	return (matriz);
}

void Sculptor::writeOFF(char* filename){
    std::ofstream fout;

    fout.open(filename);

    if(!fout.is_open()){
        std::cout << "Falha ao criar o arquivo" << std::endl;
        exit(0);
    }

    //Primeira linha do arquivo OFF
    fout << "OFF" << std::endl;

    int x, y, z;
    int Nvoxels = 0;

    for(x = 0; x < nx; x++){
        for(y = 0; y < ny; y++){
            for(z = 0; z < nz; z++){
                if(v[x][y][z].isOn){
                    Nvoxels++;
                }
            }
        }
    }

    //Segunda linha do arquivo OFF
    fout << 8*Nvoxels << " " << 6*Nvoxels << " " << 0 << std::endl;

    for(x = 0; x < nx; x++){
        for(y = 0; y < ny; y++){
            for(z = 0; z < nz; z++){
                if(v[x][y][z].isOn){
                        fout << x - 0.5 << " " << y + 0.5 << " " << z - 0.5 << std::endl;
                        fout << x - 0.5 << " " << y - 0.5 << " " << z - 0.5 << std::endl;
                        fout << x + 0.5 << " " << y - 0.5 << " " << z - 0.5 << std::endl;
                        fout << x + 0.5 << " " << y + 0.5 << " " << z - 0.5 << std::endl;
                        fout << x - 0.5 << " " << y + 0.5 << " " << z + 0.5 << std::endl;
                        fout << x - 0.5 << " " << y - 0.5 << " " << z + 0.5 << std::endl;
                        fout << x + 0.5 << " " << y - 0.5 << " " << z + 0.5 << std::endl;
                        fout << x + 0.5 << " " << y + 0.5 << " " << z + 0.5 << std::endl;
                }
            }
        }
    }

    int aux = 0;

    for(x = 0; x < nx; x++){
        for(y = 0; y < ny; y++){
            for(z = 0; z < nz; z++){
                if(v[x][y][z].isOn){
                    fout << 4 << " " << aux + 0 << " " << aux + 3 << " " << aux + 2 << " " << aux + 1 << " " << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << std::endl;
                    fout << 4 << " " << aux + 4 << " " << aux + 5 << " " << aux + 6 << " " << aux + 7 << " " << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << std::endl;
                    fout << 4 << " " << aux + 0 << " " << aux + 1 << " " << aux + 5 << " " << aux + 4 << " " << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << std::endl;
                    fout << 4 << " " << aux + 0 << " " << aux + 4 << " " << aux + 7 << " " << aux + 3 << " " << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << std::endl;
                    fout << 4 << " " << aux + 3 << " " << aux + 7 << " " << aux + 6 << " " << aux + 2 << " " << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << std::endl;
                    fout << 4 << " " << aux + 1 << " " << aux + 2 << " " << aux + 6 << " " << aux + 5 << " " << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << std::endl;

                    aux = aux + 8;
                }
            }
        }
    }

    if(fout.is_open()){
        std::cout << "Arquivo .OFF criado com sucesso!" << std::endl;
    }

    fout.close();
}
