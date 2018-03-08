/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QSpinBox *rowsSpinBox;
    QLabel *label_6;
    QLabel *label_3;
    QSpinBox *colsSpinBox;
    QLabel *label_7;
    QLabel *label_4;
    QSpinBox *minesSpinBox;
    QLabel *label_5;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *gameModesComboBox;
    QPushButton *deletePushButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QStringLiteral("SettingsDialog"));
        SettingsDialog->resize(420, 370);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SettingsDialog->sizePolicy().hasHeightForWidth());
        SettingsDialog->setSizePolicy(sizePolicy);
        SettingsDialog->setMinimumSize(QSize(420, 370));
        SettingsDialog->setMaximumSize(QSize(420, 370));
        gridLayout = new QGridLayout(SettingsDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget = new QWidget(SettingsDialog);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(true);

        verticalLayout_2->addWidget(label);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        rowsSpinBox = new QSpinBox(groupBox);
        rowsSpinBox->setObjectName(QStringLiteral("rowsSpinBox"));
        rowsSpinBox->setMinimumSize(QSize(60, 0));
        rowsSpinBox->setMinimum(4);
        rowsSpinBox->setMaximum(25);

        gridLayout_2->addWidget(rowsSpinBox, 0, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_6, 0, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        colsSpinBox = new QSpinBox(groupBox);
        colsSpinBox->setObjectName(QStringLiteral("colsSpinBox"));
        colsSpinBox->setMinimumSize(QSize(60, 0));
        colsSpinBox->setMinimum(4);
        colsSpinBox->setMaximum(25);

        gridLayout_2->addWidget(colsSpinBox, 1, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_7, 1, 2, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        minesSpinBox = new QSpinBox(groupBox);
        minesSpinBox->setObjectName(QStringLiteral("minesSpinBox"));
        minesSpinBox->setMinimumSize(QSize(60, 0));
        minesSpinBox->setMinimum(3);
        minesSpinBox->setMaximum(150);
        minesSpinBox->setValue(3);

        gridLayout_2->addWidget(minesSpinBox, 2, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_5, 2, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox);


        gridLayout_4->addLayout(verticalLayout_2, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gameModesComboBox = new QComboBox(groupBox_2);
        gameModesComboBox->setObjectName(QStringLiteral("gameModesComboBox"));
        gameModesComboBox->setMinimumSize(QSize(235, 0));

        horizontalLayout_2->addWidget(gameModesComboBox);

        deletePushButton = new QPushButton(groupBox_2);
        deletePushButton->setObjectName(QStringLiteral("deletePushButton"));

        horizontalLayout_2->addWidget(deletePushButton);


        gridLayout_5->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(SettingsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(SettingsDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Einstellungen", Q_NULLPTR));
        label->setText(QApplication::translate("SettingsDialog", "<html><head/><body><p>Lege hier den Schwierigkeitsgrad f\303\274r dein n\303\244chstes Spiel fest. W\303\244hle einen Eintrag aus der Liste um einen bestehenden Spielmodus spielen.</p></body></html>", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("SettingsDialog", "Neuer Spielmodus", Q_NULLPTR));
        label_2->setText(QApplication::translate("SettingsDialog", "Zeilen", Q_NULLPTR));
        label_6->setText(QApplication::translate("SettingsDialog", "<html><head/><body><p><span style=\" color:#776d6d;\">(Max. 25 Zeilen)</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("SettingsDialog", "Spalten", Q_NULLPTR));
        label_7->setText(QApplication::translate("SettingsDialog", "<html><head/><body><p><span style=\" color:#776d6d;\">(Max. 25 Spalten)</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("SettingsDialog", "Minen", Q_NULLPTR));
        label_5->setText(QApplication::translate("SettingsDialog", "<html><head/><body><p><span style=\" color:#776d6d;\">(Max. 20% Minen)</span></p></body></html>", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("SettingsDialog", "Spielmodus ausw\303\244hlen", Q_NULLPTR));
        deletePushButton->setText(QApplication::translate("SettingsDialog", "L\303\266schen", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
