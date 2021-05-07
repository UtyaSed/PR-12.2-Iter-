// ������������ ������ ������� ������ �� ������� ������������ ���������
// �������������� ����.

#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

typedef int Info; // ��������� ��������� ����

struct Elem
{
	Elem* link;
	Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value);
void print(Elem* L);
void process(Elem* L, Info value);
Info dequeue(Elem*& first, Elem*& last);

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // ������������ ����������� �������� � ������

	Elem* first = NULL,
		* last = NULL; // ��������� ������

	Info num;
	for (int i = 1; i <= 10; i++) {// ��������� ����� � 10 �������� 
		num = 1 + rand() % 10; // �������� ������������ ����� �� 1 �� 10
		enqueue(first, last, num); // �������� ���������� ����� � ������
	}
	cout << "����������� ������: " << endl << endl;
	print(first); // ���� �����
	cout << endl;

	Info info;
	cout << "������ �������� �������������� ����, ��� ���� ������������� � ������: "; cin >> info;
	cout << endl;
	process(first, info); // ���������� � ����

	cout << "������� ������: " << endl << endl;
	while (last != NULL) {
		cout << dequeue(first, last) << " "; // ���� �� ��������� �����
	}
	cout << endl;

	return 0;
}
void enqueue(Elem*& first, Elem*& last, Info value) // ������� �������� � ������
{
	Elem* tmp = new Elem; // ����������� ���������� �������
	tmp->info = value; // � ���������� ������� ��������� ��������, ��� ���������� � �������
	tmp->link = NULL; // ��������� ��������� �� NULL
	if (last != NULL) // ���� ������ �� ������� 
		last->link = tmp; // �� ��������� ���������� �������� ������������ �� ����������
	last = tmp; // ���������� ������� ��� �������
	if (first == NULL) // ���� ������ ������ 
		first = tmp; // �� ������ ������� ������ �������� �����������
}

Info dequeue(Elem*& first, Elem*& last) // ������� ��������� �� ��������� ������
{
	Elem* tmp = first->link; // ����������� ���������� �������, ���� ������ �������� �������� ����������, ���� �������
	Info value = first->info; // �������� value ������ �������� �������������� ���� ������� �������� ��� ��������� � ����
	delete first; // ��������� ������� ��������
	first = tmp; // ��� ������ ������� ��� ��������� 
	if (first == NULL) // ���� ������ ������� ������
		last = NULL;  // �� ������� ����� ��� ������, �� ������, �� ������ � ������
	return value; // ���������� ��� ��������� 
}

void print(Elem* L) // ������� ��������� ������
{
	while (L != NULL) // ���� ������ �� ������ �� ����
	{
		cout << L->info << " "; // ���������� ������������ ���� ��������
		L = L->link; // ������� �������� �� ���������
	}
	cout << endl;
}

void process(Elem* L, Info value) // ������� ����������� ������
{
	while (L != NULL) // ���� �� ��������� ������
	{
		if (L->info == value) // �������� �������������� ���� �� ��, �� ���� �������� � ������� ������������ ���������
		{
			Elem* tmp = new Elem;  // ����������� ���������� �������
			tmp->info = value;  // ���������� ������� ������ ��������, ������� ������������ 
			tmp->link = L->link; // ��������� ����������� �������� ������������ �� �������� �������� 
			L->link = tmp; // ������������ ���������� �������
			L = L->link; // ������� ���, ������� ������� ���������
		}
		L = L->link; // ������� ���
	}
}