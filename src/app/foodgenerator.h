#ifndef FOODGENERATOR_H
#define FOODGENERATOR_H

#include <QObject>
#include <QPen>
#include <QBrush>

class Food;

class FoodGenerator : public QObject
{
    Q_OBJECT
public:
    explicit FoodGenerator(QPen pen = QPen(),
                           QBrush brush = QBrush(),
                           QObject *parent = nullptr);

    Food* generateNewFood(QPointF position); // caller takes ownership!

private:
    QPen m_pen;
    QBrush m_brush;
};

#endif // FOODGENERATOR_H
