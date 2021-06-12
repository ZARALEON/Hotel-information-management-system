#include"Header.h"
#include"Room.h"
#include"Customer.h"
extern void Prediction();
extern vector<Room>room;
extern vector<Customer>customer;
void mainmenu()
{
l1:
	system("cls");
	cout << "***********************************" << endl;
	cout << "        Welcom to the system!" << endl;
	cout << "1.Rooms" << endl;
	cout << "2.Customer" << endl;
	cout << "3.Prediction" << endl;
	cout << "4.Exit" << endl;

	cout << "Please enter your choice:" << endl;

	switch (char a = _getch())
	{
	case '1':roommenu(); break;
	case '2':cusmenu(); break;
	case '3':Prediction(); break;
	case '4':exit(0);
	default:goto l1;
	}

	cout << "***********************************" << endl;
}

void roommenu()
{
	Room r;
l1:
	system("cls");
	cout << "***********************************" << endl;
	cout << "Welcom to roommenu!" << endl;
	cout << "1.Input" << endl;
	cout << "2.Search" << endl;
	cout << "3.Change" << endl;
	cout << "4.All dispaly" << endl;
	cout << "5.Delete" << endl;
	cout << "6.Exit" << endl;
	cout << "Please enter your choice:" << endl;

	switch (char a = _getch())
	{
	case '1':r.input(); break;
	case '2':roomsearch(); break;
	case '3':roomchangemenu(); break;
	case '4':alldisplay(); break;
	case '5':roomdelete(); break;
	case '6':mainmenu(); break;
	default:goto l1;
	}
}

void roomsearch()
{
l1:
	system("cls");
	int roomnum;
	int flag = 0;
	cout << "Input your room number:";
	cin >> roomnum;

	for (int i = 0; i < room.size(); i++)
	{
		if (room.at(i).getroomnum() == roomnum)
		{
			cout << endl << "     " << "Roomnum" << "    " << "Price" << "    " << "Level" << "  " << "Is_sold" << "    " << "Date" << "        " << "Time" << endl;
			cout << room.at(i);
			flag = 1;
			break;
		}
	}

	if (flag == 0)	cout << "No this roomnum!" << endl;
	cout << endl << "Continue?" << endl;
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

void roomchangemenu()
{
l1:
	system("cls");
	int num;
	int i;
	int flag = 0;
	cout << endl << "Input your room number:";
	cin >> num;

	for (i = 0; i < room.size(); i++)
	{
		if (room.at(i).getroomnum() == num)
		{
			cout << endl << "     " << "Roomnum" << "    " << "Price" << "    " << "Level" << "  " << "Is_sold" << "    " << "Date" << "        " << "Time" << endl;
			cout << room.at(i);
			flag = 1;
			break;
		}
	}

	if (flag == 0)
	{
		cout << "No this num!" << endl;
		cout << "Continue?" << endl;
	l2:
		switch (_getch())
		{
		case'y':;
		case'Y':goto l1;
		case'n':;
		case'N':roommenu(); break;
		default:goto l2;
		}
	}
	else
	{
		cout << "1.Roomnum" << endl;
		cout << "2.Price" << endl;
		cout << "3.Level" << endl;
		cout << "4.Is_sold" << endl;
		cout << "5.Sold time" << endl;
		cout << "6.Exit" << endl;
		cout << "Please enter your choice:" << endl;
	l3:	switch (char n = _getch())
	{
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':room.at(i).change(n); break;
	case '6':roommenu(); break;
	default:goto l3;
	}
	}
}

void Room::change(char n)
{
	if (n == '1')
	{
	l1:
		int roomnum;
		cout << "Input new roomnum:";
		cin >> roomnum;

		for (int i = 1; i < room.size(); i++)
		{
			if (roomnum == room[i].roomnum)
			{
				cout << endl << "Wrong!!!Again!" << endl;
				goto l1;
			}
		}

		this->roomnum = roomnum;

		cout << "Continue?" << endl;
	l2:
		switch (_getch())
		{
		case'y':;
		case'Y':;
		case'n':;
		case'N':
		{
			for (int i = 0; i < room.size(); i++)
				room[i].save(i);
			roomchangemenu(); break;
		}
		default:goto l2;
		}
	}

	if (n == '2')
	{
	l3:
		int price;
		cout << "Input new price:";
		cin >> price;
		this->price = price;

		cout << "Continue?" << endl;
	l4:
		switch (_getch())
		{
		case'y':;
		case'Y':goto l3;
		case'n':;
		case'N':
		{
			for (int i = 0; i < room.size(); i++)
				room[i].save(i);
			roomchangemenu(); break;
		}
		default:goto l4;
		}
	}

	if (n == '3')
	{
	l5:
		char level;
		cout << "Input new level:";
		cin >> level;
		this->level = level;

		cout << "Continue?" << endl;
	l6:
		switch (_getch())
		{
		case'y':;
		case'Y':goto l5;
		case'n':;
		case'N':
		{
			for (int i = 0; i < room.size(); i++)
				room[i].save(i);
			roomchangemenu(); break;
		}
		default:goto l6;
		}
	}

	if (n == '4')
	{
	l7:
		char is_sold;
		cout << "Input new is_sold:";
		cin >> is_sold;
		this->is_sold = is_sold;

		cout << "Continue?" << endl;
	l8:
		switch (_getch())
		{
		case'y':;
		case'Y':goto l7;
		case'n':;
		case'N':
		{
			for (int i = 0; i < room.size(); i++)
				room[i].save(i);
			roomchangemenu(); break;
		}
		default:goto l8;
		}
	}

	if (n == '6')
	{
	l9:
		Time sold_time;
		cout << "Input your new sold time(month/day hour:minute)::";
		cin >> sold_time;
		this->sold_time = sold_time;

		cout << "Continue?" << endl;
	l10:
		switch (_getch())
		{
		case'y':;
		case'Y':goto l9;
		case'n':;
		case'N':
		{
			for (int i = 0; i < room.size(); i++)
				room[i].save(i);
			roomchangemenu(); break;
		}
		default:goto l10;
		}
	}
}

void roomdelete()
{
l1:
	system("cls");
	int num;
	int flag = 0;
	cout << "Input your room number:";
	cin >> num;

	for (int i = 0; i < room.size(); i++)
	{
		if (room[i].getroomnum() == num)
		{
			cout << endl << "     " << "Roomnum" << "    " << "Price" << "    " << "Level" << "  " << "Is_sold" << "    " << "Date" << "        " << "Time" << endl << endl;
			cout << room[i] << endl;
			cout << "Delete?" << endl;
		l2:
			switch (_getch())
			{
			case'y':;
			case'Y':
			{
				for (int n = i; n < room.size(); n++)
				{
					if (n < room.size() - 1) room[n] = room[n + 1];
					else room.pop_back();
					flag = 1;
				}
				break;
			}
			case'n':;
			case'N':
			{
				cout << "Continue?" << endl;
				goto l3;
			}
			default:goto l2;
			}
		}
	}

	if (flag == 0)	cout << "No this num!" << endl;
	else
	{
		room.pop_back();
		for (int i = 0; i < room.size(); i++)
		{
			room[i].save(i);
		}
	}
	cout << "Continue?" << endl;
l3:
	switch (_getch())
	{
	case'y':;
	case'Y':goto l1; break;
	case'n':;
	case'N':roommenu(); break;
	default:goto l3;
	}
}

void cusmenu()
{
	Customer c;
l1:
	system("cls");
	cout << "***********************************" << endl;
	cout << "Welcom to cusmenu!" << endl;
	cout << "1.Input" << endl;
	cout << "2.Search" << endl;
	cout << "3.Change" << endl;
	cout << "4.Delete" << endl;
	cout << "5.Exit" << endl;
	cout << "Please enter your choice:" << endl;

	switch (char a = _getch())
	{
	case '1':c.input(); break;
	case '2':cussearchmenu(); break;
	case '3':cuschangemenu(); break;
	case '4':cusdelete(); break;
	case '5':mainmenu(); break;
	default:goto l1;
	}
}

void cussearchmenu()
{
l1:
	system("cls");
	cout << "***********************************" << endl;
	cout << "1.Num" << endl;
	cout << "2.Id" << endl;
	cout << "3.Roomnum" << endl;
	cout << "4.Date" << endl;
	cout << "5.Exit" << endl;

	cout << "Please enter your choice:" << endl;

	switch (char n = _getch())
	{
	case '1':;
	case '2':;
	case '3':cussearch(n); break;
	case '4':daylook();; break;
	case '5':cusmenu();
	default:goto l1;
	}

	cout << "***********************************" << endl;
}

void cussearch(char n)
{
	if (n == '1')
	{
	l1:
		system("cls");
		int num;
		int flag = 0;
		cout << "Input  cusnum:";
		cin >> num;

		for (int i = 0; i < customer.size(); i++)
		{
			if (customer.at(i).getcusnum() == num)
			{
				cout << endl << "       " << "Num" << "       " << "Name" << "      " << "Sex" << "       " << "ID" << "        " << "Contact" << "     " << "In  Date     Time" << "       " << "Out  Date    Time" << "      " << "Roomnum" << endl << endl;
				cout << customer.at(i);
				flag = 1;
				break;
			}
		}

		if (flag == 0)	cout << "No this num!" << endl;
		cout << "Continue?" << endl;
	l2:
		switch (_getch())
		{
		case'y':;
		case'Y':goto l1;
		case'n':;
		case'N':cussearchmenu(); break;
		default:goto l2;
		}
	}

	if (n == '2')
	{
	l3:
		string id;
		int flag = 0;
		cout << "Input  ID:";
		cin >> id;

		for (int i = 0; i < customer.size(); i++)
		{
			if (customer.at(i).getid() == id)
			{
				cout << endl << "       " << "Num" << "       " << "Name" << "      " << "Sex" << "       " << "ID" << "        " << "Contact" << "     " << "In  Date     Time" << "       " << "Out  Date    Time" << "      " << "Roomnum" << endl << endl;
				cout << customer.at(i);
				flag = 1;
				break;
			}
		}

		if (flag == 0)	cout << "No this id!" << endl;
		cout << "Continue?" << endl;
	l4:
		switch (_getch())
		{
		case'y':;
		case'Y':goto l3;
		case'n':;
		case'N':cussearchmenu(); break;
		default:goto l4;
		}
	}

	if (n == '3')
	{
	l5:
		int roomnum;
		int flag = 0;
		cout << "Input  roomnum:";
		cin >> roomnum;

		for (int i = 0; i < customer.size(); i++)
		{
			if (customer.at(i).getroomnum() == roomnum)
			{
				cout << endl << "       " << "Num" << "       " << "Name" << "      " << "Sex" << "       " << "ID" << "        " << "Contact" << "     " << "In  Date     Time" << "       " << "Out  Date    Time" << "      " << "Roomnum" << endl << endl;
				cout << customer.at(i) << endl;
				flag = 1;
			}
		}

		if (flag == 0)	cout << "No this roomnum!" << endl;
		cout << "Continue?" << endl;
	l6:
		switch (_getch())
		{
		case'y':;
		case'Y':goto l5;
		case'n':;
		case'N':cussearchmenu(); break;
		default:goto l6;
		}
	}
}

void daylook()
{
	int index = 1;
l1:
	system("cls");
	int count = 0;
	cout << "Date " << index << endl;
	cout << endl << "       " << "Num" << "       " << "Name" << "      " << "Sex" << "       " << "ID" << "        " << "Contact" << "     " << "In  Date     Time" << "       " << "Out  Date    Time" << "      " << "Roomnum" << endl << endl;
	for (int k = 0; k < customer.size(); k++)
	{
		if (index >= customer[k].getin_day() && index < customer[k].getout_day())
		{
			cout << customer[k] << endl;
			count++;
		}
	}
	cout << endl << "All people today is " << count << endl;

l2:
	switch (_getch())
	{
	case 's':
	{
		if (index == 1) goto l2;
		index--;
		goto l1;
	}
	case 'w':
	{
		if (index == 31) goto l2;
		index++;
		goto l1;
	}
	case 27:cussearchmenu(); break;
	default:goto l2;
	}
}

void cuschangemenu()
{
l1:
	int num;
	int i;
	int flag = 0;
	cout << "Input your person number:";
	cin >> num;

	for (i = 0; i < customer.size(); i++)
	{
		if (customer.at(i).getcusnum() == num)
		{
			cout << endl << "       " << "Num" << "       " << "Name" << "      " << "Sex" << "       " << "ID" << "        " << "Contact" << "     " << "In  Date     Time" << "       " << "Out  Date    Time" << "      " << "Roomnum" << endl << endl;
			cout << customer.at(i) << endl;
			flag = 1;
			break;
		}
	}

	if (flag == 0)
	{
		cout << "No this num!" << endl;
		cout << "Continue?" << endl;
	l2:
		switch (_getch())
		{
		case'y':;
		case'Y':goto l1;
		case'n':;
		case'N':cusmenu(); break;
		default:goto l2;
		}
	}
	else
	{
		cout << "1.Num" << endl;
		cout << "2.Name" << endl;
		cout << "3.Sex" << endl;
		cout << "4.ID" << endl;
		cout << "5.Contact" << endl;
		cout << "6.In_time" << endl;
		cout << "7.Out time" << endl;
		cout << "8.Roomnum" << endl;
		cout << "9.Exit" << endl;
		cout << "Please enter your choice:" << endl;
	l3:	switch (char n = _getch())
	{
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':customer.at(i).change(n); break;
	case'9':cusmenu(); break;
	default:goto l3;
	}
	}
}

void cusdelete()
{
l1:
	int num;
	int flag = 0;
	cout << "Input cusnum:";
	cin >> num;

	for (int i = 0; i < customer.size(); i++)
	{
		if (customer[i].getcusnum() == num)
		{
			cout << endl << "       " << "Num" << "       " << "Name" << "      " << "Sex" << "       " << "ID" << "        " << "Contact" << "     " << "In  Date     Time" << "       " << "Out  Date    Time" << "      " << "Roomnum" << endl << endl;
			cout << customer[i] << endl;
			cout << "Delete?" << endl;
		l2:
			switch (_getch())
			{
			case'y':;
			case'Y':
			{
				for (int n = i; n < customer.size(); n++)
				{
					if (n < customer.size() - 1) customer[n] = customer[n + 1];
					else customer.pop_back();
					flag = 1;
				}
				break;
			}
			case'n':;
			case'N':
			{
				cout << "Continue?" << endl;
				goto l3;
			}
			default:goto l2;
			}
		}
	}

	if (flag == 0)	cout << "No this num!" << endl;
	else
	{
		customer.pop_back();
		for (int i = 0; i < customer.size(); i++)
		{
			customer[i].save(i);
		}
	}
	cout << "Continue?" << endl;
l3:
	switch (_getch())
	{
	case'y':;
	case'Y':goto l1; break;
	case'n':;
	case'N':cusmenu(); break;
	default:goto l3;
	}
}

void alldisplay()
{
	system("cls");
	int i, k = 0;
	cout << endl << "     " << "Roomnum" << "    " << "Price" << "    " << "Level" << "  " << "Is_sold" << "    " << "Date" << "        " << "Time" << endl << endl;

	if (room.back().getis_sold() == 'n' || room.back().getis_sold() == 'N')
		k = room.size() - 1;
	else k = room.size();

	for (i = 0; i < k; i++)
	{
		cout << room[i] << endl;
	}
	switch (_getch())
	{
	default:roommenu();
	}
}