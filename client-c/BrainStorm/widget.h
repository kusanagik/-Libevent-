#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "communicate.h"
#include "register.h"
#include "../common.h"
#include "brainstorm.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_logpushButton_clicked();

    void on_regpushButton_clicked();

    void login(QJsonObject json);

private:
    Ui::Widget *ui;
    Communicate *_com;
};
#endif // WIDGET_H
