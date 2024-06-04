#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "snake.h"
#include "ui-constants.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionE_xit, SIGNAL(triggered()), this, SLOT(exitGame()));

    initializeScene();
    drawGameboardOnView();
    initializeSnake();

    // Add scene to view
    ui->graphicsView->setScene(m_scene);

    // Start game
    connect(m_snake, SIGNAL(hasMovementCompleted()), this, SLOT(stopGame()));
    connect(&m_timer, SIGNAL(timeout()), m_snake, SLOT(moveToNextPosition()));
    m_timer.start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_snake;
    delete m_scene;
}

void MainWindow::exitGame()
{
    QApplication::quit();
}

void MainWindow::stopGame()
{
    m_timer.stop();

    disconnect(m_snake, SIGNAL(hasMovementCompleted()), this, SLOT(stopGame()));
    disconnect(&m_timer, SIGNAL(timeout()), m_snake, SLOT(moveToNextPosition()));
}

void MainWindow::drawGameboardOnView()
{
    QPixmap bg(SINGLE_SQUARE_SIZE, SINGLE_SQUARE_SIZE);
    QPainter p(&bg);
    QPen gridPen(Qt::gray);

    p.setBrush(QBrush(Qt::lightGray));
    p.setPen(gridPen);

    p.drawRect(0, 0, SINGLE_SQUARE_SIZE, SINGLE_SQUARE_SIZE);

    ui->graphicsView->scale(1,1);
    ui->graphicsView->setBackgroundBrush(QBrush(bg));
}

void MainWindow::initializeScene()
{
    m_scene = new QGraphicsScene();
    m_scene->setSceneRect(0, 0, 600, 600);
    m_scene->setItemIndexMethod(QGraphicsScene::NoIndex);
}

void MainWindow::initializeSnake()
{
    QPen pen(Qt::black);
    QBrush brush(Qt::yellow);

    // Create snake and add it to scene
    m_snake = new Snake(QPoint(SINGLE_SQUARE_SIZE*2, SINGLE_SQUARE_SIZE), pen, brush);
    m_scene->addItem(m_snake);
}
