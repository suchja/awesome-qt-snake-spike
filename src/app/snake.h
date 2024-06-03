#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsItem>
#include <QPen>
#include <QBrush>

class Snake : public QGraphicsItem
{
public:
    Snake(QPoint start_position = QPoint(),
          QPen pen = QPen(),
          QBrush brush = QBrush(),
          QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

private:
    QPen m_pen;
    QBrush m_brush;
    int m_x;
    int m_y;
};

#endif // SNAKE_H
