//4. ¬водитьс€ в≥к ≥ стать людини.¬изначити чи людина пенс≥йного в≥ку(ж≥нки Ц п≥сл€ 55, чолов≥ки Ц п≥сл€ 60).
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
    int age;
    std::string gender;

    age = inputInt("Enter age.", 0, 200);

    do
    {
        std::cout << "Enter gender (male or female): ";
        std::cin >> gender;
    } while ( !((gender == "male") || (gender == "female")) );
       
        
    if ((gender == "male" && age > 60) || (gender == "female" && age > 55)) {
        std::cout << "This person is of retirement age." << std::endl;
    }
    else {
        std::cout << "This person is not of retirement age." << std::endl;
    }

    return 0;
}
