//1)      Оголосити тип структури Drib для збереження звичайного дробу.
//Написати та протестувати функції для додавання та віднімання двох звичайних дробів.
#include <iostream>

struct Drib 
{
    int numerator;   // Чисельник
    int denominator; // Знаменник
};

// Функція для знаходження найбільшого спільного знаменника
int findGCD(int a, int b) 
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Функція для спрощення дробу
void simplify(Drib& fraction) 
{
    int gcd = findGCD(fraction.numerator, fraction.denominator);
    fraction.numerator /= gcd;
    fraction.denominator /= gcd;
}

// Функція для додавання двох дробів
Drib addDrib(const Drib& a, const Drib& b) 
{
    Drib result;

    result.numerator   = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;

    simplify(result);
    return result;
}

// Функція для віднімання двох дробів
Drib subtractDrib(const Drib& a, const Drib& b) 
{
    Drib result;

    result.numerator   = a.numerator * b.denominator - b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;

    simplify(result);
    return result;
}

int main(int argc, char** argv)
{
    Drib fraction1, fraction2, sum, difference;

    // Input of the first fraction
    std::cout << "Enter the first fraction (numerator and denominator separated by a space): ";
    std::cin >> fraction1.numerator >> fraction1.denominator;

    // Input of the second fraction
    std::cout << "Enter the second fraction (numerator and denominator separated by a space): ";
    std::cin  >> fraction2.numerator >> fraction2.denominator;

    // Add and subtract fractions
    sum        = addDrib(fraction1, fraction2);
    difference = subtractDrib(fraction1, fraction2);

    // Display the results
    std::cout << "Sum of fractions: "        << sum.numerator        << "/" << sum.denominator        << std::endl;
    std::cout << "Difference of fractions: " << difference.numerator << "/" << difference.denominator << std::endl;

    return 0;
}











