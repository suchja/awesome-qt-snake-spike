#include "snake.h"
#include "ui-constants.h"

#include <QPainter>

Snake::Snake(const QPen& pen, const QBrush& brush, QGraphicsItem *parent)
    : QGraphicsItem(parent), m_pen(pen), m_brush(brush)
{
}

QRectF Snake::boundingRect() const
{
    return QRectF(SINGLE_SQUARE_SIZE,
                  SINGLE_SQUARE_SIZE,
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
