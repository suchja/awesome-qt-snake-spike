#include "gameboard.h"
#include "ui-constants.h"
#include "snake.h"

#include <QPainter>

GameBoard::GameBoard(int tile_count_x, int tile_count_y, QObject *parent)
    : QGraphicsScene{parent}
{
    m_max_bottom_right.rx() = tile_count_x * SINGLE_SQUARE_SIZE;
    m_max_bottom_right.ry() = tile_count_y * SINGLE_SQUARE_SIZE;

    setSceneRect(0, 0, m_max_bottom_right.x(), m_max_bottom_right.y());
    setItemIndexMethod(QGraphicsScene::NoIndex);

    initializeGameboardBackground();
    initializeAndAddSnake();
}

void GameBoard::initializeGameboardBackground()
{
    QPixmap bg(SINGLE_SQUARE_SIZE, SINGLE_SQUARE_SIZE);
    QPainter p(&bg);
    QPen gridPen(Qt::gray);

    p.setBrush(QBrush(Qt::lightGray));
    p.setPen(gridPen);

    p.drawRect(0, 0, SINGLE_SQUARE_SIZE, SINGLE_SQUARE_SIZE);

    setBackgroundBrush(QBrush(bg));
}

void GameBoard::initializeAndAddSnake()
{
    QPen pen(Qt::black);
    QBrush brush(Qt::yellow);

    // Create snake and add it to scene
    m_snake = new Snake(QPointF(SINGLE_SQUARE_SIZE*2, SINGLE_SQUARE_SIZE), pen, brush);
    addItem(m_snake);
}

const Snake& GameBoard::getSnake() const
{
    return *m_snake;
}
