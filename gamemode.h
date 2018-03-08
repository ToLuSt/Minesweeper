#ifndef GAMEMODE_H
#define GAMEMODE_H

#include "statistics.h"


class GameMode
{
public:
    GameMode();
    GameMode(int w, int h, int m, Statistics s);

    int getWidth() const;
    void setWidth(int value);

    int getHeigth() const;
    void setHeigth(int value);

    int getMines() const;
    void setMines(int value);

    Statistics getStats() const;
    void setStats(const Statistics &value);

private:
    int width;
    int heigth;
    int mines;
    Statistics stats;
};

#endif // GAMEMODE_H
