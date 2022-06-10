#include"time.h"
#include"Graph.h"
#include "Date.h"
#include<Windows.h>
#include<iostream>
#include<string>
#include<fstream>
#include"file_handling.h"
#include"ini.h"
using namespace std;
void display()
{
	string origin;
	string desti;
	string transit;
	string cost;
	string airline;
	int year, month, day;
	int transit_time;
	int input;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "-----------------------------------WELCOME TO THE airline RESERVATION SYSTEM--------------------------------------" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "--> Please select your query from the list mentioned below" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	cout << "--> Press 1 if you want to book a flight of a certain airline going to a certain destination" << endl << "    on a specific date with minimal travel cost" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "--> Press 2 if you want to book a fight going to a certain destination on a specific date with minimal travel time" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "--> Press 3 if you want to book a connecting flight going to a certain destination on a specific date with a transit" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "--> Press 4 if you want to book a connecting flight going to a certain destination on a specific" << endl << "    date having a particular transit time with minimum travel time " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	cout << "--> Press 5 if you want to book a direct flight going to a certain destination on a specific date and time" << endl;
	cin >> input;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
	if (input == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		cout << "Please fill in the following requirements to book your air travel" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "Enter your origin of air travel : ";
		cin >> origin;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		cout << "Enter your destination of air travel : ";
		cin >> desti;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "Enter your Date of air travel" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		cout << "Enter day of your travel : ";
		cin >> day;
		cout << "Enter month of your travel : ";
		cin >> month;
		cout << "Enter year of your travel : ";
		cin >> year;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "Enter the name of your preferred airline : ";
		cin >> airline;
		initializer in;
		in.origin = origin;
		in.destination = desti;
		in.airline = airline;
		Date s1_d(day, month, year);
		in.d = s1_d;
		initiate(in, input);
	}
	else if (input == 2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		cout << "Please fill in the following requirements to book your air travel" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "Enter your origin of air travel : ";
		cin >> origin;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		cout << "Enter your destination of air travel : ";
		cin >> desti;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "Enter your Date of air travel" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		cout << "Enter day of your travel : ";
		cin >> day;
		cout << "Enter month of your travel : ";
		cin >> month;
		cout << "Enter year of your travel : ";
		cin >> year;
		Date s2_d(day, month, year);
		initializer in;
		in.origin = origin;
		in.destination = desti;
		in.d = s2_d;
		initiate(in, input);
	}
	else if (input == 3) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		cout << "Please fill in the following requirements to book your air travel" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "Enter your origin of air travel : ";
		cin >> origin;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		cout << "Enter your destination of air travel : ";
		cin >> desti;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "Enter your Date of air travel" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		cout << "Enter day of your travel : ";
		cin >> day;
		cout << "Enter month of your travel : ";
		cin >> month;
		cout << "Enter year of your travel : ";
		cin >> year;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "Enter your transit location : ";
		cin >> transit;
		Date s3_d(day, month, year);
		initializer in;
		in.origin = origin;
		in.destination = desti;
		in.transit = transit;
		in.d = s3_d;
		initiate(in, input);
	}
	else if (input == 4) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		cout << "Please fill in the following requirements to book your air travel" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "Enter your origin of air travel : ";
		cin >> origin;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		cout << "Enter your destination of air travel : ";
		cin >> desti;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "Enter your Date of air travel" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		cout << "Enter day of your travel : ";
		cin >> day;
		cout << "Enter month of your travel : ";
		cin >> month;
		cout << "Enter year of your travel : ";
		cin >> year;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "Enter your transit location : ";
		cin >> transit;
		cout << "Enter your transit time in hours : ";
		cin >> transit_time;
		Date s4_d(day, month, year);
		initializer in;
		in.origin = origin;
		in.destination = desti;
		in.transit = transit;
		in.d = s4_d;
		in.transit_time = transit_time;
		initiate(in, input);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		cout << "Please fill in the following requirements to book your air travel" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "Enter your origin of air travel : ";
		cin >> origin;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		cout << "Enter your destination of air travel : ";
		cin >> desti;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "Enter your Date of air travel" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		cout << "Enter day of your travel : ";
		cin >> day;
		cout << "Enter month of your travel : ";
		cin >> month;
		cout << "Enter year of your travel : ";
		cin >> year;
		Date s5_d(day, month, year);
		initializer in;
		in.origin = origin;
		in.destination = desti;
		in.d = s5_d;
		initiate(in, input);
	}
}
int main()
{
	display();
}
