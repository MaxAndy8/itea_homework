//8. Написати  перевантажені функції для пошуку кількості двоцифрових чисел у одновимірному масиві цілих, у двовимірному  масиві цілих розміру  Nx3.
#include <iostream>

int countTwoDigitNumbers(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 10 && arr[i] <= 99) {
            count++;
        }
    }
    return count;
}

int countTwoDigitNumbers(int arr[][3], int rows) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] >= 10 && arr[i][j] <= 99) {
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char** argv)
{
    int arr1[] = { 5, 15, 25, 35, 45, 55, 65 };
    int arrSize = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[][3] = { {12, 34, 56}, {7, 89, 10}, {45, 67, 98} };
    int numRows = sizeof(arr2) / sizeof(arr2[0]);

    int count1 = countTwoDigitNumbers(arr1, arrSize);
    int count2 = countTwoDigitNumbers(arr2, numRows);

    std::cout << "The number of two-digit numbers in a one-dimensional array: " << count1 << std::endl;
    std::cout << "The number of two-digit numbers in a two-dimensional array: " << count2 << std::endl;

    return 0;
}





