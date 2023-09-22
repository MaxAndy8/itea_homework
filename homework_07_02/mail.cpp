//2)  Створити 3 динамічних змінних різного типу. Заповнити їх деякими значеннями. Вивести
//значення динамічних змінних на екран, обчислити добуток та середнє арифметичне.
//Звільнити пам’ять.
#include <iostream>

int main(int argc, char** argv)
{
    // Створення динамічної змінної типу int
    int* dynamicInt = new int(10);
    
    // Створення динамічної змінної типу double
    double* dynamicDouble = new double(3.141);

    // Створення динамічної змінної типу char
    char* dynamicChar = new char('A');

    // Виведення значень динамічних змінних
    std::cout << "The value of a dynamic variable int: "    << *dynamicInt    << std::endl;
    std::cout << "The value of a dynamic variable double: " << *dynamicDouble << std::endl;
    std::cout << "The value of a dynamic variable char: "   << *dynamicChar   << std::endl;

    // Обчислення добутку та середнього арифметичного
    double product = *dynamicInt * *dynamicDouble * *dynamicChar;
    double average = (*dynamicInt + *dynamicDouble + *dynamicChar) / 3.0;

    std::cout << "Product: "         << product << std::endl;
    std::cout << "Arithmetic mean: " << average << std::endl;

    std::cout << "A: " << static_cast<int>(*dynamicChar) << std::endl;

    // Звільнення пам'яті
    delete dynamicInt;
    delete dynamicDouble;
    delete dynamicChar;



    return 0;
}




