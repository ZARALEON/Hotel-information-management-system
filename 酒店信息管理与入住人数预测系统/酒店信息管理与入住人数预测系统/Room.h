#pragma once
#include"Time.h"
#include"Customer.h"

//客房类定义
class Room
{
private:
	int roomnum;//客房编号
	int price;//价钱
	char level;//等级
	char is_sold;//是否售出
	Time sold_time;//售出时间

public:
	//提供私有成员修改接口
	void setroomnum(int roomnum)
	{
		this->roomnum = roomnum;
	}
	void setmoney(int price)
	{
		this->price = price;
	}
	void setlevel(char level)
	{
		this->level = level;
	}
	void setis_sold(char is_sold)
	{
		this->is_sold = is_sold;
	}
	void setsold_time(Time sold_time)
	{
		this->sold_time = sold_time;
	}

	//提供私有成员访问接口
	/*
	int getmoney()const
	{
		return price;
	}
	char getlevel()const
	{
		return level;
	}

	Time getsold_time()const
	{
		return sold_time;
	}*/

	char getis_sold()const
	{
		return is_sold;
	}
	int getroomnum()const
	{
		return roomnum;
	}

	void input();//客房信息输入
	void change(char n);
	void save(int flag);//客房信息保存在文件
	bool check();//检测是否房间编号是否重复

	friend ostream& operator<<(ostream& os, const Room& r);
	friend istream& operator>>(istream& is, Room& r);
};
