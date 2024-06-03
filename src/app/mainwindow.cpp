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

    m_scene = new QGraphicsScene();
    m_scene->setSceneRect(0, 0, 600, 600);
    //m_scene->setBackgroundBrush(QBrush(Qt::lightGray));
    m_scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    // Create matrix on background of view
    QPixmap bg(SINGLE_SQUARE_SIZE, SINGLE_SQUARE_SIZE);
    QPainter p(&bg);
    QPen gridPen(Qt::gray);

    p.setBrush(QBrush(Qt::lightGray));
    p.setPen(gridPen);

    p.drawRect(0, 0, SINGLE_SQUARE_SIZE, SINGLE_SQUARE_SIZE);

    ui->graphicsView->setBackgroundBrush(QBrush(bg));

    // Create a pen and brush to customize the rectangle's appearance
    QPen pen(Qt::black);
    QBrush brush(Qt::yellow);

    // Create snake and add it to scene
    Snake* firstSnake = new Snake(QPoint(SINGLE_SQUARE_SIZE*2, SINGLE_SQUARE_SIZE), pen, brush);
    m_scene->addItem(firstSnake);
    Snake* snakeElement = new Snake(QPoint(SINGLE_SQUARE_SIZE, SINGLE_SQUARE_SIZE), pen, brush);
    m_scene->addItem(snakeElement);

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
