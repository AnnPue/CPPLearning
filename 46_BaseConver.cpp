#include <iostream>
using namespace std;
void ToLow(int n, int r);
void ToHigh(int n, int r);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int num, r, res;
        cin >> num >> r;
        if (num < 0)
        {
            cout << "-";
            num = -num;
        }
        if (r < 10)
        {
            ToLow(num, r);
            cout << endl;
        }
        else if (r > 10)
        {
            ToHigh(num, r);
            cout << endl;
        }
        else
        {
            cout << num << endl;
        }
    }
}

void ToLow(int n, int r)
{
    if (n > r - 1)
    {
        ToLow(n / r, r);
    }
    else
    {
        printf("%d", n);
        return;
    }
    printf("%d", n % r);
}

void ToHigh(int n, int r)
{
    if (n > r - 1)
    {
        ToHigh(n / r, r);
    }
    else
    {
        if (n < 10)
        {
            printf("%d", n);
        }
        else
        {
            printf("%c", n - 10 + 'A');
        }
        return;
    }
    int mod = n % r;
    if (mod < 10)
    {
        printf("%d", mod);
    }
    else
    {
        printf("%c", mod - 10 + 'A');
    }
}