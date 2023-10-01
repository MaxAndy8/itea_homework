//9. Написати  перевантажені функції для обчислення суми добутків двох сусідніх чисел: для трьох цілих чисел та у одновимірному  масиві цілих чисел.
#include <iostream>

int calculateSumOfProducts(int num1, int num2, int num3) 
{
    return (num1 * num2) + (num2 * num3);
}

int calculateSumOfProducts(int arr[], int size) 
{
    if (size <= 2) {
        std::cerr << "Error: Array size must be greater than 2." << std::endl;
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < size - 1; i++) {
        sum += (arr[i] * arr[i + 1]);
    }

    return sum;
}

int main(int argc, char** argv)
{
    int num1 = 2, num2 = 7, num3 = 4;
    int arr[] = { 1, 2, 3, 4, 7 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    int sum1 = calculateSumOfProducts(num1, num2, num3);
    int sum2 = calculateSumOfProducts(arr, arrSize);

    std::cout << "Sum of products of two adjacent numbers for three numbers: "    << sum1 << std::endl;
    std::cout << "Sum of products of two adjacent numbers for array of numbers: " << sum2 << std::endl;

    return 0;
}