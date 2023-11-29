#include "calculator.h"
#include "ui_calculator.h"

calculator::calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calculator)
{
    ui->setupUi(this);
}

calculator::~calculator()
{
    delete ui;
}


void calculator::on_addButton_clicked()
{
    int num1=ui->num1lineEdit->text().toInt(); //convert QString to int
    int num2=ui->num2lineEdit->text().toInt();
    int result=num1+num2;
    QString ourResult=QString::number(result); //convert int to QString
    ui->Resultlineedit->setText(ourResult); //setText accepts the Qstring type and string like"hello","1","5" but not int type
}


void calculator::on_subtractButton_clicked()
{
    int num1=ui->num1lineEdit->text().toInt(); //convert QString to int
    int num2=ui->num2lineEdit->text().toInt();
    int result=num1-num2;
    QString ourResult=QString::number(result); //convert int to QString
    ui->Resultlineedit->setText(ourResult); //setText accepts the Qstring type
}


void calculator::on_multiplyButton_clicked()
{
    int num1=ui->num1lineEdit->text().toInt(); //convert QString to int
    int num2=ui->num2lineEdit->text().toInt();
    int result=num1*num2;
    QString ourResult=QString::number(result); //convert int to QString
    ui->Resultlineedit->setText(ourResult); //setText accepts the Qstring type
}


void calculator::on_divideButton_clicked()
{
    int num1=ui->num1lineEdit->text().toInt(); //convert QString to int
    int num2=ui->num2lineEdit->text().toInt();
    int result=num1/num2;
    QString ourResult=QString::number(result); //convert int to QString
    ui->Resultlineedit->setText(ourResult); //setText accepts the Qstring type
}

