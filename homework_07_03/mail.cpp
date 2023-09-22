//3)  Дано цілочислові масиви А і В.Додати у
//кінець масиву А елементи з масиву В, кратні 3 або 7.
#include <iostream>

int main(int argc, char** argv)
{

    // Оголошення і ініціалізація масивів A і B
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {6, 7, 8, 9, 10};

    int lasteIndexA = sizeof(A) / sizeof(A[0]) - 1;

    // Проходимо через масив B і додаємо кратні 3 або 7 в кінець масиву A
    for (int& num : B) {
        if (num % 3 == 0 || num % 7 == 0) {
            A[lasteIndexA] = num;
            lasteIndexA--;            
        }
    }

    // Виведення масиву A після додавання елементів з масиву B
    std::cout << "Array A after adding elements from array B, multiples of 3 or 7: ";
    for (int num : A) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}


