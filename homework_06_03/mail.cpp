//3) ���������, �������������� ����������� ���������� �� ������� ����������� ����� � 7 �������� ���� long.��������� ���� ������ �������� ������
#include <iostream>
#include <ctime>
#include <cstdlib> 

int main(int argc, char** argv)
{
    const int arSize = 7;
    long myAr[arSize]{0};
   
    // ����������� ���������� ���������� ����� �� ����� ����
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // ���������� ������ ����������� ���������� 
    for (auto& x : myAr)
    {
        x = static_cast<long>(std::rand());
    }

    //
    std::cout << "Your array:" << std::endl;
    for (auto& x : myAr)
    {
        std::cout << x << " ";
    }

    std::cout << std::endl;

    // ����������� ���� ������ �������� ������
    double sumOfEven = 0;
    for (auto& x : myAr) {
        if (x % 2 == 0) {
            sumOfEven += x;
        }
    }

    // ��������� ���� ������ �������� �� �����
    std::cout << "The sum of even elements: " << sumOfEven << std::endl;
   
    return 0;
}
