#include "gameboard.h"
#include "ui-constants.h"
#include "snake.h"
#include "food.h"

#include <QRandomGenerator>
#include <QPainter>
#include <QTime>

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

    // TODO: js, it would be better to get this injected!
    m_random = QRandomGenerator::global();
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

void GameBoard::setFood(Food* food)
{
    addItem(food);
}

QPointF GameBoard::getEmptyPosition() const
{
    int x, y;

    do {
        x = m_random->bounded(30) * SINGLE_SQUARE_SIZE;
        y = m_random->bounded(30) * SINGLE_SQUARE_SIZE;
    } while (m_snake->isOnPosition(QPointF(x + 5, y + 5)));

    return QPointF(x, y);
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

float GameBoard::getRightBoardBorder() const
{
    return m_max_bottom_right.x();
}

float GameBoard::getBottomBoardBorder() const
{
    return m_max_bottom_right.y();
}
