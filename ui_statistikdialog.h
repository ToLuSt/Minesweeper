/********************************************************************************
** Form generated from reading UI file 'statistikdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTIKDIALOG_H
#define UI_STATISTIKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatistikDialog
{
public:
    QGridLayout *gridLayout_3;
    QPushButton *okayPushbutton;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QComboBox *gameModesComboBox;
    QPushButton *resetPushButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *gamesPlayedLabel;
    QLabel *wonGamesLabel;
    QLabel *lostGamesLabel;
    QLabel *recordTimeLabel;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *StatistikDialog)
    {
        if (StatistikDialog->objectName().isEmpty())
            StatistikDialog->setObjectName(QStringLiteral("StatistikDialog"));
        StatistikDialog->resize(400, 320);
        StatistikDialog->setMinimumSize(QSize(400, 320));
        StatistikDialog->setMaximumSize(QSize(400, 320));
        gridLayout_3 = new QGridLayout(StatistikDialog);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        okayPushbutton = new QPushButton(StatistikDialog);
        okayPushbutton->setObjectName(QStringLiteral("okayPushbutton"));

        gridLayout_3->addWidget(okayPushbutton, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(206, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        widget = new QWidget(StatistikDialog);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setWordWrap(true);

        verticalLayout_3->addWidget(label_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gameModesComboBox = new QComboBox(widget);
        gameModesComboBox->setObjectName(QStringLiteral("gameModesComboBox"));

        horizontalLayout->addWidget(gameModesComboBox);

        resetPushButton = new QPushButton(widget);
        resetPushButton->setObjectName(QStringLiteral("resetPushButton"));
        resetPushButton->setMaximumSize(QSize(110, 16777215));
        resetPushButton->setAutoDefault(false);

        horizontalLayout->addWidget(resetPushButton);


        verticalLayout_3->addLayout(horizontalLayout);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gamesPlayedLabel = new QLabel(groupBox);
        gamesPlayedLabel->setObjectName(QStringLiteral("gamesPlayedLabel"));

        verticalLayout_2->addWidget(gamesPlayedLabel);

        wonGamesLabel = new QLabel(groupBox);
        wonGamesLabel->setObjectName(QStringLiteral("wonGamesLabel"));

        verticalLayout_2->addWidget(wonGamesLabel);

        lostGamesLabel = new QLabel(groupBox);
        lostGamesLabel->setObjectName(QStringLiteral("lostGamesLabel"));

        verticalLayout_2->addWidget(lostGamesLabel);

        recordTimeLabel = new QLabel(groupBox);
        recordTimeLabel->setObjectName(QStringLiteral("recordTimeLabel"));

        verticalLayout_2->addWidget(recordTimeLabel);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);


        verticalLayout_3->addWidget(groupBox);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget, 0, 0, 1, 3);


        retranslateUi(StatistikDialog);

        QMetaObject::connectSlotsByName(StatistikDialog);
    } // setupUi

    void retranslateUi(QDialog *StatistikDialog)
    {
        StatistikDialog->setWindowTitle(QApplication::translate("StatistikDialog", "Statistiken", Q_NULLPTR));
        okayPushbutton->setText(QApplication::translate("StatistikDialog", "Verlassen", Q_NULLPTR));
        label_5->setText(QApplication::translate("StatistikDialog", "Hier findest du eine \303\234bersicht \303\274ber alle gespielten Spiele.", Q_NULLPTR));
        resetPushButton->setText(QApplication::translate("StatistikDialog", "Zur\303\274cksetzen", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("StatistikDialog", "Spielstatistik", Q_NULLPTR));
        label->setText(QApplication::translate("StatistikDialog", "Spiele gespielt:", Q_NULLPTR));
        label_2->setText(QApplication::translate("StatistikDialog", "davon gewonnen:", Q_NULLPTR));
        label_3->setText(QApplication::translate("StatistikDialog", "davon verloren:", Q_NULLPTR));
        label_4->setText(QApplication::translate("StatistikDialog", "Rekordzeit:", Q_NULLPTR));
        gamesPlayedLabel->setText(QString());
        wonGamesLabel->setText(QString());
        lostGamesLabel->setText(QString());
        recordTimeLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StatistikDialog: public Ui_StatistikDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTIKDIALOG_H
