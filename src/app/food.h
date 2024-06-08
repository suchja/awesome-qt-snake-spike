#ifndef FOOD_H
#define FOOD_H

#include <QGraphicsItem>
#include <QPen>
#include <QBrush>

class Food : public QGraphicsItem
{
public:
    Food(QPointF position_on_board,
         QPen pen = QPen(),
         QBrush brush = QBrush());

    // business logic
    QPointF getPosition() const;

    // Graphics View Framework logic for visualization
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

private:
    QPen m_pen;
    QBrush m_brush;
};

#endif // FOOD_H
