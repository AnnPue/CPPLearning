#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a, b;
    while (true)
    {
        cout << "人数上限：";
        cin >> a;
        if (a == -1)
            return 0;
        cout << "预选人数：";
        cin >> b;
        double res;
        res = (10.0 * b - 5.0 * a) * log(b - a) / (0.0 + a);
        printf("豆子1：%.2lf\n", res);
        res = (100.0 * b - 100.0 * a) / (0.0 + b);
        printf("豆子2：%.2lf\n", res);
        putchar('\n');
    }
}