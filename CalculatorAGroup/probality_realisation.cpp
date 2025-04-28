#pragma once
#include "probality_header.h"
#include <iostream>
#include <cmath>

using namespace std;
const int s = 100;
void prob()
{
	double m, n;
	cout << "Введите благоприятные исходы(m) ";
	cin >> m;
	cout << "Введите все возможные исходы(n) ";
	cin >> n;
	if (n == 0)
	{
		cout << "n не может быть равен 0" << endl;
		probality_menu();
	}
	double prob;
	prob = m / n;
	cout << "Вероятность: " << prob << endl;
	back1();
}
void var()
{
	int n;
	cout << "Введите количество значений ";
	cin >> n;
	if (n <= 0 || n > 100)
	{
		cout << "Некорректное количество " << endl;
		probality_menu();
	}
	double x[s];
	double p[s];
	cout << "Введите значения(x) и соответсвующие вероятности(p): ";
	for (int i = 0; i < n; i++)
	{
		cout << "x[" << i << "] = ";
		cin >> x[i];
		cout << "p[" << i << "] = ";
		cin >> p[i];
	}
	double m = 0;
	for (int i = 0; i < n; i++)
	{
		m += x[i] * p[i];
	}
	double vr = 0;
	for (int i = 0; i < n; i++)
	{
		vr += (x[i] - m) * (x[i] - m) * p[i];
	}
	cout << "Дисперсия: " << vr << endl;
	back1();
}
void expval()
{
	int n;
	cout << "Введите количество значений: ";
	cin >> n;
	if (n <= 0 || n > 100)
	{
		cout << "Некорректное количество" << endl;
		probality_menu();
	}
	double x[s];
	double p[s];
	cout << "Введите значения(x) и соответсвующие вероятности(p): ";
	for (int i = 0; i < n; i++)
	{
		cout << "x[" << i << "] = ";
		cin >> x[i];
		cout << "p[" << i << "] = ";
		cin >> p[i];
	}
	double exp = 0;
	for (int i = 0; i < n; i++)
	{
		exp += x[i] * p[i];
	}
	cout << "Математическое ожидание: " << exp << endl;
	back1();
}
void probality_menu()
{
	int k;
	cout << "Калькулятор теории вероятности и математической статистики" << endl;
	cout << "1.Вероятность m/n" << endl;
	cout << "2.Дисперсия для дискретного распределения" << endl;
	cout << "3.Математическое ожидание для дискретного распределения" << endl;
	cout << "4.Выход" << endl;
	cout << "Выберите пункт меню: ";
	cin >> k;
	switch (k)
	{
	case 1:
	{
		prob();
		break;
	}
	case 2:
	{
		var();
		break;
	}
	case 3:
	{
		expval();
		break;
	}
	case 4:
	{
		cout << "Возвращение в основное меню" << endl;
		break;
	}
	default:
	{
		cout << "Неверный выбор(введите 1-3)" << endl;
		break;
	}
	}
}
void back1()
{
	int k = 0;
	cout << "Введите любой символ чтобы вернуться в меню ";
	cin >> k;
	probality_menu();
}

