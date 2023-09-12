// 9.Написати програму, яка переводить введену користувачем довжину в сантиметри у інші одиниці довжини за вибором користувача(метри, дециметри, міліметри).
// Примітка!Роботу задачі організувати через систему меню
#include <iostream>

double getDoubleFromUser(const double minValue,
    const double maxValue,
    const std::string& prompt,
    const std::string& error) {
    double d = minValue;

    //std::cout.setf(std::ios::fixed);
    std::cout << prompt << " (from " << minValue << " to " << maxValue << "):> " << std::flush;

    bool isUserInputValid = false;
    while (!isUserInputValid)
    {
        if (std::cin >> d)
        {
            if (d >= minValue && d <= maxValue)
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
                    isUserInputValid = true;
                else
                {
                    std::cin.clear();
                    size = static_cast<int>(cinBuffer->in_avail());
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << error;
                }

            }
            else
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << error;
            }
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << error;
        }
    }

    return d;
}

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
    double centimeters, result;
    int choice;

    const double minValue = std::numeric_limits<double>::min();
    const double maxValue = std::numeric_limits<double>::max() / 10.0;

    std::string error = "Input is incorrect. Repeat the input:> ";

    centimeters = getDoubleFromUser(minValue, maxValue, "Enter the length in centimeters.", error);

    std::cout << "Select units of length to convert:" << std::endl;
    std::cout << "1. Meters"                          << std::endl;
    std::cout << "2. Decimeters"                      << std::endl;
    std::cout << "3. Millimeters"                     << std::endl;
    
    choice = inputInt("Your choice.", 1, 3);

    switch (choice) {
    case 1:
        result = centimeters / 100.0; // Conversion to meters
        std::cout << "Length in meters: "      << result << " m." << std::endl;
        break;
    case 2:
        result = centimeters / 10.0; // Conversion to decimeters
        std::cout << "Length in decimeters: "  << result << " dm." << std::endl;
        break;
    case 3:
        result = centimeters * 10.0; // Conversion to millimeters
        std::cout << "Length in millimeters: " << result << " mm." << std::endl;
        break;
    default:
        std::cout << "Invalid choice." << std::endl;
    }

    return 0;
}