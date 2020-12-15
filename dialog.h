#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}
/**
 * @brief A classe Dialog serve para recuperar as dimensões
 * escolhidas pelo usuário ao criar um novo escultor.
 */
class Dialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Dialog é o construtor da classe.
     * @param parent é a referência ao pai da classe
     */
    explicit Dialog(QWidget *parent = nullptr);
    /**
     * @brief ~Dialog é o destrutor da classe.
     */
    ~Dialog();
    /**
     * @brief getDimX recupera o valor do botão deslizante referente à dimensão do novo escultor no eixo X.
     * @return o valor do botão deslizante
     */
    int getDimX();
    /**
     * @brief getDimY recupera o valor do botão deslizante referente à dimensão do novo escultor no eixo Y.
     * @return o valor do botão deslizante
     */
    int getDimY();
    /**
     * @brief getDimZ recupera o valor do botão deslizante referente à dimensão do novo escultor no eixo Z.
     * @return o valor do botão deslizante
     */
    int getDimZ();
private:
    /**
     * @brief ui é a referência à interface gráfica
     */
    Ui::Dialog *ui;
};

#endif // DIALOG_H
