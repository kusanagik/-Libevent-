/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *PasswordlineEdit;
    QPushButton *RegpushButton;
    QPushButton *BackpushButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLineEdit *UsernamelineEdit;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(485, 386);
        layoutWidget = new QWidget(Register);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 170, 343, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(16);
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        PasswordlineEdit = new QLineEdit(layoutWidget);
        PasswordlineEdit->setObjectName(QStringLiteral("PasswordlineEdit"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(12);
        PasswordlineEdit->setFont(font1);
        PasswordlineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(PasswordlineEdit);

        RegpushButton = new QPushButton(Register);
        RegpushButton->setObjectName(QStringLiteral("RegpushButton"));
        RegpushButton->setGeometry(QRect(90, 240, 141, 51));
        BackpushButton = new QPushButton(Register);
        BackpushButton->setObjectName(QStringLiteral("BackpushButton"));
        BackpushButton->setGeometry(QRect(280, 240, 131, 51));
        widget = new QWidget(Register);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(80, 110, 343, 29));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        UsernamelineEdit = new QLineEdit(widget);
        UsernamelineEdit->setObjectName(QStringLiteral("UsernamelineEdit"));
        UsernamelineEdit->setFont(font1);

        horizontalLayout->addWidget(UsernamelineEdit);


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("Register", "\345\257\206  \347\240\201", Q_NULLPTR));
        RegpushButton->setText(QApplication::translate("Register", "\347\253\213\345\215\263\346\263\250\345\206\214", Q_NULLPTR));
        BackpushButton->setText(QApplication::translate("Register", "\350\277\224\345\233\236", Q_NULLPTR));
        label->setText(QApplication::translate("Register", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
