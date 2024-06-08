#include "foodgenerator.h"
#include "food.h"

FoodGenerator::FoodGenerator(QPen pen, QBrush brush, QObject *parent) :
    QObject{parent},
    m_pen(pen),
    m_brush(brush)
{
}

Food* FoodGenerator::generateNewFood(QPointF position)
{
    return new Food(position, m_pen, m_brush);
}
