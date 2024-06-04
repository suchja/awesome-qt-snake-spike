#include "snake.h"
#include "ui-constants.h"

#include <QPainter>

Snake::Snake(QPointF start_position, QPen pen, QBrush brush, QObject *parent)
    : QObject(parent), m_head(start_position), m_pen(pen), m_brush(brush)
{
    m_move_count = 0;

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

void Snake::moveToNextPosition()
{
    if ((m_move_count > 1) && (m_move_count <= 10))
    {
        m_head.rx() += SINGLE_SQUARE_SIZE;
        setPos(m_head);
    }

    if (m_move_count <= 10)
    {
        m_move_count++;
    }
    else
    {
        emit hasMovementCompleted();
        m_move_count = 0;
    }
}
