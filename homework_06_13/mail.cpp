//13)Дано масив(А) із К елементів(К - парне число).Утворити 2 масиви(В і С), переписуючи у масив В першу половину масиву А, у масив С – другу половину масиву А.

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
    const int maxSize = 1000;
    int A[maxSize]{ 0 };
    int B[maxSize / 2]{ 0 };
    int C[maxSize / 2]{ 0 };
    int K; // Розмір масиву A (парне число)
        
    K = inputInt("Enter the size of the array A (an even number).", 2, maxSize);
    while (K % 2 != 0)
    { 
        K = inputInt("The size of the array entered is incorrect, please repeat the entry (an even number).", 2, maxSize);
    }

    const int minValue = std::numeric_limits<int>::min();
    const int maxValue = std::numeric_limits<int>::max();
    // 
    std::cout << "Enter " << K << " of integers:" << std::endl;
    for (int i = 0; i < K; ++i)
    {
        std::string pr;
        pr.append("A[").append(std::to_string(i)).append("].");
        A[i] = inputInt(pr.c_str());
    }
    std::cout << std::endl;
    
    // Заповнення масивів B і C
    for (int i = 0; i < K / 2; i++) {
        B[i] = A[i];
        C[i] = A[i + K / 2];
    }

    // Виведення масивів B і C
    std::cout << "Array B (first half of array A): ";
    for (int i = 0; i < K / 2; i++) {
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array C (second half of array A): ";
    for (int i = 0; i < K / 2; i++) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}








