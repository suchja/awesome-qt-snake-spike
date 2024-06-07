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
    int getStartLengthOfSnake() const;

    bool isInsideBoard(QPointF position) const;
    float getLeftBoardBorder() const;
    float getTopBoardBorder() const;
    float getRightBoardBorder() const;
    float getBottomBoardBorder() const;

    // IGameVisualization - Visualization of GameBoard and Content!
    // This doesn't take ownership and only stores it in the QGraphicsScene
    void setSnakeToStartPosition(Snake* snake);

private:
    void initializeGameboardBackground();

    QPointF m_max_bottom_right;

    QPointF m_snake_start_position;
    int m_snake_start_length;

    Snake* m_snake;
};

#endif // GAMEBOARD_H
