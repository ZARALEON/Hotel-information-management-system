#include <iostream>
#include<vector>
#include "LinearRegression.h"
#include"Customer.h"
extern void mainmenu();
extern vector<Customer>customer;
using namespace std;

double* readdatax(vector<Customer>customer)
{
	int i;
	int index = 0;
	double* data = new double[30];
	for (i = 0; i < 20; i++)
	{
		data[i] = i + 1.0;
		cout << "X=" << data[i] << endl;
	}
	return data;
}

double* readdatay(vector<Customer>customer)
{
	int i;
	int index = 0;
	double* data = new double[30];

	for (index = 0; index < 20; index++)
	{
		double count = 0;
		for (i = 0; i < customer.size(); i++)
		{
			if (index >= customer[i].getin_day() && index < customer[i].getout_day())
				count++;
		}

		data[index] = count;
		cout << "Y=" << data[index] << endl;
	}

	return data;
}

void Prediction()
{
	double alpha = 0.000102;

	int iterations = 200;
	double x_predict;
	double y_predict;

	double temp;
	int length = 20;

	double* X = new double[length];
	double* Y = new double[length];

	// Ä£ÐÍÑµÁ·Ô¤²â
	X = readdatax(customer);
	Y = readdatay(customer);
	LinearRegression lr(X, Y, length);
	lr.train(alpha, iterations);
l1:
	cout << endl << "Input the day:";
	cin >> x_predict;
	y_predict = lr.predict(x_predict);
	cout << y_predict << endl;

	cout << "Continue?Enter your choice:";
l2:
	switch (_getch())
	{
	case'y':;
	case'Y':goto l1; break;
	case'n':;
	case'N':mainmenu(); break;
	default:goto l2;
	}
}