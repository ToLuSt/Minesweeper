#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <QDate>
#include <QLabel>
#include <QMainWindow>
#include <QTimer>
#include <QMouseEvent>
#include <QTableWidget>
#include <QtDebug>
#include <QScrollBar>
#include <QMessageBox>
#include <QDir>

#include "statistikdialog.h"
#include "helpdialog.h"
#include "settingsdialog.h"
#include "gamemode.h"
#include "statistics.h"

namespace Ui {
class Minesweeper;
}

class Minesweeper : public QMainWindow
{
    Q_OBJECT

public:
    explicit Minesweeper(QWidget *parent = 0);
    ~Minesweeper();

    void loadDefaultSettings();
    void setUpStatusBar();
    void initSignalAndSlots();  
    void generateGamingField(int rows, int cols);
    void initNewGame();
    void checkTableVisibility();
    void resetUIWhenPaused(bool isGameActive);
    void resizeWindowSize(int rows, int cols);
    void updateLabelText(QLabel *label, int value);
    void setHintsForDangerousNeighbourhood();
    void configureGamingFieldAfterFirstClick(QList<QString> minesPositions);
    void firstMoveConfiguration(int row, int col);
    void revealTable();
    void updateFlagsInStatusbar(int flag);
    int convertMatrixPositionInVectorPosition(int row, int col);
    QList<QString> placeMines(int row, int col);
    void updateStatistics(bool succes);

    // Clickevents
    bool eventFilter(QObject *object, QEvent *event);
    void leftClickAction(QTableWidgetItem *item);
    void rightClickAction(QTableWidgetItem *item);
    void middleClickAction(QTableWidgetItem *item);

    // Getter,Setter
    int getFlags() const;
    void setFlags(int value);

public slots:
    void updateTime();
    void startSessionTimer();
    void stopSessionTimer();
    void resetAll();

    void lostGame();
    void callingDialogs();
    void saveExistingGameModes();

private:
    Ui::Minesweeper *ui;
    int flags;
    bool isGameActive = false;
    QTime time;
    QTimer *timer = new QTimer(this);
    QLabel *timeVarLabel = new QLabel();
    QLabel *flagsVarLabel = new QLabel();
    QLabel *minesVarLabel = new QLabel();
    QList<GameMode> gameModes;
    GameMode currentGameMode;
    QString FILENAME = "Gamemodelist.csv";
    QString APPDIR = "";

    // Index of last false item for Winning Conditions
    int lastCheckedRowIdx;
    int lastCheckedColIdx;

    bool checkWinningConditions();
    bool isGameModeExcisting(GameMode gameMode);
    void gameIsFinished(bool succes);
    void callMessageBox(QString msg);
    QString buildMyOutputString();
    void loadExcistingGameModesFromFile();
    void processLine(QString line);
    bool isFlaggingOnItemCorrect(QString mine, QString flag);
    void revealSaveNeighbours(QList<QTableWidgetItem *> list);
};

#endif // MINESWEEPER_H
