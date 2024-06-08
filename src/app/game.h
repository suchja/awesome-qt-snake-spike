#ifndef GAME_H
#define GAME_H

#include <QObject>

class GameBoard;
class Snake;
class FoodGenerator;

class Game : public QObject
{
    Q_OBJECT

public:
    explicit Game(GameBoard* board,
                  FoodGenerator* food_generator,
                  Snake* snake,
                  QObject *parent = nullptr);

    bool processKeyboardInput(int key, QString text);

public slots:
    void executeMove();

signals:

private:
    GameBoard* m_board;
    FoodGenerator* m_food_generator;
    Snake* m_snake;
};

#endif // GAME_H
