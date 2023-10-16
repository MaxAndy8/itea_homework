#include <iostream>
#include <Windows.h>
#include "ED_Map.h"
#include <string>
#include <limits>

int inputInt(const char* prompt, int min, int max)
{
    int N;
    while (true) {
        std::cout << prompt;
        if (std::cin >> N && N >= min && N <= max) {
            return N;
        }
        else {
            std::cout << "����������� ��������. ���� ����� ��������� �� ���." << std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n'); // ������������� INT_MAX ������ std::numeric_limits<std::streamsize>::max()
        }
    }
}

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    ED::ED_Map dictionary; // ��������� ��'���� ��������

    std::string languageA, languageB;
    std::cout << "������ ����� ���� A: ";
    std::cin >> languageA;
    std::cout << "������ ����� ���� B: ";
    std::cin >> languageB;

    system("cls");
    // ������� ���� ��������
    while (true) {        

        std::cout << "������ ��:\n";
        std::cout << "1. ������ �������� � ���� " << languageA << " �� ���� " << languageB << std::endl;
        std::cout << "2. ������ �������� � ���� " << languageB << " �� ���� " << languageA << std::endl;
        std::cout << "3. ���������� � " << languageA << " �� " << languageB << std::endl;
        std::cout << "4. ���������� � " << languageB << " �� " << languageA << std::endl;
        std::cout << "5. �����" << std::endl;

        int choice = 7;

        choice = inputInt("��� ����. ", 1, 5);


        if (choice == 1) {
            std::string wordA, wordB;
            std::cout << "������ ����� � ���� " << languageA << ": ";
            std::cin >> wordA;
            std::cout << "������ ���� �������� �� ���� " << languageB << ": ";
            std::cin >> wordB;
            dictionary.insertAB(wordA, wordB);
            system("cls");
        }
        else if (choice == 2) {
            std::string wordB, wordA;
            std::cout << "������ ����� � ���� " << languageB << ": ";
            std::cin >> wordB;
            std::cout << "������ ���� �������� �� ���� " << languageA << ": ";
            std::cin >> wordA;
            dictionary.insertBA(wordB, wordA);
            system("cls");
        }
        else if (choice == 3) {
            std::string wordA, wordB;
            std::cout << "������ ����� � ���� " << languageA << ": ";
            std::cin >> wordA;
            if (dictionary.getAB(wordA, wordB)) {
                std::cout << "�������� �� ���� " << languageB << ": " << wordB << std::endl;
            }
            else {
                std::cout << "����� �� �������� � ��������." << std::endl;
            }
            system("cls");
        }
        else if (choice == 4) {
            std::string wordB, wordA;
            std::cout << "������ ����� � ���� " << languageB << ": ";
            std::cin >> wordB;
            if (dictionary.getBA(wordB, wordA)) {
                std::cout << "�������� �� ���� " << languageA << ": " << wordA << std::endl;
            }
            else {
                std::cout << "����� �� �������� � ��������." << std::endl;
            }
            
        }
        else if (choice == 5) {
            break;
        }
        else {
            std::cout << "������� ����. ��������� �� ���." << std::endl;
        }
    }

    return 0;
}
