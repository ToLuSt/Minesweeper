#include "services.h"

Services::Services()
{

}

QStringList Services::sortStringList(QList<GameMode> gameModes){
    QStringList gameModeStrings;
    foreach (GameMode mode, gameModes) {
        int index = 0;
        int width = mode.getWidth();
        int height = mode.getHeigth();
        int mines = mode.getMines();

        // insert sorted
        if(gameModeStrings.size() > 0){
            foreach (QString mode, gameModeStrings) {
                QStringList params = mode.split(" ");
                int excWidth = QString(params[1]).toInt();
                int excHeigth = QString(params[3]).toInt();
                int excMines = QString(params[5]).toInt();

                if(width > excWidth){
                    index++;
                } else if(width == excWidth){
                    if(height > excHeigth){
                        index++;
                    } else if(height == excHeigth){
                    if(mines > excMines){
                        index++;
                    }
                }
                }
            }
        }
        QString visibleComboBoxText = QString("Breite: " + QString::number(width) + " Höhe: " + QString::number(height) + " Minen: " + QString::number(mines));
        gameModeStrings.insert(index, visibleComboBoxText);
    }
    return gameModeStrings;
}
