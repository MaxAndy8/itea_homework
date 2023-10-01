//5. Написати функцію Avg(N), яка повертає середнє арифметичне дробових чисел   N, які були аргументами функції.

#include <iostream>

double Avg(double N)
{
    static double sum = 0;
    static int times = 0;
    times++;

    sum += N;
    return sum / times;
}

int main(int argc, char** argv)
{
    std::cout << Avg(1.0) << std::endl;
    std::cout << Avg(2.0) << std::endl;
    std::cout << Avg(3.0) << std::endl;
    std::cout << Avg(4.0) << std::endl;
    std::cout << Avg(5.0) << std::endl;
    std::cout << Avg(6.0) << std::endl;
    std::cout << Avg(7.0) << std::endl;
    std::cout << Avg(8.0) << std::endl;
    std::cout << Avg(9.0) << std::endl;
    std::cout << Avg(10.0) << std::endl;
    std::cout << Avg(11.0) << std::endl;

    return 0;
}
