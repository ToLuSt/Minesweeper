/********************************************************************************
** Form generated from reading UI file 'helpdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPDIALOG_H
#define UI_HELPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_HelpDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *leftMouseLabel;
    QLabel *label;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *rightMouseLabel;
    QLabel *label_2;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *middleMouseLabel;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okayPushbutton;

    void setupUi(QDialog *HelpDialog)
    {
        if (HelpDialog->objectName().isEmpty())
            HelpDialog->setObjectName(QStringLiteral("HelpDialog"));
        HelpDialog->resize(474, 419);
        HelpDialog->setMaximumSize(QSize(474, 419));
        gridLayout = new QGridLayout(HelpDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(HelpDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(450, 120));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        leftMouseLabel = new QLabel(groupBox);
        leftMouseLabel->setObjectName(QStringLiteral("leftMouseLabel"));
        leftMouseLabel->setMaximumSize(QSize(120, 16777215));
        leftMouseLabel->setPixmap(QPixmap(QString::fromUtf8(":/pics/res/Maus_linksklick.png")));

        gridLayout_2->addWidget(leftMouseLabel, 0, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(false);

        gridLayout_2->addWidget(label, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(HelpDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(450, 120));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        rightMouseLabel = new QLabel(groupBox_2);
        rightMouseLabel->setObjectName(QStringLiteral("rightMouseLabel"));
        rightMouseLabel->setMaximumSize(QSize(120, 16777215));
        rightMouseLabel->setPixmap(QPixmap(QString::fromUtf8(":/pics/res/Maus_rechtsklick.png")));

        horizontalLayout_3->addWidget(rightMouseLabel);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_2->setWordWrap(false);

        horizontalLayout_3->addWidget(label_2);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(HelpDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(450, 120));
        horizontalLayout_4 = new QHBoxLayout(groupBox_3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        middleMouseLabel = new QLabel(groupBox_3);
        middleMouseLabel->setObjectName(QStringLiteral("middleMouseLabel"));
        middleMouseLabel->setMaximumSize(QSize(120, 16777215));
        middleMouseLabel->setPixmap(QPixmap(QString::fromUtf8(":/pics/res/Maus_mittlererklick.png")));

        horizontalLayout_4->addWidget(middleMouseLabel);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_3->setWordWrap(false);

        horizontalLayout_4->addWidget(label_3);


        gridLayout->addWidget(groupBox_3, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okayPushbutton = new QPushButton(HelpDialog);
        okayPushbutton->setObjectName(QStringLiteral("okayPushbutton"));

        horizontalLayout->addWidget(okayPushbutton);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);


        retranslateUi(HelpDialog);

        QMetaObject::connectSlotsByName(HelpDialog);
    } // setupUi

    void retranslateUi(QDialog *HelpDialog)
    {
        HelpDialog->setWindowTitle(QApplication::translate("HelpDialog", "Steuerungshinweise", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("HelpDialog", "Linke Maustaste", Q_NULLPTR));
        leftMouseLabel->setText(QString());
        label->setText(QApplication::translate("HelpDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Mit der linken Maustaste deckst du <br/>das angeklickte Feld auf. </p></body></html>", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("HelpDialog", "Rechte Maustaste", Q_NULLPTR));
        rightMouseLabel->setText(QString());
        label_2->setText(QApplication::translate("HelpDialog", "<html><head/><body><p>Mit der rechten Maustaste markierst du <br/>das angeklickte Feld mit einer Flagge<br/> und entfernst diese wieder.</p></body></html>", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("HelpDialog", "Mittlere Maustaste", Q_NULLPTR));
        middleMouseLabel->setText(QString());
        label_3->setText(QApplication::translate("HelpDialog", "<html><head/><body><p>Mit der mittleren Maustaste entfernst du <br/>die Markierung von einem Feld.</p></body></html>", Q_NULLPTR));
        okayPushbutton->setText(QApplication::translate("HelpDialog", "Verstanden", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HelpDialog: public Ui_HelpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPDIALOG_H
