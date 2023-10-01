//10.  Написати  перевантажені функції для пошуку середнього арифметичного для двох, трьох цілих чисел та у одновимірному цілочисловому масиві.

#include <iostream>

double calculateAverage(int num1, int num2) 
{
    return static_cast<double>(num1 + num2) / 2.0;
}

double calculateAverage(int num1, int num2, int num3) 
{
    return static_cast<double>(num1 + num2 + num3) / 3.0;
}

double calculateAverage(int arr[], int size) 
{
    if (size <= 0) {
        std::cerr << "Error: Array size must be greater than 0." << std::endl;
        return 0.0;
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return static_cast<double>(sum) / static_cast<double>(size);
}

int main(int argc, char** argv)
{
    int num1 = 11, num2 = 20, num3 = 31;
    int arr[] = { 1, 2, 3, 4, 8 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    double average1 = calculateAverage(num1, num2);
    double average2 = calculateAverage(num1, num2, num3);
    double average3 = calculateAverage(arr, arrSize);

    std::cout << "Arithmetic average of two numbers: "           << average1 << std::endl;
    std::cout << "Arithmetic average of three numbers: "         << average2 << std::endl;
    std::cout << "Arithmetic average for the array of numbers: " << average3 << std::endl;

    return 0;
}



