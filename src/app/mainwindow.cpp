#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "snake.h"
#include "gameboard.h"
#include "game.h"
#include "ui-constants.h"
#include "foodgenerator.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionE_xit, SIGNAL(triggered()), this, SLOT(exitGame()));

    m_view = new QGraphicsView(this);
    createGame();

    // connect game objects with UI
    m_view->setScene(m_board);
    m_view->installEventFilter(this);
    setCentralWidget(m_view);

    // Start game
    connect(&m_timer, SIGNAL(timeout()), m_game, SLOT(executeMove()));
    m_timer.start(500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createGame()
{
    m_board = new GameBoard(30, 30, this);

    QPen snake_pen(Qt::black);
    QBrush snake_brush(Qt::green);
    Snake* snake = new Snake(*m_board,
                             snake_pen,
                             snake_brush,
                             m_board);

    QPen food_pen(Qt::white);
    QBrush food_brush(Qt::red);
    FoodGenerator* generator = new FoodGenerator(food_pen,
                                                 food_brush,
                                                 this);

    m_game = new Game(m_board, generator, snake, this);
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
