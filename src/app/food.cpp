#include "food.h"
#include "ui-constants.h"

#include <QPainter>

Food::Food(QPointF position_on_board, QPen pen, QBrush brush)
    : m_pen(pen),
      m_brush(brush),
      m_position(position_on_board)
{
    setPos(position_on_board);
}

QPointF Food::getPosition() const
{
    return m_position;
}

QRectF Food::boundingRect() const
{
    return QRectF(0,
                  0,
                  SINGLE_SQUARE_SIZE,
                  SINGLE_SQUARE_SIZE);
}

void Food::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->save();

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(m_pen);
    painter->setBrush(m_brush);
    painter->drawPath(shape());

    painter->restore();
}

QPainterPath Food::shape() const
{
    QPainterPath p;
    //p.addEllipse(QPointF(TILE_SIZE / 2, TILE_SIZE / 2), FOOD_RADIUS, FOOD_RADIUS);
    p.addEllipse(boundingRect());
    return p;
}
