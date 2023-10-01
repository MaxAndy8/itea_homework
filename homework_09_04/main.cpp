//4)      ��������� ��� ��������� Point ��� ���������� ��������� ����� � �������..�������� �� ������������
//������� ��� ��������� ������ �� ����� ������� �� ������ �� ����� �� �������
//���������.
#include <iostream>
#include <cmath>

struct Point 
{
    double x; // ���������� x
    double y; // ���������� y
    double z; // ���������� z
};

// ������� ��� ���������� ������ �� ����� �������
double distanceBetweenPoints(const Point& p1, const Point& p2) 
{
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

// ������� ��� ���������� ������ �� ����� �� ������� ���������
double distanceToOrigin(const Point& p) 
{
    return std::sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

int main() 
{
    Point point1, point2;

    std::cout << "Enter the coordinates of the first point (x1 y1 z1): ";
    std::cin >> point1.x >> point1.y >> point1.z;

    std::cout << "Enter the coordinates of the second point (x2 y2 z2): ";
    std::cin >> point2.x >> point2.y >> point2.z;

    // ���������� ������ �� ����� �������
    double distance = distanceBetweenPoints(point1, point2);

    // ���������� ������ �� ����� �� ������� ���������
    double distanceToOrigin1 = distanceToOrigin(point1);
    double distanceToOrigin2 = distanceToOrigin(point2);

    std::cout << "Distance between points: " << distance << std::endl;
    std::cout << "Distance from the first point to the origin: " << distanceToOrigin1 << std::endl;
    std::cout << "Distance from the second point to the origin: " << distanceToOrigin2 << std::endl;

    return 0;
}



