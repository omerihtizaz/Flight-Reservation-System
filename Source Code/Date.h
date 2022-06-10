#pragma once
#include<iostream>
#include<string>
class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date()
	{
		year = 0;
		month = 0;
		day = 0;

	}
	Date(int d, int m, int y)
	{
		year = y;
		month = m;
		day = d;
	}
	void set(int d, int m, int y)
	{
		year = y;
		month = m;
		day = d;
	}
	void setDay(int d)
	{
		if (d > 0 && d <= 31)
		{
			day = d;
		}

	}
	bool operator==(Date d)
	{
		if (day == d.day && month == d.month && year == d.year)
			return true;
		return false;
	}
	int getDay()const
	{
		return day;
	}
	void setMonth(int m)
	{
		if (m > 0 && m < 13)
		{
			month = m;
		}

	}
	int getMonth()const
	{
		return month;
	}
	void setYear(int y)
	{
		year = y;
	}
	int getYear()const
	{
		return year;
	}
	void operator=(Date d) {
		day = d.day;
		month = d.month;
		year = d.year;
	}
	bool operator>=(Date d) {
		if (day >= d.day && month >= d.month && year >= d.year)
			return true;
		return false;
	}
	bool operator>(Date d) {
		if (day > d.day && month > d.month && year > d.year)
			return true;
		return false;
	}
	string toString()
	{
		string toReturn;

		toReturn.append(to_string(day));
		toReturn.append("/");
		toReturn.append(to_string(month));
		toReturn.append("/");
		toReturn.append(to_string(year));
		return toReturn;
	}
};