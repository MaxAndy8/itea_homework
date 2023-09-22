//10) Дано масив символів.Кожну групу з повторів деякого символу  замінити одним його входженням.
#include <iostream>
#include <string>

void changeLine(char* str) {
    int length = std::strlen(str);

    if (length <= 1) {
        return; // Рядок порожній або містить лише один символ, нічого не потрібно змінювати
    }

    int writeIndex = 1; // Індекс для запису в масив (починаємо з другого символу)

    for (int readIndex = 1; readIndex < length; readIndex++) {
        if (str[readIndex] != str[readIndex - 1]) {
            str[writeIndex] = str[readIndex];
            writeIndex++;
        }
    }

    str[writeIndex] = '\0'; // Завершуємо рядок після зжатих символів
}

int main() {
    char str[] = "aaabbbccdddeee";
    std::cout << "Initial line: " << str << std::endl;

    changeLine(str);

    std::cout << "Result: " << str << std::endl;

    return 0;
}




