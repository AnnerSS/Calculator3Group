﻿#pragma once 
#include <iostream>
#include <string>
#include <cmath>
#include "fraction_header.h"


using namespace std;


int num[s];
int den[s];
int co = 0;


int nod(int a, int b)
{
	while (b != 0)
	{
		int t = b;
		b = a % b;
		a = t;
	}
	return abs(a);
}

void sim(int& n, int& d) {
	int g = nod(abs(n), abs(d));
	n /= g;
	d /= g;
	if (d < 0) {
		n = -n;
		d = -d;
	}
}
void print(int n, int d) {
	if (d == 1)
	{
		cout << n;
	}
	else if (abs(n) >= d)
	{
		int w = n / d;
		int fn = abs(n) % d;
		if (fn == 0)
		{
			cout << w;
		}
		else
		{
			cout << w << " " << fn << "/" << d;
		}
	}
	else
	{
		cout << n << "/" << d;
	}
}
void input()
{
	string input;
	cout << "Введите дробь(2/3 или 2 2/3): ";
	getline(cin, input);
	int w = 0;
	int n = 0;
	int d = 0;
	bool neg = false;
	int i = 0;
	if (input.empty())
	{
		cout << "Пустой ввод" << endl;
		drobi_menu();
	}
	if (input[i] == '-')
	{
		neg = true;
		i++;
	}
	int p1 = 0;
	while (i < input.length() && isdigit(input[i]))
	{
		p1 = p1 * 10 + (input[i] - '0');
		i++;
	}
	if (i < input.length() && input[i] == ' ')
	{
		w = p1;
		i++;
		n = 0;
		while (i < input.length() && isdigit(input[i]))
		{
			n = n * 10 + (input[i] - '0');
			i++;
		}
		if (i >= input.length() || input[i] != '/')
		{
			cout << "Неправильная форма ввода дроби" << endl;
			drobi_menu();
		}
		i++;
		d = 0;
		while (i < input.length() && isdigit(input[i]))
		{
			d = d * 10 + (input[i] - '0');
			i++;
		}
		if (i != input.length())
		{
			cout << "Лишние символы" << endl;
			drobi_menu();
		}
		n = w * d + n;
		d = d;
	}
	else if (i < input.length() && input[i] == '/')
	{
		n = p1;
		i++;
		d = 0;
		while (i < input.length() && isdigit(input[i]))
		{
			d = d * 10 + (input[i] - '0');
			i++;
		}
		if (i != input.length())
		{
			cout << "Лишние символы" << endl;
			drobi_menu();
		}
		d = d;
	}
	else if (i == input.length())
	{
		n = p1;
		d = 1;
	}
	else
	{
		cout << "Неправильная форма ввода дроби" << endl;
		drobi_menu();
	}
	if (d == 0)
	{
		cout << "Знаменатель не может быть равен 0" << endl;
		drobi_menu();
	}
	if (neg)
	{
		n = -n;
	}
	sim(n, d);
	num[co] = n;
	den[co] = d;
	co++;
}
void add() {
	co = 0;
	int k = 0;
	cout << "Введите количество дробей для сложения: ";
	cin >> k;
	cin.ignore();
	while (k < 2) {
		cout << "Минимум 2 дроби: ";
		cin >> k;
		cin.ignore();
	}
	int tn = 0;
	int td = 1;
	for (int i = 0; i < k; i++) {
		input();
		int n = num[co - 1];
		int d = den[co - 1];
		tn = tn * d + n * td;
		td = td * d;
		sim(tn, td);
	}
	cout << "Результат сложения: ";
	print(tn, td);
	cout << endl;
}
void sub()
{
	co = 0;
	int k = 0;
	cout << "Введите количество дробей для вычитания ";
	cin >> k;
	cin.ignore();
	while (k < 2)
	{
		cout << "Минимум 2 дроби ";
		cin >> k;
		cin.ignore();
	}
	input();
	int tn = num[co - 1];
	int td = den[co - 1];
	for (int i = 0;i < k - 1;i++)
	{
		input();
		int n = num[co - 1];
		int d = den[co - 1];
		tn = tn * d - n * td;
		td = td * d;
		sim(tn, td);
	}
	cout << "Результат вычитания: ";
	print(tn, td);
	cout << endl;
}
void multi()
{
	co = 0;
	int k = 0;
	cout << "Введите количество дробей для умножения ";
	cin >> k;
	cin.ignore();
	while (k < 2)
	{
		cout << "Минимум 2 дроби";
		cin >> k;
		cin.ignore();
	}
	int tn = 1;
	int td = 1;
	for (int i = 0;i < k;i++)
	{
		input();
		tn *= num[co - 1];
		td *= den[co - 1];
		sim(tn, td);
	}
	cout << "Результат умножения ";
	print(tn, td);
	cout << endl;
}
void div()
{
	co = 0;
	int k = 0;
	cout << "Введите количество дробей для деления ";
	cin >> k;
	cin.ignore();
	while (k < 2)
	{
		cout << "Минимум 2 дроби";
		cin >> k;
		cin.ignore();
	}
	input();
	int tn = num[co - 1];
	int td = den[co - 1];
	for (int i = 0;i < k - 1;i++)
	{
		input();
		int n = num[co - 1];
		int d = den[co - 1];
		if (d == 0 || n == 0)
		{
			cout << "Знаменатель/числитель равен 0";
			return;
		}
		tn *= d;
		td *= n;
		sim(tn, td);
	}
	cout << "Результат деления: ";
	print(tn, td);
	cout << endl;
}
void comp()
{
	co = 0;
	cout << "Сравнение дробей" << endl;
	cin.ignore();
	for (int i = 0;i < 2;i++)
	{
		input();
	}
	int n1 = num[0];
	int d1 = den[0];
	int n2 = num[1];
	int d2 = den[1];
	int com1 = n1 * d2;
	int com2 = n2 * d1;
	if (com1 == com2)
	{
		cout << "Дроби равны" << endl;
	}
	else if (com1 > com2)
	{
		cout << "Первая дробь больше второй" << endl;
	}
	else
	{
		cout << "Вторая дробь больше первой" << endl;
	}
}
void toten()
{
	int k;
	cout << "Введите сколько дробей привести к десятичной форме ";
	cin >> k;
	cin.ignore();
	for (int i = 0;i < k;i++)
	{
		input();
		double ten = (double)num[co - 1] / den[co - 1];
		cout << "Дробь " << i + 1 << " в десятичной форме равна " << ten << endl;
	}
}
void drobi_menu()
{
	int m=-1;
	while(m!=0)
	{
		cout << endl;
		cout << "Калькулятор обыкновенных дробей" << endl;
		cout << "1.Сложение" << endl;
		cout << "2.Вычитание" << endl;
		cout << "3.Умножение" << endl;
		cout << "4.Деление" << endl;
		cout << "5.Сравнение" << endl;
		cout << "6.Приведение к десятичной форме" << endl;
		cout << "0.Вернуться в главное меню" << endl;
		cin >> m;
		switch (m)
		{
		case 0:
		{
			cout << "Выход из калькулятора дробей" << endl << endl;
			return;
		}
		case 1:
		{
			add();;
			break;
		}
		case 2:
		{
			sub();
			break;
		}
		case 3:
		{
			multi();
			break;
		}
		case 4:
		{
			div();
			break;
		}
		case 5:
		{
			comp();
			break;
		}
		case 6:
		{
			toten();
			break;
		}
		default:
		{
			cout << "Ошибка!Неверный ввод";
		}
		}
	}
}


