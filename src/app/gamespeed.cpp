#include "gamespeed.h"

#include <iostream>

GameSpeed::GameSpeed(int ticks_per_second, Speed start_speed)
    : m_ticks_per_second(ticks_per_second),
      m_currentSpeed(start_speed)
{
}

GameSpeed GameSpeed::operator ++(int)
{
    GameSpeed old = *this;
    // TODO: how to avoid using Speed::Max here? It makes adding values more error prone!
    if (m_currentSpeed <= Speed::Max)
        m_currentSpeed = static_cast<Speed>(static_cast<int>(m_currentSpeed) + 1);
    return old;
}

int GameSpeed::getTicksForCurrentSpeed() const
{
    return m_ticks_per_second / static_cast<int>(m_currentSpeed);
}
