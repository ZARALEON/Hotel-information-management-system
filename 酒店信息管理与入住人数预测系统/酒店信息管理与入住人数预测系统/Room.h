#pragma once
#include"Time.h"
#include"Customer.h"

//�ͷ��ඨ��
class Room
{
private:
	int roomnum;//�ͷ����
	int price;//��Ǯ
	char level;//�ȼ�
	char is_sold;//�Ƿ��۳�
	Time sold_time;//�۳�ʱ��

public:
	//�ṩ˽�г�Ա�޸Ľӿ�
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

	//�ṩ˽�г�Ա���ʽӿ�
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

	void input();//�ͷ���Ϣ����
	void change(char n);
	void save(int flag);//�ͷ���Ϣ�������ļ�
	bool check();//����Ƿ񷿼����Ƿ��ظ�

	friend ostream& operator<<(ostream& os, const Room& r);
	friend istream& operator>>(istream& is, Room& r);
};
