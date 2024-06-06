#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsScene>

class Snake;

class GameBoard : public QGraphicsScene
{
public:
    explicit GameBoard(int tile_count_x, int tile_count_y, QObject *parent = nullptr);

    // IGameBoard - Core GameBoard functionality
    QPointF getStartPositionForSnake() const;
    bool isInsideBoard(QPointF position) const;
    float getLeftBoardBorder() const;

    // IGameVisualization - Visualization of GameBoard and Content!
    // This doesn't take ownership and only stores it in the QGraphicsScene
    void setSnakeToStartPosition(Snake* snake);

private:
    void initializeGameboardBackground();

    QPointF m_max_bottom_right;
    const QPointF m_snake_start_position;

    Snake* m_snake;
};

#endif // GAMEBOARD_H
