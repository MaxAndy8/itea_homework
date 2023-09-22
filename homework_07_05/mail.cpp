//5) Дано масив цілих чисел.Видалити з масиву усі непарні числа.
#include <iostream>

int main(int argc, char** argv)
{
    // Оголошення і ініціалізація звичайного масиву цілих чисел
    int A[] = { 5, 4, 2, 7, 8, 9, 6, 1 };
    int n = sizeof(A) / sizeof(A[0]); // Отримання розміру масиву

     int id = 0;
    // Проходження через масив і вибір елементів для збереження
    for (int i = 0; i < n; i++) {
        if (A[i] % 2 == 0) {
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







