#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsScene>

class Snake;

class GameBoard : public QGraphicsScene
{
public:
    explicit GameBoard(int tile_count_x, int tile_count_y, QObject *parent = nullptr);

    const Snake& getSnake() const;

private:
    void initializeGameboardBackground();
    void initializeAndAddSnake();

    QPointF m_max_bottom_right;
    Snake* m_snake;
};

#endif // GAMEBOARD_H
