//7)  ���� �����.������� ������ ������ � + � � ����� �� ������ � - �.
#include <iostream>

int main(int argc, char** argv)
{
    char str[100]; // ������� ����� ������ ��� ��������� ������ �������, ��� ������� �������� �����
    std::cout << "Enter the line: ";

    std::cin.getline(str, sizeof(str));

    // �������� ������� '+' �� '-'
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '+') {
            str[i] = '-';
        }
    }
    std::cout << "Changed line: " << str << std::endl;

    return 0;
}








