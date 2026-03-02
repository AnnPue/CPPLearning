#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        printf("case #%d:\n", i);
        int c, w, cnt = 0;
        cin >> c >> w;
        int min = pow(10, c - 1) + w, max = pow(10, c) - 10 + w;
        for (int j = min; j <= max; j += 10)
        {
            if (j % 3 == 0)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}