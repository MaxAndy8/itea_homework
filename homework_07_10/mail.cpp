//10) ���� ����� �������.����� ����� � ������� ������� �������  ������� ����� ���� ����������.
#include <iostream>
#include <string>

void changeLine(char* str) {
    int length = std::strlen(str);

    if (length <= 1) {
        return; // ����� ������� ��� ������ ���� ���� ������, ����� �� ������� ��������
    }

    int writeIndex = 1; // ������ ��� ������ � ����� (�������� � ������� �������)

    for (int readIndex = 1; readIndex < length; readIndex++) {
        if (str[readIndex] != str[readIndex - 1]) {
            str[writeIndex] = str[readIndex];
            writeIndex++;
        }
    }

    str[writeIndex] = '\0'; // ��������� ����� ���� ������ �������
}

int main() {
    char str[] = "aaabbbccdddeee";
    std::cout << "Initial line: " << str << std::endl;

    changeLine(str);

    std::cout << "Result: " << str << std::endl;

    return 0;
}




