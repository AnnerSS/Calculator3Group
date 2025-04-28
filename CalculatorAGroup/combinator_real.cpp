#pragma once
#include "combinator.h"
#include <iostream>
using namespace std;

int stepen(int n, int m) {
    int N = n;
    if (m > 1) {
        N = N * n;
        m--;
    }
    if (m == 0) {
        N = 1;
    }
    return N;
}
int factorial(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}
void A_repeate() {
    int m, n;
    double Ar;
    do {
        cout << "введите количество элементов: \n";
        cin >> n;
        cout << "введите по сколько элементов нужно выбрать: \n";
        cin >> m;
    } while (n < 0 || m < 0);
    if (n >= m) {
        Ar = stepen(n, m);
        cout << "Результат: " << Ar << endl;
    }
    else { cout << "введены неверные значения!"; }
}
void A_no_repeate() {
    int m, n;
    double A;
    do {
        cout << "введите количество элементов: \n";
        cin >> n;
        cout << "введите по сколько элементов нужно выбрать: \n";
        cin >> m;
    } while (n < 0 || m < 0);
    if (n >= m) {
        A = factorial(n) / factorial(n - m) * 1.0;
        cout << "Результат: " << A << endl;
    }
    else { cout << "введены неверные значения!"; }
}
void C_repeate() {
    int n, m;
    double Cr;
    do {
        cout << "введите количество элементов: \n";
        cin >> n;
        cout << "введите по сколько элементов нужно выбрать: \n";
        cin >> m;
    } while (n < 0 || m < 0);
    if (n >= m) {
        Cr = factorial(n + m - 1) / (factorial(n - 1) * factorial(m)) * 1.0;
        cout << "Результат: " << Cr << endl;
    }
    else { cout << "введены неверные значения!"; }
}
void C_no_repeate() {
    int n, m;
    double C;
    do {
        cout << "введите количество элементов: \n";
        cin >> n;
        cout << "введите по сколько элементов нужно выбрать: \n";
        cin >> m;
    } while (n < 0 || m < 0);
    if (n >= m) {
        C = factorial(n) / (factorial(n - m) * factorial(m)) * 1.0;
        cout << "Результат: " << C << endl;
    }
    else { cout << "введены неверные значения!"; }
}
void P() {
    int n;
    int P;
    do {
        cout << "введите количество элементов \n";
        cin >> n;
    } while (n < 0);
    P = factorial(n);
    cout << "Результат: " << P << endl;
}
void combinatorics_menu()
{
    int way;
    while (true) {
        cout << "Калькулятор формул комбинаторики\n";
        cout << "1. Размещение с повторением\n";
        cout << "2. Размещение без повторений\n";
        cout << "3. Сочетание с повторением\n";
        cout << "4. Сочетание без повторений\n";
        cout << "5. Перестановки\n";
        cout << "0. Вернуться в главное меню\n";
        cin >> way;

        switch (way) {
        case 0: return;
        case 1: A_repeate(); break;
        case 2: A_no_repeate(); break;
        case 3: C_repeate(); break;
        case 4: C_no_repeate(); break;
        case 5: P(); break;
        default:
        {
            cout << "Ошибка!Неверный ввод";
        }
        }
    }
}
