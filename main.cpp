#include "minesweeper.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Minesweeper w;
    QObject::connect(&a,SIGNAL(aboutToQuit()),&w,SLOT(saveExistingGameModes()));
    w.show();

    return a.exec();
}
