//6) Дано масив цілих чисел.Перед кожним елементом масиву вставити число, що рівне
//останній цифрі елемента.Наприклад, масив A
//= { 12, 23, 89, 50 } має бути перетворений до{ 2, 12, 3, 23, 9, 89, 0, 50 }.
#include <iostream>
#include <malloc.h>

int main(int argc, char** argv)
{
    // Оголошення і ініціалізація звичайного масиву цілих чисел
    int A[] = { 12, 23, 89, 50, 125 };
    int n = sizeof(A) / sizeof(A[0]); // Отримання розміру масиву

    int* B = new int[n * 2];

    for (size_t i = 0, j = 0; i < n; i++, j++)
    {
        B[j] = A[i] % 10;
        j++;
        B[j] = A[i];
    }

    std::cout << "A: ";
    for (int& a : A)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    // Отримуємо кількість елементів на які вказує В
    size_t sizeB = _msize(B) / sizeof(B[0]);
    //або size_t sizeB = n * 2;  


    std::cout << "B: ";
    for (size_t i = 0; i < sizeB; i++) {
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;

    delete[] B;

    return 0;
}








