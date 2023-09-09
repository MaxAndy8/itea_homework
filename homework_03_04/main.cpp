// 4)Ви купили в магазині 4 різні товари.Дані ціни кожного товару(константні значення) та кількість товару, який був придбаний.Обрахувати та вивести вартість покупки.Забазпечити вивід у вигляді чеку.
#include <iostream>
#include <sstream>
//#include <chrono>
#include <ctime>
#include <iomanip>


int main(int argc, char** argv)
{
    struct tovar
    {
        std::string name;
        float quantity = 0;
        float price    = 0;
    };

    const tovar t[] = 
    {
        {"Snickers"     , 5, 20.35f},
        {"Bounty"       , 4, 18.35f},
        {"Twix"         , 3, 22.55f},
        {"NESTLE KITKAT", 7, 20.00f}    
    };


    time_t rawTime;
    struct tm timeInfo;
    char buffer[80];

    time(&rawTime); // Отримуємо поточний час

    if (localtime_s(&timeInfo, &rawTime) == 0) { // Перетворення часу в локальний час
        if (strftime(buffer, sizeof(buffer), "%c", &timeInfo) > 0) { // Форматування часу
            
        }
    }
    
    std::cout << "          SHOP          " << std::endl;
    std::cout << buffer << std::endl;
    std::cout << "========================" << std::endl;

    int    k = 0;
    double total_sum = 0;
    for (const tovar& ele : t)
    {
        k++;
        double sum = static_cast<double>(ele.quantity) * ele.price;
        std::cout << k << ". " << ele.name << std::endl;
        
        std::stringstream sstr;        
        sstr << ele.quantity << "  x   " << std::fixed << std::setprecision(2) << ele.price << " = " <<  sum << "$" << std::endl;

        std::cout.width(25);
        std::cout << sstr.str() << std::endl;

        total_sum += sum;
    }
    std::cout << "========================" << std::endl;
    std::cout.width(17);
    std::cout << "TOTAL: " << std::fixed << std::setprecision(2) << total_sum << "$" << std::endl;
   
    return 0;
}



