#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pb_coffee->setEnabled(false);
    ui->pb_tea->setEnabled(false);
    ui->pb_milk->setEnabled(false);
    ui->pb_Reset->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changemoney(int diff){
    money+=diff;
    ui->lcdNumber->display(money);
    if(money>=100) ui->pb_coffee->setEnabled(true);
    else ui->pb_coffee->setEnabled(false);
    if(money>=150) ui->pb_tea->setEnabled(true);
    else ui->pb_tea->setEnabled(false);
    if(money>=200) ui->pb_milk->setEnabled(true);
    else ui->pb_milk->setEnabled(false);
    if(money!=0) ui->pb_Reset->setEnabled(true);
    else ui->pb_Reset->setEnabled(false);

}


void Widget::on_pbCoin10_clicked()
{
    changemoney(10);
}


void Widget::on_pbCoin50_clicked()
{
    changemoney(50);
}

void Widget::on_pbCoin100_clicked()
{
    changemoney(100);
}

void Widget::on_pbCoin500_clicked()
{
    changemoney(500);
}

void Widget::on_pb_coffee_clicked()
{
    changemoney(-100);
}


void Widget::on_pb_tea_clicked()
{
    changemoney(-150);
}


void Widget::on_pb_milk_clicked()
{
    changemoney(-200);
}



void Widget::on_pb_Reset_clicked()
{
    char buffer [128];
    QMessageBox mb;
    int money_500 = money/500;
    money -= money_500*500;
    int money_100 = money/100;
    money -= money_100*100;
    int money_50 = money/50;
    money -= money_50*50;
    int money_10 = money/10;
    changemoney(-money_10*10);
    sprintf (buffer, "500 coin: %d\n100 coin: %d\n50 coin: %d\n10 coin: %d", money_500, money_100, money_50, money_10);
    mb.information(this,"money",buffer);
    ui->lcdNumber->display(money);
}
