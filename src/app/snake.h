#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsItem>
#include <QPen>
#include <QBrush>

class Snake : public QGraphicsItem
{
public:
    Snake(const QPen& pen = QPen(), const QBrush& brush = QBrush(), QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

private:
    QPen m_pen;
    QBrush m_brush;
};

#endif // SNAKE_H
