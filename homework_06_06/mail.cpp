//6) Дано одновимірний масив.Знайти найбільший та найменший елементи масиву та поміняти їх у масиві місцями.
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

    std::cout << std::endl;

    // Пошук найбільшого та найменшого елементів
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 1; i < arSize; ++i) {
        if (myAr[i] < myAr[minIndex]) {
            minIndex = i;
        }
        if (myAr[i] > myAr[maxIndex]) {
            maxIndex = i;
        }
    }

    // Обмін місцями найбільшого та найменшого елементів
    int temp = myAr[minIndex];
    myAr[minIndex] = myAr[maxIndex];
    myAr[maxIndex] = temp;

    // Виведення масиву зі зміненими елементами на екран
    std::cout << "An array with changed elements:" << std::endl;
    for (auto x: myAr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}



