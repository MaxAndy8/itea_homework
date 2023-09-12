//7. ������� �������� ���������� ���� �������� ������ n - �������� �����.������� �� �����, ��� ���� �������� � ��� ������ ����� � �� ��������. - do..while
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
    int n = inputInt("Enter n (number of odd numbers).", 0, 1000);  

    int sum = 0;    // ����� ��� ��������� ���� ��������
    int count = 0;  // ˳������� �������� �����
    int number = 1; // ��������� ������� �����

    do {
        // ���������� �������� ��������� ��������� ����� �� ��������� �� ����
        int square = number * number;
        sum += square;

        // ��������� ��������� ��������� ����� � ���� ��������
        std::cout << "Odd number: " << number << ", its square: " << square << std::endl;

        // ��������� ��������� � ������� �� ���������� ��������� �����
        count++;
        number += 2;
    } while (count < n);

    std::cout << "The sum of the squares of the first " << n << " odd numbers: " << sum << std::endl;

    return 0;
}
