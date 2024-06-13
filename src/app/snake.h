#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsItem>
#include <QPen>
#include <QBrush>

class GameBoard;

class Snake : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    enum class Direction {
        NoMove,
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown
    };

    Snake(const GameBoard& board,
          QPen pen = QPen(),
          QBrush brush = QBrush(),
          QObject* parent = nullptr);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

    void setMoveDirection(Direction direction);
    Direction currentDirection();

    void moveToNextPosition();
    bool isOnPosition(QPointF position) const;

    void grow();

signals:
    void ateItself();

private:
    void initializeTailToLength(int length);

    void moveRight();
    void moveLeft();
    void moveDown();
    void moveUp();

    bool hasEatenItself();

    QPen m_pen;
    QBrush m_brush;

    QPointF m_head;
    QList<QPointF> m_tail;

    Direction m_move_direction;
    int m_grow_count;

    const GameBoard& m_board;
};

#endif // SNAKE_H
