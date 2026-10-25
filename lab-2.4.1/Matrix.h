#pragma once
#include <iostream>
#include <string>

using namespace std;

class Matrix {
private:
    static const int MAX_SIZE = 20; // Максимально можливий розмір масиву (N)
    int size;                       // Фактична кількість рядків/стовпців (N)
    int count;                      // Фактична кількість елементів (N * N)
    int m[MAX_SIZE][MAX_SIZE];      // Масив для збереження елементів матриці

public:
    // Конструктори
    Matrix();
    Matrix(int n);
    Matrix(const Matrix& other);

    // Методи доступу
    int getSize() const;
    int getCount() const;
    void setSize(int n);
    int getElement(int i, int j) const;
    void setElement(int i, int j, int value);

    // Метод для обчислення норми матриці (модуль різниці макс. і мін. елементів)
    int norm() const;

    // Перевантаження операцій (методи класу)
    Matrix& operator=(const Matrix& other);
    int* operator[](int i); // Індексування (повертає вказівник на рядок)
    operator string() const;

    // Інкремент та декремент (префіксні та постфіксні)
    Matrix& operator++();    // Префіксний
    Matrix operator++(int);  // Постфіксний
    Matrix& operator--();    // Префіксний
    Matrix operator--(int);  // Постфіксний

    // Перевантаження бінарних операцій (дружні функції)
    friend Matrix operator-(const Matrix& l, const Matrix& r);
    friend bool operator==(const Matrix& l, const Matrix& r);

    // Введення та виведення
    friend ostream& operator<<(ostream& out, const Matrix& matrix);
    friend istream& operator>>(istream& in, Matrix& matrix);
};

// Структура для демонстрації розміру з #pragma pack(1)
#pragma pack(push, 1)
struct MatrixPacked {
    int size;
    int count;
    int m[20][20];
};
#pragma pack(pop)