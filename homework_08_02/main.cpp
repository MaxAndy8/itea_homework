//2. Написати функцію Sum(N), яка повертає суму цілих чисел N, які були аргументами функції у вигляді : 
//1·N1 + 2·N2 + 3·N3 + …, де  N1, N2, … - аргументи першого, другого і т.д.виклику функції.
#include <iostream>

int Sum(int N)
{
    static int rez   = 0;
    static int times = 0;
    times++;

    rez = rez + times * N;
    return rez;
}

int main(int argc, char** argv) 
{
    std::cout << Sum(1)  << std::endl;
    std::cout << Sum(2)  << std::endl;
    std::cout << Sum(3)  << std::endl;
    std::cout << Sum(4)  << std::endl;
    std::cout << Sum(5)  << std::endl;
    std::cout << Sum(6)  << std::endl;
    std::cout << Sum(7)  << std::endl;
    std::cout << Sum(8)  << std::endl;
    std::cout << Sum(9)  << std::endl;
    std::cout << Sum(10) << std::endl;
    std::cout << Sum(11) << std::endl;

    return 0;
}
