#include "game.h"
#include "gameboard.h"
#include "snake.h"
#include "food.h"
#include "foodgenerator.h"
#include "gamespeed.h"

Game::Game(GameBoard* board, FoodGenerator* food_generator, Snake* snake, GameSpeed* speed, QObject* parent)
    : QObject{parent},
      m_board(board),
      m_food_generator(food_generator),
      m_snake(snake),
      m_speed(speed),
      m_tick_counter(0)
{
    m_board->setSnakeToStartPosition(m_snake);
    QPointF food_position = m_board->getEmptyPosition();
    m_food = m_food_generator->generateNewFood(food_position);
    m_board->setFood(m_food);
}

void Game::startGame(int ticks_per_second)
{
    connect(m_snake, SIGNAL(ateItself()), this, SLOT(handleGameOver()));
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(executeMove()));

    // 33 FPS
    m_timer.start(1000/ticks_per_second);
}

void Game::executeMove()
{
    if (m_tick_counter % m_speed->getTicksForCurrentSpeed() != 0)
    {
        m_tick_counter++;
        return;
    }
    else
    {
        m_tick_counter = 1;
    }

    m_snake->moveToNextPosition();

    if (m_snake->isOnPosition(m_food->getPosition()))
    {
        m_snake->grow();

        m_board->removeFood(m_food);
        delete m_food;

        QPointF food_position = m_board->getEmptyPosition();
        m_food = m_food_generator->generateNewFood(food_position);
        m_board->setFood(m_food);

        (*m_speed)++;
    }
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

void Game::handleGameOver()
{
    m_snake->setMoveDirection(Snake::Direction::NoMove);
    m_timer.stop();

    disconnect(m_snake, SIGNAL(ateItself()), this, SLOT(handleGameOver()));
    disconnect(&m_timer, SIGNAL(timeout()), this, SLOT(executeMove()));

    emit gameOver();
}
