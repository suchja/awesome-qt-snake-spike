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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exitGame()
{
    QApplication::quit();
}

void MainWindow::drawGameboardOnView()
{
    QPixmap bg(SINGLE_SQUARE_SIZE, SINGLE_SQUARE_SIZE);
    QPainter p(&bg);
    QPen gridPen(Qt::gray);

    p.setBrush(QBrush(Qt::lightGray));
    p.setPen(gridPen);

    p.drawRect(0, 0, SINGLE_SQUARE_SIZE, SINGLE_SQUARE_SIZE);

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
    Snake* firstSnake = new Snake(QPoint(SINGLE_SQUARE_SIZE*2, SINGLE_SQUARE_SIZE), pen, brush);
    m_scene->addItem(firstSnake);
}
