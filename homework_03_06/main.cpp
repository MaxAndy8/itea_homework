//6) Написати програму, яка переводить повний оберт планети Марс навколо Сонця в земні роки.Оберти ввести з клавіатури. (Марс робить повний оберт навколо Сонця за 686 земних днів)
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
    int    mars_rotations = inputInt("Enter the number of revolutions around the Sun of Mars: ", 0);
    double earth_rotations = 686.0 * mars_rotations / 365;
    
    std::cout << mars_rotations <<" mars rotations = " << earth_rotations << " earth rotations" << std::endl;

    return 0;
}
