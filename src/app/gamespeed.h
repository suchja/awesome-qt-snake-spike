#ifndef GAMESPEED_H
#define GAMESPEED_H


class GameSpeed
{
public:
    enum class Speed {
        Slow = 4,
        Medium = 5,
        Fast = 6,
        Faster = 7,
        EvenFaster = 8,
        Max = 9
    };

    GameSpeed(int ticks_per_second, Speed start_speed = Speed::Slow);

    GameSpeed operator++(int);

    int getTicksForCurrentSpeed() const;

private:
    Speed m_currentSpeed;
    const int m_ticks_per_second;
};

#endif // GAMESPEED_H
