#pragma once


#define Nmax 10
#define max_degree 20


struct Polynomial {
	int degree;
	double coefficient;
};

// меню
void PolynomialMenu();

// ввод вывод
void InputPolynomial(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax]);
void PrintPolynomial(Polynomial result[Nmax * max_degree], int& rez_size);

// манипуляции с массивом
void NullCoefficient(Polynomial result[Nmax * max_degree], int& rez_size, int& k);
void Sort(Polynomial result[Nmax * max_degree], int rez_size);

// функции калькулятора
void PolynomialAddition(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax],
	Polynomial result[Nmax * max_degree], int& rez_size);
void PolynomialSubtraction(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax],
	Polynomial result[Nmax * max_degree], int& rez_size);
void PolynomialMultiplication(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax],
	Polynomial result[Nmax * max_degree], int& rez_size);
void PolynomialScalarMultiplication(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax],
	Polynomial result[Nmax * max_degree], int& rez_size);
void PolynomialDivision(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax],
	Polynomial result[Nmax * max_degree], int& rez_size);
void PolynomialDerivative(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax],
	Polynomial result[Nmax * max_degree], int& rez_size);

