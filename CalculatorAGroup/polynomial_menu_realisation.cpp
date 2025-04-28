#pragma once 
#include "polynomial_header.h"
#include <iostream>
#include <locale.h>


using namespace std;

void PolynomialMenu() {

    Polynomial polynomials[Nmax][max_degree];
    int sizes[Nmax];
    Polynomial result[Nmax * max_degree];
    int rez_size = 0;
    int num_of_polynomials;

    int choice;
    bool exit = false;


    while (!exit) {

        cout << endl;
        cout << "КАЛЬКУЛЯТОР МНОГОЧЛЕНОВ" << endl;
        cout << "1. Сложение многочленов" << endl;
        cout << "2. Вычитание многочленов" << endl;
        cout << "3. Умножение многочленов друг на друга" << endl;
        cout << "4. Умножение многочлена на число" << endl;
        cout << "5. Деление многочленов в столбик" << endl;
        cout << "6. Вычисление производной многочлена" << endl;
        cout << "0. Вернуться в главное меню" << endl << endl;
        cout << "Выберите действие (0-6): "; cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            cout << "Выбрано сложение многочленов" << endl << endl;
            PolynomialAddition(polynomials, num_of_polynomials, sizes, result, rez_size);
            cout << "Результат: " << endl;
            PrintPolynomial(result, rez_size);
            break;
        case 2:
            cout << "Выбрано вычитание многочленов" << endl << endl;
            PolynomialSubtraction(polynomials, num_of_polynomials, sizes, result, rez_size);
            cout << "Результат: " << endl;
            PrintPolynomial(result, rez_size);
            break;
        case 3:
            cout << "Выбрано умножение многочленов друг на друга" << endl << endl;
            PolynomialMultiplication(polynomials, num_of_polynomials, sizes, result, rez_size);
            cout << "Результат: " << endl;
            PrintPolynomial(result, rez_size);
            break;
        case 4:
            cout << "Выбрано умножение многочлена на число" << endl << endl;
            PolynomialScalarMultiplication(polynomials, num_of_polynomials, sizes, result, rez_size);
            break;
        case 5:
            cout << "Выбрано деление в столбик" << endl << endl;
            PolynomialDivision(polynomials, num_of_polynomials, sizes, result, rez_size);
            break;
        case 6:
            cout << "Выбрана производная" << endl << endl;
            PolynomialDerivative(polynomials, num_of_polynomials, sizes, result, rez_size);
            break;
        case 0:
            exit = true;
            break;
        default:
            cout << "Пункта с таким номером нет!" << endl;
        }
        cout << endl;
    }

}