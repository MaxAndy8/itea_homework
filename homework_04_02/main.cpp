//2)дано 2 - цифрове число.вивести кожну цифру числа окремо та знайти суму його цифр(скоритсайтеся операцією % для обчислення останньої(другої) цифри.
#include <iostream> 

int inputInt(const char* prompt,
    int m = std::numeric_limits<int>::min(),
    int M = std::numeric_limits<int>::max())
{
    std::cout << prompt << " (from " << m << " to " << M << "):> " << std::flush;

    int N;
    for (;;) {

        if ((std::cin >> N).good() && (m <= N) && (N <= M))
        {
            std::streambuf* cinBuffer = std::cin.rdbuf();
            int size = static_cast<int>(cinBuffer->in_avail());

            while (size > 0)
            {
                char charValue = static_cast<char>(cinBuffer->sgetc());
                cinBuffer->sbumpc();

                if (charValue == ' ' || charValue == '\n')
                {
                    size = static_cast<int>(cinBuffer->in_avail());
                    continue;
                }
                break;
            }

            if (size == 0)
                return N;
        }
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cout << "Invalid input, please repeat:> " << std::endl;
        }
        else
        {
            std::cout << "The number is out of range. Re-enter :> ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main(int argc, char** argv)
{    
    int x = inputInt("Enter a two-digit number", 10, 99);
    int x1 = x % 10;
    int x2 = (x - x1) / 10;

    std::cout << x << " = " << x2 << " * 10 + " << x1 << std::endl;
    std::cout << "Sum of digits = " << x1 + x2 << std::endl;

    return 0;
}
