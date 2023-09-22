//9) ���� �����.������� � ����� ����� ��������� ����� ��������� ��� �������(���� �z�, �Z� ��������� ������ �a�, �A�).���������,
//�����  �Zebra has two colors� �� ������������� �� �Afcsb ibt uxp dpmpst�.�������� �������� ������� ���������� �����.
#include <iostream>
#include <cstring>

void changeLine(char* str) {
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        if (std::isalpha(str[i])) { // ����������, �� ������ � ������
            char base = (std::isupper(str[i])) ? 'A' : 'a'; // ��������� ������ ����� (A ��� a)
            str[i] = base + ((str[i] - base + 1) % 26); // �������� ����� �� �������� �� ��������
        }
    }
}

int main() {
    char str[100];
    std::cout << "Enter the line: ";

    std::cin.getline(str, sizeof(str));

    changeLine(str);

    std::cout << "The resulting string: " << str << std::endl;

    return 0;
}



