// 8)Дано витрати машиною пального на 100 км, ціну 1 л пального, а також шлях, який потрібно проїхати водію.
// Обчислити та вивести на екран скільки потрібно витратити грошей водію, щоб проїхати вказаний шлях
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

    std::string prompt = "Enter the car's fuel consumption per 100 km, (l)";
    std::string error = "The price is incorrect. Repeat the input:> ";

    double l_100km = getDoubleFromUser(minValue, maxValue, prompt, error);

    prompt = "Enter the price of 1 liter of fuel, (UAH)";
    double price_1l = getDoubleFromUser(minValue, maxValue, prompt, error);

    prompt = "Enter the path that the driver needs to travel, (km) ";
    double travel_km = getDoubleFromUser(minValue, maxValue, prompt, error);

    std::cout.setf(std::ios::fixed);
    std::cout << "The fare for the specified route = " << std::setprecision(2) << l_100km * price_1l * travel_km / 100.0 << " UAH" << std::endl;
   
    return 0;
}

