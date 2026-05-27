#include "widget.h"
#include "ui_widget.h"
#include "register.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    _com = new Communicate();
    connect(_com,SIGNAL(login(QJsonObject)),this,SLOT(login(QJsonObject)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::login(QJsonObject json)
{
    int result = json["result"].toInt();

    switch (result)
    {
    case OK:
    {
        this->hide();
        BrainStorm *dig = new BrainStorm(_com,json);
        dig->show();
        dig->setAttribute(Qt::WA_DeleteOnClose);
        break;
    }
    case ERROR:
        QMessageBox::critical(this,"登录","登录失败，未知错误");
        break;
    case USERLOGIN:
        QMessageBox::critical(this,"登录","登录失败，不允许重复登录");
        break;
    case NAMEORPASSWD:
        QMessageBox::critical(this,"登录","用户名或密码错误");
        break;

    }
}

void Widget::on_logpushButton_clicked()
{
    QString userName = ui->UsernamelineEdit->text();
    QString passwd = ui->PasswordlineEdit->text();

    //将登录信息发送给服务器
    QJsonObject json;
    json["cmd"] = LOGIN;
    json["username"] = userName;
    json["passwd"] = passwd;

    //向服务器发送数据
    _com->writeData(json);
}

void Widget::on_regpushButton_clicked()
{
    this->hide();
    Register reg(_com);
    reg.exec();
    this->show();
}
