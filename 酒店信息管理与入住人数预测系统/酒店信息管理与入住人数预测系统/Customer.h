#pragma once
#include"Room.h"
#include"Time.h"

//顾客类定义
class Customer
{
	int cusnum;//顾客编号
	string name;//姓名
	char sex;//性别
	string id;//身份证号 5位
	string contact;//联系方式 5位
	Time in_time;//入住时间
	Time out_time;//离开时间
	int roomnum;
public:

	//提供私有成员修改接口
	void setnum(int cusnum)
	{
		this->cusnum = cusnum;
	}
	void setname(string name)
	{
		this->name = name;
	}
	void setsex(char sex)
	{
		this->sex = sex;
	}
	void setid(string id)
	{
		this->id = id;
	}
	void setcontact(string contact)
	{
		this->contact = contact;
	}
	void setin_time(Time in_time)
	{
		this->in_time = in_time;
	}
	void setout_time(Time out_time)
	{
		this->out_time = out_time;
	}
	void setroomnum(int roomnum)
	{
		this->roomnum = roomnum;
	}

	//提供私有成员访问接口
	int getcusnum()const
	{
		return cusnum;
	}
	string getname()const
	{
		return name;
	}
	char getsex()const
	{
		return sex;
	}
	string getid()const
	{
		return id;
	}
	string getcontact()const
	{
		return contact;
	}
	Time getin_time()const
	{
		return in_time;
	}
	Time getout_time()const
	{
		return out_time;
	}
	int getin_day()const
	{
		return in_time.day;
	}
	int getout_day()const
	{
		return out_time.day;
	}
	int getroomnum()const
	{
		return roomnum;
	}

	void input();//信息输入
	void save(int flag);//顾客信息保存在文件
	bool check();//检测是否顾客编号是否重复
	void change(char n);

	friend ostream& operator<<(ostream& os, const Customer& c);
	friend istream& operator>>(istream& is, Customer& c);
};
