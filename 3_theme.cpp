#include <iostream>
using namespace std;

int main() {
    char col1, col2;
    int row1, row2;
    char choice;

    do {
        cout << "Введите первое поле ферзя (например, e2): ";
        cin >> col1 >> row1;
        cout << "Введите второе поле (например, f5): ";
        cin >> col2 >> row2;

        int x1 = tolower(col1) - 'a' + 1;
        int x2 = tolower(col2) - 'a' + 1;

        bool isThreat = (x1 == x2) ||          // Та же вертикаль
                        (row1 == row2) ||       // Та же горизонталь
                        (abs(x1 - x2) == abs(row1 - row2));  // Та же диагональ

        if(isThreat) {
            cout << "Ферзь угрожает этому полю!\n";
        } else {
            cout << "Ферзь НЕ угрожает этому полю.\n";
        }

        cout << "Проверить еще раз? (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');

    return 0;
}