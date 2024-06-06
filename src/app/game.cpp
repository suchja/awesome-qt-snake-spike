#include "game.h"
#include "gameboard.h"

Game::Game(GameBoard* board, QObject *parent)
    : QObject{parent}, m_board(board)
{}

void Game::executeMove()
{}

void Game::processKeyboardInput(int key, QString text)
{}
