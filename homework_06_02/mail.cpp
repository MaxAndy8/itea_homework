// 2) ��������� ����������� ����� � 7 �������� ���� int.��������� ���� ����������� ���������� � �������[-12.. + 50] 
// �� ������� �� �����.ϳ��������� ������� ������ �� ������� �������� ������.
#include <iostream>
#include <ctime>
#include <cstdlib> 

int main(int argc, char** argv)
{
    const int arSize = 7;
    int myAr[arSize];
    
    // ����������� ���������� ���������� �����
    std::srand(std::time(0));

    // ���������� ������ ����������� ���������� � ������� [-12..+50]
    for (int& x: myAr) 
    {
        x = std::rand() % 63 - 12; // �������� ��������� ����� �� -12 �� +50
    }
    
    //
    std::cout << "Your array:" << std::endl;
    for (int& x : myAr) 
    {
        std::cout << x << " ";
    }

    std::cout << std::endl;

    // ϳ�������� ������� ��'����� �� ������� ��������
    int positiveCount = 0;
    int negativeCount = 0;

    for (int i = 0; i < arSize; ++i) {
        if (myAr[i] > 0) {
            positiveCount++;
        }
        else if (myAr[i] < 0) {
            negativeCount++;
        }
    }

    std::cout << "Number of positive elements: " << positiveCount << std::endl;
    std::cout << "Number of negative elements: " << negativeCount << std::endl;

    return 0;
}


