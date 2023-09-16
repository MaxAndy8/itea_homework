//4) Утворити одновимірний масив розміром 30. Заповнити його числами, які є степенями 2: (1, 2, 4, 8, 16, ...).Вивести елементи масиву на екран у прямому і оберненому порядку.
#include <iostream>
#include <cmath>

int main(int argc, char** argv)
{
    const int arSize = 30; 
    int myAr[arSize]; 
        
    for (int i = 0; i < arSize; ++i) {
        myAr[i] = static_cast<int>(std::pow(2, i));
    }

    std::cout << "Array elements in direct order:" << std::endl;
    for (int i = 0; i < arSize; ++i) {
        std::cout << myAr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array elements in reverse order:" << std::endl;
    for (int i = arSize - 1; i >= 0; --i) {
        std::cout << myAr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}