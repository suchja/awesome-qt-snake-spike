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

    // Install event filter on the QMainWindow
    this->installEventFilter(this);

    // Start game
    connect(&m_timer, SIGNAL(timeout()), m_game, SLOT(executeMove()));
    m_timer.start(500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent* keyEvent = static_cast<QKeyEvent *>(event);

        if (m_game->processKeyboardInput(keyEvent->key(), keyEvent->text())) {
            // we handled keys successfully, otherwise the base class needs to do its work!
            return true;
        }
    }
    // Call base class eventFilter
    return QMainWindow::eventFilter(obj, event);

    // React to key press events
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
