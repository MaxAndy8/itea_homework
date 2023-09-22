//8) ���� �����.�������� �������, ��� ������� ������� ���� � �����.��������� ������
//�������.
#include <iostream>

int countDigits(const char* str) {
    int count = 0;

    while (*str) { // ����������� ����� ������ � �����
        if (std::isdigit(*str)) { // ���� ������ � ������
            count++;
        }
        str++; // ��������� �������� �� ��������� ������
    }

    return count;
}

int main(int argc, char** argv)
{
    char str[100];
    std::cout << "Enter the line: ";

    std::cin.getline(str, sizeof(str));

    int digitCount = countDigits(str);

    std::cout << "The number of digits in a row: " << digitCount << std::endl;

    return 0;
}




