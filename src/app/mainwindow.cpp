#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "snake.h"
#include "gameboard.h"
#include "ui-constants.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionE_xit, SIGNAL(triggered()), this, SLOT(exitGame()));

    m_board = new GameBoard(30, 30, this);
    const Snake& snake = m_board->getSnake();

    // Add scene/board to view
    ui->graphicsView->setScene(m_board);

    // Start game
    connect(&snake, SIGNAL(hasMovementCompleted()), this, SLOT(stopGame()));
    connect(&m_timer, SIGNAL(timeout()), &snake, SLOT(moveToNextPosition()));
    m_timer.start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_scene;
}

void MainWindow::exitGame()
{
    QApplication::quit();
}

void MainWindow::stopGame()
{
    m_timer.stop();
    const Snake& snake = m_board->getSnake();

    disconnect(&snake, SIGNAL(hasMovementCompleted()), this, SLOT(stopGame()));
    disconnect(&m_timer, SIGNAL(timeout()), &snake, SLOT(moveToNextPosition()));
}
