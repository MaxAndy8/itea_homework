//  11) Дано масив А.Утворити реверс масиву А у масиві В(тобто перший елемент масиву А записати на місце останнього елемента масиву В, 
// другий елемент масиву А записати на місце передостаннього елемента масиву В і т.д.).Вивести обидва масиви та індекси елементів на екран у вигляді 3 - х стовпців.
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
    int A[arSize];

    const int minValue = std::numeric_limits<int>::min();
    const int maxValue = std::numeric_limits<int>::max();

    // 
    std::cout << "Enter " << arSize << " of integers:" << std::endl;
    for (int i = 0; i < arSize; ++i)
    {
        std::string pr;
        pr.append("Enter array[").append(std::to_string(i)).append("].");

        A[i] = inputInt(pr.c_str());
    }

    std::cout << std::endl;
    //
    int B[arSize];
  
    // Утворення реверсу масиву A у масиві B
    for (int i = 0; i < arSize; i++) {
        B[i] = A[arSize - i - 1];
    }

    // Виведення масивів та їх індексів у вигляді 3-х стовпців
    std::cout << "Index\tArray A\tArray B" << std::endl;
    for (int i = 0; i < arSize; i++) {
        std::cout << i << "\t" << A[i] << "\t" << B[i] << std::endl;
    }

    

    return 0;
}
