#include "snake.h"
#include "ui-constants.h"
#include "gameboard.h"

#include <QPainter>

Snake::Snake(const GameBoard& board, QPen pen, QBrush brush, QObject *parent) :
    QObject(parent),
    m_board(board),
    m_head(board.getStartPositionForSnake()),
    m_pen(pen),
    m_brush(brush),
    m_move_direction(Direction::NoMove)
{
    // handling of position on QGraphicsScene
    setPos(m_head);
}

QRectF Snake::boundingRect() const
{
    return QRectF(0,
                  0,
                  SINGLE_SQUARE_SIZE,
                  SINGLE_SQUARE_SIZE);
}

void Snake::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setPen(m_pen);
    painter->setBrush(m_brush);
    painter->drawRect(boundingRect());
}

void Snake::setMoveDirection(Direction direction)
{
    if (m_move_direction == Direction::MoveLeft && direction == Direction::MoveRight)
        return;
    if (m_move_direction == Direction::MoveRight && direction == Direction::MoveLeft)
        return;
    if (m_move_direction == Direction::MoveUp && direction == Direction::MoveDown)
        return;
    if (m_move_direction == Direction::MoveDown && direction == Direction::MoveUp)
        return;

    m_move_direction = direction;
}

void Snake::moveToNextPosition()
{
    if (m_move_direction == Direction::NoMove)
    {
        return;
    }
    if (m_move_direction == Direction::MoveRight)
    {
        m_head.rx() += SINGLE_SQUARE_SIZE;
        if (!m_board.isInsideBoard(m_head))
        {
            m_head.rx() = m_board.getLeftBoardBorder();
        }
        setPos(m_head);
    }
}
