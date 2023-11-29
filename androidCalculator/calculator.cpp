#include "calculator.h"
#include "ui_calculator.h"

calculator::calculator(QWidget *parent) : QMainWindow(parent), ui(new Ui::calculator)
{
    ui->setupUi(this);
    num1=0;
    symbol="";
}

calculator::~calculator()
{
    delete ui;
}


void calculator::on_Ninebtn_clicked()
{
  QString num1=ui->OutputlineEdit->text();
  ui->OutputlineEdit->setText(num1+"9");
}


void calculator::on_Eightbtn_clicked()
{
    QString num1=ui->OutputlineEdit->text();
    ui->OutputlineEdit->setText(num1+"8");
}


void calculator::on_Sevenbtn_clicked()
{
    QString num1=ui->OutputlineEdit->text();
    ui->OutputlineEdit->setText(num1+"7");
}


void calculator::on_Sixbtn_clicked()
{
    QString num1=ui->OutputlineEdit->text();
    ui->OutputlineEdit->setText(num1+"6");
}



void calculator::on_Fivebtn_clicked()
{
    QString num1=ui->OutputlineEdit->text();
    ui->OutputlineEdit->setText(num1+"5");
}


void calculator::on_Fourbtn_clicked()
{
    QString num1=ui->OutputlineEdit->text();
    ui->OutputlineEdit->setText(num1+"4");
}


void calculator::on_Threebtn_clicked()
{
    QString num1=ui->OutputlineEdit->text();
    ui->OutputlineEdit->setText(num1+"3");
}



void calculator::on_Twobtn_clicked()
{
    QString num1=ui->OutputlineEdit->text();
    ui->OutputlineEdit->setText(num1+"2");
}


void calculator::on_Onebtn_clicked()
{
QString num1=ui->OutputlineEdit->text();
ui->OutputlineEdit->setText(num1+"1");
}


void calculator::on_Zerobtn_clicked()
{
    QString num1=ui->OutputlineEdit->text();
    ui->OutputlineEdit->setText(num1+"0");
}




void calculator::on_Clearbtn_clicked()
{
    ui->OutputlineEdit->setText("");
}


void calculator::on_Resultbtn_clicked()
{
double num2=ui->OutputlineEdit->text().toDouble();
double result=0;
if(symbol=="+")
 {
    result=num1+num2;
 }
else if(symbol=="-")
 {
    result=num1-num2;
 }
else if(symbol=="*")
 {
    result=num1*num2;
 }
else if(symbol=="/")
 {
    result=num1/num2;
 }
ui->OutputlineEdit->setText(QString::number(result)); //number()function of QString is used to convert the number to QString type

}

void calculator::on_Addbtn_clicked()
{
     num1=ui->OutputlineEdit->text().toDouble();
     symbol="+";
      ui->OutputlineEdit->setText("");
}
void calculator::on_Subtractbtn_clicked()
{
    num1=ui->OutputlineEdit->text().toDouble();
    symbol="-";
     ui->OutputlineEdit->setText("");
}

void calculator::on_Multiplybtn_clicked()
{
    num1=ui->OutputlineEdit->text().toDouble();
    symbol="*";
     ui->OutputlineEdit->setText("");
}

void calculator::on_Dividebtn_clicked()
{
    num1=ui->OutputlineEdit->text().toDouble();
    symbol="/";
    ui->OutputlineEdit->setText("");
}

