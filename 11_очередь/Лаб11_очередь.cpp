#include <iostream>
#include <clocale>
#include <random>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct Queue
{
	int size;
	Node* head, * tail;

	void create_Q(int n)
	{
		if (n != 0)
		{
			int value = rand() % 100 - 50;
			init_Q(value);
			for (int i = 2; i <= n; i++)
			{
				value = rand() % 100 - 50;
				push_Q(value);
			}
		}
		else cout << "Список пустой";
	}

	void init_Q(int value)
	{
		Node* new_Node = new Node{ value, nullptr };
		new_Node->data = value;
		new_Node->next = nullptr;
		head = new_Node;
		tail = new_Node;
		size = 1;
	}

	void push_Q(int data)
	{
		Node* new_Node = new Node{ data, nullptr };
		tail->next = new_Node;
		tail = new_Node;
		size++;
	}

	void pop()
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
	}

	void erase_Q(int K, int num)
	{
		for (int i = 0; i < num - K - 1; i++)
		{
			push_Q(head->data);
			pop();
		}
		for (int i = 0; i < K; i++) pop();
		for (int i = 0; i < size - K; i++)
		{
			push_Q(head->data);
			pop();
		}
	}

	void delete_Q()
	{
		while (head->next != nullptr)
			pop();
		Node* temp = head;
		head = nullptr;
		size--;
		delete temp;
	}

	void print()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << ' ';
			temp = temp->next;
		}
		cout << endl;
	}
};

int main()
{
	setlocale(0, "");
	srand(time(0));
	cout << "Введите длину массива: ";
	int n;
	cin >> n;
	Queue Q;
	Q.create_Q(n);
	Q.print();
	int k;
	cout << "Введите сколько элементов добавить в конец массива: ";
	cin >> k;
	for (int i = 0; i < k; i++) Q.push_Q(rand() % 100 - 50);
	Q.print();
	cout << "Ведите номер элемента перед которым нужно удалить K элементов: ";
	int num;
	cin >> num;
	int K;
	cout << "Введите K: ";
	cin >> K;
	Q.erase_Q(K, num);
	cout << "Итоговый массив:\n";
	Q.print();
	Q.delete_Q();
	return 0;
}