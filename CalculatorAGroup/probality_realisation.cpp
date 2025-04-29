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
	if (m <= 0)
	{
		cout << "m �� ����� ���� ������ ��� ����� 0" << endl;
		return;
	}
	cout << "������� ��� ��������� ������(n) ";
	cin >> n;
	if (n <=0)
	{
		cout << "n �� ����� ���� ������ ��� ����� 0" << endl;
		return;
	}
	double prob;
	prob = m / n;
	cout << "�����������: " << prob << endl;
}
void var()
{
	int n;
	cout << "������� ���������� �������� ";
	cin >> n;
	if (n <= 0 || n > 100)
	{
		cout << "������������ ���������� " << endl;
		return;
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
}
void expval()
{
	int n;
	cout << "������� ���������� ��������: ";
	cin >> n;
	if (n <= 0 || n > 100)
	{
		cout << "������������ ����������" << endl;
		return;
	}
	double x[s];
	double p[s];
	cout << "������� ��������(x) � �������������� �����������(p): "<<endl;
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
}
void probality_menu()
{
	int k=-1;
	while (k!=0)
	{
		cout << endl;
		cout << "����������� ������ ����������� � �������������� ����������" << endl;
		cout << "1.����������� m/n" << endl;
		cout << "2.��������� ��� ����������� �������������" << endl;
		cout << "3.�������������� �������� ��� ����������� �������������" << endl;
		cout << "0.�����" << endl;
		cout << "�������� ����� ����: ";
		cin >> k;
		switch (k)
		{
		case 0:
		{
			cout << "����������� � �������� ����" << endl << endl;
			return;
		}
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
		default:
		{
			cout << "�������� �����(������� 0-3)" << endl;
		}
		}
	}
}

