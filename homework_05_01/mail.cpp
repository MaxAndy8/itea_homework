// 1.  ористувач вводить температуру.ѕрограма виводить пов≥домленн€ про стан орган≥зму
// (наприклад, 35 - 36.0 Ц понижена температура, стан ослабленого орган≥зму, 36.1 Ц 36.8 Ц нормальна температура, людина здорова ≥ т.≥.).
#include <iostream>

double getDoubleFromUser(const double minValue,
    const double maxValue,
    const std::string& prompt,
    const std::string& error) {
    double d = minValue;

    std::cout.setf(std::ios::fixed);
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
    double minValue =   0.0;
    double maxValue = 100.0;

    std::string error = "Input is incorrect. Repeat the input:> ";;

    double temp = getDoubleFromUser(minValue, maxValue, "Enter the person's temperature.", error);

    if (temp < 35.0)
    {
        std::cout << "Living people do not have such a temperature " << temp << std::endl;
    }
    else if (temp < 36.0)
    {
        std::cout << "Low temperature, weakened state of the body" << std::endl;
    }
    else if (temp < 36.8)
    {
        std::cout << "Normal temperature, the person is healthy" << std::endl;
    }
    else if (temp < 40.8)
    {
        std::cout << "Elevated temperature, the condition of the sick body" << std::endl;
    }
    else 
    {
        std::cout << "Roast duck temperature" << std::endl;
    }
    
    return 0;
}


