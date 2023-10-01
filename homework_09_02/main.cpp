//2)      Оголосити тип структури Complex для збереження комплексного числа.Написати та
//протестувати функції для додавання та віднімання двох комплексних чисел.
#include <iostream>

// Структура для збереження комплексного числа
struct Complex 
{
    double real;      // Дійсна частина
    double imaginary; // Уявна частина
};

// Функція для додавання двох комплексних чисел
Complex addComplex(const Complex& a, const Complex& b) 
{
    Complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}

// Функція для віднімання двох комплексних чисел
Complex subtractComplex(const Complex& a, const Complex& b) 
{
    Complex result;
    result.real = a.real - b.real;
    result.imaginary = a.imaginary - b.imaginary;
    return result;
}

int main(int argc, char** argv)
{
    Complex num1, num2, sum, difference;

    // Введення першого комплексного числа
    std::cout << "Enter the first complex number (real and imaginary parts separated by a space): ";
    std::cin >> num1.real >> num1.imaginary;

    // Введення другого комплексного числа
    std::cout << "Enter the second complex number (real and imaginary parts separated by a space): ";
    std::cin >> num2.real >> num2.imaginary;

    // Додавання та віднімання комплексних чисел
    sum        = addComplex(num1, num2);
    difference = subtractComplex(num1, num2);

    // Виведення результатів
    std::cout << "Sum of complex numbers: "        << sum.real        << " + " << sum.imaginary        << "i" << std::endl;
    std::cout << "Difference of complex numbers: " << difference.real << " + " << difference.imaginary << "i" << std::endl;
    return 0;
}




















