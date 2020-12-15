#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief A classe MainWindow é a janela principal do programa,
 * onde está disposta toda a interface e suas funcionalidades.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow é o construtor da classe.
     * @param parent é a referência ao pai da classe
     */
    MainWindow(QWidget *parent = nullptr);
    /**
     * @brief ~MainWindow
     */
    ~MainWindow();
public slots:
    /**
     * @brief updateSliders atualiza os valores dos botões deslizantes quando um novo escultor é criado.
     */
	void updateSliders();
private slots:
    /**
     * @brief on_actionExit_triggered fecha o programa ao clicar na ação de saída.
     */
    void on_actionExit_triggered();
private:
    /**
     * @brief ui é a referência à interface gráfica
     */
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
