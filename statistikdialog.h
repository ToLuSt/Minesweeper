#ifndef STATISTIKDIALOG_H
#define STATISTIKDIALOG_H

#include <QDialog>
#include <QtDebug>

#include "gamemode.h"
#include "statistics.h"
#include "services.h"

namespace Ui {
class StatistikDialog;
}

class StatistikDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StatistikDialog(QWidget *parent = 0);
    ~StatistikDialog();

    void generateStringlist();
    void importGameModes(QList<GameMode> gameModes);

    bool getHasGameModeReset() const;

    QList<GameMode> getGameModesList() const;

public slots:
    void updateStatisticsView(QString string);

    void resetStatistics();
private:
    Ui::StatistikDialog *ui;
    QList<GameMode> gameModesList;
    QStringList gameModeStrings;
    bool hasGameModeReset = false;
    int idxOfResettedMode = 0;

    void initUI();
    GameMode getSelectedEntryFromComboBox(QString entry);
    void updateUI(int games, int won, int lost, QString record);
};

#endif // STATISTIKDIALOG_H
