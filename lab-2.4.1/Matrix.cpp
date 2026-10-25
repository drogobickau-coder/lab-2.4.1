#include "Matrix.h"
#include <sstream>
#include <cmath>
#include <algorithm>
#pragma execution_character_set("utf-8")

Matrix::Matrix() {
    setSize(1);
    m[0][0] = 0;
}

Matrix::Matrix(int n) {
    setSize(n);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            m[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix& other) {
    size = other.size;
    count = other.count;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            m[i][j] = other.m[i][j];
        }
    }
}

int Matrix::getSize() const {
    return size;
}

int Matrix::getCount() const {
    return count;
}

void Matrix::setSize(int n) {
    if (n < 1) n = 1;
    if (n > MAX_SIZE) n = MAX_SIZE;
    size = n;
    count = n * n;
}

int Matrix::getElement(int i, int j) const {
    if (i >= 0 && i < size && j >= 0 && j < size) {
        return m[i][j];
    }
    return 0; // Значення за умовчанням при виході за межі
}

void Matrix::setElement(int i, int j, int value) {
    if (i >= 0 && i < size && j >= 0 && j < size) {
        m[i][j] = value;
    }
}

int Matrix::norm() const {
    if (count == 0) return 0;
    int min_val = m[0][0];
    int max_val = m[0][0];

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (m[i][j] < min_val) min_val = m[i][j];
            if (m[i][j] > max_val) max_val = m[i][j];
        }
    }
    return std::abs(max_val - min_val);
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;
    size = other.size;
    count = other.count;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            m[i][j] = other.m[i][j];
        }
    }
    return *this;
}

int* Matrix::operator[](int i) {
    return m[i];
}

Matrix::operator string() const {
    stringstream ss;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            ss << m[i][j] << "\t";
        }
        ss << "\n";
    }
    return ss.str();
}

Matrix& Matrix::operator++() {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            ++m[i][j];
    return *this;
}

Matrix Matrix::operator++(int) {
    Matrix temp(*this);
    ++(*this);
    return temp;
}

Matrix& Matrix::operator--() {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            --m[i][j];
    return *this;
}

Matrix Matrix::operator--(int) {
    Matrix temp(*this);
    --(*this);
    return temp;
}

Matrix operator-(const Matrix& l, const Matrix& r) {
    int newSize = min(l.size, r.size);
    Matrix result(newSize);
    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            result.m[i][j] = l.m[i][j] - r.m[i][j];
        }
    }
    return result;
}

bool operator==(const Matrix& l, const Matrix& r) {
    if (l.size != r.size) return false;
    for (int i = 0; i < l.size; ++i) {
        for (int j = 0; j < l.size; ++j) {
            if (l.m[i][j] != r.m[i][j]) return false;
        }
    }
    return true;
}

ostream& operator<<(ostream& out, const Matrix& matrix) {
    out << string(matrix);
    return out;
}

istream& operator>>(istream& in, Matrix& matrix) {
    cout << "Введіть елементи матриці (" << matrix.size << "x" << matrix.size << "):\n";
    for (int i = 0; i < matrix.size; ++i) {
        for (int j = 0; j < matrix.size; ++j) {
            in >> matrix.m[i][j];
        }
    }
    return in;
}