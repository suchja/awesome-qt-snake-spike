#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QTimer>

class Snake;
class GameBoard;

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

private slots:
    void exitGame();
    void stopGame();

private:    
    void initializeScene();
    void drawGameboardOnView();
    void initializeSnake();

    Ui::MainWindow* ui;

    QGraphicsScene* m_scene;
    GameBoard* m_board;
    QTimer m_timer;
};
#endif // MAINWINDOW_H
