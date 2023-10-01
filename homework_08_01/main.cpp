//1.Ќаписати фукц≥ю, €ка отримуЇ номер м≥с€ц€ ≥ повертаЇ к≥льк≥сть дн≥в у цьому м≥с€ц≥.
//Ќаписати функц≥ю, €ка по номеру м≥с€ц€ виводить його назву.
//«а допомогою цих двох функц≥й вивести на екран назви м≥с€ц≥в та к≥льк≥сть дн≥в у кожному м≥с€ц≥.
#include <iostream>
#include <string>
//
int getDaysInMonth(int month, bool isLeapYear = false) 
{
    if (!(1 <= month || month <= 12)) {
        std::cerr << "Error: The month number is incorrect." << std::endl;
        return 0;
    }

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if ((month == 2) && (isLeapYear)) 
    {
        return 29;
    }

    return daysInMonth[month - 1];
}
//
std::string getMonthName(int month) {
    std::string monthNames[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

    if (month >= 1 && month <= 12) {
        return monthNames[month - 1];
    }
    else {
        return "Invalid month number";
    }
}

int main(int argc, char** argv)
{
    bool isLeapYear = false;
    std::cout << " - - - - - - - - - - - - - - - - -" << std::endl;
    std::cout << "Non-leap year:" << std::endl;
    for (int month = 1; month <= 12; ++month) 
    {
        std::string monthName = getMonthName(month);
        int days = getDaysInMonth(month, isLeapYear);
        std::cout << monthName << " has " << days << " days." << std::endl;
    }
    std::cout << " - - - - - - - - - - - - - - - - -" << std::endl;
    isLeapYear = true;
    std::cout << "Leap year:" << std::endl;
    for (int month = 1; month <= 12; ++month)
    {
        std::string monthName = getMonthName(month);
        int days = getDaysInMonth(month, isLeapYear);
        std::cout << monthName << " has " << days << " days." << std::endl;
    }
    std::cout << " - - - - - - - - - - - - - - - - -" << std::endl;

    return 0;
}



