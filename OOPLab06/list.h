#pragma once
#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
template <class T> class List // шаблон класса списків
{

	struct Element
	{
		T data; // змінна для збереження данних елемента
		Element *next; // вказівник на наступний елемент списку
	};
private:
	Element *start; //вказівник на перший доданий елемент
	Element *Curr; //вказівник на поточний елемент
	Element *prev;
public:
	void clear();
	int length = 0;
	void push(T data);
	int isNoEmpty();
	void deleteElem(T elem);
	void PrintElem(int k);
	List();
	~List();
	void loop();
};
template<class T>
List<T>::~List<T>()
{
	clear();
}

template<class T>
List<T>::List()
{
	this->start = NULL;
	this->Curr = NULL;
}
template <class T> void List<T>::push(T data)
{
	Element *inserted;
	inserted = new Element;

	inserted->data = data;

	if (!isNoEmpty()) // якщо список пустий
	{
		this->start = inserted; // встановити вказівник першого елемента на новий елемент
		Curr = inserted;
		Curr->next = nullptr;

	}
	else
	{
		inserted->next = start;
		Curr->next = inserted;
	}

	length++;
	Curr = inserted;
}

template <class T> int List<T> ::isNoEmpty() // перевіряємо чи список пустий
{
	if (this->Curr == NULL)
		return 0;
	else
		return 1;
}


template <class T > void List <T> ::deleteElem(T elem)
{
	if (!isNoEmpty())
		return;

	Element *prev = start;
	Element *node = start;
	
	if (prev->data == elem)
	{
		start = start->next;
		delete prev;
		length--;
		return;
	}

	while (node != nullptr)
	{
		if (node->data == elem)
		{
			prev->next = node->next;
			delete node;
			length--;
			break;
		}
		prev = prev->next;
		node = node->next;
	}

}

template <class T> void List<T>::loop()
{
	if (isNoEmpty())
	{
		Element *tempCar = start;

		for (int i = 0; i < length; i++)
		{
			cout << tempCar->data << endl;
			tempCar = tempCar->next;
		}
		cout << "\n";
	}

	else
		cout << "List is empty\n";
}
template <class T> void List<T>::clear()
{
	if (isNoEmpty())
	{

		Element*tmp = start;

		while (tmp != start)
		{
			prev->next = tmp->next;
			delete(tmp);
			tmp = prev->next;
		}



	}
}
template <class T> void List<T>::PrintElem(int k)
{
	if (isNoEmpty())
	{
		Element *tempCar = start;

		for (int i = 0; i < k; i++)
		{
			cout << tempCar->data << " ";
			tempCar = tempCar->next;
		}
		cout << "\n";
	}

	else
		cout << "List is empty\n";
}
#endif // LIST_H
