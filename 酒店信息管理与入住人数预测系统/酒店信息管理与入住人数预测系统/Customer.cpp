#include "Customer.h"
#include"Header.h"
extern vector<Room>room;
extern vector<Customer>customer;

ostream& operator<<(ostream& os, const Customer& c)
{
	os << "       " << c.cusnum << "       " << c.name << "       " << c.sex << "       " << c.id << "       " << c.contact << "       " << c.in_time << "       " << c.out_time << "       " << c.roomnum << endl;
	return os;
}

istream& operator>>(istream& is, Customer& c)
{
l1:

	cout << endl << "Cusnum:";
	is >> c.cusnum;
	if (c.cusnum < 100 || c.cusnum>999 || !c.check())
	{
		cout << endl << "Wrong!!!Again!" << endl;
		goto l1;
	}

	cout << endl << "Name:";
	is >> c.name;
l2:
	cout << endl << "Sex:";
	is >> c.sex;
	if (c.sex != 'm' && c.sex != 'M' && c.sex != 'w' && c.sex != 'W')
	{
		cout << endl << "Wrong!!!Again!" << endl;
		goto l2;
	}
l3:
	cout << endl << "ID:";
	is >> c.id;
	if (strlen(c.id.c_str()) != 5)
	{
		cout << endl << "Wrong!!!Again!" << endl;
		goto l3;
	}
l4:
	cout << endl << "Contact:";
	is >> c.contact;
	if (strlen(c.contact.c_str()) != 5)
	{
		cout << endl << "Wrong!!!Again!" << endl;
		goto l4;
	}

	cout << endl << "In time(month/day hour:minute)::";
	is >> c.in_time;

	cout << endl << "Out time(month/day hour:minute)::";
	is >> c.out_time;
l5:
	int flag = 0;
	int i;
	cout << endl << "Roomnum:";
	is >> c.roomnum;

	for (i = 0; i < room.size(); i++)
	{
		if (room.at(i).getroomnum() == c.roomnum)
		{
			flag = 1;
			break;
		}
	}

	if (flag == 0)
	{
		cout << "No this roomnum!" << endl;
		goto l5;
	}

	room.at(i).setroomnum(c.roomnum);
	room.at(i).setis_sold('y');
	room.at(i).setsold_time(c.in_time);

	if (room[room.size() - 2].getroomnum() == room[room.size() - 3].getroomnum())
	{
		Room temp;
		temp = room[room.size() - 2];
		room[room.size() - 2] = room[room.size() - 1];
		room[room.size() - 1] = temp;
		room.pop_back();
	}

	for (i = 0; i < room.size(); i++) room[i].save(i);

	return is;
}

void Customer::input()
{
l1:
	system("cls");
	Customer c;
	cin >> c;
	c.save(!0);
	customer.push_back(c);
	cout << "Continue?Enter your choice:";
l2:
	switch (_getch())
	{
	case'y':;
	case'Y':goto l1; break;
	case'n':;
	case'N':cusmenu(); break;
	default:goto l2;
	}
}
void Customer::save(int flag)
{
	ofstream out;
	if (flag == 0) out.open("customer.dat", ios::out | ios::trunc);
	else out.open("customer.dat", ios::out | ios::app);

	if (!out.is_open())
	{
		cout << "Failed!" << endl;
		return;
	}

	else out << '\n' << cusnum << ' ' << name << ' ' << sex << ' ' << id << ' ' << contact << ' ' << in_time.month << ' ' << in_time.day << ' ' << in_time.hour << ' ' << in_time.minis << ' ' << out_time.month << ' ' << out_time.day << ' ' << out_time.hour << ' ' << out_time.minis << ' ' << roomnum;

	out.close();
}
bool Customer::check()
{
	for (int i = 0; i < customer.size(); i++)
		if (customer.at(i).cusnum == cusnum)
			return false;
	return true;
}

void Customer::change(char n)
{
	if (n == '1')
	{
	l1:
		int cusnum;
		cout << "Input new number:";
		cin >> cusnum;
		this->cusnum = cusnum;

		for (int i = 0; i < customer.size(); i++)
		{
			if (cusnum == customer[i].cusnum)
			{
				cout << endl << "Wrong!!!Again!" << endl;
				goto l1;
			}
		}

		cout << "Continue?" << endl;
	l2:
		switch (_getch())
		{
		case'y':;
		case'Y':goto l1;
		case'n':;
		case'N':
		{
			for (int i = 0; i < customer.size(); i++)
				customer[i].save(i);
			cuschangemenu(); break;
		}
		default:goto l2;
		}
	}

	if (n == '2')
	{
	l3:
		string name;
		cout << "Input new name:";
		cin >> name;
		this->name = name;

		cout << "Continue?" << endl;
	l4:
		switch (_getch())
		{
		case'y':;
		case'Y':goto l3;
		case'n':;
		case'N':
		{
			for (int i = 0; i < customer.size(); i++)
				customer[i].save(i);
			cuschangemenu(); break;
		}
		default:goto l4;
		}
	}

	if (n == '3')
	{
	l5:
		char sex;
		cout << "Input new sex:";
		cin >> sex;
		this->sex = sex;

		cout << "Continue?" << endl;
	l6:
		switch (_getch())
		{
		case'y':;
		case'Y':goto l5;
		case'n':;
		case'N':
		{
			for (int i = 0; i < customer.size(); i++)
				customer[i].save(i);
			cuschangemenu(); break;
		}
		default:goto l6;
		}
	}

	if (n == '4')
	{
	l7:
		string id;
		cout << "Input new id:";
		cin >> id;
		this->id = id;

		cout << "Continue?" << endl;
	l8:
		switch (_getch())
		{
		case'y':;
		case'Y':goto l7;
		case'n':;
		case'N':
		{
			for (int i = 0; i < customer.size(); i++)
				customer[i].save(i);
			cuschangemenu(); break;
		}
		default:goto l8;
		}
	}

	if (n == '5')
	{
	l9:
		string contact;
		cout << "Input new contact:";
		cin >> contact;
		this->contact = contact;

		cout << "Continue?" << endl;
	l10:
		switch (_getch())
		{
		case'y':;
		case'Y':goto l9;
		case'n':;
		case'N':
		{
			for (int i = 0; i < customer.size(); i++)
				customer[i].save(i);
			cuschangemenu(); break;
		}
		default:goto l10;
		}
	}

	if (n == '6')
	{
	l11:
		Time in_time;
		cout << "Input new in time:";
		cin >> in_time;
		this->in_time = in_time;

		cout << "Continue?" << endl;
	l12:
		switch (_getch())
		{
		case'y':;
		case'Y':goto l11;
		case'n':;
		case'N':
		{
			for (int i = 0; i < customer.size(); i++)
				customer[i].save(i);
			cuschangemenu(); break;
		}
		default:goto l12;
		}
	}
	if (n == '7')
	{
	l13:
		Time out_time;
		cout << "Input new out time:";
		cin >> out_time;
		this->out_time = out_time;

		cout << "Continue?" << endl;
	l14:
		switch (_getch())
		{
		case'y':;
		case'Y':goto l13;
		case'n':;
		case'N':
		{
			for (int i = 0; i < customer.size(); i++)
				customer[i].save(i);
			cuschangemenu(); break;
		}
		default:goto l14;
		}
	}

	if (n == '8')
	{
	l15:
		int roomnum;
		cout << "Input new roomnum:";
		cin >> roomnum;
		this->roomnum = roomnum;

		cout << "Continue?" << endl;
	l16:
		switch (_getch())
		{
		case'y':;
		case'Y':goto l15;
		case'n':;
		case'N':
		{
			for (int i = 0; i < customer.size(); i++)
				customer[i].save(i);
			cuschangemenu(); break;
		}
		default:goto l16;
		}
	}
}