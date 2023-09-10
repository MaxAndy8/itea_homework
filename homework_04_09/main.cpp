//	9) дано символ.визначити чи символ є цифрою.
#include <iostream>

char inputChar(const char* prompt)
{
    std::cout << prompt << std::flush;
    for (;;) {
        std::streambuf* cinBuffer = std::cin.rdbuf();
        char charValue = static_cast<char>(cinBuffer->sgetc());

        int size = static_cast<int>(cinBuffer->in_avail());
        if (size == 2)
        {
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
    char h = inputChar("Enter a character > ");
    if('0' <= h && h <= '9')
    {
        std::cout << "'" << h << "' character is a number." << std::endl;
    }
    else
    {
        std::cout << "'" << h << "' character is not a number." << std::endl;
    }
    
    return 0;
}





