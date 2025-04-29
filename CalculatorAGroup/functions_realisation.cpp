#pragma once
#include "functions_header.h"

double pol_coeffs[11] = { 0 };
int pol_degree = 0;
double a = 0, b = 0, c = 0, d = 0;

using namespace std;

int chose() {
    int type = -1;
    cout << "Выберите функцию: " << endl;
    cout << "1. Полином степени N: a0+a1*x+a2*x^2+...+aN*x^N" << endl;
    cout << "2. Степенная: a*x^b+c" << endl;
    cout << "3. Показательная: a*b^(c*x)+d" << endl;
    cout << "4. Логарифмическая: a*ln(b*x)+c" << endl;
    cout << "5. Синусоида: a*sin(b*x+c)+d" << endl;
    cout << "6. Косинусоида: a*cos(b*x+c)+d" << endl;
    cout << "0. Вернуться в меню калькулятора работы с функциями" << endl;
    cin >> type;
    while (type < 0 || type > 6) {
        cout << "Неверный ввод. Попробуйте снова.\n";
        cin >> type;
    }
    return type;
}
void input(int type) {
    cout << "Введите параметры функции:\n";
    if (type == 1) {
        cout << "Степень полинома (<= 10): ";
        cin >> pol_degree;
        while (pol_degree > 10 || pol_degree < 0) {
            cout << "Степень должна быть от 0 до 10: ";
            cin >> pol_degree;
        }
        for (int i = 0; i <= pol_degree; i++) {
            cout << "a" << i << ": ";
            cin >> pol_coeffs[i];
        }
    }
    else if (type == 2 || type == 4) {
        cout << "a: "; cin >> a;
        cout << "b: "; cin >> b;
        if (type == 4) {
            while (b <= 0) {
                cout << "Подлогарифмическое выражение должно быть >0. Введите b снова: "; cin >> b;
            }
        }
        cout << "c: "; cin >> c;
    }
    else {
        cout << "a: "; cin >> a;
        cout << "b: "; cin >> b;
        cout << "c: "; cin >> c;
        cout << "d: "; cin >> d;
    }
}

double polynom(double x) {
    double res = 0;
    double st = 1;
    for (int i = 0; i <= pol_degree; i++) {
        res += pol_coeffs[i] * st;
        st *= x;
    }
    return res;
}

double stepen(double x) {
    return a * pow(x, b) + c;
}

double pokaz(double x) {
    return a * pow(b, c * x) + d;
}

double logar(double x) {
    return a * log(b * x) + c;
}

double sinus(double x) {
    return a * sin(b * x + c) + d;
}

double cosinus(double x) {
    return a * cos(b * x + c) + d;
}

bool initSDL(SDL_Window*& window, SDL_Renderer*& renderer) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) return false;

    window = SDL_CreateWindow("Grafic", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (window == NULL) {
        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }
    if (TTF_Init() < 0) return false;
    return true;
}

SDL_Texture* get_text_texture(SDL_Renderer*& renderer, char* text, TTF_Font* my_font) {
    SDL_Surface* textSurface = NULL;
    textSurface = TTF_RenderText_Shaded(my_font, text, { 0, 0, 0, 255 }, { 255, 255, 255, 255 });
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    return texture;
}
void draw_text(SDL_Renderer*& renderer, SDL_Texture* texture, SDL_Rect rect) {
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Oxy(SDL_Renderer* renderer, int SCREEN_HEIGHT, int SCREEN_WIDTH, int STEP) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);
    SDL_RenderDrawLine(renderer, SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT);

    for (int x = SCREEN_WIDTH / 2; x <= SCREEN_WIDTH; x += STEP) {
        int centerY = SCREEN_HEIGHT / 2;
        SDL_RenderDrawLine(renderer, x, centerY - 2, x, centerY + 2);
    }
    for (int x = SCREEN_WIDTH / 2; x >= 0; x -= STEP) {
        int centerY = SCREEN_HEIGHT / 2;
        SDL_RenderDrawLine(renderer, x, centerY - 2, x, centerY + 2);
    }
    for (int y = SCREEN_HEIGHT / 2; y <= SCREEN_HEIGHT; y += STEP) {
        int centerX = SCREEN_WIDTH / 2;
        SDL_RenderDrawLine(renderer, centerX - 2, y, centerX + 2, y);
    }
    for (int y = SCREEN_HEIGHT / 2; y >= 0; y -= STEP) {
        int centerX = SCREEN_WIDTH / 2;
        SDL_RenderDrawLine(renderer, centerX - 2, y, centerX + 2, y);
    }
}

void draw(SDL_Renderer* renderer, int type) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);


    for (double x = -(SCREEN_WIDTH / STEP); x <= (SCREEN_WIDTH / STEP); x += 0.001) {
        double y;
        switch (type) {
        case 1: y = polynom(x); break;
        case 2: y = stepen(x); break;
        case 3: y = pokaz(x); break;
        case 4: y = logar(x); break;
        case 5: y = sinus(x); break;
        case 6: y = cosinus(x); break;
        }

        int scrX = SCREEN_WIDTH / 2 + (x * STEP);
        int scrY = SCREEN_HEIGHT / 2 - (y * STEP);

        if (scrX >= 0 && scrX < SCREEN_WIDTH && scrY >= 0 && scrY < SCREEN_HEIGHT) {
            SDL_RenderDrawPoint(renderer, scrX, scrY);
        }
    }
}

void run(SDL_Renderer* renderer, SDL_Window* window, int type) {
    bool running = true;
    SDL_Texture* textTexture1 = nullptr;
    SDL_Texture* textTexture2 = nullptr;
    TTF_Font* my_font = TTF_OpenFont("times.ttf", 20);
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        Oxy(renderer, SCREEN_HEIGHT, SCREEN_WIDTH, STEP);
        char text1[] = "x";
        char text2[] = "y";
        
        textTexture1 = get_text_texture(renderer, text1, my_font);
        textTexture2 = get_text_texture(renderer, text2, my_font);

        draw_text(renderer, textTexture1, { SCREEN_WIDTH - 20, SCREEN_HEIGHT / 2 + 2, 15, 15 });
        draw_text(renderer, textTexture2, { SCREEN_WIDTH / 2 + 2, 0, 15, 15 });

        draw(renderer, type);
        
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(textTexture1);
    SDL_DestroyTexture(textTexture2);
    TTF_CloseFont(my_font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();}

void run_grafic() {
    int type;
    do {
        type = chose();

        if (type == 0) {
            break;
        }

        input(type);

        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        if (!initSDL(window, renderer)) {
            cout << "Ошибка инициализации SDL." << endl;
            continue;
        }
        run(renderer, window, type);
    } while (true);
}

double integral(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (func(a) + func(b));

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += func(x);
    }
    return sum * h;
}


void run_integral() {
    int type;
    double a, b;
    int n = 1000;

    while (true) {
        type = chose();

        if (type == 0) {
            return;
        }

        input(type);

        cout << "Введите границы интегрирования: \n";
        cout << "a: ";
        cin >> a;
        cout << "b: ";
        cin >> b;
        while (a > b) {
            cout << "a не может превышать b \n";
            cout << "a: ";
            cin >> a;
            cout << "b: ";
            cin >> b;
        }

        double result = 0;
        switch (type) {
        case 1: result = integral(polynom, a, b, n); break;
        case 2: result = integral(stepen, a, b, n); break;
        case 3: result = integral(pokaz, a, b, n); break;
        case 4: result = integral(logar, a, b, n); break;
        case 5: result = integral(sinus, a, b, n); break;
        case 6: result = integral(cosinus, a, b, n); break;
        default: cout << "Неверный выбор!" << endl; continue;
        }

        cout << "Значение интеграла: " << result << endl << endl;
    }
}

void findRoots(double (*func)(double), double l, double r, double EPS, double step, double roots[], int& root_count) {

    for (double x = l; x <= r && root_count < MAX_ROOTS; x += step) {
        double next_x;
        if (x + step > r) {
            next_x = r;
        }
        else {
            next_x = x + step;
        }
        double prev_value = func(x);
        double next_value = func(next_x);

        if (prev_value * next_value <= 0) {
            double a = x;
            double b = next_x;
            while (fabs(b - a) > EPS) {
                double mid = (a + b) / 2.0;
                double f_mid = func(mid);

                if (fabs(f_mid) < EPS) {
                    a = mid;
                    break;
                }

                if (func(a) * f_mid <= 0) {
                    b = mid;
                }
                else {
                    a = mid;
                }
            }

            double root = (a + b) / 2.0;

            if (root_count < MAX_ROOTS) {
                roots[root_count++] = root;
            }
        }
    }
}

void run_root_finding() {
    int choice;
    int root_count = 0;
    double a, b;
    const double step = 0.1;
    double roots[MAX_ROOTS];

    while (true) {
        choice = chose();
        if (choice == 0) return;

        input(choice);

        cout << "Введите границы отрезка: \n";
        cout << "a: ";
        cin >> a;
        cout << "b: ";
        cin >> b;
        while (a > b) {
            cout << "a не может превышать b \n";
            cout << "a: ";
            cin >> a;
            cout << "b: ";
            cin >> b;
        }

        int root_count = 0;
        switch (choice) {
        case 1: findRoots(polynom, a, b, EPS, step, roots, root_count); break;
        case 2: findRoots(stepen, a, b, EPS, step, roots, root_count); break;
        case 3: findRoots(pokaz, a, b, EPS, step, roots, root_count); break;
        case 4: findRoots(logar, a, b, EPS, step, roots, root_count); break;
        case 5: findRoots(sinus, a, b, EPS, step, roots, root_count); break;
        case 6: findRoots(cosinus, a, b, EPS, step, roots, root_count); break;
        }

        if (root_count > 0) {
            cout << "Найдены корни:\n";
            for (int i = 0; i < root_count; i++) {
                cout << "x = " << roots[i] << endl;
            }
        }
        else {
            cout << "Корни не найдены на заданном отрезке.\n";
        }
    }
}

double proizvodnaya(double (*func)(double), double x, double EPS) {
    return (func(x + EPS) - func(x - EPS)) / (2 * EPS);
}


double bisection(double (*f)(double), double a, double b, double tol) {
    double fa = proizvodnaya(f, a, EPS);
    double fb = proizvodnaya(f, b, EPS);

    while (fabs(b - a) > EPS) {
        double mid = (a + b) / 2.0;
        double fmid = proizvodnaya(f, mid, EPS);

        if (fmid * fa < 0) {
            b = mid;
            fb = fmid;
        }
        else {
            a = mid;
            fa = fmid;
        }
    }

    return (a + b) / 2.0;
}

void findExtremums(double (*f)(double), double a, double b, double step, double EPS,
    double minima[], double maxima[], int& minCount, int& maxCount) {
    minCount = 0;
    maxCount = 0;


    for (double x = a; x <= b - step && minCount < MAX_EXTREMA && maxCount < MAX_EXTREMA; x += step) {
        double x1 = x;
        double x2 = x + step;

        double d1 = proizvodnaya(f, x1, EPS);
        double d2 = proizvodnaya(f, x2, EPS);


        if (d1 * d2 <= 0) {

            double extremum = bisection(f, x1, x2, EPS);


            double dd1 = proizvodnaya(f, extremum - EPS, EPS);
            double dd2 = proizvodnaya(f, extremum + EPS, EPS);

            if (dd1 < 0 && dd2 > 0 && minCount < MAX_EXTREMA) {
                minima[minCount++] = extremum;
            }
            else if (dd1 > 0 && dd2 < 0 && maxCount < MAX_EXTREMA) {
                maxima[maxCount++] = extremum;
            }
        }
    }

    if (minCount < MAX_EXTREMA && maxCount < MAX_EXTREMA) {
        if (fabs(proizvodnaya(f, a, EPS)) < EPS) {
            double d = proizvodnaya(f, a + EPS, EPS);
            if (d < 0) maxima[maxCount++] = a;
            else minima[minCount++] = a;
        }
        if (fabs(proizvodnaya(f, b, EPS)) < EPS) {
            double d = proizvodnaya(f, b - EPS, EPS);
            if (d < 0) maxima[maxCount++] = b;
            else minima[minCount++] = b;
        }
    }
}

void run_extremum_finding() {
    int choice;
    double a, b;
    const double step = 0.1;
    double minima[MAX_EXTREMA], maxima[MAX_EXTREMA];
    int minCount, maxCount;

    while (true) {
        int choice = chose();
        if (choice == 0) return;

        input(choice);

        cout << "Введите границы отрезка: \n";
        cout << "a: ";
        cin >> a;
        cout << "b: ";
        cin >> b;
        while (a > b) {
            cout << "a не может превышать b \n";
            cout << "a: ";
            cin >> a;
            cout << "b: ";
            cin >> b;
        }

        switch (choice) {
        case 1: findExtremums(polynom, a, b, step, EPS, minima, maxima, minCount, maxCount); break;
        case 2: findExtremums(stepen, a, b, step, EPS, minima, maxima, minCount, maxCount); break;
        case 3: findExtremums(pokaz, a, b, step, EPS, minima, maxima, minCount, maxCount); break;
        case 4: findExtremums(logar, a, b, step, EPS, minima, maxima, minCount, maxCount); break;
        case 5: findExtremums(sinus, a, b, step, EPS, minima, maxima, minCount, maxCount); break;
        case 6: findExtremums(cosinus, a, b, step, EPS, minima, maxima, minCount, maxCount); break;
        }

        if (minCount > 0) {
            cout << "Найдены минимумы:\n";
            for (int i = 0; i < minCount; i++) {
                if (fabs(minima[i]) < EPS) {
                    minima[i] = 0.0;
                }

                switch (choice) {
                case 1: cout << "x = " << minima[i] << "; y = " << polynom(minima[i]) << endl; break;
                case 2: cout << "x = " << minima[i] << "; y = " << stepen(minima[i]) << endl; break;
                case 3: cout << "x = " << minima[i] << "; y = " << pokaz(minima[i]) << endl;break;
                case 4: cout << "x = " << minima[i] << "; y = " << logar(minima[i]) << endl;break;
                case 5: cout << "x = " << minima[i] << "; y = " << sinus(minima[i]) << endl; break;
                case 6: cout << "x = " << minima[i] << "; y = " << cosinus(minima[i]) << endl; break;
                }
            }
        }

        else {
            cout << "Минимумы не найдены на заданном отрезке.\n";
        }

        if (maxCount > 0) {
            cout << "Найдены максимумы:\n";
            for (int i = 0; i < maxCount; i++) {
                if (fabs(maxima[i]) < EPS) {
                    maxima[i] = 0.0;
                }
                switch (choice) {
                case 1: cout << "x = " << maxima[i] << "; y = " << polynom(maxima[i]) << endl; break;
                case 2: cout << "x = " << maxima[i] << "; y = " << stepen(maxima[i]) << endl; break;
                case 3: cout << "x = " << maxima[i] << "; y = " << pokaz(maxima[i]) << endl;break;
                case 4: cout << "x = " << maxima[i] << "; y = " << logar(maxima[i]) << endl;break;
                case 5: cout << "x = " << maxima[i] << "; y = " << sinus(maxima[i]) << endl; break;
                case 6: cout << "x = " << maxima[i] << "; y = " << cosinus(maxima[i]) << endl; break;
                }
            }
        }
        else {
            cout << "Максимумы не найдены на заданном отрезке.\n";
        }
    }
}


void functions_menu() {
    int way;
    while (true) {
        cout << "\nРабота с функциями\n";
        cout << "1. Вычисление определенного интеграла на отрезке\n";
        cout << "2. Построение графика функции\n";
        cout << "3. Поиск корня у=0 на отрезке\n";
        cout << "4. Поиск экстремумов на отрезке\n";
        cout << "0. Вернуться в главное меню\n";
        cout << "Введите выбор: ";
        cin >> way;

        switch (way) {
        case 0: return;
        case 1: run_integral(); break;
        case 2: run_grafic(); break;
        case 3: run_root_finding(); break;
        case 4: run_extremum_finding(); break;
        default:
            cout << "Неверный ввод. Попробуйте снова.\n";
        }
    }
}
