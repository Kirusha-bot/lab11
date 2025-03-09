#include <iostream>
#include <clocale>
#include <random>
#include <ctime>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct Stack
{
	Node* head;
	int size;
};

void setNode(Node*& temp, int data, Node* next)
{
	temp = new Node;
	temp->next = next;
	temp->data = data;
}

void setStack(Stack& MyStack)
{
	MyStack.head = nullptr;
	MyStack.size = 0;
}

void push(Stack& MyStack, int& data)
{
	Node* new_node;
	setNode(new_node, data, MyStack.head);
	MyStack.head = new_node;
	MyStack.size++;
}

void pop(Stack& MyStack)
{
	if (MyStack.head != nullptr)
	{
		Node* delete_el = MyStack.head;
		MyStack.head = MyStack.head->next;
		delete delete_el;
		MyStack.size--;
	}
}

void clear(Stack& MyStack)
{
	while (MyStack.head != NULL)
	{
		Node* delete_el = MyStack.head;
		MyStack.head = MyStack.head->next;
		delete delete_el;
		MyStack.size--;
	}
}

void print(Stack& MyStack)
{
	Node* temp = MyStack.head;
	while (temp != NULL)
	{
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	setlocale(0, "");
	srand(time(0));
	Stack MyStack;
	setStack(MyStack);
	int n, data;
	cout << "Введите размер массива: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		data = rand() % 100 - 50;
		push(MyStack, data);
	}
	cout << "Начальный массив:\n";
	print(MyStack);
	cout << "Введите сколько элементов хотите добавить в конец массива: ";
	int k;
	cin >> k;
	Stack temp_Stack;
	setStack(temp_Stack);
	for (Node* temp = MyStack.head; temp != NULL; temp = temp->next)
	{
		push(temp_Stack, temp->data);
	}
	clear(MyStack);
	for (int i = 0; i < k; i++)
	{
		data = rand() % 100 - 50;
		push(temp_Stack, data);
	}
	for (Node* temp = temp_Stack.head; temp != NULL; temp = temp->next)
		push(MyStack, temp->data);
	clear(temp_Stack);
	cout << "Добавлено " << k << " элементов:\n";
	print(MyStack);
	cout << "Введите номер элемента перед которым нужно удалить K элементов: ";
	int num, K;
	cin >> num;
	cout << "Введите K: ";
	cin >> K;
	Node* temp = MyStack.head;
	for (int i = 0; i < num - K - 1; i++)
	{
		push(temp_Stack, temp->data);
		temp = temp->next;
	}
	for (int i = 0; i < num - 1; i++)
	{
		pop(MyStack);
	}
	for (temp = temp_Stack.head; temp != NULL; temp = temp->next)
	{
		push(MyStack, temp->data);
	}
	cout << "Итоговый массив: \n";
	print(MyStack);
	clear(MyStack);
	clear(temp_Stack);
	return 0;
}