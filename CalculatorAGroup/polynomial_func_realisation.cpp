#pragma once
#include "polynomial_header.h"
#include <iostream>
#include <iomanip>

using namespace std;


// ввод многочлена
void InputPolynomial(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax]) {

    do {
        cout << "Введите количество многочленов (минимум 1): "; cin >> num_of_polynomials;
        if (num_of_polynomials < 1) cout << "Неправильный ввод" << endl;
    } while (num_of_polynomials < 1);

    for (int i = 0; i < num_of_polynomials; i++) {
        do {
            cout << "Введите количество членов " << i + 1 << "-го многочлена (минимум 2): "; cin >> sizes[i];
            if (sizes[i] < 2) cout << "Неправильный ввод" << endl;
        } while (sizes[i] < 2);


        for (int j = 0; j < sizes[i]; j++) {
            bool unique = true;
            cout << "Член " << j + 1 << endl;
            do {
                unique = true;
                do {
                    cout << setw(15) << "Cтепень x: "; cin >> polynomials[i][j].degree;
                    if (polynomials[i][j].degree < 0) cout << "Степень не может быть меньше 0" << endl;
                } while (polynomials[i][j].degree < 0);

                for (int k = 0; k < j; k++) {
                    if (polynomials[i][k].degree == polynomials[i][j].degree) {
                        cout << "Степень " << polynomials[i][j].degree << " уже есть в многочлене. ";
                        cout << "Введите другую степень." << endl;
                        unique = false;
                        break;
                    }
                }
            } while (!unique);

            do {
                cout << setw(15) << "Коэффициент: "; cin >> polynomials[i][j].coefficient;
                if (polynomials[i][j].coefficient == 0) cout << "Вводите информацию только о ненулевых членах многочлена" << endl;
            } while (polynomials[i][j].coefficient == 0);
        }
    }
}


// вывод многочлена
void PrintPolynomial(Polynomial result[Nmax * max_degree], int& rez_size) {

    if (rez_size == 0) {
        cout << 0;
    }
    else {
        for (int i = 0; i < rez_size; i++) {

            if (i == 0 && result[i].coefficient < 0) {
                cout << "-";
            }
            else if (i > 0 && result[i].coefficient > 0) {
                cout << " + ";
            }
            else if (i > 0 && result[i].coefficient < 0) {
                cout << " - ";
            }

            if (result[i].degree == 0 || abs(result[i].coefficient) != 1) {
                cout << abs(result[i].coefficient);
            }

            if (result[i].degree > 0) {
                cout << "x";
                if (result[i].degree > 1) {
                    cout << "^" << result[i].degree;
                }
            }
        }
    }
    cout << endl;
}


// удаление членов с нулевыми коэффициентами
void NullCoefficient(Polynomial result[Nmax * max_degree], int& rez_size, int& k) {

    for (int i = k; i < rez_size - 1; i++) {
        result[i] = result[i + 1];
    }
    rez_size--;
    k--;
}


// сортировка по убыванию
void Sort(Polynomial result[Nmax * max_degree], int rez_size) {

    for (int i = 0; i < rez_size - 1; i++) {
        for (int j = 0; j < rez_size - i - 1; j++) {
            if (result[j].degree < result[j + 1].degree) {
                Polynomial temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }
}


// сложение
void PolynomialAddition(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax],
    Polynomial result[Nmax * max_degree], int& rez_size) {

    InputPolynomial(polynomials, num_of_polynomials, sizes);

    for (int j = 0; j < sizes[0]; j++) {
        result[j] = polynomials[0][j];
    }
    rez_size = sizes[0];

    for (int i = 1; i < num_of_polynomials; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            bool found = false;

            for (int k = 0; k < rez_size; k++) {
                if (result[k].degree == polynomials[i][j].degree) {
                    result[k].coefficient += polynomials[i][j].coefficient;
                    found = true;

                    if (result[k].coefficient == 0) NullCoefficient(result, rez_size, k);

                    break;
                }
            }
            if (!found) {
                result[rez_size] = polynomials[i][j];
                rez_size++;
            }
        }
    }
    Sort(result, rez_size);
}

// вычитание
void PolynomialSubtraction(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax],
    Polynomial result[Nmax * max_degree], int& rez_size) {

    InputPolynomial(polynomials, num_of_polynomials, sizes);

    for (int j = 0; j < sizes[0]; j++) {
        result[j] = polynomials[0][j];
    }
    rez_size = sizes[0];

    for (int i = 1; i < num_of_polynomials; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            bool found = false;

            for (int k = 0; k < rez_size; k++) {
                if (result[k].degree == polynomials[i][j].degree) {
                    result[k].coefficient -= polynomials[i][j].coefficient;
                    found = true;

                    if (result[k].coefficient == 0) NullCoefficient(result, rez_size, k);

                    break;
                }
            }
            if (!found) {
                result[rez_size].degree = polynomials[i][j].degree;
                result[rez_size].coefficient = -polynomials[i][j].coefficient;
                rez_size++;
            }
        }
    }
    Sort(result, rez_size);
}

// умножение многочленов друг на друга
void PolynomialMultiplication(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials,
    int sizes[Nmax], Polynomial result[Nmax * max_degree], int& rez_size) {

    InputPolynomial(polynomials, num_of_polynomials, sizes);

    rez_size = sizes[0];
    for (int i = 0; i < sizes[0]; i++) {
        result[i] = polynomials[0][i];
    }

    for (int i = 1; i < num_of_polynomials; i++) {
        Polynomial temp[Nmax * max_degree];
        int temp_size = 0;

        for (int j = 0; j < rez_size; j++) {
            for (int k = 0; k < sizes[i]; k++) {
                temp[temp_size].coefficient = result[j].coefficient * polynomials[i][k].coefficient;
                temp[temp_size].degree = result[j].degree + polynomials[i][k].degree;
                temp_size++;
            }
        }

        for (int j = 0; j < temp_size; j++) {
            for (int k = j + 1; k < temp_size; k++) {
                if (temp[j].degree == temp[k].degree) {
                    temp[j].coefficient += temp[k].coefficient;
                    temp[k].coefficient = 0;
                }
            }
        }

        rez_size = 0;
        for (int j = 0; j < temp_size; j++) {
            if (temp[j].coefficient != 0) {
                result[rez_size++] = temp[j];
            }
        }
    }
    Sort(result, rez_size);
}

void PolynomialScalarMultiplication(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax],
    Polynomial result[Nmax * max_degree], int& rez_size) {

    int scalar;
    InputPolynomial(polynomials, num_of_polynomials, sizes);
    cout << "На какое число хотите умножить: "; cin >> scalar;

    if (scalar == 0) {
        cout << "Результат: 0" << endl;
    }
    else {
        for (int i = 0; i < num_of_polynomials; i++) {
            rez_size = 0;
            for (int j = 0; j < sizes[i]; j++) {
                result[rez_size].coefficient = polynomials[i][j].coefficient * scalar;
                result[rez_size].degree = polynomials[i][j].degree;
                rez_size++;
            }

            if (i > 0) cout << endl;
            PrintPolynomial(result, rez_size);
        }
    }
    Sort(result, rez_size);
}

// деление в столбик
void PolynomialDivision(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax],
    Polynomial result[Nmax * max_degree], int& rez_size) {

    cout << "Первый многочлен делится на второй" << endl;
    InputPolynomial(polynomials, num_of_polynomials, sizes);

    Polynomial delimoe[Nmax * max_degree];
    Polynomial delitel[Nmax * max_degree];
    Polynomial chastnoe[Nmax * max_degree];
    Polynomial ostat[Nmax * max_degree];
    int delimoe_size = sizes[0];
    int delitel_size = sizes[1];
    int chastnoe_size = 0;
    int ostat_size = delimoe_size;

    for (int i = 0; i < delimoe_size; i++) {
        delimoe[i] = polynomials[0][i];
    }
    Sort(delimoe, delimoe_size);

    for (int i = 0; i < delitel_size; i++) {
        delitel[i] = polynomials[1][i];
    }
    Sort(delitel, delitel_size);

    while (ostat_size > 0 && delimoe[0].degree >= delitel[0].degree) {

        Polynomial new_quotient_term;
        new_quotient_term.degree = delimoe[0].degree - delitel[0].degree;
        new_quotient_term.coefficient = delimoe[0].coefficient / delitel[0].coefficient;
        chastnoe[chastnoe_size++] = new_quotient_term;


        for (int i = 0; i < delitel_size; i++) {
            Polynomial term;
            term.degree = new_quotient_term.degree + delitel[i].degree;
            term.coefficient = new_quotient_term.coefficient * delitel[i].coefficient;


            for (int j = 0; j < ostat_size; j++) {
                if (delimoe[j].degree == term.degree) {
                    delimoe[j].coefficient -= term.coefficient;
                    if (delimoe[j].coefficient == 0) {

                        for (int k = j; k < ostat_size - 1; k++) {
                            delimoe[k] = delimoe[k + 1];
                        }
                        ostat_size--;
                        j--;
                    }
                    break;
                }
            }
        }

        while (ostat_size > 0 && delimoe[0].coefficient == 0) {
            for (int i = 0; i < ostat_size - 1; i++) {
                delimoe[i] = delimoe[i + 1];
            }
            ostat_size--;
        }
    }

    for (int i = 0; i < ostat_size; i++) {
        ostat[i] = delimoe[i];
    }

    cout << "Частное: ";
    PrintPolynomial(chastnoe, chastnoe_size);
    cout << "Остаток: ";
    PrintPolynomial(ostat, ostat_size);
}

// производная
void PolynomialDerivative(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax],
    Polynomial result[Nmax * max_degree], int& rez_size) {

    InputPolynomial(polynomials, num_of_polynomials, sizes);

    for (int i = 0; i < num_of_polynomials; i++) {
        rez_size = 0;
        for (int j = 0; j < sizes[i]; j++) {
            if (polynomials[i][j].degree > 0) {
                result[rez_size].coefficient = polynomials[i][j].coefficient * polynomials[i][j].degree;
                result[rez_size].degree = polynomials[i][j].degree - 1;
                rez_size++;
            }
        }
        Sort(result, rez_size);
        PrintPolynomial(result, rez_size);
    }
}