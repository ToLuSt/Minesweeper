#include "statistikdialog.h"
#include "ui_statistikdialog.h"

StatistikDialog::StatistikDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatistikDialog)
{
    ui->setupUi(this);

    connect(ui->okayPushbutton,SIGNAL(clicked(bool)),this,SLOT(accept()));
    connect(ui->resetPushButton,SIGNAL(clicked(bool)),this,SLOT(resetStatistics()));
    connect(ui->gameModesComboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(updateStatisticsView(QString)));
}

StatistikDialog::~StatistikDialog()
{
    delete ui;
}

/**
 * Create StringList for the ComboBox-View
 * @brief StatistikDialog::generateStringlist
 */
void StatistikDialog::generateStringlist()
{
    Services services;

    gameModeStrings = services.sortStringList(gameModesList);
}

/**
 * import gameModeList and update UI with its entries
 * @brief StatistikDialog::importGameModes
 * @param gameModes
 */
void StatistikDialog::importGameModes(QList<GameMode> gameModes){
    gameModesList = gameModes;
    generateStringlist();
    initUI();
}

/**
 * Slot for choosen entry from ComboBox,
 * load its content with GameMode-KEY: width, height, mines
 * @brief StatistikDialog::updateStatisticsView
 * @param string
 */
void StatistikDialog::updateStatisticsView(QString string)
{
    GameMode gameMode = getSelectedEntryFromComboBox(string);

    Statistics stats = gameMode.getStats();
    updateUI(stats.getPlayedGames(), stats.getWonGames(), stats.getLostGames(), stats.getRecord());
}

/**
 * return selected GameMode
 * @brief StatistikDialog::getSelectedEntryFromComboBox
 * @param entry
 * @return
 */
GameMode StatistikDialog::getSelectedEntryFromComboBox(QString entry){
    QStringList params = entry.split(" ");
    int width = QString(params[1]).toInt();
    int height = QString(params[3]).toInt();
    int mines = QString(params[5]).toInt();
    int count = 0;
    foreach (GameMode mode, gameModesList) {
        if(mode.getWidth() == width && mode.getHeigth() == height && mode.getMines() == mines){
            idxOfResettedMode = count;
            return mode;
        }
        count++;
    }
}

/**
 * reset current statistic of GameMode
 * @brief StatistikDialog::resetStatistics
 */
void StatistikDialog::resetStatistics(){
    QString entry = ui->gameModesComboBox->currentText();
    GameMode gameMode = getSelectedEntryFromComboBox(entry);
    Statistics stats = gameMode.getStats();
    stats.setPlayedGames(0);
    stats.setWonGames(0);
    stats.setLostGames(0);
    stats.setRecord("");
    gameMode.setStats(stats);
    gameModesList.replace(idxOfResettedMode,gameMode);
    hasGameModeReset = true;
    updateUI(0,0,0,"");
}

/**
 * return getter of gameModes
 * @brief StatistikDialog::getGameModesList
 * @return
 */
QList<GameMode> StatistikDialog::getGameModesList() const
{
    return gameModesList;
}

/**
 * return getter of bool, if sth has been resettet
 * @brief StatistikDialog::getHasGameModeReset
 * @return
 */
bool StatistikDialog::getHasGameModeReset() const
{
    return hasGameModeReset;
}

/**
 * update UI (Statistic Labels)
 * @brief StatistikDialog::updateUI
 * @param games
 * @param won
 * @param lost
 * @param record
 */
void StatistikDialog::updateUI(int games, int won, int lost, QString record){
    ui->gamesPlayedLabel->setText(QString::number(games));
    ui->wonGamesLabel->setText(QString::number(won));
    ui->lostGamesLabel->setText(QString::number(lost));
    ui->recordTimeLabel->setText(record);
}

/**
 * Update ComboBox
 * @brief StatistikDialog::initUI
 */
void StatistikDialog::initUI(){
    ui->gameModesComboBox->addItems(gameModeStrings);
}
