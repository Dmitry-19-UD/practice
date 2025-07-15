#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double account = 1.0; 
    int age = 5;
    const double interest = 0.08; 

    cout << "Возраст | Подарок | Начислено % | Состояние счета" << endl;
    cout << "----------------------------------------------" << endl;

    while (age <= 18) {
        double gift = age; 
        double earned = account * interest; 
        
        cout << setw(4) << age << "   |" 
             << setw(6) << gift << "  |" 
             << setw(9) << fixed << setprecision(2) << earned << "   |" 
             << setw(10) << account + earned + gift << endl;


        account += earned + gift;
        
        age++; 
    }

    cout << "\nК 18 годам на счету будет: $" 
         << fixed << setprecision(2) << account << endl;

    return 0;
}