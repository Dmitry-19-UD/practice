#include <iostream>
#include <string>

using namespace std;

int main() {
    int K; 
    cout << "Введите себестоимость фотографии (K руб.): ";
    cin >> K;

    int n;
    cout << "Введите количество записей в журнале: ";
    cin >> n;

    string journal[n]; 
    int profit = 0;

    cout << "Введите записи журнала (дачник или обитатель):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> journal[i];
    }

    for (int i = 0; i < n; i++) {
        if (journal[i] == "дачник") {
            profit += 2 * K; 
        } else if (journal[i] == "обитатель") {
            profit -= K; 
        }
    }

    cout << "Прибыль Шарика за день: " << profit << " руб." << endl;

    if (profit > 0) {
        cout << "Шарик в плюсе!" << endl;
    } else if (profit < 0) {
        cout << "Шарик в убытке :(" << endl;
    } else {
        cout << "Шарик вышел в ноль." << endl;
    }

    return 0;
}