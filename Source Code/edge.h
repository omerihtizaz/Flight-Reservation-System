#pragma once
#include<iostream>
#include<string>
#include"time.h"
#include"Date.h"
using namespace std;
class edge
{
public:
	edge(string des_ci, int day, int month, int year, int dt_h, int dt_m, int lt_h, int lt_m, int price, string a)
	{
		desti = des_ci;
		edge_date.set(day, month, year);
		depart_time.set(dt_h, dt_m);
		landing_time.set(lt_h, lt_m);
		ticket_price = price;
		airline = a;
	}
	edge()
	{
		edge_date.set(0, 0, 0);
		depart_time.set(0, 0);
		landing_time.set(0, 0);
		desti = "";
		ticket_price = 0;
		airline = "";
	}
	void set(string des_ci, int day = 0, int month = 0, int year = 0, int dt_h = 0, int dt_m = 0, int lt_h = 0, int lt_m = 0, int price = 0, string a = "")
	{
		desti = des_ci;
		edge_date.set(day, month, year);
		depart_time.set(dt_h, dt_m);
		landing_time.set(lt_h, lt_m);
		ticket_price = price;
		airline = a;
	}
	int getticket_price() {
		return ticket_price;
	}
	string get_airline()
	{
		return airline;
	}
	string get_city_destination()
	{
		return desti;
	}
	Date get_date()
	{
		return edge_date;
	}
	void set_airline(string air)
	{
		this->airline = air;
	}
	void Display()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "Date of flight : " << edge_date.toString() << endl;
		cout << "Time of Departure : " << depart_time.getTime() << endl;
		cout << "Landing time : " << landing_time.getTime() << endl;
		cout << "Destination City : " << desti << endl;
		cout << "Airline : " << airline << endl;
		cout << "Cost :" << ticket_price << endl;
	}
	void visit_true()
	{
		visited = true;
	}
	void visit_false()
	{
		visited = false;
	}
	bool get_visited()
	{
		return visited;
	}
	Time getdepart_time() {
		return depart_time;
	}
	Time getlanding_time() {
		return landing_time;
	}
	bool operator==(edge e)
	{
		if (edge_date == e.edge_date && depart_time == e.depart_time && landing_time == e.landing_time
			&& ticket_price == e.ticket_price && desti == e.desti && airline == e.airline && transit_cost == e.transit_cost)
			return true;
		return false;
	}

private:
	Date edge_date;
	Time depart_time;
	Time landing_time;
	int ticket_price;
	string desti;
	string airline;
	int transit_cost;
	bool visited;
};