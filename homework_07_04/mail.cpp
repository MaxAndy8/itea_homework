//4) Дано масив цілих чисел.Якщо перший елемент масиву є парним числом, то видалити із
//масиву всі парні числа, інакше – навпаки(видалити непарні числа).
#include <iostream>

int main(int argc, char** argv)
{
    // Оголошення і ініціалізація звичайного масиву цілих чисел
    int A[] = { 4, 2, 7, 8, 9, 6, 1 };
    int n = sizeof(A) / sizeof(A[0]); // Отримання розміру масиву

    // Перевірка, чи є перший елемент парним чи непарним
    bool isFirstElementEven = (A[0] % 2 == 0);

    int id = 0;
    // Проходження через масив і вибір елементів для збереження
    for (int i = 1; i < n; i++) {
        if ((isFirstElementEven && A[i] % 2 == 1) || (!isFirstElementEven && A[i] % 2 == 0)) {
            A[id] = A[i];
            id++;
        }
    }

    for (int i = id; i < n; i++) {
        A[i] = 0;
    }

    // Виведення оновленого масиву
    std::cout << "Updated array: ";
    for (int i = 0; i < n; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}




