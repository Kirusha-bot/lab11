﻿#include <iostream>
#include <clocale>
#include <fstream>
#include <Windows.h>
#include <random>
#include <ctime>

using namespace std;

struct Node
{
	int data;
	Node* prev = nullptr, * next = nullptr;

	void addData(int Data)
	{
		data = Data;
	}
};

struct	LinckedList
{
	Node* head = nullptr, * tail = nullptr;

	// Вывод списка
	void print(LinckedList list)
	{
		Node* node = list.head;

		if (node == nullptr) cout << "Список пустой";
		else
		{
			while (node != nullptr)
			{
				cout << node->data << ' ';
				node = node->next;
			}
			cout << endl;
		}
	}

	// Адрес по индексу
	Node* getAd(int ind)
	{
		if (ind < 0) return 0;

		Node* node = head;
		int n = 0;
		while (node && n != ind && node->next)
		{
			node = node->next;
			n++;
		}

		if (n == ind) return node;
		else return nullptr;
	}

	// Удаление первого элемента списка
	void pop_front()
	{
		Node* node = head;
		head = node->next;
		head->prev = nullptr;

		delete node;
	}

	// Удаление элемента слева
	void erase_el(int ind)
	{
		if (ind <= 0) return;

		if (ind == 1)
		{
			pop_front();
			return;
		}

		Node* left = getAd(ind - 2);
		Node* node = left->next;
		Node* right = node->next;
		left->next = right;
		right->prev = left;

		delete node;
	}

	// Добавление в конец
	void push_back(int data)
	{
		Node* node = new Node;
		node->addData(data);

		node->prev = tail;
		if (tail != nullptr) tail->next = node;
		if (head == nullptr) head = node;
		tail = node;
	}
};

int main()
{
	setlocale(0, "");
	srand(time(0));
	LinckedList list;
	int N;
	cout << "Введите размер списка: ";
	cin >> N;
	cout << "Начальный массив:" << '\n';
	for (int i = 0; i < N; i++) list.push_back(rand() % 100 - 50);
	list.print(list);

	int push_n;
	cout << "Введите сколько элементов хотите добавить в конец списка: ";
	cin >> push_n;
	for (int i = 0; i < push_n; i++) list.push_back(rand() % 100 - 50);
	cout << "Добавлено 3 элемента в конец списка:" << endl;
	list.print(list);

	int erase_k, erase_ind;
	cout << "Введите номер элемента от которого нужно удалить слева элементы: ";
	cin >> erase_ind;
	erase_ind--;
	cout << "Введите сколько элементов удалить: ";
	cin >> erase_k;

	for (int i = 0; i < erase_k; i++) list.erase_el(erase_ind - i);
	cout << "Итоговый массив:" << endl;
	list.print(list);
	return 0;
}