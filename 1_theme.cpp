#include <iostream>

int main() {
    
    double candyPrice, cookiePrice, applePrice;
    std::cout << "Введите стоимость 1 кг конфет: ";
    std::cin >> candyPrice;
    std::cout << "Введите стоимость 1 кг печенья: ";
    std::cin >> cookiePrice;
    std::cout << "Введите стоимость 1 кг яблок: ";
    std::cin >> applePrice;

    double X, Y, Z;
    std::cout << "Введите количество кг конфет: ";
    std::cin >> X;
    std::cout << "Введите количество кг печенья: ";
    std::cin >> Y;
    std::cout << "Введите количество кг яблок: ";
    std::cin >> Z;

    double totalCost = (candyPrice * X) + (cookiePrice * Y) + (applePrice * Z);

    std::cout << "Общая стоимость покупки: " << totalCost << std::endl;

    return 0;
}