#ifndef SERVICES_H
#define SERVICES_H

#include "gamemode.h"

#include <QString>
#include <QList>

class Services
{
public:
    Services();
    QStringList sortStringList(QList<GameMode> gameModes);
};

#endif // SERVICES_H
