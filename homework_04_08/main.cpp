//	8) ���� ������� ������������.��������� �� ����������� � ���������.
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
    double minValue = 0.000001;
    double maxValue = 100000000.0;
        
    std::string error = "Input is incorrect. Repeat the input:> ";

    double x1 = getDoubleFromUser(minValue, maxValue, "Enter the size of the first side of the rectangle." , error);
    double x2 = getDoubleFromUser(minValue, maxValue, "Enter the size of the second side of the rectangle.", error);

    // ��� ��������� ���� ����� ���� double ����� ��������������� "(fabs(x1 - x2) < 1e-9)"
    // ��� ����� ������� �������� ������� �� ����� ��������������� "(x1 == x2)"
    if (x1 == x2)
    {
        std::cout << "This rectangle is a square" << std::endl;
    }
    else
    {
        std::cout << "This rectangle is not a square" << std::endl;
    }

    return 0;
}
