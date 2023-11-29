#include "login.h"
#include "ui_login.h"
#include "QDebug"
#include"QMessageBox"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_exitbtn_clicked()
{
    QApplication::exit();
}


void login::on_loginbtn_clicked()
{
QString userid=ui->useridlineEdit->text();
QString password=ui->passwordlineEdit->text();

if(userid=="admin")
{
    if(password=="admin123")
    {
      qDebug()<<"Login Successfull!" ;

     mainmenuUi.show();
     login::close();                             //where is close() defined?
    }
    else
    {
         QMessageBox::information(0,"Authentication","Incorrect Password");     //(nullpointer,name of box, body of the box)
    }
}

else
{
    //qDebug()<<"Login failed ";
    QMessageBox::information(0,"Authentication","Incorrect userid");     //(nullpointer,name of box, body of the box)
}
}

