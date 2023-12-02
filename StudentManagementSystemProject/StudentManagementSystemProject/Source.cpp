#include<iostream>
#include<fstream>
//#include<iomanip>
#include<stdlib.h>
using namespace std;


void project();
void addData();
void displayData();
void deleteData();
void getTrash();

class student
{
  
	int admissionNo;
	char sname[20];
	char sgender;
	int std;
	float smarks;
	double spercentage;

public:

	void getData();
	void showData();
	int getAdmno()
	{
		return admissionNo;
	}
}s; //object created here itself

int main()
{
	project();

	return 0;
}




void project()
{

	int ch;

	do
	{
		system("cls"); //clear screen

		cout << "*****************STUDENT MANAGEMENT SYSTEM***************\n";

		cout << "1. Write Student Record\n";

		cout << "2.Read Student record\n";

		cout << "3.Delete Student record\n";

		cout << "4.Get Deleted records\n";
		
		cout << "0.Exit\n";

		cout << "Enter your choice: ";

		cin >> ch;
		system("cls");
		
		switch (ch)
		{
		case 1: 
			addData();
			break;
		case 2:
			displayData();
			break;
		case 3:
			deleteData();
			break;
		case 4:
			getTrash();
			break;

		}

		system("pause");
	} while (ch);

}

void addData()
{
	ofstream fout;
	fout.open("Stu.txt", ios::out | ios::app | ios::binary);//ios::binary - to preserve the exact content ,so we're reading and writing in binary rather than a text file
	
	s.getData(); //get data from console

	//read((char*)&s,sizeof(s));
	//write((char*)&s,sizeof(s));

	fout.write((char*)&s, sizeof(s)); //write data to file from object"s"

	fout.close();
	cout << "\n\n***********Data Successfully Saved to File**********\n";

}

void displayData()
{
	ifstream fin; //input stream
	fin.open("stu.txt", ios::in | ios::binary); //ios::binary - to preserve the exact content ,so we're reading and writing in binary rather than a text file
	
	while (fin.read((char*)&s, sizeof(s)))
	{
		s.showData();//will show data to console
    }
	fin.close();
	cout << "\n\n**********Data Reading from file Successfully Done*********\n";
}

void deleteData() //delete data from file
{
	int n, flag = 0;
	ifstream fin;
	ofstream fout, tout;
	fin.open("stu.txt", ios::in | ios::binary);
	fout.open("Temp.txt", ios::out | ios::binary);
	tout.open("Trash.txt", ios::out | ios::binary);
	cout << "Enter Admission Number: ";
	cin >> n;


	while (fin.read((char*)&s, sizeof(s))) //read the file stu.txt
	{
		if (n == s.getAdmno())
		{
			cout << "\nThis Record " << n << " has been sent to Trash:\n";
			s.showData(); //display the content to the console
			tout.write((char*)&s, sizeof(s)); //write data to Trash.txt
			flag++;

		}
		else
		{
			fout.write((char*)&s, sizeof(s));//write data to temp.txt
		}
	}
	fout.close();
	tout.close();
	fin.close();



	if (flag == 0)
		cout << "  " << n << "No Record Found*******\n\n";
	else
		cout << "####### No of records Deleted: " << flag <<" #######" << endl;

	remove("stu.txt");//delete stu.txt                                   
	rename("Temp.txt", "stu.txt");//rename temp.txt as stu.txt

	/*these removeand rename function are defined in stdio.h library maybe is indirectly included through
	other standard libraries like <iostream> or <fstream>*/
}

void getTrash()
{
	ifstream fin;//open file in input mode
	fin.open("Trash.txt", ios::in | ios::binary);
	while (fin.read((char*)&s, sizeof(s))) //read data from file
	{
		s.showData();//display data on console
	}
	fin.close();//close file
	cout << "\n\n***********data reading from Trash File successfully Done**********\n";
}



void student::getData() //will get data from console
{
	cout << "\n\n***********Enter Student Data***********\n";
	cout << "Admission No. : ";
	cin >> admissionNo;
	cout << "Full Name: ";
	cin.ignore();
	cin.getline(sname, 20);
	cout << "gender(M/F): ";
	cin >> sgender;
	cout << "Class: ";
	cin >>std;
	
	cout << "Total Marks(/500): ";
	cin >> smarks;
	cout << endl;
	spercentage = smarks * 100.0 / 500.00;


}

void student::showData()//will display data to console
{
	cout << "\n***********Student Details***********\n";
	cout << "Admission No.: " << admissionNo << endl;
	cout << "Full Name: " << sname << endl;
	cout << "Gender: " << sgender << endl;
	cout << "Class: " << std << endl;
	cout << "Total Marks(/500): " << smarks << endl;
	cout << "Percentage: " << spercentage << endl;
	cout << endl;
}