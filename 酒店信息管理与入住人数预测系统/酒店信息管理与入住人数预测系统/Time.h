#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
class Time
{
public:
	int month;
	int day;
	int hour;
	int minis;

	friend ostream& operator<<(ostream& os, const Time& t);
	friend istream& operator>>(istream& is, Time& t);
	bool operator==(const Time& t)const;
	Time& operator= (const Time& t)
	{
		if (this != &t)
		{
			month = t.month;
			day = t.day;
			hour = t.hour;
			minis = t.minis;
		}
		return *this;
	}
};
