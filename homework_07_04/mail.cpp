//4) ���� ����� ����� �����.���� ������ ������� ������ � ������ ������, �� �������� ��
//������ �� ���� �����, ������ � �������(�������� ������ �����).
#include <iostream>

int main(int argc, char** argv)
{
    // ���������� � ����������� ���������� ������ ����� �����
    int A[] = { 4, 2, 7, 8, 9, 6, 1 };
    int n = sizeof(A) / sizeof(A[0]); // ��������� ������ ������

    // ��������, �� � ������ ������� ������ �� ��������
    bool isFirstElementEven = (A[0] % 2 == 0);

    int id = 0;
    // ����������� ����� ����� � ���� �������� ��� ����������
    for (int i = 1; i < n; i++) {
        if ((isFirstElementEven && A[i] % 2 == 1) || (!isFirstElementEven && A[i] % 2 == 0)) {
            A[id] = A[i];
            id++;
        }
    }

    for (int i = id; i < n; i++) {
        A[i] = 0;
    }

    // ��������� ���������� ������
    std::cout << "Updated array: ";
    for (int i = 0; i < n; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}




