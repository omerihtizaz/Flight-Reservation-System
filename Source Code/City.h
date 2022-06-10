#pragma once
#include"edge.h"
#include<iostream>
#include<string>
#include"link.h"
using namespace std;
class City
{
public:
	bool operator==(City c)
	{
		if (name == c.name && num_connects == c.num_connects && Link_connects == c.Link_connects)
		{
			return true;
		}
		return false;
	}
	List<edge> Link_connects;
	City()
	{
		name = "";
	}
	void insert(edge e)
	{
		Link_connects.insert(e);
	}
	City(string n)
	{
		name = n;
	}
	void set(string n)
	{
		name = n;
	}
	void set_transit_cost(string t) {
		transit_cost = t;
	}
	int get_transit_cost() {
		return stoi(transit_cost);
	}
	string get_name()
	{
		return name;
	}
	City* getC()
	{
		return this;
	}
	void Display()
	{
		cout << "City Name : " << name << endl;
	}
	edge e;
private:
	string name;
	string transit_cost;
	int num_connects;
};