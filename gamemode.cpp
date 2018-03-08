#include "gamemode.h"

GameMode::GameMode()
{
}

GameMode::GameMode(int w, int h, int m, Statistics s)
{
    width = w;
    heigth = h;
    mines = m;
    stats = s;
}

int GameMode::getWidth() const
{
    return width;
}

void GameMode::setWidth(int value)
{
    width = value;
}

int GameMode::getHeigth() const
{
    return heigth;
}

void GameMode::setHeigth(int value)
{
    heigth = value;
}

int GameMode::getMines() const
{
    return mines;
}

void GameMode::setMines(int value)
{
    mines = value;
}

Statistics GameMode::getStats() const
{
    return stats;
}

void GameMode::setStats(const Statistics &value)
{
    stats = value;
}

