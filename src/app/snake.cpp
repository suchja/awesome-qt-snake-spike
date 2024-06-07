#include "snake.h"
#include "ui-constants.h"
#include "gameboard.h"

#include <QPainter>
#include <stdexcept>

Snake::Snake(const GameBoard& board, QPen pen, QBrush brush, QObject *parent) :
    QObject(parent),
    m_board(board),
    m_head(board.getStartPositionForSnake()),
    m_pen(pen),
    m_brush(brush),
    m_move_direction(Direction::NoMove)
{
    initializeTailToLength(m_board.getStartLengthOfSnake());

    // handling of position on QGraphicsScene
    setPos(m_head);
}

void Snake::initializeTailToLength(int length)
{
    for (int i = length; i >= 1; --i)
    {
        QPointF tail(m_head.x() - i * SINGLE_SQUARE_SIZE, m_head.y());
        m_tail << tail;
    }
}

QRectF Snake::boundingRect() const
{
    qreal min_x = m_head.x();
    qreal min_y = m_head.y();
    qreal max_x = m_head.x();
    qreal max_y = m_head.y();

    foreach (QPointF p, m_tail) {
        max_x = p.x() > max_x ? p.x() : max_x;
        max_y = p.y() > max_y ? p.y() : max_y;
        min_x = p.x() < min_x ? p.x() : min_x;
        min_y = p.y() < min_y ? p.y() : min_y;
    }

    QPointF top_left = mapFromScene(QPointF(min_x, min_y));
    QPointF bottom_right = mapFromScene(QPointF(max_x, max_y));

    QRectF bound = QRectF(top_left.x(),
                          top_left.y(),
                          bottom_right.x() - top_left.x() + SINGLE_SQUARE_SIZE,
                          bottom_right.y() - top_left.y() + SINGLE_SQUARE_SIZE);

    return bound;
}

void Snake::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->save();
    painter->setPen(m_pen);
    painter->setBrush(m_brush);
    painter->drawPath(shape());
    painter->restore();
}

QPainterPath Snake::shape() const
{
    QPainterPath path;

    path.addRect(QRectF(0, 0, SINGLE_SQUARE_SIZE, SINGLE_SQUARE_SIZE));

    foreach (const QPointF current_point, m_tail) {
        const QPointF itemp = mapFromScene(current_point);
        path.addRect(QRectF(itemp.x(), itemp.y(), SINGLE_SQUARE_SIZE, SINGLE_SQUARE_SIZE));
    }

    return path;
}

void Snake::setMoveDirection(Direction direction)
{
    if (m_move_direction == Direction::MoveLeft && direction == Direction::MoveRight)
        return;
    if (m_move_direction == Direction::MoveRight && direction == Direction::MoveLeft)
        return;
    if (m_move_direction == Direction::MoveUp && direction == Direction::MoveDown)
        return;
    if (m_move_direction == Direction::MoveDown && direction == Direction::MoveUp)
        return;

    m_move_direction = direction;
}

void Snake::moveToNextPosition()
{
    if (m_move_direction == Direction::NoMove)
    {
        return;
    }

    m_tail.removeFirst();
    m_tail << m_head;

    switch (m_move_direction)
    {
        case Direction::MoveRight:
            moveRight();
            break;
        case Direction::MoveLeft:
            moveLeft();
            break;
        case Direction::MoveDown:
            moveDown();
            break;
        case Direction::MoveUp:
            moveUp();
            break;
        default:
            throw std::invalid_argument("Invalid move direction");
            break;
    }

    setPos(m_head);
}

void Snake::moveRight() {
    m_head.rx() += SINGLE_SQUARE_SIZE;
    if (!m_board.isInsideBoard(m_head)) {
        m_head.rx() = m_board.getLeftBoardBorder();
    }
}

void Snake::moveLeft() {
    m_head.rx() -= SINGLE_SQUARE_SIZE;
    if (!m_board.isInsideBoard(m_head)) {
        m_head.rx() = m_board.getRightBoardBorder();
    }
}

void Snake::moveDown() {
    m_head.ry() += SINGLE_SQUARE_SIZE;
    if (!m_board.isInsideBoard(m_head)) {
        m_head.ry() = m_board.getTopBoardBorder();
    }
}

void Snake::moveUp() {
    m_head.ry() -= SINGLE_SQUARE_SIZE;
    if (!m_board.isInsideBoard(m_head)) {
        m_head.ry() = m_board.getBottomBoardBorder();
    }
}
