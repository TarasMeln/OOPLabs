#pragma once

#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Vacation {
private:
	char Place[20];
	char *Pplace = Place;
	char  time[10];
	char *ptime = time;
public:

	Vacation()
	{
	}

	char *Set_time(char *time)
	{
		strcpy_s(this->time, time);
	}

	char* Get_Time()
	{
		return this->time;
	}

	char* Get_place()
	{
		return this->Place;
	}

	void  Set_place(char *Place)
	{
		strcpy_s(this->Place, Place);
	}

	~Vacation() {}
};
class Rest_aboard : public Vacation
{
private:

	double one_day_price;
	double  travel_price;

public:

	Rest_aboard()
	{
		one_day_price = 0;
		travel_price = 0;
		//cout<<"Called const"<<endl;
	}

	void Set_travel_price(int travel_price)
	{
		this->travel_price = travel_price;
	}

	double  Get_travel_price()
	{
		return this->travel_price;
	}

	friend ostream &operator<<(ostream &out, Rest_aboard &point)
	{
		out << '(' << point.travel_price << ')';
		out << '(' << point.Get_place() << ')' << endl;
		return out;
	}
};

