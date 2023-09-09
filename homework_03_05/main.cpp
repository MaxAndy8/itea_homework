//5) Розробити програму, яка організовує діалог з користувачем і дозволяє обчислити по вказаній сумі і курсу євро, долара та злотого в суму в гривнях.Примітка!З використанням констант.

#include <iostream>
#include <iomanip>

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
    const double UAH_to_USD = 37.45;
    const double UAH_to_EUR = 39.25;
    const double UAH_to_XAU = 1.0 / 70779.7; // 1 XAU = 70,779.7 UAH
    // XAU – Gold Ounce
    // Тройська унція золота у грамах дорівнює значенню 31, 1035, що часто округляється до 31 грама.Так склалося, 
    // що в ювелірній, косметичній та банківській справі до сьогодні вартість золота за вагою визначається в унціях.

    double minValue = 0.0;
    double maxValue = 100000000.0;
                      
    std::string prompt = "Enter the amount of hryvnias (UAH). ";
    std::string error  = "The price is incorrect. Repeat the input:> ";

    double UAH = getDoubleFromUser(minValue, maxValue, prompt, error);

    std::cout.setf(std::ios::fixed);
    std::cout << std::setprecision(2) << UAH << " UAH = " << UAH / UAH_to_USD << " USD = " << UAH / UAH_to_EUR << " EUR = " << std::setprecision(10) << UAH / UAH_to_XAU << " XAU" << std::endl;

    return 0;
}

























