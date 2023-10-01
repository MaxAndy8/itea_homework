//3)      Оголосити тип структури Vector для збереження координат вектора на площині.Написати та протестувати
//функції для перевірки двох векторів на перпендикулярність та колінеарність..
#include <iostream>
#include <cmath>

// Структура для збереження координат вектора на площині
struct Vector {
    double x; // Координата x
    double y; // Координата y
};

// Функція для обчислення скалярного добутку двох векторів
double dotProduct(const Vector& a, const Vector& b) {
    return a.x * b.x + a.y * b.y;
}

// Функція для обчислення модуля вектора
double vectorMagnitude(const Vector& v) {
    return std::sqrt(v.x * v.x + v.y * v.y);
}

// Функція для перевірки перпендикулярності двох векторів
bool arePerpendicular(const Vector& a, const Vector& b) {
    // Вектори a та b перпендикулярні, якщо їх скалярний добуток дорівнює 0.
    return dotProduct(a, b) == 0.0;
}

// Функція для перевірки колінеарності двох векторів
bool areCollinear(const Vector& a, const Vector& b) {
    // Вектори a та b колінеарні, якщо відношення їх модулів співпадає зі знаком.
    double magnitudeA = vectorMagnitude(a);
    double magnitudeB = vectorMagnitude(b);
    return (a.x / magnitudeA == b.x / magnitudeB) && (a.y / magnitudeA == b.y / magnitudeB);
}

int main(int argc, char** argv)
{
    Vector vector1, vector2;

    // Введення координат першого вектора
    std::cout << "Enter the coordinates of the first vector (x1 y1):";
    std::cin >> vector1.x >> vector1.y;

    // Введення координат другого вектора
    std::cout << "Enter the coordinates of the second vector (x2 y2):";
    std::cin >> vector2.x >> vector2.y;

    // Перевірка перпендикулярності та колінеарності векторів
    bool perpendicular = arePerpendicular(vector1, vector2);
    bool collinear     = areCollinear(vector1, vector2);

    if (perpendicular) {
        std::cout << "Vectors are perpendicular." << std::endl;
    }
    else {
        std::cout << "The vectors are not perpendicular." << std::endl;
    }

    if (collinear) {
        std::cout << "Vectors are collinear." << std::endl;
    }
    else {
        std::cout << "Vectors are not collinear." << std::endl;
    }
    return 0;
}














