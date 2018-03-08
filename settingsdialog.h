#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QtDebug>
#include <QPushButton>

#include "statistics.h"
#include "gamemode.h"
#include "services.h"

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

    void setupGUI();
    void fillSettings(int rows, int cols, int mines);
    void importGameModes(QList<GameMode> gameModes);
    bool validateEntries(int cols, int rows, int mines);

    GameMode getCurrentGameMode();
    QList<GameMode> getGameModesList() const;

public slots:
    void takeChoosenSettings();
    void deleteChosenEntry();
    void reactToCurrentIndex(int index);

    void updateMaxMines(int count);
private:
    Ui::SettingsDialog *ui;
    QList<GameMode> gameModesList;
    QStringList gameModeStrings;
    GameMode gameMode;
    int idxOfSelectedMode = 0;

    void generateStringlist();
    void initUI();
    bool showYesNoMessageBox(QString msg);
    int getSelectedEntryIndexFromComboBox(QString entry);
    GameMode getSelectedEntryFromComboBox(QString entry);
};

#endif // SETTINGSDIALOG_H
