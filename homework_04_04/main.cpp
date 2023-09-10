//	4) дано 3 числа.вивести true, якщо серед них є додатні та парні.
#include <iostream>
#include <string> 

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
    const int size_x = 3;
    int x[size_x];

    for (int i = 0; i < size_x; i++)
    {
        std::string pr;
        pr.append("Enter X").append(std::to_string(i)).append(". ");

        x[i] = inputInt(pr.c_str());
    }

    bool is_even_number(false);
    bool is_positive_number(false);

    for (int i = 0; i < size_x; i++)
    {
        if ((x[i] % 2) == 0)
            is_even_number = true;
        if (x[i] > 0)
            is_positive_number = true;
    }

    if(is_even_number && is_positive_number)
        std::cout << "Among the numbers there are positive ones, and among them there are even ones: true"<< std::endl;
    /*
    З умови задачі незрозуміло чи при перевірці числа має перевірятися дві умови за раз чи окремо.
    Тому дане рішення було зроблене з припущенням того що ми перевіряємо ці числа зпершу на те чи серед них є
    додатні, а потім чи серед них є парні. 
    Тобто:
    -4  5 -3 =>  true
    -3  5  1 => false
     4  5  3 =>  true    
    */
    return 0;
}