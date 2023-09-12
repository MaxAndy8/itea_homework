// 10.Написати повноцінний калькулятор.Введення цифр та вибір математичної операції виконати в діалоговому стилі(запитати у користувача, вивести меню).
// У програмі передбачити уникнення помилок(ділення на нуль і т.д.).Фантазія та «дизайн» меню – ціниться та вітається!!!
#include <iostream>
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

char inputChar(const char* prompt)
{
    {
        std::cin.clear();    
        std::streambuf* cinBuffer = std::cin.rdbuf();
        int size = static_cast<int>(cinBuffer->in_avail());
        for (size_t i = 0; i < size; i++)
        {
            std::cin.get(); 
        }
    }
    

    std::cout << prompt << std::flush;
    for (;;) {
        std::streambuf* cinBuffer = std::cin.rdbuf();
        char charValue = static_cast<char>(cinBuffer->sgetc());

        int size = static_cast<int>(cinBuffer->in_avail());
        if (size == 2)
        {
            std::cin.get();
            std::cin.get();
            return charValue;
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "One character must be entere. Re-enter :> ";
        }
    }

}

int main(int argc, char** argv)
 {
    double result;   

    const double maxValue = sqrt(std::numeric_limits<double>::max());
    const double minValue = - maxValue;

    std::string error = "Input is incorrect. Repeat the input:> ";

    double num1 = getDoubleFromUser(minValue, maxValue, "Enter the first number.", error);

    char operation;
    do
    {
        operation = inputChar("Choose operation (+, -, *, /): ");

    } while (!(operation == '+' || operation == '-' || operation == '*' || operation == '/'));
    
    

    double num2 = getDoubleFromUser(minValue, maxValue, "Enter the second number.", error);

    switch (operation) {
    case '+':
        result = num1 + num2;
        std::cout << "Result: " << num1 << " + " << num2 << " = " << result << std::endl;
        break;
    case '-':
        result = num1 - num2;
        std::cout << "Result: " << num1 << " - " << num2 << " = " << result << std::endl;
        break;
    case '*':
        result = num1 * num2;
        std::cout << "Result: " << num1 << " * " << num2 << " = " << result << std::endl;
        break;
    case '/':
        if (num2 != 0) {
            result = num1 / num2;
            std::cout << "Result: " << num1 << " / " << num2 << " = " << result << std::endl;
        }
        else {
            std::cout << "Error: Division by zero!" << std::endl;
        }
        break;
    default:
        std::cout << "Invalid operation!" << std::endl;
    }

    return 0;
}

