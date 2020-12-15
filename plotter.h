#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QAction>
#include <QColor>
#include <vector>
#include "sculptor.h"
/**
 * @brief A classe Plotter serve para gerenciar as funcionalidades
 * de desenho do escultor 3D.
 */
class Plotter : public QWidget
{
    Q_OBJECT

private:
    /**
     * @brief s é a referência para o objeto da classe Sculptor
     */
    Sculptor *s;
    /**
     * @brief v é uma matriz bidimensional de voxels
     */
    std::vector<std::vector<Voxel>> v;
    /**
     * @brief mousePressed indica se o botão esquerdo do mouse está sendo pressionado ou não
     */
    bool mousePressed;
    /**
     * @brief mouseX é a coordenada X da posição do clique do mouse
     */
    int mouseX;
    /**
     * @brief mouseY é a coordenada Y da posição do clique do mouse
     */
    int mouseY;
    /**
     * @brief posX é a coordenada X da posição onde será desenhado no escultor
     */
    int posX;
    /**
     * @brief posY é a coordenada Y da posição onde será desenhado no escultor
     */
    int posY;
    /**
     * @brief posZ é a coordenada Z da posição onde será desenhado no escultor
     */
    int posZ;
    /**
     * @brief dimX é a dimensão do escultor no eixo X
     */
    int dimX;
    /**
     * @brief dimY é a dimensão do escultor no eixo Y
     */
    int dimY;
    /**
     * @brief dimZ é a dimensão do escultor no eixo Z
     */
    int dimZ;
    /**
     * @brief action é a ação que será realizada no escultor
     */
    int action;
    /**
     * @brief boxSizeX é a dimensão no eixo X que será utilizada para o desenho e a remoção da caixa de voxels
     */
    int boxSizeX;
    /**
     * @brief boxSizeY é a dimensão no eixo Y que será utilizada para o desenho e a remoção da caixa de voxels
     */
    int boxSizeY;
    /**
     * @brief boxSizeZ é a dimensão no eixo Z que será utilizada para o desenho e a remoção da caixa de voxels
     */
    int boxSizeZ;
    /**
     * @brief r é a dosagem de cor vermelha presente na região do escultor onde será desenhado pelo usuário
     */
    int r;
    /**
     * @brief g é a dosagem de cor verde presente na região do escultor onde será desenhado pelo usuário
     */
    int g;
    /**
     * @brief b é a dosagem de cor azul presente na região do escultor onde será desenhado pelo usuário
     */
    int b;
    /**
     * @brief a é a transparência presente na região do escultor onde será desenhado pelo usuário
     */
    int a;
    /**
     * @brief radius é o raio que será utilizado para o desenho e a remoção da esfera de voxels
     */
    int radius;
    /**
     * @brief radiusX é o raio no eixo X que será utilizado para o desenho e a remoção da elipsoide de voxels
     */
    int radiusX;
    /**
     * @brief radiusY é o raio no eixo Y que será utilizado para o desenho e a remoção da elipsoide de voxels
     */
    int radiusY;
    /**
     * @brief radiusZ é o raio no eixo Z que será utilizado para o desenho e a remoção da elipsoide de voxels
     */
    int radiusZ;
    /**
     * @brief slice é a profundidade da escultura visível ao usuário
     */
    int slice;
    /**
     * @brief cellSize é o tamanho das células da área do escultor que é destinada ao desenho
     */
    int cellSize;
public:
    /**
     * @brief Plotter é o construtor da classe.
     * @param parent é a referência ao pai da classe
     */
    explicit Plotter(QWidget *parent = nullptr);
    /**
     * @brief paintEvent trata da interface visual do escultor e de como ela reage ao desenho da escultura.
     * @param event é a referência ao evento de pintura
     */
    void paintEvent(QPaintEvent *event);
    /**
     * @brief mouseMoveEvent trata o que ocorre ao movimentar o mouse dentro do escultor.
     * @param event é a referência ao evento de movimento do mouse
     */
    void mouseMoveEvent(QMouseEvent *event);
    /**
     * @brief mousePressEvent trata o que ocorre ao clicar com o botão esquerdo do mouse dentro do escultor.
     * @param event é a referência ao evento de clique do mouse
     */
    void mousePressEvent(QMouseEvent *event);
    /**
     * @brief mouseReleaseEvent trata o que ocorre ao liberar o botão esquerdo do mouse.
     * @param event é a referência ao evento de fim do clique do mouse
     */
    void mouseReleaseEvent(QMouseEvent *event);
    /**
     * @brief draw executa a ação de desenho escolhida pelo usuário no escultor.
     * @param action é a ação que será executada
     * @param mousePressed indica se o botão esquerdo do mouse está sendo pressionado ou não
     */
    void draw(int action, bool mousePressed);
    /**
     * @brief getDimX recupera a dimensão do escultor no eixo X.
     * @return a dimensão no eixo X
     */
    int getDimX();
    /**
     * @brief getDimY recupera a dimensão do escultor no eixo Y.
     * @return a dimensão no eixo Y
     */
    int getDimY();
    /**
     * @brief getDimZ recupera a dimensão do escultor no eixo Z.
     * @return a dimensão no eixo Z
     */
    int getDimZ();
    /**
     * @brief getMinDim recupera a menor dimensão do escultor entre os três eixos.
     * @return a menor dimensão
     */
    int getMinDim();
signals:

public slots:
    /**
     * @brief changeDimensionX recupera o valor do controle deslizante referente à dimensão da caixa de voxels no eixo X.
     * @param x é o valor do controle deslizante
     */
    void changeDimensionX(int x);
    /**
     * @brief changeDimensionY recupera o valor do controle deslizante referente à dimensão da caixa de voxels no eixo Y.
     * @param y é o valor do controle deslizante
     */
    void changeDimensionY(int y);
    /**
     * @brief changeDimensionZ recupera o valor do controle deslizante referente à dimensão da caixa de voxels no eixo Z.
     * @param z é o valor do controle deslizante
     */
    void changeDimensionZ(int z);
    /**
     * @brief changeRadius recupera o valor do controle deslizante referente ao raio da esfera de voxels.
     * @param r é o valor do controle deslizante
     */
    void changeRadius(int r);
    /**
     * @brief changeRadiusX recupera o valor do controle deslizante referente ao raio da elipsoide de voxels no eixo X.
     * @param rx é o valor do controle deslizante
     */
    void changeRadiusX(int rx);
    /**
     * @brief changeRadiusY recupera o valor do controle deslizante referente ao raio da elipsoide de voxels no eixo Y.
     * @param ry é o valor do controle deslizante
     */
    void changeRadiusY(int ry);
    /**
     * @brief changeRadiusZ recupera o valor do controle deslizante referente ao raio da elipsoide de voxels no eixo Z.
     * @param rz é o valor do controle deslizante
     */
    void changeRadiusZ(int rz);
    /**
     * @brief putVoxel informa ao escultor que a forma desenhada será um voxel.
     */
    void putVoxel();
    /**
     * @brief cutVoxel informa ao escultor que a forma removida será um voxel.
     */
    void cutVoxel();
    /**
     * @brief putBox informa ao escultor que a forma desenhada será uma caixa de voxels.
     */
    void putBox();
    /**
     * @brief cutBox informa ao escultor que a forma removida será uma caixa de voxels.
     */
    void cutBox();
    /**
     * @brief putSphere informa ao escultor que a forma desenhada será uma esfera de voxels.
     */
    void putSphere();
    /**
     * @brief cutSphere informa ao escultor que a forma removida será uma esfera de voxels.
     */
    void cutSphere();
    /**
     * @brief putEllipsoid informa ao escultor que a forma desenhada será uma elipsoide de voxels.
     */
    void putEllipsoid();
    /**
     * @brief cutEllipsoid informa ao escultor que a forma removida será uma elipsóide de voxels.
     */
    void cutEllipsoid();
    /**
     * @brief changeRed recupera o valor do controle deslizante referente à dosagem de cor vermelha.
     * @param red é o valor do controle deslizante
     */
    void changeRed(int red);
    /**
     * @brief changeGreen recupera o valor do controle deslizante referente à dosagem de cor verde.
     * @param green é o valor do controle deslizante
     */
    void changeGreen(int green);
    /**
     * @brief changeBlue recupera o valor do controle deslizante referente à dosagem de cor azul.
     * @param blue é o valor do controle deslizante
     */
    void changeBlue(int blue);
    /**
     * @brief changeAlpha recupera o valor do controle deslizante referente à transparência.
     * @param alpha é o valor do controle deslizante
     */
    void changeAlpha(int alpha);
    /**
     * @brief changeDepth recupera o valor do controle deslizante referente ao eixo Z da escultura tridimensional.
     * @param depth é o valor do controle deslizante
     */
    void changeDepth(int depth);
    /**
     * @brief newSculptor cria um novo escultor com dimensões fornecidas pelo usuário.
     */
    void newSculptor();
    /**
     * @brief saveFile gera um arquivo .OFF contendo as informações da escultura tridimensional.
     */
    void saveFile();
};

#endif // PLOTTER_H
