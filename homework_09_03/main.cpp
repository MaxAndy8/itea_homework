//3)      ��������� ��� ��������� Vector ��� ���������� ��������� ������� �� ������.�������� �� ������������
//������� ��� �������� ���� ������� �� ����������������� �� �����������..
#include <iostream>
#include <cmath>

// ��������� ��� ���������� ��������� ������� �� ������
struct Vector {
    double x; // ���������� x
    double y; // ���������� y
};

// ������� ��� ���������� ���������� ������� ���� �������
double dotProduct(const Vector& a, const Vector& b) {
    return a.x * b.x + a.y * b.y;
}

// ������� ��� ���������� ������ �������
double vectorMagnitude(const Vector& v) {
    return std::sqrt(v.x * v.x + v.y * v.y);
}

// ������� ��� �������� ����������������� ���� �������
bool arePerpendicular(const Vector& a, const Vector& b) {
    // ������� a �� b ��������������, ���� �� ��������� ������� ������� 0.
    return dotProduct(a, b) == 0.0;
}

// ������� ��� �������� ����������� ���� �������
bool areCollinear(const Vector& a, const Vector& b) {
    // ������� a �� b ��������, ���� ��������� �� ������ ������� � ������.
    double magnitudeA = vectorMagnitude(a);
    double magnitudeB = vectorMagnitude(b);
    return (a.x / magnitudeA == b.x / magnitudeB) && (a.y / magnitudeA == b.y / magnitudeB);
}

int main(int argc, char** argv)
{
    Vector vector1, vector2;

    // �������� ��������� ������� �������
    std::cout << "Enter the coordinates of the first vector (x1 y1):";
    std::cin >> vector1.x >> vector1.y;

    // �������� ��������� ������� �������
    std::cout << "Enter the coordinates of the second vector (x2 y2):";
    std::cin >> vector2.x >> vector2.y;

    // �������� ����������������� �� ����������� �������
    bool perpendicular = arePerpendicular(vector1, vector2);
    bool collinear     = areCollinear(vector1, vector2);

    if (perpendicular) {
        std::cout << "Vectors are perpendicular." << std::endl;
    }
    else {
        std::cout << "The vectors are not perpendicular." << std::endl;
    }

    if (collinear) {
        std::cout << "Vectors are collinear." << std::endl;
    }
    else {
        std::cout << "Vectors are not collinear." << std::endl;
    }
    return 0;
}














