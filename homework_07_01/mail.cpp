//1) Дано час(години, хвилини, секунди).Знайти кількість секунд, які пройшли від початку
//доби.Доступ до вхідних та результуючих даних програми виконувати через вказівники
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
    // Вказівник на години, хвилини і секунди
    int* pHours   = new int(0);
    int* pMinutes = new int(0);
    int* pSeconds = new int(0);

    *pHours   = inputInt("Enter the hours."  , 0, 23);
    *pMinutes = inputInt("Enter the minutes.", 0, 59);
    *pSeconds = inputInt("Enter seconds."    , 0, 59);

    // Обчислення кількості секунд, які пройшли від початку доби
    int totalSeconds = (*pHours) * 3600 + (*pMinutes) * 60 + (*pSeconds);

    std::cout << "The number of seconds that have passed since the beginning of the day: " << totalSeconds << " seconds." << std::endl;

    delete pHours  ;
    delete pMinutes;
    delete pSeconds;

	return 0;
}
