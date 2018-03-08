/********************************************************************************
** Form generated from reading UI file 'minesweeper.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINESWEEPER_H
#define UI_MINESWEEPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Minesweeper
{
public:
    QAction *actionEinstellungen;
    QAction *actionStatistik;
    QAction *actionHilfe;
    QAction *actionAnwendung_schliessen;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *newgamePushbutton;
    QPushButton *pausegamePushbutton;
    QPushButton *endgamePushbutton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget;
    QSpacerItem *horizontalSpacer_2;
    QLabel *statusLabel;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuMen;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Minesweeper)
    {
        if (Minesweeper->objectName().isEmpty())
            Minesweeper->setObjectName(QStringLiteral("Minesweeper"));
        Minesweeper->resize(408, 362);
        Minesweeper->setMaximumSize(QSize(1400, 800));
        QIcon icon;
        icon.addFile(QStringLiteral(":/pics/res/Mine.png"), QSize(), QIcon::Normal, QIcon::Off);
        Minesweeper->setWindowIcon(icon);
        actionEinstellungen = new QAction(Minesweeper);
        actionEinstellungen->setObjectName(QStringLiteral("actionEinstellungen"));
        actionStatistik = new QAction(Minesweeper);
        actionStatistik->setObjectName(QStringLiteral("actionStatistik"));
        actionHilfe = new QAction(Minesweeper);
        actionHilfe->setObjectName(QStringLiteral("actionHilfe"));
        actionAnwendung_schliessen = new QAction(Minesweeper);
        actionAnwendung_schliessen->setObjectName(QStringLiteral("actionAnwendung_schliessen"));
        centralWidget = new QWidget(Minesweeper);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        newgamePushbutton = new QPushButton(centralWidget);
        newgamePushbutton->setObjectName(QStringLiteral("newgamePushbutton"));
        newgamePushbutton->setMinimumSize(QSize(120, 0));

        horizontalLayout->addWidget(newgamePushbutton);

        pausegamePushbutton = new QPushButton(centralWidget);
        pausegamePushbutton->setObjectName(QStringLiteral("pausegamePushbutton"));
        pausegamePushbutton->setEnabled(true);
        pausegamePushbutton->setMinimumSize(QSize(120, 0));

        horizontalLayout->addWidget(pausegamePushbutton);

        endgamePushbutton = new QPushButton(centralWidget);
        endgamePushbutton->setObjectName(QStringLiteral("endgamePushbutton"));
        endgamePushbutton->setEnabled(true);
        endgamePushbutton->setMinimumSize(QSize(120, 0));

        horizontalLayout->addWidget(endgamePushbutton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidget->setAutoScroll(true);
        tableWidget->setAutoScrollMargin(16);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setTextElideMode(Qt::ElideNone);
        tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget->setCornerButtonEnabled(false);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(20);
        tableWidget->horizontalHeader()->setMinimumSectionSize(20);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(20);
        tableWidget->verticalHeader()->setMinimumSectionSize(20);

        horizontalLayout_2->addWidget(tableWidget);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        statusLabel = new QLabel(centralWidget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(statusLabel, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        Minesweeper->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Minesweeper);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 408, 22));
        menuMen = new QMenu(menuBar);
        menuMen->setObjectName(QStringLiteral("menuMen"));
        Minesweeper->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Minesweeper);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Minesweeper->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Minesweeper);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Minesweeper->setStatusBar(statusBar);

        menuBar->addAction(menuMen->menuAction());
        menuMen->addAction(actionHilfe);
        menuMen->addAction(actionStatistik);
        menuMen->addAction(actionEinstellungen);
        menuMen->addSeparator();
        menuMen->addAction(actionAnwendung_schliessen);

        retranslateUi(Minesweeper);

        QMetaObject::connectSlotsByName(Minesweeper);
    } // setupUi

    void retranslateUi(QMainWindow *Minesweeper)
    {
        Minesweeper->setWindowTitle(QApplication::translate("Minesweeper", "Minesweeper", Q_NULLPTR));
        actionEinstellungen->setText(QApplication::translate("Minesweeper", "Einstellungen", Q_NULLPTR));
        actionStatistik->setText(QApplication::translate("Minesweeper", "Statistik", Q_NULLPTR));
        actionHilfe->setText(QApplication::translate("Minesweeper", "Hilfe", Q_NULLPTR));
        actionAnwendung_schliessen->setText(QApplication::translate("Minesweeper", "Anwendung schlie\303\237en", Q_NULLPTR));
        newgamePushbutton->setText(QApplication::translate("Minesweeper", "Neues Spiel", Q_NULLPTR));
        pausegamePushbutton->setText(QApplication::translate("Minesweeper", "Pause", Q_NULLPTR));
        endgamePushbutton->setText(QApplication::translate("Minesweeper", "Beenden", Q_NULLPTR));
        statusLabel->setText(QString());
        menuMen->setTitle(QApplication::translate("Minesweeper", "Men\303\274", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Minesweeper: public Ui_Minesweeper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINESWEEPER_H
