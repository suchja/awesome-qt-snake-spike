#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "snake.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionE_xit, SIGNAL(triggered()), this, SLOT(exitGame()));

    m_scene = new QGraphicsScene();
    m_scene->setSceneRect(-300, -300, 600, 600);
    m_scene->setBackgroundBrush(QBrush(Qt::darkRed));
    m_scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    // Create a pen and brush to customize the rectangle's appearance
    QPen pen(Qt::black);
    QBrush brush(Qt::blue);

    // Create snake and add it to scene
    Snake* firstSnake = new Snake(pen, brush);
    m_scene->addItem(firstSnake);

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
