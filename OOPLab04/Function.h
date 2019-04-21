#pragma once

#include "method.h"

void sort(Rest_aboard CustomArr[], int size)
{
	Rest_aboard tmp;
	for (int i = 1; i < size; i++)
		for (int j = i; j > 0 && CustomArr[j - 1].Get_travel_price() < CustomArr[j].Get_travel_price(); j--)
		{
			tmp = CustomArr[j];
			CustomArr[j] = CustomArr[j - 1];
			CustomArr[j - 1] = tmp;
		}
}
void Print(Rest_aboard a[], int K)
{
	for (int i = 0; i < K; ++i)
	{
		cout << a[i] << endl;
	}

}
void Input(Rest_aboard a[], int  K)
{
	char currency[5];
	int convert;
	double  travel_price;
	char place[20] = "";
	for (int i = 0; i < K; ++i)
	{
		cout << "Input place" << endl;
		cin >> place;
		a[i].Set_place(place);
		cout << "Enter the price for travel" << endl;
		cin >> travel_price;
		cout << "Enter currency" << endl;
		cin >> currency;
		if (strcmp(currency, "USD") == 0)
		{
			travel_price *= 26;
		}
		if (strcmp(currency, "EUR") == 0)
		{
			travel_price *= 29;
		}
		if (strcmp(currency, "RUR") == 0)
		{
			travel_price /= 4;
		}

		a[i].Set_travel_price(travel_price);
	}
}
double sum(Rest_aboard a[], int K, const char *str)
{

	double sum = 0;
	for (int i = 0; i < K; ++i)
	{
		sum += a[i].Get_travel_price();
	}

	if (strcmp(str, "USD") == 0)
	{
		sum /= 26;
	}
	if (strcmp(str, "EUR") == 0)
	{
		sum /= 29;
	}
	if (strcmp(str, "RUR") == 0)
	{
		sum *= 4;
	}
	return sum;
}
