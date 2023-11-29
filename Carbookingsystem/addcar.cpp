#include "addcar.h"
#include "ui_addcar.h"
#include "QFile"
#include"QTextStream"
#include"QDebug"

addCar::addCar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCar)
{
    ui->setupUi(this);
    ui->CarTypelistWidget->addItem("Mini");
    ui->CarTypelistWidget->addItem("Sedan");
    ui->CarTypelistWidget->addItem("SUV");
    ui->CarTypelistWidget->addItem("Premium");
}

addCar::~addCar()
{
    delete ui;
}


void addCar::on_AddCarbtn_clicked()
{
    //we are storing the inputs from the addCar page in a vector
    QVector<QString> Cardata;
    Cardata.append(ui->CarnolineEdit->text());
    Cardata.append(ui->BrandlineEdit->text());
    Cardata.append(ui->fareLineEdit->text());

    QListWidgetItem *selectedcarType = ui->CarTypelistWidget->currentItem();

    Cardata.append(selectedcarType->text());

    //now store the car data into the file- inlcude"QFile" header like we do "fstream"

    QFile file("CarData.txt");
    if(file.open(QIODevice::Append|QIODevice::Text)) //however we can't read or write with file along with << and >> operator. but there are other ways
    {
        //we need QTextStream to read and write into this file. this associates with the QFile
        QTextStream outObj(&file);
        for(int i=0;i<Cardata.size();i++)
        {
            outObj<<Cardata[i]<<" ";
        }
        outObj<<endl;
    }

    file.close();
    qDebug()<<"Data written into the file successfully "; //creating anonymous object for qdebug class and it works like ostream object "cout"

    /*
    QFile file;
    file.open("CarData.txt", QIODevice::Append|QIODevice::Text); //this gives error.reason is given below.
    */


    /*
    //we can use the file name in the open member function but we can't use in QFile's open() member function
    //again open() without file name isn't possible in fstream

    fstream file1;
    file1.open("CarData.txt",ios::app|ios::out);

    fstream file2("cars2.txt");
    file2.open("cars2.txt",ios::app|ios::in);
    file2.open("cars3.txt",ios::app|ios::in);
    */
}


void addCar::on_exitbtn_clicked()
{
  QApplication::exit();
}

