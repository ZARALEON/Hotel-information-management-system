#pragma once
#include"Room.h"
#include"Time.h"

//�˿��ඨ��
class Customer
{
	int cusnum;//�˿ͱ��
	string name;//����
	char sex;//�Ա�
	string id;//���֤�� 5λ
	string contact;//��ϵ��ʽ 5λ
	Time in_time;//��סʱ��
	Time out_time;//�뿪ʱ��
	int roomnum;
public:

	//�ṩ˽�г�Ա�޸Ľӿ�
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

	//�ṩ˽�г�Ա���ʽӿ�
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

	void input();//��Ϣ����
	void save(int flag);//�˿���Ϣ�������ļ�
	bool check();//����Ƿ�˿ͱ���Ƿ��ظ�
	void change(char n);

	friend ostream& operator<<(ostream& os, const Customer& c);
	friend istream& operator>>(istream& is, Customer& c);
};
