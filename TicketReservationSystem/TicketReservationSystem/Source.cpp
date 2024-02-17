#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<algorithm>
using namespace std;
char ch;
class Bus
{
	int Bid, Fare;
	string Destination,Time;
	
public:


	Bus()
	{
		Bid = 000;
		Fare = 0;
	}
	void Input();
	void SpecificBus(string);
	void DisplayBus();
	void DeleteBus(string);
	string getDest();


}b;



void Bus::Input()
{
	cout << "Enter the Bus id:\t";
	cin >> Bid;
	cout << "Enter the Destination:\t";
	cin >> Destination;
	cout << "Enter the Time:\t";
	cin >> Time;
	cout << "Enter the fare of the bus:\t";
	cin >> Fare;


	ofstream fout("BusData.txt", ios::app | ios::binary);
	if (fout.fail())
	{
		cout << "Oops! couldn't open the file!";
	}
	else
	{
		fout.write((char*)&b, sizeof(b));
	}
		
	fout.close();
	cout << "Bus detail saved successfully!";
	ch=_getch();
}

string lowercase(string str)
{
	transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {return tolower(c); });
	return str;
}


void Bus::SpecificBus(string BidDes)
{

	int count = 0;
	fstream fin;
	fin.open("BusData.txt", ios::in | ios::binary);

	while (fin.read((char*)&b, sizeof(b)))
	{
		
		if (to_string(Bid) == BidDes || lowercase(b.Destination)==lowercase(BidDes )) //do string comparing ignoring the case
		{
			DisplayBus();
			count++;
		}
	}
	fin.close();

	if (count == 0)
	{
		cout << "Oops! No Bus Found" << endl;
		
	}
	_getch();
}

void Bus::DisplayBus()
{

	cout << "****Bus Detail****" << endl;
	cout << "\nBus ID:\t" << Bid;
	cout << "\nFare:\t" << Fare;
	cout << "\nDestination:\t" << Destination;
	cout << "\nTime:\t" << Time<<endl<<endl;

}

void Bus::DeleteBus(string BidDest)
{
	ifstream fin("BusData.txt", ios::binary);
	ofstream fout("TempFile.txt", ios::app | ios::binary);

	while (fin.read((char*)&b, sizeof(b)))
	{
		if (to_string(Bid) != BidDest && lowercase(Destination) != lowercase(BidDest))
		{
			fout.write((char*)&b, sizeof(b));
		}
		else
		{
			DisplayBus();
			
			
		}
	}

	fin.close();
	fout.close();
	remove("BusData.txt");
	int status =rename("TempFile.txt", "BusData.txt");
	cout << "Bus is Deleted Successfully!" << endl;
	_getch();


}

string Bus::getDest()
{
	return (b.Destination);
}




class Ticket
{
	int Age;
	string Name, Dest;

public:

	void Getdetails(string name, int age, string dest)
	{
		Age = age;
		Name = name;
		Dest = dest;
		BookTicket();

	}
	void BookTicket();
	
}T;

void Ticket::BookTicket()
{
	int count = 0;
	fstream fout;
	fout.open("BookedTickets.txt", ios::app | ios::binary);
	fstream fin;
	fin.open("BusData.txt", ios::in);
	
	

	while (fin.read((char*)&b, sizeof(b)))
	{
		if (lowercase(T.Dest) == lowercase(b.getDest()))
		{
			b.DisplayBus();

			if (fout.fail())
			{
				cout << "Oops! couldn't open the file";
			}
			else
			{
				fout.write((char*)&T, sizeof(T));
				cout << "Ticket Booked successfully" << endl;
	

			}
			count++;
		}
	}


	if (count == 0)
	{
		cout << "No Buses available to that destination";
	}

	_getch();
	fin.close();
	fout.close();
}












int main()
{
	int opt;
	char name[20], dest[50];
	int age;
	ifstream fin;
	string BidDest;

	do
	{
		system("cls");
		cout << "1 - Enter Bus Details" << endl;
		cout << "2 - Display all buses" << endl;
		cout << "3 - Book a Ticket " << endl;
		cout << "4 - See a Specific Bus " << endl;
		cout << "5 - Delete a Bus " << endl;
		cout << "6 - Exit " << endl;
		cout << "\n\nEnter your choice:\t";
		cin >> opt;
		system("cls"); 


		switch (opt)
		{
			
		case 1:
			b.Input();
			break;
			
		case 2:
			fin.open("BusData.txt", ios::in | ios::binary);
			while (fin.read((char*)&b, sizeof(b)))
			{
				b.DisplayBus();
			}

			fin.close();
			_getch();
			break;



		case 3:
			cout << "Enter the Name:\t";
			cin >> name;
			cout << "Enter the age:\t";
			cin >> age;
			cout << "Enter the destination:\t";
			cin >>dest;
			cout << endl << endl;
			T.Getdetails(name, age, dest);
			break;

		case 4:
			
			cout << "Enter the BusId or Destination:\t";
			cin >> BidDest;
			system("cls");
			b.SpecificBus(BidDest);
			break;

		case 5:

			cout<< "Enter the BusId or Destination to Delete:\t";
			cin >> BidDest;
			system("cls");
			b.DeleteBus(BidDest);
			break;

		case 6:
			cout << "Exiting program..." << endl;

			 
		}


	} while (opt!=6);


	return 0;
}