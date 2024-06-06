#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "snake.h"
#include "gameboard.h"
#include "game.h"
#include "ui-constants.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionE_xit, SIGNAL(triggered()), this, SLOT(exitGame()));

    m_board = new GameBoard(30, 30, this);
    m_game = new Game(m_board, this);

    QPen snake_pen(Qt::black);
    QBrush snake_brush(Qt::yellow);
    Snake* snake = new Snake(*m_board,
                             snake_pen,
                             snake_brush,
                             m_board);

    m_board->setSnakeToStartPosition(snake);

    // Add scene/board to view
    ui->graphicsView->setScene(m_board);

    // Start game
    connect(&m_timer, SIGNAL(timeout()), m_game, SLOT(executeMove()));
    m_timer.start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exitGame()
{
    QApplication::quit();
}

void MainWindow::stopGame()
{
    m_timer.stop();

    disconnect(&m_timer, SIGNAL(timeout()), m_game, SLOT(executeMove()));
}
