// Продублювати кожний елемент списку із заданим користувачем значенням
// інформаційного поля.

#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

typedef int Info; // створення псевдоніму типу

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
	SetConsoleOutputCP(1251); // забезпечення відображення кирилиці в консолі

	Elem* first = NULL,
		* last = NULL; // створення списку

	Info num;
	for (int i = 1; i <= 10; i++) {// створення черги з 10 елементів 
		num = 1 + rand() % 10; // рандомно вичисляється число від 1 до 10
		enqueue(first, last, num); // внесення рандомного числа в список
	}
	cout << "Оригінальний список: " << endl << endl;
	print(first); // вивід черги
	cout << endl;

	Info info;
	cout << "Введіть значення інформаційного поля, яке буде продубльовано в списку: "; cin >> info;
	cout << endl;
	process(first, info); // дублювання в черзі

	cout << "Змінений список: " << endl << endl;
	while (last != NULL) {
		cout << dequeue(first, last) << " "; // Вивід та видалення черги
	}
	cout << endl;

	return 0;
}
void enqueue(Elem*& first, Elem*& last, Info value) // функція внесення в список
{
	Elem* tmp = new Elem; // створюється тимчасовий елемент
	tmp->info = value; // в тимчасовий елемент вноситься значення, яке передається в функцію
	tmp->link = NULL; // настройка посилання на NULL
	if (last != NULL) // якщо список не порожній 
		last->link = tmp; // то посилання останнього елементу настроюється на тимчасовий
	last = tmp; // тимчасовий елемент стає останнім
	if (first == NULL) // Якщо список пустий 
		first = tmp; // То перший елемент приймає значення тимчасового
}

Info dequeue(Elem*& first, Elem*& last) // функція виведення та видалення списку
{
	Elem* tmp = first->link; // створюється тимчасовий елемент, який приймає значення елемента наступного, після першого
	Info value = first->info; // перемінна value приймає значення інформаційного поля першого елемента для виведення в кінці
	delete first; // видалення першого елемента
	first = tmp; // тоді перший елемент стає наступним 
	if (first == NULL) // якщо перший елемент пустий
		last = NULL;  // то останній також стає пустим, що означає, що список є пустим
	return value; // повернення для виведення 
}

void print(Elem* L) // функція виведення списку
{
	while (L != NULL) // поки список не дойшов до кінця
	{
		cout << L->info << " "; // виводиться інформаційне поле елемента
		L = L->link; // перехід елемента на наступний
	}
	cout << endl;
}

void process(Elem* L, Info value) // функція опрацювання списку
{
	while (L != NULL) // поки не закінчився список
	{
		if (L->info == value) // перевірка інформаційного поля на те, що воно збігається з заданим користувачем значенням
		{
			Elem* tmp = new Elem;  // створюється тимчасовий елемент
			tmp->info = value;  // тимчасовий елемент отримує значення, введене користувачем 
			tmp->link = L->link; // посилання тимчасового елементу настроюється на посиланя елемента 
			L->link = tmp; // вставляється тимчасовий елемент
			L = L->link; // перехід далі, оскільки елемент вставлено
		}
		L = L->link; // перехід далі
	}
}