#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QTimer>

class GameBoard;
class GameSpeed;
class Snake;
class FoodGenerator;
class Food;

class Game : public QObject
{
    Q_OBJECT

public:
    explicit Game(GameBoard* board,
                  FoodGenerator* food_generator,
                  Snake* snake,
                  GameSpeed* speed,
                  QObject* parent = nullptr);

    bool processKeyboardInput(int key, QString text);
    void startGame(int ticks_per_second);

private slots:
    void executeMove();

signals:

private:
    GameBoard* m_board;
    FoodGenerator* m_food_generator;
    Snake* m_snake;
    Food* m_food;
    QTimer m_timer;
    GameSpeed* m_speed;
    int m_tick_counter;
};

#endif // GAME_H
