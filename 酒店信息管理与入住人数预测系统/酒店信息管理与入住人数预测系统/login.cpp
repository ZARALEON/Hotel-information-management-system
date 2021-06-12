#include"login.h"
#include"Header.h"
#include"Room.h"
#include"Customer.h"
//此处定义两个容器
vector<Room>room;
vector<Customer>customer;

void loginmenu()
{
	system("cls");
	string account, password;

	cout << "***********************************" << endl;
	cout << "        Welcom to this system!     " << endl;
	cout << "Please input your account and password!" << endl;
	cout << endl << "Account:";
	cin >> account;
	cout << endl << "Password:";
	cin >> password;

	if (logincheck(account, password))
	{
		cout << endl << "Successful!!\n" << endl;
		cout << "***********************************" << endl;
		login_import();
		system("pause");
		mainmenu();
	}

	else
	{
		cout << endl << "Failed!!Again!!\n" << endl;
		cout << "***********************************" << endl;
		system("pause");
		loginmenu();
	}
}

bool logincheck(string account, string password)
{
	vector<Admin>admin;
	ifstream in;

	in.open("account.dat", ios::in);
	if (!in.is_open())
	{
		cout << "Failed!" << endl;
		return false;
	}

	else while (!in.eof())
	{
		string faccount, fpassword;

		in >> faccount >> fpassword;

		Admin a;
		a.setaccount(faccount);
		a.setpassword(fpassword);
		admin.push_back(a);

		if (strcmp(a.getaccount().c_str(), account.c_str())) continue;

		else
		{
			if (!strcmp(a.getpassword().c_str(), password.c_str()))
			{
				in.close();
				return true;
				break;
			}
			else continue;
		}
	}

	in.close();
	return false;
}

void login_import()
{
	ifstream rin, cuin;

	rin.open("room.dat", ios::in);
	cuin.open("customer.dat", ios::in);
	if (!rin.is_open() && !cuin.is_open())
	{
		cout << "Failed!" << endl;
	}

	else
	{
		while (!rin.eof())
		{
			int fnum;
			int fmoney;
			char flevel;
			char fis_sold;
			Time fsold_time;

			rin >> fnum >> fmoney >> flevel >> fis_sold;
			if (fis_sold == 'y' || fis_sold == 'Y') rin >> fsold_time.month >> fsold_time.day >> fsold_time.hour >> fsold_time.minis;

			Room r;
			r.setroomnum(fnum);
			r.setmoney(fmoney);
			r.setlevel(flevel);
			r.setis_sold(fis_sold);
			if (fis_sold == 'y' || fis_sold == 'Y') r.setsold_time(fsold_time);
			room.push_back(r);
		}
		while (!cuin.eof())
		{
			int fnum;
			string fname;
			char fsex;
			string fid;
			string fcontact;
			Time fin_time;
			Time fout_time;
			int froomnum;

			cuin >> fnum >> fname >> fsex >> fid >> fcontact >> fin_time.month >> fin_time.day >> fin_time.hour >> fin_time.minis >> fout_time.month >> fout_time.day >> fout_time.hour >> fout_time.minis >> froomnum;

			Customer c;

			c.setnum(fnum);
			c.setname(fname);
			c.setsex(fsex);
			c.setid(fid);
			c.setcontact(fcontact);
			c.setin_time(fin_time);
			c.setout_time(fout_time);
			c.setroomnum(froomnum);
			customer.push_back(c);
		}
	}

	rin.close();
	cuin.close();
}