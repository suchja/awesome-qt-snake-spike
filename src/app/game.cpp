#include "game.h"
#include "gameboard.h"
#include "snake.h"

Game::Game(GameBoard* board, Snake *snake, QObject *parent)
    : QObject{parent},
      m_board(board),
      m_snake(snake)
{
    m_snake->setMoveDirection(Snake::Direction::MoveRight);
}

void Game::executeMove()
{
    m_snake->moveToNextPosition();
}

void Game::processKeyboardInput(int key, QString text)
{}
