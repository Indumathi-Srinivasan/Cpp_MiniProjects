#include "bookcar.h"
#include "ui_bookcar.h"
#include"QFile"
#include"QTextStream"
#include"QDebug"
#include"QMessageBox"

QVector<QString> getAlltheCarDetails(); //declaring a function

bookCar::bookCar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookCar)
{
    ui->setupUi(this);
    //we need to read data from carData.txt here
    QVector<QString>cardataVec =getAlltheCarDetails();

    for(int i=0;i<cardataVec.size();i++)
    {
        ui->SelectCarlistWidget->addItem(cardataVec[i]);
    }

}

bookCar::~bookCar()
{
    delete ui;
}

void bookCar::on_BookCarbtn_clicked()
{
QVector<QString>bookedCarData;
bookedCarData.append(ui->NamelineEdit->text());
bookedCarData.append(ui->AgelineEdit->text());
bookedCarData.append(ui->PickupuPointLineEdit->text());
bookedCarData.append(ui->DestinationLineEdit->text());

bool male=ui->MaleradioButton->isChecked();
//bool female=ui->FemaleradioButton->isChecked();
if(male)
{
    bookedCarData.append("male");
}
else
{
    bookedCarData.append("female");
}

QListWidgetItem *selectedItem=ui->SelectCarlistWidget->currentItem();
bookedCarData.append(selectedItem->text());




QFile file("BookedCarData.txt");
if(file.open(QIODevice::Append|QIODevice::Text)) //however we can't read or write with file along with << and >> operator. but there are other ways
{
    //we need QTextStream to read and write into this file. this associates with the QFile
    QTextStream outObj(&file);
    for(int i=0;i<bookedCarData.size();i++)
    {
        outObj<<bookedCarData[i]<<" ";
    }
    outObj<<endl;
}

file.close();


QModelIndex currentIndex=ui->SelectCarlistWidget->currentIndex(); //currentIndex() returns an object that contains the index of the selected item(index means all:row,col,etc.. as the object's member)
int currentRow=currentIndex.row();//currentIndex.row() returns  the row number of the QmodelIndex object

QVector<QString>allcarData=getAlltheCarDetails();
allcarData.remove(currentRow); //remove function is available in Qvector but not in std vector,there are other algorithms to remove in std vector
qDebug()<<currentRow;

//rewrite allcardata into carData.txt
QFile file2("carData.txt");

if(file2.open(QIODevice::WriteOnly|QIODevice::Text))
{
    QTextStream stream(&file2);

    for(int i=0;i<allcarData.size();i++)
    {
        stream<<allcarData[i]<<endl;
    }
}
file2.close();
QMessageBox::information(0,"Booking Status","Car is booked successfully!");
}


void bookCar::on_exitbtn_clicked()
{
QApplication::exit();
}


QVector<QString> getAlltheCarDetails()
{

    QVector<QString>getData;
    QFile readObj("CarData.txt");

    if(readObj.open(QIODevice::ReadOnly|QIODevice::Text))
    {
      QTextStream Read_obj(&readObj);
      //Read the file line by line
      while(!Read_obj.atEnd())
      {
          QString line=Read_obj.readLine();

          getData.append(line);
          qDebug()<<line;
      }
    }

    readObj.close();
    return getData;
}
