#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 10;

void inputArray(int a[], int n) { cout << "Введите " << n << " чисел: "; for(int i=0;i<n;i++) cin>>a[i]; }
bool hasZero(int a[], int n) { for(int i=0;i<n;i++) if(a[i]==0) return 1; return 0; }
void printArray(int a[], int n) { for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl; }

int countAroundZeros(int a[], int n) {
    int f=-1, l=-1, i;
    for(i=0;i<n;i++) if(a[i]==0) {f=i; break;}
    for(i=n-1;i>=0;i--) if(a[i]==0) {l=i; break;}
    return f==-1 ? -1 : (f==0&&l==n-1 ? 0 : f+(n-l-1));
}

void trimArray(int a[], int &n) {
    int f=-1, l=-1, i;
    for(i=0;i<n;i++) if(a[i]==0) {f=i; break;}
    for(i=n-1;i>=0;i--) if(a[i]==0) {l=i; break;}
    if(f==-1) return;
    for(i=0;i<l-f+1;i++) a[i]=a[f+i];
    n=l-f+1;
}

void generateArray(int a[], int n) { srand(time(0)); for(int i=0;i<n;i++) a[i]=rand()%5; }

bool newBetweenZeros(int src[], int n, int* &dst, int &sz) {
    int f=-1, l=-1, i;
    for(i=0;i<n;i++) if(src[i]==0) {f=i; break;}
    for(i=n-1;i>=0;i--) if(src[i]==0) {l=i; break;}
    if(f==-1) return 0;
    sz=l-f+1; dst=new int[sz];
    for(i=0;i<sz;i++) dst[i]=src[f+i];
    return 1;
}

int main() {
    int arr[SIZE], n=SIZE, *newArr, newSize, choice;
    cout << "1. Ввод 2. Генерация\nВыбор: "; cin >> choice;
    choice==1 ? inputArray(arr,n) : generateArray(arr,n);
    
    cout << "Массив: "; printArray(arr,n);
    cout << (hasZero(arr,n)?"Есть нули\n":"Нет нулей\n");
    cout << "Элементов вокруг нулей: " << countAroundZeros(arr,n) << endl;
    
    trimArray(arr,n);
    cout << "После обрезки: "; printArray(arr,n);
    
    if(newBetweenZeros(arr,n,newArr,newSize)) {
        cout << "Между нулями: "; printArray(newArr,newSize);
        delete[] newArr;
    } else cout << "Не удалось создать массив\n";
    
    return 0;
}