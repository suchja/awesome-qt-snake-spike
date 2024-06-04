#ifndef GAME_H
#define GAME_H

#include <QObject>

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);

    void executeMove();

public slots:
    void processKeyboardInput(int key, QString text);

signals:
};

#endif // GAME_H
