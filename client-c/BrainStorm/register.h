#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QJsonObject>
#include "../common.h"
#include "communicate.h"
#include <QMessageBox>
#include <QString>
namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(Communicate *com, QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_RegpushButton_clicked();

    void on_BackpushButton_clicked();

    void rstResult(int );

private:
    Ui::Register *ui;
    Communicate *_com;
};

#endif // REGISTER_H
