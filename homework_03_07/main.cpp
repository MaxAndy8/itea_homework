//7)Напишіть програму, яка обраховує квадрат та куб довільного введеного числа

#include <iostream>
#include <iomanip>
#include <cmath>

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


int main(int argc, char** argv)
{

    double minValue = std::numeric_limits<double>::min();
    double maxValue = cbrtl(std::numeric_limits<double>::max());

    std::string prompt = "Enter the number. ";
    std::string error = "The price is incorrect. Repeat the input:> ";

    double number = getDoubleFromUser(minValue, maxValue, prompt, error);

    std::cout.setf(std::ios::fixed);
    std::cout << number << " * " << number << " = " << number * number << std::endl;
    std::cout << number << " * " << number << " * " << number << " = " << number * number * number << std::endl;
    
    return 0;
}



























