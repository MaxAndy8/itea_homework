//8) Дано рядок.Написати функцію, яка повертає кількість цифр у рядку.Перевірити роботу
//функції.
#include <iostream>

int countDigits(const char* str) {
    int count = 0;

    while (*str) { // Переглядаємо кожен символ в рядку
        if (std::isdigit(*str)) { // Якщо символ є цифрою
            count++;
        }
        str++; // Переміщуємо вказівник на наступний символ
    }

    return count;
}

int main(int argc, char** argv)
{
    char str[100];
    std::cout << "Enter the line: ";

    std::cin.getline(str, sizeof(str));

    int digitCount = countDigits(str);

    std::cout << "The number of digits in a row: " << digitCount << std::endl;

    return 0;
}




