#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cout << "Введите количество комплексных ланчей (N): ";
    cin >> N;
    cout << "Введите количество блюд в каждом ланче (Q): ";
    cin >> Q;

    // Чтение матрицы стоимостей из файла
    ifstream costFile("costs.txt");
    vector<vector<int>> costs(N, vector<int>(Q));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < Q; ++j) {
            costFile >> costs[i][j];
        }
    }
    costFile.close();

    // Чтение матрицы калорийностей из файла
    ifstream calorieFile("calories.txt");
    vector<vector<int>> calories(N, vector<int>(Q));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < Q; ++j) {
            calorieFile >> calories[i][j];
        }
    }
    calorieFile.close();

    // Вычисление общей стоимости и калорийности для каждого ланча
    vector<int> totalCosts(N), totalCalories(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < Q; ++j) {
            totalCosts[i] += costs[i][j];
            totalCalories[i] += calories[i][j];
        }
    }

    // Выбор ланчей по калорийности
    int maxCalories;
    cout << "Введите максимальную допустимую калорийность: ";
    cin >> maxCalories;

    cout << "Ланчи с калорийностью ниже " << maxCalories << ":\n";
    int totalCost = 0;
    for (int i = 0; i < N; ++i) {
        if (totalCalories[i] < maxCalories) {
            cout << "Ланч " << i + 1 << ": " << totalCalories[i] << " ккал, стоимость: " << totalCosts[i] << " руб.\n";
            totalCost += totalCosts[i];
        }
    }
    cout << "Общая стоимость: " << totalCost << " руб.\n\n";

    // Выбор ланчей по стоимости
    int maxCost;
    cout << "Введите максимальную допустимую стоимость: ";
    cin >> maxCost;

    cout << "Ланчи со стоимостью ниже " << maxCost << ":\n";
    int totalCal = 0;
    for (int i = 0; i < N; ++i) {
        if (totalCosts[i] < maxCost) {
            cout << "Ланч " << i + 1 << ": " << totalCosts[i] << " руб., калорийность: " << totalCalories[i] << " ккал\n";
            totalCal += totalCalories[i];
        }
    }
    cout << "Общая калорийность: " << totalCal << " ккал\n";

    return 0;
}