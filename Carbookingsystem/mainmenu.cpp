#include "mainmenu.h"
#include "ui_mainmenu.h"

mainmenu::mainmenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainmenu)
{
    ui->setupUi(this);
}

mainmenu::~mainmenu()
{
    delete ui;
}

void mainmenu::on_addcarbtn_clicked()
{
    addCarUi.show();
    mainmenu::close();
}


void mainmenu::on_bookcarbtn_clicked()
{
    bookCarUi.show();
     mainmenu::close();
}

