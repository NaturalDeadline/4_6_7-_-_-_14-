﻿//Задача 4. Шувалов А., 14 гр.

/*Задание 1. При значениях x и N, определяемых вводом, вычислить частичную сумму ряда
SN(x). Найти абсолютную погрешность полученного результата (абсолютную величину
разности между значением соответствующей функции и SN(x)). Сравнить полученную
погрешность с абсолютной величиной последнего (N-го) слагаемого, включенного в
частичную сумму.
Задание 2. При значениях x и Е, определяемых вводом, вычислить сумму тех слагаемых
заданного вида, которые по абсолютной величине больше Е. Подсчитать количество таких
слагаемых N. Выполнить суммирование для двух значений Е, отличающихся на порядок
(в 10 раз).
Вычисление частичных сумм необходимо оформить в виде отдельных функций с
соответствующими наборами параметров.
*/

#include <iostream>
#include <locale.h>
#include <math.h>
#include <conio.h>
using namespace std;

double sumN(double, int, double&);
double sumE(double, double, int&);

int main()
{
    setlocale(0, "Rus");
    //здесь и далее - до следующего комментария - подготовка "меню":
    int re = 0;
    cout << "Если хотите узнать точное значение функции и частичной суммы, введите 1, для выхода введите 0:\n";
    cin >> re;
    while ((re != 1) && (re != 0)) {
        cout << "Ошибка: введено некорректное число или набор символов\n" << "Если хотите узнать точное значение функции и частичной суммы, имеющие наибольшее значение, введите 1, для выхода введите 0\n";
        cin >> re;
    }
    //Цикл-меню
    while (re) {
                // аргумент
                int x; 
                // Точное значение функции и частичной суммы
                double func, sum; 
                // Число слагаемых в частичной сумме
                int n; 

                //Задание 1
                cout << "Введите значение аргумента:";
                cin >> x;
                cout << "Задайте число слагаемых:";
                cin >> n;
                // Вычисление "точного" значения
                func = atan(x);
                double last;
                sum = sumN(x, n, last);
                cout << "Точное значение функции равно " << func << endl;
                cout << "Частичная сумма ряда равна " << sum << endl;
                cout << "Абсолютная погрешность равна " << fabs(func-sum) << endl;
                cout << "Последнее слагаемое равно " << last << endl;

                //Задание 2
                double E;
                cout << "Введите значение аргумента:";
                cin >> x;
                cout << "Задайте точность вычислений E:";
                cin >> E;
                // Вычисление частичной суммы
                sum = sumE(x, E, n);
                cout << "Точное значение функции равно " << func << endl;
                cout << "Частичная сумма ряда c заданной точностью равна " << sum << endl;
                cout << "Учтено " << n << " членов ряда" << endl;
                sum = sumE(x, E / 10, n);
                cout << "Частичная сумма ряда c точностью, большей в 10 раз, равна " << sum << endl;
                cout << "Учтено " << n << " членов ряда" << endl;

        //необходимые действия для зацикливания программы (меню)
        cout << "Если хотите узнать точное значение функции и частичной суммы, имеющие наибольшее значение, введите 1, для выхода введите 0:\n";
        cin >> re;
        while ((re != 1) && (re != 0)) {
            cout << "Ошибка: введено некорректное число или набор символов\n" << "Если хотите узнать точное значение функции и частичной суммы, введите 1, для выхода введите 0:\n";
            cin >> re;
        }
    }
    system("pause");
}
double sumN(double x, int n, double& last)
{
    last = x;
    double sum = last;
    for (int i = 1; i < n; ++i)
    {
        // Отношение i члена к (i - 1) 
        double r = pow(-1, i + 1) * pow(x, i) / i;
        last *= r;
        sum += last;
    }
    return sum;
}

double sumE(double x, double E, int& n)
{
    double last;
    last = x;
    double sum = last;
    for (n = 1; fabs(last) > E; ++n)
    {
        // Отношение n слагаемлого к (n - 1)
        double r = pow(-1,n+1)*pow(x, n)/n;
        last *= r;
        sum += last;
    }
    return sum;
}