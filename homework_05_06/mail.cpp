//6.Вводяться 10 чисел. Знайти суму та середнє арифметичне цих чисел. - while
#include <iostream>
#include <string>

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
    const int times = 10;
    int    count = 0;  
    double sum   = 0;
    double number;

    const double minValue = std::numeric_limits<double>::min();
    const double maxValue = std::numeric_limits<double>::max() / times;

    std::string error = "Input is incorrect. Repeat the input:> ";

    while (count < times) {
        std::string pr;
        pr.append("Enter the number ").append(std::to_string(count + 1)).append(". ");
        
        number = getDoubleFromUser(minValue, maxValue, pr.c_str(), error);

        sum += number; 
        count++; 
    }

    double average = static_cast<double>(sum) / times;

    std::cout << "Sum of entered numbers: " << sum << std::endl;
    std::cout << "Arithmetic average of entered numbers: " << average << std::endl;

    return 0;
}

