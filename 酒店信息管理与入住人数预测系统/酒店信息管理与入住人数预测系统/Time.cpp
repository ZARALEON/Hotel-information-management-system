#include "Time.h"

ostream& operator<<(ostream& os, const Time& t)
{
	os << t.month << "/" << t.day << "       " << t.hour << ":" << t.minis;
	return os;
}

istream& operator>>(istream& is, Time& t)
{
l1:
	is >> t.month >> t.day;
	is >> t.hour >> t.minis;
	if (t.month < 0 || t.month > 12 || t.day < 0 || t.day > 31 || t.hour < 0 || t.hour>23 || t.minis < 0 || t.minis>59)
	{
		cout << endl << "Wrong!!!Again!" << endl;
		goto l1;
	}
	return is;
}

bool Time::operator==(const Time& t)const
{
	if (month == t.month && day == t.day)
		return true;
	else return false;
}