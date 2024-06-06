#ifndef GAME_H
#define GAME_H

#include <QObject>

class GameBoard;
class Snake;

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(GameBoard* board,
                  Snake* snake,
                  QObject *parent = nullptr);

    bool processKeyboardInput(int key, QString text);

public slots:
    void executeMove();

signals:

private:
    GameBoard* m_board;
    Snake* m_snake;
};

#endif // GAME_H
