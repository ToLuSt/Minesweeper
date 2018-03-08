#include "statistics.h"

Statistics::Statistics()
{

}

Statistics::Statistics(int played, int won, int lost, QString rec)
{
    playedGames = played;
    wonGames = won;
    lostGames = lost;
    record = rec;
}

int Statistics::getPlayedGames() const
{
    return playedGames;
}

void Statistics::setPlayedGames(int value)
{
    playedGames = value;
}

int Statistics::getWonGames() const
{
    return wonGames;
}

void Statistics::setWonGames(int value)
{
    wonGames = value;
}

int Statistics::getLostGames() const
{
    return lostGames;
}

void Statistics::setLostGames(int value)
{
    lostGames = value;
}

QString Statistics::getRecord() const
{
    return record;
}

void Statistics::setRecord(const QString &value)
{
    record = value;
}
