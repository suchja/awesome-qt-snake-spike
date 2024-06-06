#ifndef GAME_H
#define GAME_H

#include <QObject>

class GameBoard;

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(GameBoard* board, QObject *parent = nullptr);

    void executeMove();

public slots:
    void processKeyboardInput(int key, QString text);

signals:

private:
    GameBoard* m_board;
};

#endif // GAME_H
