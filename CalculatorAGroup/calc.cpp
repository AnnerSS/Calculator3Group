#pragma once
#include <iostream>
#include <Windows.h>
#include "fraction_header.h"
#include "combinator.h"
#include "matrix_header.h"
#include "polynomial_header.h"
#include "probality_header.h"
#include "functions_header.h"
#include <SDL.h>
#include "SDL_ttf.h"


using namespace std;

void main_menu()
{
	

	bool fl = true;
	while (fl) {
		int x = -1;
		cout << "Выберите вид калькулятора" << endl;
		cout << "1. Матричный калькулятор" << endl;
		cout << "2. Калькулятор обыкновенных дробей" << endl;
		cout << "3. Калькулятор формул комбинаторики" << endl;
		cout << "4. Теор. вер. и мат. статистика" << endl;
		cout << "5. Калькулятор многочленов" << endl;
		cout << "6. Работа с функциями" << endl;
		cout << "0. Выход из программы" << endl;
		cout << "Ваш выбор (0-6): ";

		cin >> x;

		while (x < 0 || x > 6) {
			cout << "Некорректный ввод! Ваш выбор (0-6): ";
			cin >> x;
		}
		cout << endl;
		switch (x)
		{
		case 0:
		{
			fl = false;
			cout << "Программа завершена!";
			break;
		}
		case 1:
		{
			matrix_menu();
			break;
		}
		case 2:
		{
			drobi_menu();
			break;
		}
		case 3:
		{
			combinatorics_menu();
			break;
		}
		case 4: 
			probality_menu();
			break;
		case 5:
		{
			PolynomialMenu();
			break;
		}
		case 6:
		{
			functions_menu();
			break;
		}
		}
	}
}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru");
	main_menu();
	return 0;
}