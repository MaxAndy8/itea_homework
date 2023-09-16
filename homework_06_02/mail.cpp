// 2) Оголосити одновимірний масив з 7 елементів типу int.Заповнити його випадковими значеннями в діапазоні[-12.. + 50] 
// та вивести на екран.Підрахувати кількість відємних та додатніх елементів масиву.
#include <iostream>
#include <ctime>
#include <cstdlib> 

int main(int argc, char** argv)
{
    const int arSize = 7;
    int myAr[arSize];
    
    // Ініціалізація генератора випадкових чисел
    std::srand(std::time(0));

    // Заповнення масиву випадковими значеннями в діапазоні [-12..+50]
    for (int& x: myAr) 
    {
        x = std::rand() % 63 - 12; // Генеруємо випадкове число від -12 до +50
    }
    
    //
    std::cout << "Your array:" << std::endl;
    for (int& x : myAr) 
    {
        std::cout << x << " ";
    }

    std::cout << std::endl;

    // Підрахунок кількості від'ємних та додатніх елементів
    int positiveCount = 0;
    int negativeCount = 0;

    for (int i = 0; i < arSize; ++i) {
        if (myAr[i] > 0) {
            positiveCount++;
        }
        else if (myAr[i] < 0) {
            negativeCount++;
        }
    }

    std::cout << "Number of positive elements: " << positiveCount << std::endl;
    std::cout << "Number of negative elements: " << negativeCount << std::endl;

    return 0;
}


