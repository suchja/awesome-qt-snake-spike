#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsItem>
#include <QPen>
#include <QBrush>

class Snake : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Snake(QPoint start_position = QPoint(),
          QPen pen = QPen(),
          QBrush brush = QBrush(),
          QObject* parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

public slots:
    void moveToNextPosition();

signals:
    void hasMovementCompleted();

private:
    QPen m_pen;
    QBrush m_brush;
    int m_x;
    int m_y;
    int m_move_count;
};

#endif // SNAKE_H
