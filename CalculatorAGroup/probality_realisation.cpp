#pragma once
#include "probality_header.h"
#include <iostream>
#include <cmath>

using namespace std;
const int s = 100;
void prob()
{
	double m, n;
	cout << "������� ������������� ������(m) ";
	cin >> m;
	cout << "������� ��� ��������� ������(n) ";
	cin >> n;
	if (n == 0)
	{
		cout << "n �� ����� ���� ����� 0" << endl;
		probality_menu();
	}
	double prob;
	prob = m / n;
	cout << "�����������: " << prob << endl;
	back1();
}
void var()
{
	int n;
	cout << "������� ���������� �������� ";
	cin >> n;
	if (n <= 0 || n > 100)
	{
		cout << "������������ ���������� " << endl;
		probality_menu();
	}
	double x[s];
	double p[s];
	cout << "������� ��������(x) � �������������� �����������(p): ";
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
	cout << "���������: " << vr << endl;
	back1();
}
void expval()
{
	int n;
	cout << "������� ���������� ��������: ";
	cin >> n;
	if (n <= 0 || n > 100)
	{
		cout << "������������ ����������" << endl;
		probality_menu();
	}
	double x[s];
	double p[s];
	cout << "������� ��������(x) � �������������� �����������(p): ";
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
	cout << "�������������� ��������: " << exp << endl;
	back1();
}
void probality_menu()
{
	int k;
	cout << "����������� ������ ����������� � �������������� ����������" << endl;
	cout << "1.����������� m/n" << endl;
	cout << "2.��������� ��� ����������� �������������" << endl;
	cout << "3.�������������� �������� ��� ����������� �������������" << endl;
	cout << "4.�����" << endl;
	cout << "�������� ����� ����: ";
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
		cout << "����������� � �������� ����" << endl;
		break;
	}
	default:
	{
		cout << "�������� �����(������� 1-3)" << endl;
		break;
	}
	}
}
void back1()
{
	int k = 0;
	cout << "������� ����� ������ ����� ��������� � ���� ";
	cin >> k;
	probality_menu();
}

