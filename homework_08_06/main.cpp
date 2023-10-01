//6. Написати функцію Count(N), яка повертає кількість ненульових дробових чисел N, які були аргументами функції.
#include <iostream>
// *************************************
bool is_equal(double x, double y) {
    return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
}

int Count(double N)
{
    static int times = 0;
    if (!is_equal(N, 0.0)) {
        times++;
    }
    return times;
}

int main(int argc, char** argv)
{
    std::cout << Count(1.0) << std::endl;
    std::cout << Count(2.0) << std::endl;
    std::cout << Count(3.0) << std::endl;
    std::cout << Count(4.0) << std::endl;
    std::cout << Count(5.0) << std::endl;
    std::cout << Count(0.0) << std::endl;
    std::cout << Count(7.0) << std::endl;
    std::cout << Count(8.0) << std::endl;
    std::cout << Count(9.0) << std::endl;
    std::cout << Count(10.0) << std::endl;
    std::cout << Count(11.0) << std::endl;

    return 0;
}

















