#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QTimer>

class Snake;
class GameBoard;
class Game;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void exitGame();
    void stopGame();

private:    
    void initializeScene();
    void drawGameboardOnView();
    void initializeSnake();

    Ui::MainWindow* ui;

    GameBoard* m_board;
    Game* m_game;
    QTimer m_timer;
};
#endif // MAINWINDOW_H
