// 3. Дано рік(номер року).Визначити чи рік високосний. 
// Рік високосний, якщо число року року ділиться націло на 4 і не ділиться на 100(наприклад високосними є 1996, 1992 роки). 
// Серед років, число яких має дві останн і цифри нулі(тобто рік ділиться на 100), високосними є ті що діляться на 400(н - д, 1600, 1200 – високосні, а 1700, 1900 - ні).
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
    int year = inputInt("Enter the year.", 1, 30000);
       
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        std::cout << "Year " << year << " is a leap year." << std::endl;
    }
    else {
        std::cout << "Year " << year << " is not a leap year." << std::endl;
    }

    return 0;
}
