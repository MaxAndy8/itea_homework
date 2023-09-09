// 1) ¬вести 2 ц≥лих числа(зм≥нн≥ типу int).«найти та вивести суму та добуток чисел.
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
    int number1 = inputInt("Enter the FIRST integer: ");
    int number2 = inputInt("Enter the SECOND integer: ");

    std::cout << number1 << " + " << number2 << " = " << static_cast<long long>(number1) + number2 << std::endl;
    std::cout << number1 << " * " << number2 << " = " << static_cast<long long>(number1) * number2 << std::endl;
    return 0;
}

