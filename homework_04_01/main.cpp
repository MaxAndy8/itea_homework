//1) написати програму, яка знаходить та виводить в дійсному вигляді середнє арифметичне трьох введених цілих чисел запропонувати декілька варіантів розвязку.
#include <iostream>
#include <string> 

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
    const int size_x = 3;
    int x[size_x];

    for (int i = 0; i < size_x; i++)
    {
        std::string pr;
        pr.append("Enter X").append(std::to_string(i)).append(". ");

        x[i] = inputInt(pr.c_str());
    }

    double sum(0);
    for (int i = 0; i < size_x; i++)
    {    
        sum += x[i];
    }

    std::cout << "Average value X: " << sum / size_x << std::endl;

    return 0;
}
