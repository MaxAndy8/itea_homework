//3) Оголосити, проініціалізувати початковими значеннями та вивести одновимірний масив з 7 елементів типу long.Визначити суму парних елементів масиву
#include <iostream>
#include <ctime>
#include <cstdlib> 

int main(int argc, char** argv)
{
    const int arSize = 7;
    long myAr[arSize]{0};
   
    // Ініціалізація генератора випадкових чисел на основі часу
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Заповнення масиву випадковими значеннями 
    for (auto& x : myAr)
    {
        x = static_cast<long>(std::rand());
    }

    //
    std::cout << "Your array:" << std::endl;
    for (auto& x : myAr)
    {
        std::cout << x << " ";
    }

    std::cout << std::endl;

    // Знаходження суми парних елементів масиву
    double sumOfEven = 0;
    for (auto& x : myAr) {
        if (x % 2 == 0) {
            sumOfEven += x;
        }
    }

    // Виведення суми парних елементів на екран
    std::cout << "The sum of even elements: " << sumOfEven << std::endl;
   
    return 0;
}
