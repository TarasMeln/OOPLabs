#include <iostream>
#include "list.h"
/*
  �������� ��������� ���� � ����������� �������� ������ � �������� �����.
  ��� �������� ������ ����������� ���������� ������� (��� �����, ���� �����, ������� ��� �������� �����).
  ����������� ������� ��� ��������� ����� ��������: ��������� �������� �� ������, ��������� �������� � ������,
��������� ������ ������� �������� ��������� ������ �� �����, ���������� ������� �������� ������.
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
