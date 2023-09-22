//2)  �������� 3 ��������� ������ ������ ����. ��������� �� ������� ����������. �������
//�������� ��������� ������ �� �����, ��������� ������� �� ������ �����������.
//�������� ������.
#include <iostream>

int main(int argc, char** argv)
{
    // ��������� �������� ����� ���� int
    int* dynamicInt = new int(10);
    
    // ��������� �������� ����� ���� double
    double* dynamicDouble = new double(3.141);

    // ��������� �������� ����� ���� char
    char* dynamicChar = new char('A');

    // ��������� ������� ��������� ������
    std::cout << "The value of a dynamic variable int: "    << *dynamicInt    << std::endl;
    std::cout << "The value of a dynamic variable double: " << *dynamicDouble << std::endl;
    std::cout << "The value of a dynamic variable char: "   << *dynamicChar   << std::endl;

    // ���������� ������� �� ���������� �������������
    double product = *dynamicInt * *dynamicDouble * *dynamicChar;
    double average = (*dynamicInt + *dynamicDouble + *dynamicChar) / 3.0;

    std::cout << "Product: "         << product << std::endl;
    std::cout << "Arithmetic mean: " << average << std::endl;

    std::cout << "A: " << static_cast<int>(*dynamicChar) << std::endl;

    // ��������� ���'��
    delete dynamicInt;
    delete dynamicDouble;
    delete dynamicChar;



    return 0;
}




