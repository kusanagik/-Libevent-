/********************************************************************************
** Form generated from reading UI file 'brainstorm.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRAINSTORM_H
#define UI_BRAINSTORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BrainStorm
{
public:
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *mainMenu;
    QPushButton *rankButton;
    QPushButton *singlepushButton;
    QWidget *single_menu;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QPushButton *Single_start;
    QPushButton *Single_back;
    QWidget *single_running;
    QLabel *Question;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *singleSelectButton1;
    QPushButton *singleSelectButton2;
    QPushButton *singleSelectButton3;
    QPushButton *singleSelectButton4;
    QLCDNumber *lcdNumber;
    QWidget *single_score;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_4;
    QLabel *singleResult;
    QSpacerItem *verticalSpacer_5;
    QLabel *singleScore;
    QSpacerItem *verticalSpacer_3;
    QPushButton *BackpushButton;
    QWidget *rank_wait;
    QLabel *label_3;
    QWidget *rank_running;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_5;
    QPushButton *rankSelectButton1;
    QPushButton *rankSelectButton2;
    QPushButton *rankSelectButton3;
    QPushButton *rankSelectButton4;
    QLabel *rankQuestion;
    QLCDNumber *lcdNumber_2;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *enemyStatus;
    QLabel *selfStatus;
    QWidget *rank_result;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_7;
    QLabel *rankResult;
    QLabel *Newrank;
    QSpacerItem *verticalSpacer_6;
    QPushButton *BackpushButton_2;

    void setupUi(QDialog *BrainStorm)
    {
        if (BrainStorm->objectName().isEmpty())
            BrainStorm->setObjectName(QString::fromUtf8("BrainStorm"));
        BrainStorm->resize(418, 574);
        verticalLayout_2 = new QVBoxLayout(BrainStorm);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        stackedWidget = new QStackedWidget(BrainStorm);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        mainMenu = new QWidget();
        mainMenu->setObjectName(QString::fromUtf8("mainMenu"));
        rankButton = new QPushButton(mainMenu);
        rankButton->setObjectName(QString::fromUtf8("rankButton"));
        rankButton->setGeometry(QRect(100, 60, 191, 61));
        singlepushButton = new QPushButton(mainMenu);
        singlepushButton->setObjectName(QString::fromUtf8("singlepushButton"));
        singlepushButton->setGeometry(QRect(100, 160, 191, 61));
        stackedWidget->addWidget(mainMenu);
        single_menu = new QWidget();
        single_menu->setObjectName(QString::fromUtf8("single_menu"));
        verticalLayout = new QVBoxLayout(single_menu);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(single_menu);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(24);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(single_menu);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        Single_start = new QPushButton(single_menu);
        Single_start->setObjectName(QString::fromUtf8("Single_start"));

        verticalLayout->addWidget(Single_start);

        Single_back = new QPushButton(single_menu);
        Single_back->setObjectName(QString::fromUtf8("Single_back"));

        verticalLayout->addWidget(Single_back);

        stackedWidget->addWidget(single_menu);
        single_running = new QWidget();
        single_running->setObjectName(QString::fromUtf8("single_running"));
        Question = new QLabel(single_running);
        Question->setObjectName(QString::fromUtf8("Question"));
        Question->setGeometry(QRect(0, 130, 401, 201));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(20);
        Question->setFont(font2);
        Question->setWordWrap(true);
        widget = new QWidget(single_running);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(110, 340, 161, 221));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        singleSelectButton1 = new QPushButton(widget);
        singleSelectButton1->setObjectName(QString::fromUtf8("singleSelectButton1"));

        verticalLayout_3->addWidget(singleSelectButton1);

        singleSelectButton2 = new QPushButton(widget);
        singleSelectButton2->setObjectName(QString::fromUtf8("singleSelectButton2"));

        verticalLayout_3->addWidget(singleSelectButton2);

        singleSelectButton3 = new QPushButton(widget);
        singleSelectButton3->setObjectName(QString::fromUtf8("singleSelectButton3"));

        verticalLayout_3->addWidget(singleSelectButton3);

        singleSelectButton4 = new QPushButton(widget);
        singleSelectButton4->setObjectName(QString::fromUtf8("singleSelectButton4"));

        verticalLayout_3->addWidget(singleSelectButton4);

        lcdNumber = new QLCDNumber(single_running);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(140, 0, 111, 111));
        lcdNumber->setFont(font);
        stackedWidget->addWidget(single_running);
        single_score = new QWidget();
        single_score->setObjectName(QString::fromUtf8("single_score"));
        verticalLayout_4 = new QVBoxLayout(single_score);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);

        singleResult = new QLabel(single_score);
        singleResult->setObjectName(QString::fromUtf8("singleResult"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setPointSize(26);
        singleResult->setFont(font3);
        singleResult->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(singleResult);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        singleScore = new QLabel(single_score);
        singleScore->setObjectName(QString::fromUtf8("singleScore"));
        singleScore->setFont(font3);
        singleScore->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(singleScore);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        BackpushButton = new QPushButton(single_score);
        BackpushButton->setObjectName(QString::fromUtf8("BackpushButton"));

        verticalLayout_4->addWidget(BackpushButton);

        stackedWidget->addWidget(single_score);
        rank_wait = new QWidget();
        rank_wait->setObjectName(QString::fromUtf8("rank_wait"));
        label_3 = new QLabel(rank_wait);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 140, 321, 131));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font4.setPointSize(22);
        label_3->setFont(font4);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(rank_wait);
        rank_running = new QWidget();
        rank_running->setObjectName(QString::fromUtf8("rank_running"));
        widget_2 = new QWidget(rank_running);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(90, 330, 161, 211));
        verticalLayout_5 = new QVBoxLayout(widget_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        rankSelectButton1 = new QPushButton(widget_2);
        rankSelectButton1->setObjectName(QString::fromUtf8("rankSelectButton1"));

        verticalLayout_5->addWidget(rankSelectButton1);

        rankSelectButton2 = new QPushButton(widget_2);
        rankSelectButton2->setObjectName(QString::fromUtf8("rankSelectButton2"));

        verticalLayout_5->addWidget(rankSelectButton2);

        rankSelectButton3 = new QPushButton(widget_2);
        rankSelectButton3->setObjectName(QString::fromUtf8("rankSelectButton3"));

        verticalLayout_5->addWidget(rankSelectButton3);

        rankSelectButton4 = new QPushButton(widget_2);
        rankSelectButton4->setObjectName(QString::fromUtf8("rankSelectButton4"));

        verticalLayout_5->addWidget(rankSelectButton4);

        rankQuestion = new QLabel(rank_running);
        rankQuestion->setObjectName(QString::fromUtf8("rankQuestion"));
        rankQuestion->setGeometry(QRect(0, 130, 401, 171));
        rankQuestion->setFont(font2);
        rankQuestion->setAlignment(Qt::AlignCenter);
        rankQuestion->setWordWrap(true);
        lcdNumber_2 = new QLCDNumber(rank_running);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(270, 10, 101, 101));
        lcdNumber_2->setFont(font2);
        widget_3 = new QWidget(rank_running);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(20, 20, 221, 91));
        verticalLayout_6 = new QVBoxLayout(widget_3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        enemyStatus = new QLabel(widget_3);
        enemyStatus->setObjectName(QString::fromUtf8("enemyStatus"));

        verticalLayout_6->addWidget(enemyStatus);

        selfStatus = new QLabel(widget_3);
        selfStatus->setObjectName(QString::fromUtf8("selfStatus"));

        verticalLayout_6->addWidget(selfStatus);

        stackedWidget->addWidget(rank_running);
        rank_result = new QWidget();
        rank_result->setObjectName(QString::fromUtf8("rank_result"));
        verticalLayout_7 = new QVBoxLayout(rank_result);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_7->addItem(verticalSpacer_7);

        rankResult = new QLabel(rank_result);
        rankResult->setObjectName(QString::fromUtf8("rankResult"));
        rankResult->setFont(font);
        rankResult->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(rankResult);

        Newrank = new QLabel(rank_result);
        Newrank->setObjectName(QString::fromUtf8("Newrank"));
        Newrank->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(Newrank);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_6);

        BackpushButton_2 = new QPushButton(rank_result);
        BackpushButton_2->setObjectName(QString::fromUtf8("BackpushButton_2"));

        verticalLayout_7->addWidget(BackpushButton_2);

        stackedWidget->addWidget(rank_result);

        verticalLayout_2->addWidget(stackedWidget);


        retranslateUi(BrainStorm);

        QMetaObject::connectSlotsByName(BrainStorm);
    } // setupUi

    void retranslateUi(QDialog *BrainStorm)
    {
        BrainStorm->setWindowTitle(QCoreApplication::translate("BrainStorm", "Dialog", nullptr));
        rankButton->setText(QCoreApplication::translate("BrainStorm", "\346\216\222\344\275\215\350\265\233", nullptr));
        singlepushButton->setText(QCoreApplication::translate("BrainStorm", "\344\270\252\344\272\272\350\256\255\347\273\203", nullptr));
        label->setText(QCoreApplication::translate("BrainStorm", "\350\277\236\347\273\255\347\255\224\345\257\271\344\272\224\351\201\223\351\242\230", nullptr));
        label_2->setText(QCoreApplication::translate("BrainStorm", "\347\255\224\351\224\231\347\273\223\346\235\237\350\277\224\345\233\236", nullptr));
        Single_start->setText(QCoreApplication::translate("BrainStorm", "\345\274\200\345\247\213\347\255\224\351\242\230", nullptr));
        Single_back->setText(QCoreApplication::translate("BrainStorm", "\350\277\224\345\233\236", nullptr));
        Question->setText(QCoreApplication::translate("BrainStorm", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        singleSelectButton1->setText(QCoreApplication::translate("BrainStorm", "PushButton", nullptr));
        singleSelectButton2->setText(QCoreApplication::translate("BrainStorm", "PushButton", nullptr));
        singleSelectButton3->setText(QCoreApplication::translate("BrainStorm", "PushButton", nullptr));
        singleSelectButton4->setText(QCoreApplication::translate("BrainStorm", "PushButton", nullptr));
        singleResult->setText(QCoreApplication::translate("BrainStorm", "TextLabel", nullptr));
        singleScore->setText(QCoreApplication::translate("BrainStorm", "TextLabel", nullptr));
        BackpushButton->setText(QCoreApplication::translate("BrainStorm", "\350\277\224\345\233\236", nullptr));
        label_3->setText(QCoreApplication::translate("BrainStorm", "\346\255\243\345\234\250\345\214\271\351\205\215\345\257\271\346\211\213...", nullptr));
        rankSelectButton1->setText(QCoreApplication::translate("BrainStorm", "PushButton", nullptr));
        rankSelectButton2->setText(QCoreApplication::translate("BrainStorm", "PushButton", nullptr));
        rankSelectButton3->setText(QCoreApplication::translate("BrainStorm", "PushButton", nullptr));
        rankSelectButton4->setText(QCoreApplication::translate("BrainStorm", "PushButton", nullptr));
        rankQuestion->setText(QCoreApplication::translate("BrainStorm", "A", nullptr));
        enemyStatus->setText(QCoreApplication::translate("BrainStorm", "\345\260\217\346\230\216 \351\273\204\351\207\2211 1\351\242\227\346\230\237\357\274\232120\345\210\206", nullptr));
        selfStatus->setText(QCoreApplication::translate("BrainStorm", "\345\260\217\347\272\242 \347\231\275\351\223\2663 3\351\242\227\346\230\237\357\274\232140\345\210\206", nullptr));
        rankResult->setText(QCoreApplication::translate("BrainStorm", "\350\203\234\345\210\251", nullptr));
        Newrank->setText(QCoreApplication::translate("BrainStorm", "\351\273\204\351\207\2211 2\351\242\227\346\230\237 ---> \351\273\204\351\207\2211 3\351\242\227\346\230\237", nullptr));
        BackpushButton_2->setText(QCoreApplication::translate("BrainStorm", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BrainStorm: public Ui_BrainStorm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRAINSTORM_H
