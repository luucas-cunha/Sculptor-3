#ifndef SELECTEDCOLOR_H
#define SELECTEDCOLOR_H

#include <QWidget>
/**
 * @brief A classe SelectedColor serve para permitir ao usuário
 * visualizar qual cor está escolhendo ao mover os botões deslizantes correspondentes.
 */
class SelectedColor : public QWidget
{
    Q_OBJECT
private:
    /**
     * @brief r é a dosagem de cor vermelha presente no retângulo
     */
    int r;
    /**
     * @brief g é a dosagem de cor verde presente no retângulo
     */
    int g;
    /**
     * @brief b é a dosagem de cor azul presente no retângulo
     */
    int b;
    /**
     * @brief a é a transparência presente no retângulo
     */
    int a;
public:
    /**
     * @brief SelectedColor é o construtor da classe.
     * @param parent é a referência ao pai da classe
     */
    explicit SelectedColor(QWidget *parent = nullptr);
    /**
     * @brief paintEvent muda a cor de preenchimento do retângulo conforme a cor escolhida.
     * @param event é a referência ao evento de pintura
     */
    void paintEvent(QPaintEvent *event);
signals:

public slots:
    /**
     * @brief selectedRed recupera o valor do botão deslizante referente à dosagem de cor vermelha.
     * @param red é o valor do botão deslizante
     */
    void selectedRed(int red);
    /**
     * @brief selectedGreen recupera o valor do botão deslizante referente à dosagem de cor verde.
     * @param green é o valor do botão deslizante
     */
    void selectedGreen(int green);
    /**
     * @brief selectedBlue recupera o valor do botão deslizante referente à dosagem de cor azul.
     * @param blue é o valor do botão deslizante
     */
    void selectedBlue(int blue);
    /**
     * @brief selectedAlpha recupera o valor do botão deslizante referente à transparência.
     * @param alpha é o valor do botão deslizante
     */
    void selectedAlpha(int alpha);
};

#endif // SELECTEDCOLOR_H
