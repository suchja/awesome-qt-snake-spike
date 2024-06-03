#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

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

private:
    Ui::MainWindow* ui;

    QGraphicsScene* m_scene;
    void initializeScene();
    void drawGameboardOnView();
    void initializeSnake();
};
#endif // MAINWINDOW_H
