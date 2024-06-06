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

    QPen snake_pen(Qt::black);
    QBrush snake_brush(Qt::green);
    Snake* snake = new Snake(*m_board,
                             snake_pen,
                             snake_brush,
                             m_board);

    m_board->setSnakeToStartPosition(snake);

    m_game = new Game(m_board, snake, this);

    // Add scene/board to view
    ui->graphicsView->setScene(m_board);

    // Start game
    connect(&m_timer, SIGNAL(timeout()), m_game, SLOT(executeMove()));
    m_timer.start(500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // React to key press events
    if (!m_game->processKeyboardInput(event->key(), event->text())) {
        // For other keys, call the base class implementation
        QMainWindow::keyPressEvent(event);
    }
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
