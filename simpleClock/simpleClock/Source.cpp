#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	int h, m, s, err = 0, a = 0;

	while (err == 0)
	{
		cout << "*** Enter the current time ***" << endl;
		cout << "Enter the hour:  " << endl;
		cin >> h;
		cout << "Enter the minutes:  " << endl;
		cin >> m;
		cout << "Enter the seconds: " << endl;
		cin >> s;

		if (h < 24 && m < 60 && s < 60)
		{
			err++;
		
		}
		else
		{
			system("cls");
		}
	}

	while (a == 0)
	{
		system("cls");
		cout << h << ":" << m << ":" << s << endl;
		Sleep(1000);//1000 milliseconds = 1 second
		s++;


		if (s > 59)
		{
			s = 0;
			m++;
		}
		if (m > 59)
		{
			m = 0;
			h++;
		}
		if (h > 23) //you could also use 24 here, becz when we see clock we would say 12:01 am not 00:01 am
		{
			h = 0;
		}
	}


	return 0;
}