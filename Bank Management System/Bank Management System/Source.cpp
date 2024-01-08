                        //BANK MANAGEMENT PROJECT




#include<conio.h>
#include<stdio.h>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;



class bank
{
	char name[25],add[100],accType;
	int balance;
	char accNo[11];


public:
	void open_account();
	void Acc_no();
	void deposit_money();
    void Display_account();
	void withdraw_money();

}obj;

void bank:: Acc_no()
{

	for (int i = 0; i < 10; i++)
	{
		accNo[i] = (rand()%(57+1-48))+48; //48-57 is the decimal value for characters 0-9 in ascii
	}
	accNo[10] = '\0';

}


void bank::open_account()
{


	cout << "Enter your full name: "; 
	cin.ignore();
	cin.getline(name, 25);
	cout << "Enter your address: ";
	cin.getline(add, 100);
	cout << "What type of account you want to open saving(s) or current(c):  ";
	cin >> accType;
	cout << "Enter amount for deposit:  ";
	cin >> balance;
	Acc_no();
	cout << "Your account is created!\n";
	cout << "Account No:\t"<< accNo << endl;




	ofstream fout; 
	fout.open("customerdetails.txt",ios::app);
	fout.write((char*)&obj, sizeof(obj));
	fout.close();



	_getch();
	
}

void bank:: deposit_money()
{
	string accno;
	cout << "Enter the account number:\t";
	cin >> accno;
	int amt;
	cout << "Enter the amount you want to deposit: ";
	cin >> amt;

	ifstream fin;
	fin.open("customerdetails.txt", ios::in );

	fstream fnew;
	fnew.open("UpdatedFile.txt", ios::out | ios::app );
	
	while (fin.read((char*)&obj, sizeof(obj)))
	{
		if (accNo == accno)
		{
			balance += amt;
			cout << "Account Balance:\t" << balance;
			
		}
		fnew.write((char*)&obj, sizeof(obj));

	}
	fin.close();
	fnew.close();
	remove("customerdetails.txt");
	rename("UpdatedFile.txt","customerdetails.txt");

	
	

	
	_getch();
}


void bank::Display_account()
{
	string accno;
	cout << "Enter the account no:\t";
	cin >> accno;

	ifstream fin;
	fin.open("customerdetails.txt", ios::in );
	while (fin.read((char*)&obj, sizeof(obj)))
	{
		if (accNo == accno)
		{
			cout << "Your full name:\t" << name << endl;
			cout << "Your Address:\t" << add << endl;
			cout << "Account Type:\t";
			if (accType == 'S' || accType == 's')
				cout << "Saving\n";
			else
				cout << "Current\n";
			cout << "Account Balance:\t" << balance << endl;
		}
	}
	fin.close();
	_getch();
}


void bank::withdraw_money()
{
	string accno;
	cout << "Enter the account number:\t";
	cin >> accno;
	int amt;
	cout << "Enter the amount you want to withdraw: ";
	cin >> amt;
	
	ifstream fin;
	fin.open("customerdetails.txt");
	ofstream fout;
	fout.open("UpdatedFile.txt", ios::out | ios::app ); 
	while (fin.read((char*)&obj, sizeof(obj)));
	{
		if (accNo == accno)
		{
			balance -= amt;
			cout << "Current balance:\t" << balance << endl;
			
		}
		fout.write((char*)&obj, sizeof(obj));
		
	}
	fin.close();
	fout.close();
	remove("customerdetails.txt");
	rename("UpdatedFile.txt","customerdetails.txt");
	

	_getch();

}




int main()
{
	int option;
	char ch='y';
	
	do
	{
		system("cls");
		cout << "1) Open account\n";
		cout << "2) Deposit money\n";
		cout << "3) Withdraw money \n";
		cout << "4) Display account\n";
		cout << "5) Exit\n\n\n";
		cout << "select an option:\t";

		cin >> option;
		system("cls");

		switch (option)
		{
		case 1:
			cout<<"New account\n";
			cout<<"***********\n\n";
			srand(time(0));//seed the random number generator to get new sequence of random  numbers 
			obj.open_account();
			break;

		case 2:
			cout << "Deposit Money\n";
			cout << "*************\n\n";
			obj.deposit_money();
			break;

		case 3:
			cout<< "Withdraw Money\n";
			cout <<"**************\n\n";
			obj.withdraw_money();
			break;

		case 4:
			cout << "Display account\n";
			cout << "***************\n\n";
			obj.Display_account();
			break;
		case 5:
			cout << "Exiting..." << endl;
			Sleep(1000);
			system("cls");
			exit(1);
			break;

		default:
			cout << "OOPS! Enter the valid option" << endl;
			Sleep(1500);

		}

		if (option < 5 && option!=0) //This doesn't execute when user press exit or invalid option
		{
			cout << "\nDo you want to choose another option (y/n):\t";
			ch = _getch();
		}

	} while (ch=='Y'||ch=='y');

	system("cls");

	return 0;
}