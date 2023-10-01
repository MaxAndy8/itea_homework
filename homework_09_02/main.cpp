//2)      ��������� ��� ��������� Complex ��� ���������� ������������ �����.�������� ��
//������������ ������� ��� ��������� �� �������� ���� ����������� �����.
#include <iostream>

// ��������� ��� ���������� ������������ �����
struct Complex 
{
    double real;      // ĳ���� �������
    double imaginary; // ����� �������
};

// ������� ��� ��������� ���� ����������� �����
Complex addComplex(const Complex& a, const Complex& b) 
{
    Complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}

// ������� ��� �������� ���� ����������� �����
Complex subtractComplex(const Complex& a, const Complex& b) 
{
    Complex result;
    result.real = a.real - b.real;
    result.imaginary = a.imaginary - b.imaginary;
    return result;
}

int main(int argc, char** argv)
{
    Complex num1, num2, sum, difference;

    // �������� ������� ������������ �����
    std::cout << "Enter the first complex number (real and imaginary parts separated by a space): ";
    std::cin >> num1.real >> num1.imaginary;

    // �������� ������� ������������ �����
    std::cout << "Enter the second complex number (real and imaginary parts separated by a space): ";
    std::cin >> num2.real >> num2.imaginary;

    // ��������� �� �������� ����������� �����
    sum        = addComplex(num1, num2);
    difference = subtractComplex(num1, num2);

    // ��������� ����������
    std::cout << "Sum of complex numbers: "        << sum.real        << " + " << sum.imaginary        << "i" << std::endl;
    std::cout << "Difference of complex numbers: " << difference.real << " + " << difference.imaginary << "i" << std::endl;
    return 0;
}




















