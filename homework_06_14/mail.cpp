// 14) Дано одновимірний масив.Циклічно зрушити(зсунути) масив на К елементів вліво або вправо(в залежності від 
// обраної дії користувача)

#include <iostream>
#include <string> 

const int maxSize = 100; // Максимальний розмір масиву (змініть за потребою)


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

void rotateLeft(int arr[], int n, int k) {
    int temp[maxSize];
    for (int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }

    for (int i = k; i < n; i++) {
        arr[i - k] = arr[i];
    }

    for (int i = n - k, j = 0; i < n; i++, j++) {
        arr[i] = temp[j];
    }
}

void rotateRight(int arr[], int n, int k) {
    int temp[maxSize];
    for (int i = n - k, j = 0; i < n; i++, j++) {
        temp[j] = arr[i];
    }

    for (int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }

    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[maxSize];
    int n; // Розмір масиву
    int k; // Кількість позицій для зсуву

    // Введення розміру масиву
    n = inputInt("Enter the size of the array A (an even number).", 2, maxSize);

    const int minValue = std::numeric_limits<int>::min();
    const int maxValue = std::numeric_limits<int>::max();
    // 
    std::cout << "Enter " << n << " of integers:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::string pr;
        pr.append("arr[").append(std::to_string(i)).append("].");
        arr[i] = inputInt(pr.c_str());
    }
    std::cout << std::endl;

    // Введення кількості позицій для зсуву
    k = inputInt("Enter the number of positions to shift: ", 1, n);

    // Вибір напрямку зсуву (вліво або вправо)

    char direction = inputChar("Select the shift direction (L - left, R - right):");

    switch (direction)
    {
    case 'L':
    case 'l':
        rotateLeft(arr, n, k);
        break;
    case 'R':
    case 'r':
        rotateRight(arr, n, k);
        break;
    default:
        std::cout << "Incorrect shift direction. Enter 'L' or 'R'." << std::endl;
        break;
    }
    
    // Виведення масиву після зсуву
    std::cout << "Array after shift: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}