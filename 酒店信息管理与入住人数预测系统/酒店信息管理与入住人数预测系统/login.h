#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;

void loginmenu();/*��¼�˵�*/
void login_import();/*��¼�ɹ�ʱ���ļ��е�����Ϣ*/
bool logincheck(string account, string password);/*����˺������Ƿ���ȷ*/

//�������Ա��
class Admin
{
private:
	string account;
	string password;

public:
	//�ṩ�˺������޸Ľӿ�
	void setaccount(string account)
	{
		this->account = account;
	}
	void setpassword(string password)
	{
		this->password = password;
	}

	//�ṩ�˺�������ʽӿ�
	string getaccount()const
	{
		return account;
	}
	string getpassword()const
	{
		return password;
	}
};
