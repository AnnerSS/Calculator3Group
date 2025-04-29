#pragma once

#include <SDL.h>
#include "SDL_ttf.h"
#include <iostream>
#include <cmath>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int STEP = 20;
const int MAX_ROOTS = 100;
const int MAX_EXTREMA = 100;
const double EPS = 1e-6;

extern double pol_coeffs[11];
extern int pol_degree;
extern double a, b, c, d;

int chose();
void input(int type);
double polynom(double x);
double stepen(double x);
double pokaz(double x);
double logar(double x);
double sinus(double x);
double cosinus(double x);
bool initSDL(SDL_Window*& window, SDL_Renderer*& renderer);
SDL_Texture* get_text_texture(SDL_Renderer*& renderer, char* text, TTF_Font* my_font);
void draw_text(SDL_Renderer*& renderer, SDL_Texture* texture, SDL_Rect rect);
void Oxy(SDL_Renderer* renderer, int SCREEN_HEIGHT, int SCREEN_WIDTH, int STEP);
void draw(SDL_Renderer* renderer, int type);
void run(SDL_Renderer* renderer, SDL_Window* window, int type);
void run_grafic();
double integral(double (*func)(double), double a, double b, int n);
void run_integral();
void findRoots(double (*func)(double), double l, double r, double EPS, double step, double roots[], int& root_count);
void run_root_finding();
double proizvodnaya(double (*func)(double), double x, double EPS);
double bisection(double (*f)(double), double a, double b, double tol);
void findExtremums(double (*f)(double), double a, double b, double step, double EPS,
    double minima[], double maxima[], int& minCount, int& maxCount);
void run_extremum_finding();
void functions_menu();
