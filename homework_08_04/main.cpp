//4. Написати функцію Count(N), яка повертає кількість одноцифрових цілих чисел N, які були аргументами функції.
#include <iostream>

int Count(int N)
{
    static int rez = 0;
    if ((-9 <= N) && (N <= 9))
    {
        rez++;
    }

    return rez;
}

int main(int argc, char** argv)
{
    std::cout << Count(-4) << std::endl;
    std::cout << Count(1) << std::endl;
    std::cout << Count(2) << std::endl;
    std::cout << Count(3) << std::endl;
    std::cout << Count(4) << std::endl;
    std::cout << Count(5) << std::endl;
    std::cout << Count(6) << std::endl;
    std::cout << Count(7) << std::endl;
    std::cout << Count(8) << std::endl;
    std::cout << Count(9) << std::endl;
    std::cout << Count(10) << std::endl;
    std::cout << Count(11) << std::endl;

    return 0;
}
