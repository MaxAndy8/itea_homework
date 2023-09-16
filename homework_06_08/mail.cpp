//8) Дано одновимірний масив.Знайти скільки елементів знаходиться між першим і останнім відємним елементом.
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
    //


    int firstNegativeIndex = -1; // Індекс першого від'ємного елемента
    int lastNegativeIndex = -1;  // Індекс останнього від'ємного елемента

    // Знаходження індексів першого і останнього від'ємного елементів
    for (int i = 0; i < arSize; i++) {
        if (myAr[i] < 0) {
            if (firstNegativeIndex == -1) {
                firstNegativeIndex = i;
            }
            lastNegativeIndex = i;
        }
    }

    // Перевірка наявності від'ємних елементів
    if (firstNegativeIndex == -1) {
        std::cout << "There are no negative elements in the array." << std::endl;
    }
    else {
        int countBetweenNegatives = lastNegativeIndex - firstNegativeIndex - 1;

        if (countBetweenNegatives > 0) {
            std::cout << "The number of elements between the first and the last negative element: "
                << countBetweenNegatives << std::endl;
        }
        else {
            std::cout << "There are no other elements between the first and last negative element." << std::endl;
        }
    }


    return 0;
}
