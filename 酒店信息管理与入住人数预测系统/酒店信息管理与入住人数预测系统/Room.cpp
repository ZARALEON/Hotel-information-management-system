#include "Room.h"
#include"Header.h"
extern vector<Room>room;
extern vector<Customer>customer;
ostream& operator<<(ostream& os, const Room& r)
{
	os << "       " << r.roomnum << "       " << r.price << "       " << r.level << "       " << r.is_sold << "       ";

	if (r.is_sold == 'y' || r.is_sold == 'Y')
	{
		os << r.sold_time << endl;
	}
	else os << endl;
	return os;
}
istream& operator>>(istream& is, Room& r)
{
l1:
	cout << endl << "Num:";
	is >> r.roomnum;
	if (r.roomnum < 100 || r.roomnum>999 || !r.check())
	{
		cout << endl << "Wrong!!!Again!" << endl;
		goto l1;
	}

l2:
	cout << endl << "Price:";
	is >> r.price;
	if (r.price < 100 || r.price>999)
	{
		cout << endl << "Wrong!!!Again!" << endl;
		goto l2;
	}

l3:
	cout << endl << "Level:";
	is >> r.level;
	if (r.level != 'a' && r.level != 'A' && r.level != 'b' && r.level != 'B' && r.level != 'c' && r.level != 'C' && r.level != 'd' && r.level != 'D')
	{
		cout << endl << "Wrong!!!Again!" << endl;
		goto l3;
	}

l4:
	cout << endl << "Is_sold :";

	is >> r.is_sold;

	if (r.is_sold != 'Y' && r.is_sold != 'y' && r.is_sold != 'N' && r.is_sold != 'n')
	{
		cout << endl << "Wrong!!!Again!" << endl;
		goto l4;
	}

	switch (r.is_sold)
	{
	case'y':
	case'Y':
	{
		cout << endl << "sold time(month/day hour:minute):";
		is >> r.sold_time;
	}
	break;

	case'n':
	case'N':; break;
	}
	return is;
}

void Room::input()
{
l1:
	system("cls");
	Room r;
	cin >> r;
	r.save(!0);
	room.push_back(r);

	if (r.is_sold == 'y' || r.is_sold == 'Y')
	{
		Customer c;
		cin >> c;
		c.save(!0);
		customer.push_back(c);
	}

	cout << "Continue?Enter your choice:";
l2:
	switch (_getch())
	{
	case'y':;
	case'Y':goto l1; break;
	case'n':;
	case'N':roommenu(); break;
	default:goto l2;
	}
}

void Room::save(int flag)

{
	ofstream out;
	if (flag == 0) out.open("room.dat", ios::out | ios::trunc);
	else out.open("room.dat", ios::out | ios::app);

	if (!out.is_open())
	{
		cout << "Failed!" << endl;
		return;
	}

	else
	{
		out << '\n' << roomnum << ' ' << price << ' ' << level << ' ' << is_sold << ' ';

		if (is_sold == 'y' || is_sold == 'Y')
			out << sold_time.month << ' ' << sold_time.day << ' ' << sold_time.hour << ' ' << sold_time.minis;
	}

	out.close();
}

bool Room::check()
{
	for (int i = 0; i < room.size(); i++)
		if (room.at(i).roomnum == roomnum)
			return false;
	return true;
}