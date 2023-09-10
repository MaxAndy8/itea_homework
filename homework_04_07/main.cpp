//	7) дано трьохцифрове число.визначити чи число має однакові першу і останню
//	цифри(131, 272 і т.д.)
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
    int x = inputInt("Enter a two-digit number", 100, 999);
    int x1 = x % 10;
    int x3 = (x - x % 100) / 100;

    if (x1 == x3)
        std::cout << "The first digit and the third digit of the number " << x << " are the same." << std::endl;
    else
        std::cout << "The first digit and the third digit of the number " << x << " are not the same." << std::endl;

    return 0;
}