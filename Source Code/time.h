#pragma once
#include<iostream>
#include<string>
using namespace std;
class Time {
	int hours;
	int minutes;
public:
	Time() {
		minutes = hours = 0;
	}
	Time(int h, int m) {
		if (h >= 0 && h < 24)
			hours = h;
		if (m >= 0 && m < 60)
			minutes = m;
	}
	void set(int h, int m) {
		if (m >= 0 && m < 60)
			minutes = m;
		else minutes = 0;
		if (h >= 0 && h < 24)
			hours = h;
		else hours = 0;
	}
	string getTime() {
		string toReturn;

		toReturn.append(to_string(hours));
		toReturn.append(":");
		toReturn.append(to_string(minutes));
		return toReturn;
	}
	int getmin() {
		return minutes;
	}
	int gethour() {
		return hours;
	}
	bool operator==(Time t) {
		if (hours == t.hours && minutes == t.minutes)
			return true;
		return false;
	}
	int Cal_transit_time(Time landtime, Time depart) {
		if (landtime.gethour() < depart.gethour())
			return (depart.gethour() * 60 + depart.getmin()) - (landtime.gethour() * 60 + landtime.getmin());
		else
			return (landtime.gethour() * 60 + landtime.getmin()) - (depart.gethour() * 60 + depart.getmin());
	}
	int Cal_flying_time(Time landtime, Time depart) {
		return(landtime.gethour() * 60 + landtime.getmin()) + (depart.gethour() * 60 + depart.getmin());
	}
	int return_in_min(Time a)
	{
		return a.hours * 60 + a.minutes;
	}
	bool operator>=(Time t) {
		if (hours >= t.hours && minutes >= t.minutes)
			return true;
		return false;
	}
	Time operator+(Time t2) {
		Time toreturn;
		toreturn.hours = t2.hours + hours;
		toreturn.minutes = t2.minutes + minutes;
		return toreturn;
	}

};