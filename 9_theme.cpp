#include <iostream>
#include <climits>

using namespace std;

int sumRow(int row[], int m) {
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        sum += row[i];
    }
    return sum;
}

int findMinIndex(int arr[], int n) {
    int minIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int findMaxIndex(int arr[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    int n, m;
    cout << "Введите количество строк (n) и столбцов (m): ";
    cin >> n >> m;

    int matrix[n][m];
    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    int sums[n]; 
    for (int i = 0; i < n; ++i) {
        sums[i] = sumRow(matrix[i], m);
        cout << "Сумма строки " << i + 1 << ": " << sums[i] << endl;
    }

    int minIndex = findMinIndex(sums, n);
    int maxIndex = findMaxIndex(sums, n);

    cout << "Наименьшая сумма: " << sums[minIndex] << " (строка " << minIndex + 1 << ")\n";
    cout << "Наибольшая сумма: " << sums[maxIndex] << " (строка " << maxIndex + 1 << ")\n";

    return 0;
}