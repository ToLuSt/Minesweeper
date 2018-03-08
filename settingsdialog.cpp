#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QMessageBox>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(takeChoosenSettings()));
    connect(ui->deletePushButton,SIGNAL(clicked(bool)),this,SLOT(deleteChosenEntry()));
    connect(ui->gameModesComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(reactToCurrentIndex(int)));
    connect(ui->colsSpinBox,SIGNAL(valueChanged(int)),this,SLOT(updateMaxMines(int)));
    connect(ui->rowsSpinBox,SIGNAL(valueChanged(int)),this,SLOT(updateMaxMines(int)));
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

/**
 * Function should be used for Quick-Start of a Game -> ComboBox
 * Imports alle excisting GameModes
 * @brief SettingsDialog::importGameModes
 * @param gameModes
 */
void SettingsDialog::importGameModes(QList<GameMode> gameModes){
    gameModesList = gameModes;
    generateStringlist();
    initUI();
}

/**
 * Update automatically mine's maximum
 * @brief SettingsDialog::updateMaxMines
 * @param count
 */
void SettingsDialog::updateMaxMines(int count){
    int max = ui->colsSpinBox->value()*ui->rowsSpinBox->value()*0.2;
    ui->minesSpinBox->setMaximum(max);
    ui->minesSpinBox->setValue(max);
}

/**
 * import entries from SpinBoxes, call validation and
 * Filling of temporary GameMode-Object
 * @brief SettingsDialog::takeChoosenSettings
 */
void SettingsDialog::takeChoosenSettings(){
    if(ui->gameModesComboBox->currentIndex() == 0){
        int cols = ui->colsSpinBox->text().toInt();
        int rows = ui->rowsSpinBox->text().toInt();
        int mines = ui->minesSpinBox->text().toInt();

        if(validateEntries(cols, rows, mines)){
            fillSettings(rows, cols, mines);
            QDialog::accept();
            this->close();
        }
    } else {
        gameMode = getSelectedEntryFromComboBox(ui->gameModesComboBox->currentText());
        QDialog::accept();
        this->close();
    }
}

/**
 * Validate entries, mines must not be more than
 * fields will exist
 * @brief SettingsDialog::validateEntries
 * @param cols
 * @param rows
 * @param mines
 * @return
 */
bool SettingsDialog::validateEntries(int cols, int rows, int mines){
    if(rows > 3 && cols > 3 && mines >= 3) {
        if((rows*cols*0.2) >= mines){
            return true;
        }
    }
    QMessageBox msgBox;
    msgBox.setText("Die Parameter sind nicht gültig.");
    msgBox.exec();
    return false;
}

/**
 * Create ne GameMode and put entries in Object
 * @brief SettingsDialog::fillSettings
 * @param rows
 * @param cols
 * @param mines
 */
void SettingsDialog::fillSettings(int rows, int cols, int mines){
    Statistics stats(0,0,0,"");
    gameMode.setHeigth(rows);
    gameMode.setWidth(cols);
    gameMode.setMines(mines);
    gameMode.setStats(stats);
}

/**
 * Create StringList for the ComboBox-View
 * @brief SettingsDialog::generateStringlist
 */
void SettingsDialog::generateStringlist()
{
    Services services;

    gameModeStrings = services.sortStringList(gameModesList);
}

/**
 * Update ComboBox
 * @brief SettingsDialog::initUI
 */
void SettingsDialog::initUI(){
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Bestätigen");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Abbrechen");
    ui->deletePushButton->setDisabled(true);
    ui->gameModesComboBox->addItem(" ");
    ui->gameModesComboBox->addItems(gameModeStrings);
}

/**
 * Delete selected Entry from ComboBox and List
 * @brief SettingsDialog::deleteChosenEntry
 */
void SettingsDialog::deleteChosenEntry(){
    int index = ui->gameModesComboBox->currentIndex();
    QString text = ui->gameModesComboBox->currentText();
    if(index != 0){
        if(showYesNoMessageBox("Wollen Sie den Spielmodus wirklich löschen?")){
            int selectedMode = getSelectedEntryIndexFromComboBox(text);

            if(selectedMode != -1){
                gameModesList.removeAt(selectedMode);
                ui->gameModesComboBox->removeItem(index);

                ui->gameModesComboBox->setCurrentIndex(0);
            }
        }
    } else {
        QMessageBox msgBox;
        msgBox.setText("Du hast keinen Spielmodus ausgewählt.");
        msgBox.exec();
    }
}

/**
 * enable/disable Delete Button
 * @brief SettingsDialog::reactToCurrentIndex
 * @param index
 */
void SettingsDialog::reactToCurrentIndex(int index)
{
    if(index != 0){
        ui->deletePushButton->setEnabled(true);
    } else {
        ui->deletePushButton->setDisabled(true);
    }
}

QList<GameMode> SettingsDialog::getGameModesList() const
{
    return gameModesList;
}

/**
 * YesNo MessageBox
 * @brief SettingsDialog::showYesNoMessageBox
 * @param msg
 * @return
 */
bool SettingsDialog::showYesNoMessageBox(QString msg){
    QMessageBox reply(QMessageBox::Question,
                      "Achtung",
                      msg,
                      QMessageBox::Yes | QMessageBox::No);
    reply.setButtonText(QMessageBox::Yes, "Ja");
    reply.setButtonText(QMessageBox::No, "Nein");
    if (reply.exec() == QMessageBox::Yes) {
        return true;
    } else {
        return false;
    }
}

/**
 * return selected GameMode's index
 * @brief SettingsDialog::getSelectedEntryFromComboBox
 * @param entry
 * @return
 */
int SettingsDialog::getSelectedEntryIndexFromComboBox(QString entry){
    QStringList params = entry.split(" ");
    int width = QString(params[1]).toInt();
    int height = QString(params[3]).toInt();
    int mines = QString(params[5]).toInt();
    int index = 0;
    foreach (GameMode mode, gameModesList) {
        if(mode.getWidth() == width && mode.getHeigth() == height && mode.getMines() == mines){
            return index;
        }
        index++;
    }
    return index = -1;
}

/**
 * return selected GameMode
 * @brief SettingsDialog::getSelectedEntryFromComboBox
 * @param entry
 * @return
 */
GameMode SettingsDialog::getSelectedEntryFromComboBox(QString entry){
    QStringList params = entry.split(" ");
    int width = QString(params[1]).toInt();
    int height = QString(params[3]).toInt();
    int mines = QString(params[5]).toInt();
    int count = 0;
    foreach (GameMode mode, gameModesList) {
        if(mode.getWidth() == width && mode.getHeigth() == height && mode.getMines() == mines){
            idxOfSelectedMode = count;
            return mode;
        }
        count++;
    }
}

/**
 * Getter for temp GaeMode
 * @brief SettingsDialog::getCurrentGameMode
 * @return
 */
GameMode SettingsDialog::getCurrentGameMode(){
    return gameMode;
}
