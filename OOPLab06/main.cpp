#include <iostream>
#include "list.h"
/*
  Створити шаблонний клас – однозв’язний кільцевий список у динамічній пам’яті.
  Тип елементів списку визначається параметром шаблона (цілі числа, дійсні числа, символи або символьні рядки).
  Передбачити функції для виконання таких операцій: занесення елемента до списку, вилучення елемента зі списку,
виведення заданої кількості елементів кільцевого списку на екран, визначення кількості елементів списку.
*/
int  main(void)
{
	system("color F0");
	List<string> d;
	d.push(string("Taras"));
	d.push(string("Oleg"));
	d.push(string("Roxolana"));
	cout << "Enter elements:"<<endl;
	d.loop();
	//d.PrintElem(3);
	// d.clear();
	d.deleteElem(string("Taras"));
	//d.PrintElem(3);
	cout << "After deletion:"<<endl;
	d.loop();
	system("pause");
	return 0;
}
