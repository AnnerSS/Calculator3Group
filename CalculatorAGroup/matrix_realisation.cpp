#pragma once
#include "matrix_header.h"
#include <iostream>
using namespace std;

double** create_array(int n, int m) {
    double** array = new double* [n];
    for (int i = 0; i < n; i++) {
        array[i] = new double[m];
    }
    return array;
}
void input_array(int n, int m, double** array) {
    for (int i = 0; i < n; i++) {
        cout << "Введите элемент " << i + 1 << " строки: \n";
        for (int j = 0; j < m; j++) {
            cin >> array[i][j];
        }
    }
}
void output_array(int n, int m, double** array) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
}
void delete_array(int n, int m, double** array) {
    for (int i = 0; i < n; i++) {
        delete[] array[i];
    }
    delete[]array;
}
void summa() {
    int n, m;
    do {
        cout << "Введите количество строк в матрицах\n";
        cin >> n;
    } while (n <= 0);
    do {
        cout << "Введите количество столбцов в матрицах\n";
        cin >> m;
    } while (m <= 0);

    double** array1;
    double** array2;
    array1 = create_array(n, m);
    input_array(n, m, array1);
    array2 = create_array(n, m);
    input_array(n, m, array2);

    double** res;
    res = create_array(n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = array1[i][j] + array2[i][j];
        }
    }
    output_array(n, m, res);
    delete_array(n, m, array1);
    delete_array(n, m, array2);
    delete_array(n, m, res);
}
void difference() {
    int n, m;
    do {
        cout << "Введите количество строк в матрицах\n";
        cin >> n;
    } while (n <= 0);
    do {
        cout << "Введите количество столбцов в матрицах\n";
        cin >> m;
    } while (m <= 0);

    double** array1;
    double** array2;
    array1 = create_array(n, m);
    input_array(n, m, array1);
    array2 = create_array(n, m);
    input_array(n, m, array2);

    double** res;
    res = create_array(n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = array1[i][j] - array2[i][j];
        }
    }
    output_array(n, m, res);
    delete_array(n, m, array1);
    delete_array(n, m, array2);
    delete_array(n, m, res);
}
void umnojenie() {
    int n1, m1, n2, m2;
    do {
        cout << "Введите количество строк первой матрицы: \n";
        cin >> n1;
    } while (n1 <= 0);
    do {
        cout << "Введите количество столбцов первой матрицы: \n";
        cin >> m1;
    } while (m1 <= 0);
    do {
        cout << "Введите количество строк второй матрицы: \n";
        cin >> n2;
    } while (n2 <= 0);
    do {
        cout << "Введите количество столбцов второй матрицы: \n";
        cin >> m2;
    } while (m2 <= 0);

    if (m1 != n2) { cout << "Умножение невозможно!\n"; }
    else {
        double** array1;
        double** array2;
        array1 = create_array(n1, m1);
        input_array(n1, m1, array1);
        array2 = create_array(n2, m2);
        input_array(n2, m2, array2);

        double** res;
        res = create_array(n1, m2);
        for (int i = 0; i < n1; ++i)
            for (int j = 0; j < m2; ++j)
                res[i][j] = 0;

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < m2; j++) {
                for (int k = 0; k < m1; k++) {
                    res[i][j] += array1[i][k] * array2[k][j];
                }
            }
        }
        output_array(n1, m2, res);
        delete_array(n1, m1, array1);
        delete_array(n2, m2, array2);
        delete_array(n1, m2, res);
    }
}
void umnojenie_na_chislo() {
    int n, m, x;
    do {
        cout << "Введите количество строк матрицы:\n";
        cin >> n;
    } while (n <= 0);
    do {
        cout << "Введите количество столбцов матрицы:\n";
        cin >> m;
    } while (m <= 0);
    cout << "Введите число:\n";
    cin >> x;

    double** array;
    array = create_array(n, m);
    input_array(n, m, array);

    double** res;
    res = create_array(n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = array[i][j] * x;
        }
    }
    output_array(n, m, res);
    delete_array(n, m, array);
    delete_array(n, m, res);
}
void summa_s_chislom() {
    int n, m, x;
    do {
        cout << "Введите количество строк матрицы:\n";
        cin >> n;
    } while (n <= 0);
    do {
        cout << "Введите количество столбцов матрицы:\n";
        cin >> m;
    } while (m <= 0);
    cout << "Введите число:\n";
    cin >> x;

    double** array;
    array = create_array(n, m);
    input_array(n, m, array);

    double** res;
    res = create_array(n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = array[i][j] + x;
        }
    }
    output_array(n, m, res);
    delete_array(n, m, array);
    delete_array(n, m, res);
}
void difference_s_chislom() {
    int n, m, x;
    do {
        cout << "Введите количество строк матрицы:\n";
        cin >> n;
    } while (n <= 0);
    do {
        cout << "Введите количество столбцов матрицы:\n";
        cin >> m;
    } while (m <= 0);
    cout << "Введите число:\n";
    cin >> x;

    double** array;
    array = create_array(n, m);
    input_array(n, m, array);

    double** res;
    res = create_array(n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = array[i][j] - x;
        }
    }
    output_array(n, m, res);
    delete_array(n, m, array);
    delete_array(n, m, res);
}

void transponirovanie() {
    int n, m;
    do {
        cout << "Введите количество строк матрицы:\n";
        cin >> n;
    } while (n <= 0);
    do {
        cout << "Введите количество столбцов матрицы:\n";
        cin >> m;
    } while (m <= 0);

    double** array;
    array = create_array(n, m);
    input_array(n, m, array);

    double** res;
    res = create_array(m, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[j][i] = array[i][j];
        }
    }
    output_array(m, n, res);
    delete_array(n, m, array);
    delete_array(m, n, res);
}
double opredelitel(double** array, int n) {
    if (n == 1) return array[0][0];
    if (n == 2) return array[0][0] * array[1][1] - array[0][1] * array[1][0];

    double det = 0.0;

    for (int q = 0; q < n; q++) {
        double** subarray = create_array(n - 1, n - 1);
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == q) continue;
                subarray[subi][subj] = array[i][j];
                subj++;
            }
            subi++;
        }
        int sign = (q % 2 == 0) ? 1 : -1;
        det += sign * array[0][q] * opredelitel(subarray, n - 1);
        delete_array(n - 1, n - 1, subarray);
    }
    return det;
}
void determinant() {
    int n, m;
    do {
        cout << "Введите количество строк матрицы:\n";
        cin >> n;
    } while (n <= 0);
    do {
        cout << "Введите количество столбцов матрицы:\n";
        cin >> m;
    } while (m <= 0);

    if (n != m) { cout << "Невозможно найти определитель"; }
    if (n == m) {
        double** array;
        array = create_array(n, m);
        input_array(n, m, array);
        double det = opredelitel(array, n);
        cout << det;
    }
}
void inverse() {
    int n;
    do {
        cout << "Введите размер квадратной матрицы: \n";
        cin >> n;
    } while (n <= 0);

    double** array = create_array(n, 2 * n);

    input_array(n, n, array);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j)
                array[i][j + n] = 1.0;
            else
                array[i][j + n] = 0.0;
        }

    for (int i = 0; i < n; i++) {
        if (array[i][i] == 0) {
            for (int k = i + 1; k < n; k++) {
                if (array[k][i] != 0) {
                    for (int j = 0; j < 2 * n; j++) {
                        double temp = array[i][j];
                        array[i][j] = array[k][j];
                        array[k][j] = temp;
                    }
                    break;
                }
            }
        }

        double pivot = array[i][i];
        if (pivot == 0) {
            cout << "Матрица необратима." << endl;
            delete_array(n, 2 * n, array);
            return;
        }

        for (int j = 0; j < 2 * n; j++)
            array[i][j] = array[i][j] / pivot;

        for (int k = 0; k < n; k++) {
            if (k == i) continue;
            double factor = array[k][i];
            for (int j = 0; j < 2 * n; j++)
                array[k][j] -= factor * array[i][j];
        }
    }

    cout << "Обратная матрица:\n";
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2 * n; j++)
            cout << array[i][j] << " ";
        cout << endl;
    }

    delete_array(n, 2 * n, array);
}
void matrix_menu()
{
    int way;
    while (true) {
        cout << "Матричный калькулятор\n";
        cout << "1. Сумму матриц\n";
        cout << "2. Разность матриц\n";
        cout << "3. Умножение матриц\n";
        cout << "4. Умножение матрицы на число\n";
        cout << "5. Сложение матрицы с числом\n";
        cout << "6. Разность матрицы с числом\n";
        cout << "7. Транспонирование\n";
        cout << "8. Определитель\n";
        cout << "9. Обратная матрица\n";
        cout << "0. Вернуться в главное меню\n";
        cout << "Введите выбор: ";
        cin >> way;

        switch (way) {
        case 0: return;
        case 1:summa(); break;
        case 2:difference(); break;
        case 3: umnojenie(); break;
        case 4: umnojenie_na_chislo(); break;
        case 5:summa_s_chislom(); break;
        case 6: difference_s_chislom(); break;
        case 7:transponirovanie(); break;
        case 8:determinant(); break;
        case 9:inverse(); break;
        default:
        {
            cout << "Ошибка!Неверный ввод";
        }
        }
    }
}