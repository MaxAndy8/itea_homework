// 3) Дано ціна 1 хвилини та кількість хвилин.Обчислити вартість дзвінка.
#include <iostream>

double getDoubleFromUser(const double minValue,
    const double maxValue,
    const std::string& prompt,
    const std::string& error) {
    double d = minValue;

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
    double minValue = 0.0;
    double maxValue = 1000.0;

    std::string prompt = "Enter the price per minute of the call ($). ";
    std::string error  = "The price is incorrect. Repeat the input:> ";

    double price = getDoubleFromUser(minValue, maxValue, prompt, error);

    prompt = "Enter the quantity of minutes of the call. ";
    double minutes = getDoubleFromUser(minValue, maxValue, prompt, error);

    std::cout << "The cost of the call = " << price * minutes << "$." << std::endl;

    return 0;
}



