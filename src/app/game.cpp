#include "game.h"
#include "gameboard.h"
#include "snake.h"

Game::Game(GameBoard* board, Snake *snake, QObject *parent)
    : QObject{parent},
      m_board(board),
      m_snake(snake)
{
    m_snake->setMoveDirection(Snake::Direction::MoveDown);
}

void Game::executeMove()
{
    m_snake->moveToNextPosition();
}

bool Game::processKeyboardInput(int key, QString text)
{
    switch (key)
    {
        case Qt::Key_Left:
            m_snake->setMoveDirection(Snake::Direction::MoveLeft);
            break;
        case Qt::Key_Right:
            m_snake->setMoveDirection(Snake::Direction::MoveRight);
            break;
        case Qt::Key_Up:
            m_snake->setMoveDirection(Snake::Direction::MoveUp);
            break;
        case Qt::Key_Down:
            m_snake->setMoveDirection(Snake::Direction::MoveDown);
            break;
        case Qt::Key_Space:
            m_snake->setMoveDirection(Snake::Direction::NoMove);
            break;
        default:
            return false;
    }

    return true;
}
