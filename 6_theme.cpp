#include <iostream>
using namespace std;

bool checkSegment(double x1, double y1, double x2, double y2, 
                 double cx, double cy, double r) {

    bool p1 = (x1-cx)*(x1-cx) + (y1-cy)*(y1-cy) <= r*r;
    bool p2 = (x2-cx)*(x2-cx) + (y2-cy)*(y2-cy) <= r*r;
    return p1 && p2;
}

int main() {
    double r, cx, cy, x1, y1, x2, y2;
    char again;

    do {
        cout << "Введите радиус и центр окружности (r cx cy): ";
        cin >> r >> cx >> cy;
        cout << "Введите концы отрезка (x1 y1 x2 y2): ";
        cin >> x1 >> y1 >> x2 >> y2;

        if(checkSegment(x1, y1, x2, y2, cx, cy, r)) {
            cout << "Отрезок внутри окружности\n";
        } else {
            cout << "Отрезок снаружи\n";
        }

        cout << "Еще раз? (y/n): ";
        cin >> again;
    } while(again == 'y');

    return 0;
}