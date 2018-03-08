#ifndef STATISTICS_H
#define STATISTICS_H

#include <QString>

class Statistics
{
public:
    Statistics();
    Statistics(int played, int won, int lost, QString rec);

    int getPlayedGames() const;
    void setPlayedGames(int value);

    int getWonGames() const;
    void setWonGames(int value);

    int getLostGames() const;
    void setLostGames(int value);

    QString getRecord() const;
    void setRecord(const QString &value);

private:
    int playedGames;
    int wonGames;
    int lostGames;
    QString record;
};

#endif // STATISTICS_H
