#include "minesweeper.h"
#include "ui_minesweeper.h"

Minesweeper::Minesweeper(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Minesweeper)
{
    ui->setupUi(this);
    APPDIR = QCoreApplication::applicationDirPath();
    gameModes.clear();
    QWidget::setWindowIcon(QPixmap("://pics/res/Mine.png"));
    ui->centralWidget->setObjectName("centralW");
    ui->centralWidget->setStyleSheet("QWidget#centralW { background-image: url(://pics/res/Minefield.jpg); }");
    ui->statusLabel->setAttribute(Qt::WA_TranslucentBackground);
    ui->tableWidget->setMouseTracking( true );
    ui->tableWidget->viewport()->installEventFilter( this );

    // initialisation
    loadExcistingGameModesFromFile();
    loadDefaultSettings();
    initNewGame();
    setUpStatusBar();
    initSignalAndSlots();
}

Minesweeper::~Minesweeper()
{
    delete ui;
}

/// Initialisation Methods

/**
 * Import File with GameModes if it is excisting
 * @brief Minesweeper::loadExcistingGameModesFromFile
 */
void Minesweeper::loadExcistingGameModesFromFile(){
    QFile file;
    QDir::setCurrent(APPDIR);
    file.setFileName(FILENAME);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            processLine(line);
        }
    }
}

/**
 * process read data and create patientList
 * @brief Minesweeper::processLine
 * @param line
 */
void Minesweeper::processLine(QString line){
    QStringList gameModesList = line.split(";");
    if (gameModesList.length()>2 && gameModesList[0] != "width"){
        GameMode gameMode;
        gameMode.setWidth(gameModesList[0].toInt());
        gameMode.setHeigth(gameModesList[1].toInt());
        gameMode.setMines(gameModesList[2].toInt());
        Statistics stats;
        stats.setPlayedGames(gameModesList[3].toInt());
        stats.setWonGames(gameModesList[4].toInt());
        stats.setLostGames(gameModesList[5].toInt());
        stats.setRecord(gameModesList[6]);
        gameMode.setStats(stats);
        gameModes.append(gameMode);
    }
}

/**
 * init a new game
 * @brief Minesweeper::initNewGame
 */
void Minesweeper::initNewGame(){
    int rows = currentGameMode.getHeigth();
    int cols = currentGameMode.getWidth();
    generateGamingField(rows, cols);
    time.setHMS(0,0,0,0);
}

/**
 * load default settings for initial game
 * @brief Minesweeper::loadDefaultSettings
 */
void Minesweeper::loadDefaultSettings(){
    if(gameModes.size() > 0){
        currentGameMode = gameModes.first();
    } else {
        // GameMode object
        GameMode gm;
        gm.setHeigth(10);
        gm.setWidth(10);
        gm.setMines(10);
        Statistics stats = Statistics(0,0,0,"");
        gm.setStats(stats);
        gameModes.append(gm);
        currentGameMode = gm;
    }

    // Other variables

    ui->statusLabel->setStyleSheet(" QLabel { background-color : black; color: red; }");
    setFlags(0);
    lastCheckedRowIdx = 0;
    lastCheckedColIdx = 0;
    ui->pausegamePushbutton->setDisabled(true);
    ui->endgamePushbutton->setDisabled(true);
}

/**
 * Initial function for all signal/slots
 * @brief Minesweeper::initSignalAndSlots
 */
void Minesweeper::initSignalAndSlots(){

    // Menu
    connect(ui->actionAnwendung_schliessen,SIGNAL(triggered(bool)),this,SLOT(close()));
    connect(ui->actionEinstellungen,SIGNAL(triggered(bool)),this,SLOT(callingDialogs()));
    connect(ui->actionHilfe,SIGNAL(triggered(bool)),this,SLOT(callingDialogs()));
    connect(ui->actionStatistik,SIGNAL(triggered(bool)),this,SLOT(callingDialogs()));

    // Timer
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    connect(ui->newgamePushbutton, SIGNAL(clicked(bool)), this, SLOT(resetAll()));
    connect(ui->pausegamePushbutton, SIGNAL(clicked(bool)), this, SLOT(stopSessionTimer()));
    connect(ui->endgamePushbutton, SIGNAL(clicked(bool)), this, SLOT(lostGame()));
}

/**
 * initial setup for the statusbar in the bottom
 * @brief Minesweeper::setUpStatusBar
 */
void Minesweeper::setUpStatusBar(){
    QWidget *widg = new QWidget();
    QLabel *minesLabel = new QLabel();
    QLabel *flagsLabel = new QLabel();
    QLabel *timeLabel = new QLabel();
    QPalette palette;
    QBrush brush;

    brush.setColor(QColor(0, 0, 255, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Normal, QPalette::WindowText, brush);

    flagsVarLabel->setPalette(palette);
    minesLabel->setText("Enthaltene Minen:");
    minesVarLabel->setText(QString::number(currentGameMode.getMines()));
    flagsLabel->setText("Gesetzte Flaggen:");
    flagsVarLabel->setText(QString::number(flags));
    timeLabel->setText("Zeit:");
    timeVarLabel->setText(time.toString("mm:ss"));

    QGridLayout *layout = new QGridLayout(widg);
    layout->addWidget(minesLabel,0,0,1,1,Qt::AlignVCenter | Qt::AlignLeft);
    layout->addWidget(minesVarLabel,0,1,1,1,Qt::AlignVCenter | Qt::AlignLeft);
    layout->addWidget(flagsLabel,0,2,1,1,Qt::AlignVCenter | Qt::AlignLeft);
    layout->addWidget(flagsVarLabel,0,3,1,1,Qt::AlignVCenter | Qt::AlignLeft);
    layout->addWidget(timeLabel,0,4,1,1,Qt::AlignVCenter | Qt::AlignRight);
    layout->addWidget(timeVarLabel,0,5,1,1,Qt::AlignVCenter | Qt::AlignRight);
    ui->statusBar->addWidget(widg,1);
}

/**
 * Setup Gaming area in creating the Items for the TableWidget
 * and giving them the data, which is Mine or Save, which
 * depends on the randomly created parameter QList
 * @brief Minesweeper::generateGamingField
 */
void Minesweeper::generateGamingField(int rows, int cols){
    ui->tableWidget->setColumnCount(cols);

    for(int m=0;m<rows;m++) {
        ui->tableWidget->insertRow(m);
        for(int n=0;n<cols;n++){
            QTableWidgetItem *content = new QTableWidgetItem();
            content->setFlags(content->flags() ^ Qt::ItemIsEditable);
            content->setBackgroundColor(QColor(119,109,109,137));
            ui->tableWidget->setItem(m,n, content);
        }
    }

    resizeWindowSize(rows,cols);
}

/**
 * Get first user action in TableWidget to configure
 * gaming area, be sure to click save field at first
 * @brief Minesweeper::handleUserAction
 * @param row
 * @param col
 */
void Minesweeper::firstMoveConfiguration(int row, int col){
    QList<QString> minesPositions = placeMines(row,col);
    configureGamingFieldAfterFirstClick(minesPositions);
    startSessionTimer();
    ui->pausegamePushbutton->setEnabled(true);
    ui->endgamePushbutton->setEnabled(true);
    isGameActive = true;
}

/**
 * Generates a List, which is firstly filled
 * with bombs and then Randomly 'save' is inserted
 * @brief Minesweeper::placeMines
 * @return
 */
QList<QString> Minesweeper::placeMines(int row, int col){
    int areaSize = currentGameMode.getWidth()*currentGameMode.getHeigth();
    int savePlaces;
    //List, which is filled with Mines and save places
    //it will be imported in gaming field element by element
    QList<QString> mineArea;

    for(int i=0;i<currentGameMode.getMines();i++){
        mineArea.append("Mine");
    }
    savePlaces = areaSize - currentGameMode.getMines() - 1;
    qsrand(QTime::currentTime().msec());
    for(int i=0;i<savePlaces;i++){
        int rndIdx = qrand() % ((mineArea.size() + 1) - 0) + 0;
        mineArea.insert(rndIdx,"Save");
    }

    // Be sure, that clicked cell is save
    int safeCell = convertMatrixPositionInVectorPosition(row, col);
    mineArea.insert(safeCell,"Save");

    return mineArea;
}

/**
 * place status of cells at first click in TableWidget
 * @brief Minesweeper::configureGamingFieldAfterFirstClick
 * @param minesPositions
 */
void Minesweeper::configureGamingFieldAfterFirstClick(QList<QString> minesPositions){
    int counter = 0;
    for(int m=0;m<currentGameMode.getHeigth();m++) {
        for(int n=0;n<currentGameMode.getWidth();n++){
            QTableWidgetItem* item = ui->tableWidget->item(m,n);
            if(minesPositions[counter] == "Mine"){
                item->setData(Qt::AccessibleDescriptionRole,QVariant(tr("Mine")));
            } else {
                item->setData(Qt::AccessibleDescriptionRole,QVariant(tr("Save")));
            }
            counter++;
        }
    }
    setHintsForDangerousNeighbourhood();
}

/**
 * Checks the neighbours for every item
 * with special check on items at the edge
 * @brief Minesweeper::setHintsForDangerousNeighbourhood
 */
void Minesweeper::setHintsForDangerousNeighbourhood(){
    int surroundingMines = 0;
    int rowSize = currentGameMode.getHeigth();
    int colSize = currentGameMode.getWidth();

    // Go through whole Matrix
    for(int m=0;m<rowSize;m++){
        for(int n=0;n<colSize;n++){

            QTableWidgetItem* currItem= ui->tableWidget->item(m,n);
            if (currItem->data(Qt::AccessibleDescriptionRole).toString() != "Mine"){
                // check surrounding cells in 3x3 matrix -> two loops
                for(int i=-1;i<=1;i++){
                    for(int j=-1;j<=1;j++){
                        QTableWidgetItem* item = ui->tableWidget->item(m+j, n+i);

                        // 1. If cell is excisting
                        if(item != 0){
                            if(item->data(Qt::AccessibleDescriptionRole).toString() == "Mine"){
                                surroundingMines++;
                            }
                        }

                    }
                }
                if(surroundingMines == 0){
                    currItem->setData(Qt::AccessibleDescriptionRole,"");
                } else {
                    currItem->setData(Qt::AccessibleDescriptionRole,surroundingMines);
                }
                surroundingMines = 0;
            }
        }
    }
}

/**
 * resize table (gaming area) depending on m x n
 * @brief Minesweeper::resizeWindowSize
 * @param rowsize
 * @param colsize
 */
void Minesweeper::resizeWindowSize(int rows, int cols){
    int colsize = ui->tableWidget->columnWidth(0)*cols;
    int rowsize = ui->tableWidget->rowHeight(0)*rows;
    ui->tableWidget->setFixedSize(rowsize+2,colsize+2);

    if (rowsize < 408){
        this->setMaximumWidth(408);
        this->setMinimumWidth(408);
    } else {
        this->setMaximumWidth(ui->tableWidget->width()+300);
        this->setMinimumWidth(ui->tableWidget->width()+300);
    }

    qDebug()<<QString::number(colsize);
    if (colsize < 362){
        qDebug()<<"kleiner";
        this->setMaximumHeight(362);
        this->setMinimumHeight(362);
    } else {
        qDebug()<<"gr";
        this->setMaximumHeight(ui->tableWidget->height()+150);
        this->setMinimumHeight(ui->tableWidget->height()+150);
    }
    //this->wind
}

/**
 * show TableWidget, if hidden
 * @brief Minesweeper::checkTableVisibility
 */
void Minesweeper::checkTableVisibility(){
    if(ui->tableWidget->isHidden())
        ui->tableWidget->show();
}

/// Calling dialogs

/**
 * Slot for the menu bar
 * Redirect to to their goal destination
 * @brief Minesweeper::callingDialogs
 */
void Minesweeper::callingDialogs(){
    QObject* obj = sender();

    if(obj == ui->actionHilfe) {
        // Open Help-Dialog
        HelpDialog helpDialog;
        helpDialog.exec();
    } else if(obj == ui->actionEinstellungen) {
        // Open Settings-Dialog and get its output (new or excisting gameMode)
        SettingsDialog settingsDialog(this);
        if(gameModes.size() > 0){
            settingsDialog.importGameModes(gameModes);
        }
        if(settingsDialog.exec() == settingsDialog.Accepted){
            GameMode gameMode = settingsDialog.getCurrentGameMode();

            // Update GameModesList
            gameModes = settingsDialog.getGameModesList();

            // Import to List with all gameModes? No duplicated entries
            if(!isGameModeExcisting(gameMode)){
                gameModes.append(gameMode);
            }

            // Set new gameMode to active gameMode
            currentGameMode = gameMode;

            // Prepare for new game.. reset ui, variables...
            resetAll();
        }
    } else if(obj == ui->actionStatistik) {
        // Open Statistics, export gameModeList
        StatistikDialog statistikDialog;
        if(gameModes.size() > 0){
            statistikDialog.importGameModes(gameModes);
        }
        if(statistikDialog.exec() == statistikDialog.Accepted){
            if(statistikDialog.getHasGameModeReset()){
                gameModes.clear();
                gameModes.append(statistikDialog.getGameModesList());
            }
        }
    }
}

/// Gameplay

/**
 * Listener for ClickReleaseEvent on Tablewidget
 * @brief Minesweeper::eventFilter
 * @param object
 * @param event
 * @return
 */
bool Minesweeper::eventFilter(QObject *object, QEvent *event)
{
    if(object == ui->tableWidget->viewport())
    {
        if (event->type() == QEvent::MouseButtonRelease)
        {
            QTableWidgetItem *item = ui->tableWidget->currentItem();
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);

            if ((mouseEvent->button() == Qt::LeftButton)){
                // First Move
                if(!isGameActive){
                    int row = item->row();
                    int col = item->column();
                    firstMoveConfiguration(row, col);
                }
                leftClickAction(item);
            } else if ((mouseEvent->button() == Qt::RightButton)){
                rightClickAction(item);
            } else if ((mouseEvent->button() == Qt::MiddleButton)){
                middleClickAction(item);
            }
            ui->tableWidget->clearSelection();
        }
    }
    return QObject::eventFilter(object, event);
}

/**
 * What happens if cell is left-clicked
 * @brief Minesweeper::leftClickAction
 * @param item
 */
void Minesweeper::leftClickAction(QTableWidgetItem *item){
    QString itemValue = item->data(Qt::AccessibleDescriptionRole).toString();

    if (itemValue == "Mine") {
        // Yes, you've found a Bomb... Booom!! Loose..
        item->setIcon(QIcon(QPixmap("://pics/res/Mine.png")));
        gameIsFinished(false);
    } else {
        // No Bomb, but maybe an already flagged or revealed Field
        if(!item->data(Qt::AccessibleTextRole).toString().contains("finished")){
            // Reveal a save Field
            item->setBackgroundColor(QColor(119,109,109,50));
            item->setData(Qt::AccessibleTextRole, QVariant(tr("finished")));
            item->setText(itemValue);
            // Reveal Neighbours, if DescriptionRole == 0 bzw. ""
            if(itemValue == ""){
                QList<QTableWidgetItem*> list;
                list.append(item);
                revealSaveNeighbours(list);
            }

            if(checkWinningConditions()){
                gameIsFinished(true);
            }
        }
    }
}

/**
 * What happens if cell is right-clicked
 * @brief Minesweeper::rightClickAction
 * @param item
 */
void Minesweeper::rightClickAction(QTableWidgetItem *item){
    if(QString::compare(item->data(Qt::AccessibleTextRole).toString(),"finished") != 0){
        if(item->icon().isNull()){
            item->setIcon(QIcon(QPixmap("://pics/res/Flag.png")));
            item->setData(Qt::AccessibleTextRole, QVariant(tr("flagfinished")));
            updateFlagsInStatusbar(1);
            if(checkWinningConditions()){
                gameIsFinished(true);
            }
        } else {
            item->setIcon(QIcon());
            item->setData(Qt::AccessibleTextRole, QVariant(tr("")));
            lastCheckedRowIdx = item->row();
            lastCheckedColIdx = item->column();
            updateFlagsInStatusbar(-1);
        }
    }
}

/**
 * Takes flag from item
 * @brief Minesweeper::middleClickAction
 * @param item
 */
void Minesweeper::middleClickAction(QTableWidgetItem *item){
    if(!item->icon().isNull()){
        item->setIcon(QIcon());
        item->setData(Qt::AccessibleTextRole, QVariant(tr("")));
        lastCheckedRowIdx = item->row();
        lastCheckedColIdx = item->column();
        updateFlagsInStatusbar(-1);
    }
}

/**
 * recursively reveal cells, if DescriptionRole = "" (no surrounding mines)
 * @brief Minesweeper::revealSaveNeighbours
 * @param item
 */
void Minesweeper::revealSaveNeighbours(QList<QTableWidgetItem*> list){

    // This list is filled with celld, that should become
    // revealed too
    QList<QTableWidgetItem*> revealableCells;

    // Iterate through List with Items
    foreach(QTableWidgetItem* item, list){
        int initialRow = item->row();      //width
        int initialCol = item->column();   //height

        // check surrounding cells in 3x3 matrix -> two loops
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                QTableWidgetItem* currItem = ui->tableWidget->item(initialRow+j, initialCol+i);

                // 1. If cell is excisting
                if(currItem != 0){

                    // 2. If cell is not already revealed
                    if(!currItem->data(Qt::AccessibleTextRole).toString().contains("finished")){

                        // Reveal Cell and update tmp List, if valid
                        currItem->setBackgroundColor(QColor(119,109,109,50));
                        currItem->setData(Qt::AccessibleTextRole, QVariant(tr("finished")));
                        QString text = currItem->data(Qt::AccessibleDescriptionRole).toString();
                        currItem->setText(text);
                        if(text == ""){
                            revealableCells.append(currItem);
                        }
                    }
                }
            }
        }
    }

    // recursive call same function
    if(revealableCells.size() > 0){
        revealSaveNeighbours(revealableCells);
    }
}

/**
 * check winning conditions after each turn and save last false check at index x,y
 * so we dont check the whole matrix again and again
 * @brief Minesweeper::checkWinningConditions
 * @return
 */
bool Minesweeper::checkWinningConditions(){
    int m = lastCheckedRowIdx;
    int n = lastCheckedColIdx;

    // 1. Fields should be marked as finished
    for(m; m<currentGameMode.getHeigth(); m++){
        for(n; n<currentGameMode.getWidth(); n++){
            QTableWidgetItem* item = ui->tableWidget->item(m,n);
            QString status = item->data(Qt::AccessibleTextRole).toString();
            if(!status.contains("finished")){
                lastCheckedColIdx = n;
                lastCheckedRowIdx = m;
                return false;
            }
        }
        n = 0;
    }

    // 2. Counter of Mines and Flags should be equal
    if(currentGameMode.getMines() != getFlags()){
        return false;
    }
    return true;
}

/**
 * Return true, if gameMode already exists in List
 * else appends new gameMode to List
 * KEYS: WIDTH, HEIGHT, MINES
 * @brief Minesweeper::isGameModeExcisting
 * @param gameMode
 * @return
 */
bool Minesweeper::isGameModeExcisting(GameMode gameMode)
{
    int width = gameMode.getWidth();
    int height = gameMode.getHeigth();
    int mines = gameMode.getMines();
    foreach (GameMode gm, gameModes) {
        if(gm.getWidth() == width && gm.getHeigth() == height && gm.getMines() == mines){
            return true;
        }
    }
    return false;
}

/**
 * Do all the things that have to be done
 * when the game is finished
 * no matter whether won or lost
 * @brief Minesweeper::gameIsFinished
 */
void Minesweeper::gameIsFinished(bool succes){
    QString message;
    timer->stop();
    if(succes){
        message = "Du hast das Spiel gewonnen";
        callMessageBox(message);
    } else {
        message = "Du hast das Spiel verloren!";
        ui->statusLabel->setText(message);
        revealTable();
    }
    ui->newgamePushbutton->setEnabled(true);
    ui->pausegamePushbutton->setDisabled(true);
    ui->endgamePushbutton->setDisabled(true);
    ui->tableWidget->setDisabled(true);

    //Update statistics
    updateStatistics(succes);
}

/**
 * if a new flag is set or taken, this function
 * updates the current count of excisting flags,
 * including to change color, if there are
 * more flags than mines
 * @brief Minesweeper::updateFlagsInStatusbar
 * @param flag
 */
void Minesweeper::updateFlagsInStatusbar(int flagaddOrSubFlag){
    int currentFlags = getFlags();
    QPalette palette;
    QBrush brush;

    if(flagaddOrSubFlag == 1){
        currentFlags++;
    } else {
        currentFlags--;
    }
    if(currentFlags > currentGameMode.getMines()){
        brush.setColor(QColor(255, 0, 0, 255));
    } else {
        brush.setColor(QColor(0, 0, 255, 255));
    }
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Normal, QPalette::WindowText, brush);
    flagsVarLabel->setPalette(palette);
    flagsVarLabel->setText(QString::number(currentFlags));
    setFlags(currentFlags);
}

/**
 * reset UI and variables for new Game
 * @brief Minesweeper::resetAll
 */
void Minesweeper::resetAll(){

    // Reset TableWidget
    checkTableVisibility();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setEnabled(true);

    // Reset Statusbar
    flagsVarLabel->setText("0");
    minesVarLabel->setText(QString::number(currentGameMode.getMines()));

    resetUIWhenPaused(false);
    ui->newgamePushbutton->setDisabled(true);

    // init new game area
    initNewGame();

    // reset backend
    isGameActive = false;
    lastCheckedRowIdx = 0;
    lastCheckedColIdx = 0;
    setFlags(0);
    time.setHMS(0,0,0,0);
    timeVarLabel->setText(time.toString("mm:ss"));
    timer->stop();
}

/**
 * Update LabelText if value is valid
 * @brief Minesweeper::updateLabelText
 * @param label
 * @param value
 */
void Minesweeper::updateLabelText(QLabel* label, int value){
    if(value != -1)
        label->setText(QString::number(value));
}

/**
 * Convert position of clicked cell in matrix into vector position
 * @brief Minesweeper::convertMatrixPositionInVectorPosition
 * @param row
 * @param col
 * @return
 */
int Minesweeper::convertMatrixPositionInVectorPosition(int row, int col){
    int cellVectorPosition = 0;
    for(int m=0;m<currentGameMode.getHeigth();m++) {
        for(int n=0;n<currentGameMode.getWidth();n++){
            if(m == row && n == col){
                return cellVectorPosition;
            }
            cellVectorPosition++;
        }
    }
    return cellVectorPosition;
}

/**
 * Slot, activated through new Game or
 * going on with game after pause
 * @brief Minesweeper::startSessionTimer
 */
void Minesweeper::startSessionTimer(){
    timer->start(1000);
}

/**
 * Slot, activated through Pause-Event
 * @brief Minesweeper::stopSessionTimer
 */
void Minesweeper::stopSessionTimer(){
    if(ui->pausegamePushbutton->text() == "Pause"){
        timer->stop();
        resetUIWhenPaused(true);
    } else {
        timer->start();
        resetUIWhenPaused(false);
    }
}

/**
 * Additional part of resetting the game
 * in normal or paused status, relevant for new Game
 * @brief Minesweeper::resetUIWhenPaused
 * @param isGameActive
 */
void Minesweeper::resetUIWhenPaused(bool isGameActive){
    if(isGameActive){
        ui->pausegamePushbutton->setText("Weiter");
        ui->tableWidget->hide();
        ui->statusLabel->setText("Das Spiel ist pausiert..");
    } else {
        ui->pausegamePushbutton->setText("Pause");
        ui->tableWidget->show();
        ui->statusLabel->clear();
    }
}

/**
 * This function is called, when the Game has ended.
 * It updates the statistics to the currentGameMode and
 * changes parameters: Games, Won, Lost, Record
 * @brief Minesweeper::updateStatistics
 * @param succes
 */
void Minesweeper::updateStatistics(bool succes)
{
    int width = currentGameMode.getWidth();
    int height = currentGameMode.getHeigth();
    int mines = currentGameMode.getMines();
    int counter = 0;
    foreach (GameMode mode, gameModes) {
        if(mode.getWidth() == width && mode.getHeigth() == height && mode.getMines() == mines){
            GameMode tmpMode = mode;
            Statistics stats = tmpMode.getStats();
            stats.setPlayedGames(stats.getPlayedGames()+1);
            if (succes){
                stats.setWonGames(stats.getWonGames()+1);
                if(stats.getRecord() == ""){
                    stats.setRecord(time.toString("mm:ss"));
                } else {
                    if(time < QTime::fromString(stats.getRecord(),"mm:ss")){
                        stats.setRecord(time.toString("mm:ss"));
                    }
                }
            } else {
                stats.setLostGames(stats.getLostGames()+1);
            }
            tmpMode.setStats(stats);
            mode = tmpMode;
            gameModes.replace(counter,tmpMode);
        }
        counter++;
    }
}

/**
 * Slot for Updating Time
 * @brief Minesweeper::updateTime
 */
void Minesweeper::updateTime(){
    time = time.addSecs(1);
    timeVarLabel->setText(time.toString("mm:ss"));
}

/**
 * Slot which is activated when the game ended by button signal
 * @brief Minesweeper::lostGame
 */
void Minesweeper::lostGame(){
    checkTableVisibility();
    gameIsFinished(false);
}

/**
 * compare two strings, which own info to one item
 * whether a flag was placed correctly or not
 * @brief Minesweeper::isFlaggingOnItemCorrect
 * @param mine
 * @param flag
 * @return
 */
bool Minesweeper::isFlaggingOnItemCorrect(QString mine, QString flag){
    if(flag.contains("flag") && mine.contains("Mine")){
        return true;
    } else {
        return false;
    }
}

/**
 * Show all fields after the game has finished
 * @brief Minesweeper::revealTable
 */
void Minesweeper::revealTable(){
    for(int m=0;m<currentGameMode.getHeigth();m++){
        for(int n=0;n<currentGameMode.getWidth();n++){
            QTableWidgetItem* item = ui->tableWidget->item(m,n);
            QString itemValue = item->data(Qt::AccessibleDescriptionRole).toString();
            QString itemValueModificated = item->data(Qt::AccessibleTextRole).toString();

            // setText or mine-icon if it's a mine
            if (itemValue == "Mine"){
                item->setIcon(QIcon(QPixmap("://pics/res/Mine.png")));
            } else {
                item->setIcon(QIcon());
                item->setText(itemValue);
            }

            // set Backgroundcolor for flagged or normal fields
            if(itemValueModificated.contains("flag")){
                if(isFlaggingOnItemCorrect(itemValue, itemValueModificated)){
                    item->setBackgroundColor(QColor(0,0,119,75));
                } else {
                    item->setBackgroundColor(QColor(119,0,0,75));
                }
            } else {
                item->setBackgroundColor(QColor(119,109,109,50));
            }
        }
    }
}

/**
 * Call a Messagebox with given string
 * @brief Minesweeper::callMessageBox
 * @param msg
 */
void Minesweeper::callMessageBox(QString msg){
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();
}

/**
 * Create File to write in and save stream in file,
 * Overwrites excisting file
 * @brief Minesweeper::saveExistingGameModes
 */
void Minesweeper::saveExistingGameModes(){
    QDir::setCurrent(APPDIR);
    QFile file(FILENAME);

    // give permissions to created file
    if (file.setPermissions(QFile::ReadOwner|QFile::WriteOwner|QFile::ExeOwner|QFile::ReadGroup|QFile::ExeGroup|QFile::ReadOther|QFile::ExeOther)){
    }

    if ( file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text) )
    {
        QString output = buildMyOutputString();
        QTextStream stream( &file );
        stream << output;
    }
}

/**
 * Get all GameModes from List and put them semicolon-separated in stream
 * @brief Minesweeper::buildMyOutputString
 * @return
 */
QString Minesweeper::buildMyOutputString(){
    QString output, header, gameModeString;
    header += "width;height;mines;games;won;lost;record \n";
    output = header;
    foreach(GameMode mode, gameModes){
        gameModeString = "";
        gameModeString += QString::number(mode.getWidth()) + ";";
        gameModeString += QString::number(mode.getHeigth()) + ";";
        gameModeString += QString::number(mode.getMines()) + ";";
        gameModeString += QString::number(mode.getStats().getPlayedGames()) + ";";
        gameModeString += QString::number(mode.getStats().getWonGames()) + ";";
        gameModeString += QString::number(mode.getStats().getLostGames()) + ";";
        gameModeString += mode.getStats().getRecord() + "\n";
        output += gameModeString;
    }
    return output;
}

/////////////////////////
/// Getter and Setter ///
/////////////////////////

int Minesweeper::getFlags() const
{
    return flags;
}

void Minesweeper::setFlags(int value)
{
    flags = value;
}
