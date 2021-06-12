#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;

void loginmenu();/*登录菜单*/
void login_import();/*登录成功时从文件中导入信息*/
bool logincheck(string account, string password);/*检测账号密码是否正确*/

//定义管理员类
class Admin
{
private:
	string account;
	string password;

public:
	//提供账号密码修改接口
	void setaccount(string account)
	{
		this->account = account;
	}
	void setpassword(string password)
	{
		this->password = password;
	}

	//提供账号密码访问接口
	string getaccount()const
	{
		return account;
	}
	string getpassword()const
	{
		return password;
	}
};
