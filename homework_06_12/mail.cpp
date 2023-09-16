// Додаткові бали за виконання :
// 12) Дано 2 одновимірних масиви(А і В) по К елементів кожен.Утворити третій масив(С) 
// із К * 2 елементів, переписуючи у нього спочатку всі елементи масиву А по порядку, 
// а потім елементи масиву В.
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
    const int maxSize = 100;
    int A[maxSize];
    int B[maxSize];
    int C[maxSize * 2];
    int K; 

    K = inputInt("Enter the size of the array.", 1, maxSize);

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
    //
    
    std::cout << "Enter next " << K << " of integers:" << std::endl;
    for (int i = 0; i < K; ++i)
    {
        std::string pr;
        pr.append("B[").append(std::to_string(i)).append("].");
        B[i] = inputInt(pr.c_str());
    }
    //
    
    // Заповнення масиву C
    for (int i = 0; i < K * 2; i++) 
    {
        if (i < K) {
            C[i] = A[i];
        }
        else {
            C[i] = B[i - K];
        }
    }
    // 
    std::cout << std::endl;
    for (int i = 0; i < K * 2; i++)
    {
        std::cout << "C[" << i << "] = " << C[i] << std::endl;
    }

    return 0;
}
















