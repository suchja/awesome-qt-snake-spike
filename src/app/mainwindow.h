#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

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
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void exitGame();
    void stopGame();

private:
    void createGame();

    Ui::MainWindow* ui;
    QGraphicsView* m_view;

    GameBoard* m_board;
    Game* m_game;
};
#endif // MAINWINDOW_H
