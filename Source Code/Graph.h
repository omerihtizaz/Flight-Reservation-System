#pragma once
#include"windows.h"
#include"queue.h"
#include "file_handling.h"
#include"City.h"
#include"link.h"
#include<iostream>
#include<list>
#include"ini.h"
using namespace std;
class graph
{
public:
	graph(int num, string* cities_names)
	{
		num_cities = num;
		this->cities = new City[num];
		for (int i = 0; i < num; i++)
		{
			cities[i].set(cities_names[i]);
		}

	}
	void setcost(string arr, string c) {
		for (int i = 0; i < num_cities; i++) {
			if (cities[i].get_name() == arr)
				cities[i].set_transit_cost(c);
		}
	}
	void create_edge(string a, edge e) {
		for (int i = 0; i < num_cities; i++) {
			if (cities[i].get_name() == a) {
				cities[i].Link_connects.insert(e);
			}
		}
	}
	int find(string origin)
	{
		int i = 0;
		for (i = 0; i < num_cities; i++)
		{
			if (cities[i].get_name() == origin)
			{
				return i;
			}
		}
		if (i > num_cities)
			return -1;

	}
	int getMinindex(int* arr)
	{
		int size = sizeof(arr) / sizeof(int);
		int n = arr[0];
		int index = 0;
		if (size != 1)
		{
			for (int i = 0; i < size; i++)
			{
				if (arr[i] < n)
				{
					n = arr[i];
					index = i;
				}
			}
		}
		cout << "Mimimum cost is: " << n << endl;
		return index;
	}
	int return_in_min(Time a)
	{
		return a.gethour() * 60 + a.getmin();
	}
	City* get_cities() {
		return cities;
	}
private:
	City* cities;
	int num_cities;
};
void Scenario1(string origin, string desti, Date d, string airline, graph &g) {
	Queue<Node_l<edge>*> q;
	Queue<Queue<Node_l<edge>*>> q1;
	int i = g.find(origin);
	int j = 0;
	bool desti_found = false;
	bool flight_found = false;
	Date date1;
	Date date2;
	int arr[10] = { 0 };
	int count = 0;
	Node_l<edge>* temp = g.get_cities()[i].Link_connects.getHead();
	while (temp->next != NULL) {
		if (g.return_in_min(temp->data.getdepart_time()) + g.return_in_min(temp->data.getlanding_time()) > 1440)
		{
			d.setDay(d.getDay() + 1);
		}
		if (temp->data.get_city_destination() == desti && temp->data.get_date() == d && temp->data.get_airline() == airline)
		{
			flight_found = true;
			q.enqueue(temp);
			q1.enqueue(q);
			arr[count] = temp->data.getticket_price();
			count++;
			g.get_cities()[i].Display();
			temp->data.Display();
			cout << endl;
		}
		if (temp->data.get_date() == d && temp->data.get_airline() == airline) {
			date1 = temp->data.get_date();
			j = g.find(temp->data.get_city_destination());
			Node_l<edge>* temp1 = g.get_cities()[j].Link_connects.getHead();
			while (temp1->next != NULL) {
				date2 = temp1->data.get_date();
				if (date2 >= date1 && temp1->data.get_airline() == airline && temp1->data.get_city_destination() == desti) {
					desti_found = true;
					if (desti_found == true) {
						flight_found = true;
						q.enqueue(temp);
						q.enqueue(temp1);
						q1.enqueue(q);
						arr[count] = temp->data.getticket_price() + temp1->data.getticket_price();
						count++;
						g.get_cities()[i].Display();
						temp->data.Display();
						temp1->data.Display();
						break;
						cout << endl;
						desti_found = false;
					}
				}
				temp1 = temp1->next;
			}
		}
		temp = temp->next;
	}
	cout << "Path with minimum cost is" << endl << endl;
	Queue<Node_l<edge>*> min_path;
	int a = g.getMinindex(arr);
	for (int i = 0; i < a - 1; i++)
	{
		q1.dequeue();
	}
	min_path = q1.dequeue();
	while (!min_path.isEmpty())
	{
		min_path.dequeue()->data.Display();
	}
	if (flight_found == false) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "!!!!!!!!!!!!  No flight available  !!!!!!!!!!!" << endl;
	}
}
void Scenario2(string origin, string desti, Date d, graph &g) {
	Queue<Node_l<edge>*> q;
	Queue<Queue<Node_l<edge>*>> q1;
	int i = g.find(origin);
	cout << i << endl;
	int j = 0;
	int count_ar = 0;
	Date date1;
	Date date2;
	bool desti_found = false;
	bool flight_found = false;
	Node_l<edge>* temp = g.get_cities()[i].Link_connects.getHead();
	while (temp->next != NULL) {
		if (temp->data.get_city_destination() == desti && temp->data.get_date() == d)
		{
			flight_found = true;
			q.enqueue(temp);
			//q1.enqueue(q);
			g.get_cities()[i].Display();
			temp->data.Display();
			cout << endl;
		}
		if (temp->data.get_date() == d) {
			date1 = temp->data.get_date();
			j = g.find(temp->data.get_city_destination());
			Node_l<edge>* temp1 = g.get_cities()[j].Link_connects.getHead();
			while (temp1->next != NULL) {
				date2 = temp1->data.get_date();
				if (date2 >= date1 && temp1->data.get_city_destination() == desti) {
					desti_found = true;
					if (desti_found == true) {
						flight_found = true;
						q.enqueue(temp);
						q.enqueue(temp1);
						q1.enqueue(q);
						g.get_cities()[i].Display();
						temp->data.Display();
						temp1->data.Display();
						cout << endl;
						break;
					}
					desti_found = false;
				}
				temp1 = temp1->next;
			}
		}
		temp = temp->next;
	}

	if (flight_found == false) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "!!!!!!!!!!!!  No flight available  !!!!!!!!!!!" << endl;
	}

}
void Scenario4(string origin, string desti, string transit, Date d, int transit_time, graph &g) {
	int i = g.find(origin);
	int j = 0;
	int k = 0;
	Time t;
	Date d1;
	Date d2;
	bool flight_found = false;
	bool transit_found = false;
	bool desti_found = false;
	Node_l<edge>* temp = g.get_cities()[i].Link_connects.getHead();
	while (temp->next != NULL) {
		if (temp->data.get_city_destination() == transit && temp->data.get_date() == d) {
			d1 = temp->data.get_date();
			transit_found = true;
			j = g.find(transit);
			Node_l<edge>* temp1 = g.get_cities()[j].Link_connects.getHead();
			while (temp1->next != NULL) {
				d2 = temp1->data.get_date();
				if (d2 >= d1 && temp1->data.get_city_destination() == desti) {
					int cal_time = t.Cal_transit_time(temp->data.getlanding_time(), temp1->data.getdepart_time());
					if (cal_time == (transit_time * 60)) {
						desti_found = true;
						if (transit_found == true && desti_found == true) {
							flight_found = true;
							g.get_cities()[i].Display();
							temp->data.Display();
							temp1->data.Display();
							if (transit_time > 12)
								cout << "Total cost of journey is: " << temp->data.getticket_price() + temp1->data.getticket_price() + g.get_cities()[j].get_transit_cost() << endl;
							else
								cout << "Total cost of journey is: " << temp->data.getticket_price() + temp1->data.getticket_price() << endl;
							cout << endl;
							break;
						}
						desti_found = false;
					}
				}
				temp1 = temp1->next;
			}
			transit_found = false;
		}
		temp = temp->next;
	}
	if (flight_found == false) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "!!!!!!!!!!!!  No flight available  !!!!!!!!!!!" << endl;
	}
}
void Scenario3(string origin, string desti, string transit, Date d, graph &g) {
	int i = g.find(origin);
	int j = 0;
	bool transit_found = false;
	bool desti_found = false;
	Date d1;
	Date d2;
	Node_l<edge>* temp = g.get_cities()[i].Link_connects.getHead();
	while (temp->next != NULL) {
		if (temp->data.get_city_destination() == transit && temp->data.get_date() == d) {
			d1 = temp->data.get_date();
			transit_found = true;
			j = g.find(transit);
			Node_l<edge>* temp1 = g.get_cities()[j].Link_connects.getHead();
			d2 = temp1->data.get_date();
			while (temp1->next != NULL) {
				if (d2 >= d1 && temp1->data.get_city_destination() == desti) {
					desti_found = true;
					if (desti_found == true && transit_found == true) {
						g.get_cities()[i].Display();
						temp->data.Display();
						temp1->data.Display();
						cout << endl;
						cout << "Total cost is" << temp->data.getticket_price() + temp1->data.getticket_price() << endl;
						cout << endl;
						break;
						desti_found = false;
					}
				}
				temp1 = temp1->next;
			}
			transit_found = false;
		}
		temp = temp->next;
	}
}
void Scenario5(string origin, string desti, Date d, graph &g) {
	//bool flight_found = false;
	int i = g.find(origin);
	Node_l<edge>* temp = g.get_cities()[i].Link_connects.getHead();
	while (temp->next != NULL)
	{
		if (temp->data.get_city_destination() == desti && temp->data.get_date() == d)
		{
			//flight_found = true;
			g.get_cities()[i].Display();
			temp->data.Display();
			cout << endl;
		}
		temp = temp->next;
	}
	/*if (flight_found == false) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "!!!!!!!!!!!!  No flight available  !!!!!!!!!!!" << endl;
	}*/
}
