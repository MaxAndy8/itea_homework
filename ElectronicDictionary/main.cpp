#include <iostream>
#include <Windows.h>
#include "ED_Map.h"

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    ED::ED_Map dictionary; // Створення об'єкту словника

    std::string languageA, languageB;
    std::cout << "Введіть назву мови A: ";
    std::cin >> languageA;
    std::cout << "Введіть назву мови B: ";
    std::cin >> languageB;

    system("cls");
    // Головне меню програми
    while (true) {        

        std::cout << "Оберіть дію:\n";
        std::cout << "1. Додати переклад з мови " << languageA << " на мову " << languageB << std::endl;
        std::cout << "2. Додати переклад з мови " << languageB << " на мову " << languageA << std::endl;
        std::cout << "3. Перекласти з " << languageA << " на " << languageB << std::endl;
        std::cout << "4. Перекласти з " << languageB << " на " << languageA << std::endl;
        std::cout << "5. Вийти" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string wordA, wordB;
            std::cout << "Введіть слово з мови " << languageA << ": ";
            std::cin >> wordA;
            std::cout << "Введіть його переклад на мову " << languageB << ": ";
            std::cin >> wordB;
            dictionary.insertAB(wordA, wordB);
            system("cls");
        }
        else if (choice == 2) {
            std::string wordB, wordA;
            std::cout << "Введіть слово з мови " << languageB << ": ";
            std::cin >> wordB;
            std::cout << "Введіть його переклад на мову " << languageA << ": ";
            std::cin >> wordA;
            dictionary.insertBA(wordB, wordA);
            system("cls");
        }
        else if (choice == 3) {
            std::string wordA, wordB;
            std::cout << "Введіть слово з мови " << languageA << ": ";
            std::cin >> wordA;
            if (dictionary.getAB(wordA, wordB)) {
                std::cout << "Переклад на мову " << languageB << ": " << wordB << std::endl;
            }
            else {
                std::cout << "Слово не знайдено у словнику." << std::endl;
            }
            system("cls");
        }
        else if (choice == 4) {
            std::string wordB, wordA;
            std::cout << "Введіть слово з мови " << languageB << ": ";
            std::cin >> wordB;
            if (dictionary.getBA(wordB, wordA)) {
                std::cout << "Переклад на мову " << languageA << ": " << wordA << std::endl;
            }
            else {
                std::cout << "Слово не знайдено у словнику." << std::endl;
            }
            
        }
        else if (choice == 5) {
            break;
        }
        else {
            std::cout << "Невірний вибір. Спробуйте ще раз." << std::endl;
        }
    }

    return 0;
}
