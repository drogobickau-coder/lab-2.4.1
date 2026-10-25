#include "Matrix.h"
#include <iostream>
#pragma execution_character_set("utf-8")
#include <windows.h>


using namespace std;

int main() {

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    {
        setlocale(LC_ALL, "uk_UA.UTF-8");
    }

    cout << "=== Розмір класу ===" << endl;
    cout << "Розмір Matrix (без pragma pack): " << sizeof(Matrix) << " байт" << endl;
    cout << "Розмір Matrix (з pragma pack(1)): " << sizeof(MatrixPacked) << " байт\n" << endl;

    cout << "=== Створення матриць ===" << endl;
    Matrix m1(2);
    Matrix m2(2);

    // Демонстрація операції індексування []
    m1[0][0] = 5; m1[0][1] = 2;
    m1[1][0] = 9; m1[1][1] = 1;

    m2[0][0] = 3; m2[0][1] = 3;
    m2[1][0] = 3; m2[1][1] = 3;

    cout << "Матриця m1:\n" << m1;
    cout << "Матриця m2:\n" << m2;

    cout << "=== Норма матриці m1 ===" << endl;
    cout << "Норма m1 (Max(9) - Min(1)) = " << m1.norm() << "\n" << endl;

    cout << "=== Віднімання (m1 - m2) ===" << endl;
    Matrix m3 = m1 - m2;
    cout << m3 << endl;

    cout << "=== Порівняння ===" << endl;
    cout << "m1 == m2 : " << (m1 == m2 ? "Так" : "Ні") << endl;

    cout << "\n=== Інкремент і декремент ===" << endl;
    cout << "m3 до ++m3:\n" << m3;
    Matrix m4 = ++m3;
    cout << "m3 після ++m3:\n" << m3;

    cout << "\n=== Масив об'єктів ===" << endl;
    Matrix arr[2] = { Matrix(2), Matrix(3) };
    cout << "Масив матриць створено. Розмір першої: " << arr[0].getSize()
        << ", розмір другої: " << arr[1].getSize() << "\n";

    return 0;
}