//5. Вивести на екран цілі числа від 1 до 100. - while

#include <iostream>

int main(int argc, char** argv) 
{
    int number = 1;  

    while (number <= 100) {
        std::cout << number << " ";
        number++;  
    }

    std::cout << std::endl;

    return 0;
}
