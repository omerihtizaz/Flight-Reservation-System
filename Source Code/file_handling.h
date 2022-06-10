#include"time.h"
#include"Graph.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
graph file_handle() {
	int number_airline = 0;
	int number_cities = 0;
	ifstream file("Flights.txt");
	string city[25];
	string city1;
	string city2;
	string garbage;
	int i = 0;
	int j = 0;
	bool found = false;
	bool found1 = true;
	if (i == 0) {
		getline(file, city1, ' ');
		city[i] = city1;
		i++;
		getline(file, city2, ' ');
		city[i] = city2;
		i++;
	}
	getline(file, garbage);
	while (file) {
		getline(file, city1, ' ');
		getline(file, city2, ' ');
		getline(file, garbage);
		for (j = 0; j < i; j++)
		{
			if (city1 == city[j])
			{
				found = true;
			}
			if (city2 == city[j])
			{
				found1 = true;
			}
		}
		if (found == false && j == i)
		{
			city[i] = city1;
			i++;
		}
		else if (found1 == false && j == i)
		{
			city[i] = city2;
			i++;
		}
		found = false;
		found1 = false;
		j = 0;
	}
	number_cities = i;
	file.close();

	file.open("FLights.txt", ios::beg);
	int* array_num = new int[number_cities];
	for (int i = 0; i < number_cities; i++)
		array_num[i] = 0;

	int counter;
	string c;
	string garbage1;
	while (file)
	{
		getline(file, c, ' ');
		getline(file, garbage1);
		for (int i = 0; i < number_cities; i++)
		{
			if (c == city[i])
			{
				counter = array_num[i];
				array_num[i] = ++counter;
			}
		}
	}
	file.close();
	string air[110];
	string air1[15];
	file.open("Flights.txt", ios::beg);
	string airline;
	i = 0, j = 0;
	found = false;
	while (file) {
		getline(file, airline, ' ');
		getline(file, airline, ' ');
		getline(file, airline, ' ');
		getline(file, airline, ' ');
		getline(file, airline, ' ');
		getline(file, airline, ' ');
		getline(file, airline);
		if (i == 0)
		{
			air1[i] = airline;
			i++;
		}
		else
		{
			for (j = 0; j < i; j++)
			{
				if (airline == air1[j])
				{
					found = true;
					break;
				}
			}
			if (found == false && j == i)
			{
				air1[i] = airline;
				i++;
			}
		}
		found = false;
		j = 0;
	}
	file.close();
	number_airline = i;

	ifstream file1("HotelCharges_perday.txt");
	string city_name;
	string t_price;
	graph v(number_cities, city);
	while (file1) {
		getline(file1, city_name, ' ');
		getline(file1, t_price);
		for (int i = 0; i < number_cities; i++) {
			if (city_name == city[i])
				v.setcost(city_name, t_price);
		}
	}
	file.open("Flights.txt", ios::beg);
	string c1;
	string c2;
	string price;
	int price1;
	string day1, month1, year1;
	int day, month, year;
	string hour2, mint2;
	string hour0, mint0;
	int hour, mint;
	int hour1, mint1;
	string air2;
	while (file)
	{
		getline(file, c1, ' ');
		getline(file, c2, ' ');
		getline(file, day1, '/');
		getline(file, month1, '/');
		getline(file, year1, ' ');
		getline(file, hour0, ':');
		getline(file, mint0, ' ');
		getline(file, hour2, ':');
		getline(file, mint2, ' ');
		getline(file, price, ' ');
		getline(file, air2);
		hour1 = stoi(hour2);
		mint1 = stoi(mint2);
		hour = stoi(hour0);
		mint = stoi(mint0);
		day = stoi(day1);
		month = stoi(month1);
		year = stoi(year1);
		price1 = stoi(price);
		edge e(c2, day, month, year, hour, mint, hour1, mint1, price1, air2);
		v.create_edge(c1, e);
	}
	return v;
}
void initiate(initializer sa, int input) {
	graph v = file_handle();
	if (input == 1)
	{
		Scenario1(sa.origin, sa.destination, sa.d, sa.airline, v);
	}
	else if (input == 2)
	{
		Scenario2(sa.origin, sa.destination, sa.d, v);
	}
	else if (input == 3)
	{
		Scenario3(sa.origin, sa.destination, sa.transit, sa.d, v);
	}
	else if (input == 4)
	{
		Scenario4(sa.origin, sa.destination, sa.transit, sa.d, sa.transit_time, v);
	}
	else if (input == 5)
	{
		Scenario5(sa.origin, sa.destination, sa.d, v);
	}
}