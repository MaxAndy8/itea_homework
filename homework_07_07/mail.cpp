//7)  ƒано р€док.«ам≥нити кожний символ Т + Т у р€дку на символ Т - Т.
#include <iostream>

int main(int argc, char** argv)
{
    char str[100]; // ¬идал≥ть розм≥р масиву або встанов≥ть досить великим, щоб вм≥стити введений р€док
    std::cout << "Enter the line: ";

    std::cin.getline(str, sizeof(str));

    // «ам≥нюЇмо символи '+' на '-'
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '+') {
            str[i] = '-';
        }
    }
    std::cout << "Changed line: " << str << std::endl;

    return 0;
}








