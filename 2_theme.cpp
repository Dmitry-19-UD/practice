#include <iostream>
using namespace std;

int main() {
    int sum;
    char choice;

    do {
        cout << "Введите сумму (не более 100 рублей): ";
        cin >> sum;

        if(sum < 1 || sum > 100) {
            cout << "Ошибка! Сумма должна быть от 1 до 100 рублей.\n";
            continue;
        }

        cout << sum << " ";

        if(sum >= 11 && sum <= 19) {
            cout << "рублей";
        }
        else {
          
            int lastDigit = sum % 10;

            if(lastDigit == 1) {
                cout << "рубль";
            }
            else if(lastDigit >= 2 && lastDigit <= 4) {
                cout << "рубля";
            }
            else {
                cout << "рублей";
            }
        }

        cout << "\nПовторить? (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');

    return 0;
}