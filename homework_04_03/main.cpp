//	3)дано 3 цілих числа.вивести на екран true, якщо числа впорядковані за зростанням(наприклад 1 5 7 впорядковані за зростанням, а 1 5 3 - ні), інакше вивести - false.

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
    int x1 = inputInt("Enter X1.");
    int x2 = inputInt("Enter X2.");
    int x3 = inputInt("Enter X3.");

    if(x1 < x2 && x2 < x3)
    {
        std::cout << "(x1 < x2 && x2 < x3) = true" << std::endl;
    }
    else
    {
        std::cout << "(x1 < x2 && x2 < x3) = false" << std::endl;
    }

    return 0;
}



