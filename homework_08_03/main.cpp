//3.Написати функцію SumParni(N), яка повертає суму парних серед  цілих чисел N, які були аргументами функції.
#include <iostream>

int SumParni(int N)
{
    static int rez = 0;
    if ((N > 0) && (N % 2 == 0))
    {
        rez = rez + N;
    }

    return rez;
}

int main(int argc, char** argv)
{
    std::cout << SumParni(-4) << std::endl; 
    std::cout << SumParni(1)  << std::endl;
    std::cout << SumParni(2)  << std::endl;
    std::cout << SumParni(3)  << std::endl;
    std::cout << SumParni(4)  << std::endl;
    std::cout << SumParni(5)  << std::endl;
    std::cout << SumParni(6)  << std::endl;
    std::cout << SumParni(7)  << std::endl;
    std::cout << SumParni(8)  << std::endl;
    std::cout << SumParni(9)  << std::endl;
    std::cout << SumParni(10) << std::endl;
    std::cout << SumParni(11) << std::endl;

    return 0;
}
