#include "gameboard.h"
#include "ui-constants.h"
#include "snake.h"

#include <QPainter>

GameBoard::GameBoard(int tile_count_x, int tile_count_y, QObject *parent)
    : QGraphicsScene{parent}
{
    m_max_bottom_right.rx() = tile_count_x * SINGLE_SQUARE_SIZE;
    m_max_bottom_right.ry() = tile_count_y * SINGLE_SQUARE_SIZE;

    m_snake_start_position = QPointF((tile_count_x / 2) * SINGLE_SQUARE_SIZE,
                                     (tile_count_y / 2) * SINGLE_SQUARE_SIZE);

    if (tile_count_x > 20)
    {
        m_snake_start_length = 7;
    }
    else
    {
        m_snake_start_length = 4;
    }

    setSceneRect(0, 0, m_max_bottom_right.x(), m_max_bottom_right.y());
    setItemIndexMethod(QGraphicsScene::NoIndex);

    initializeGameboardBackground();
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

QPointF GameBoard::getStartPositionForSnake() const
{
    return m_snake_start_position;
}

int GameBoard::getStartLengthOfSnake() const
{
    return m_snake_start_length;
}

void GameBoard::setSnakeToStartPosition(Snake* snake)
{
    m_snake = snake;
    addItem(m_snake);
}

bool GameBoard::isInsideBoard(QPointF position) const
{
    if ((position.x() < 0) || (position.y() < 0))
        return false;

    if ((position.x() >= m_max_bottom_right.x()) || (position.y() >= m_max_bottom_right.y()))
        return false;

    return true;
}

float GameBoard::getLeftBoardBorder() const
{
    return 0;
}

float GameBoard::getTopBoardBorder() const
{
    return 0;
}
