//1) Оголосити одновимірний масив з 10 елементів типу int.Заповнити його значеннями з клавіатури, вивести на екран та підрахувати добуток елементів масиву
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
    const int arSize = 10; 
    int myAr[arSize]; 
    
    const int minValue = std::numeric_limits<int>::min();
    const int maxValue = std::numeric_limits<int>::max();

    // 
    std::cout << "Enter " << arSize << " of integers:" << std::endl;
    for (int i = 0; i < arSize; ++i) 
    {
        std::string pr;
        pr.append("Enter array[").append(std::to_string(i)).append("].");

        myAr[i] = inputInt(pr.c_str());
    }

    //
    std::cout << "Your array:" << std::endl;
    for (int i = 0; i < arSize; ++i) {
        std::cout << myAr[i] << " ";
    }
    std::cout << std::endl;

    // 
    double product = 1.0L;
    for (int i = 0; i < arSize; ++i) {
        product *= myAr[i];
    }

    std::cout << "Product of array elements: " << product << std::endl;

    return 0;
}