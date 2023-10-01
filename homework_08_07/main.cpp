//7. Написати  перевантажені функції для пошуку найбільшого з двох, трьох цілих чисел та  найбільшого значення у одновимірному цілочисловому масиві.
#include <iostream>

int findMax(int num1, int num2) 
{
    return (num1 > num2) ? num1 : num2;
}

int findMax(int num1, int num2, int num3) 
{
    int max = num1;
    if (num2 > max) {
        max = num2;
    }
    if (num3 > max) {
        max = num3;
    }
    return max;
}

int findMax(int arr[], int size) {
    if (size <= 0) {
        std::cerr << "Error: Array size must be greater than 0." << std::endl;
        return 0;
    }

    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main(int argc, char** argv)
{
    int num1    = 17, num2 = 29, num3 = 30;
    int arr[]   = { 15, 7, 25, 12, 4 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    int max1 = findMax(num1, num2);
    int max2 = findMax(num1, num2, num3);
    int max3 = findMax(arr, arrSize);

    std::cout << "The largest of two numbers: "                << max1 << std::endl;
    std::cout << "The largest of three numbers: "              << max2 << std::endl;
    std::cout << "The largest value in the array of numbers: " << max3 << std::endl;

    return 0;
}
