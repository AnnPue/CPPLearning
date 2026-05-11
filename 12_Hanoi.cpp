#include <iostream>
using namespace std;

// n: number of disks
// from: the source pole
// assist: the auxiliary pole
// to: the destination pole
void Hanoi(int n, char from, char assist, char to)
{
    if (n == 1)
    {
        printf("move %d from %c to %c\n", n, from, to);
        return;
    }
    Hanoi(n - 1, from, to, assist);
    printf("move %d from %c to %c\n", n, from, to);
    Hanoi(n - 1, assist, from, to);
}

int main()
{
    int n;
    cout << "Enter the number of disks: \n";
    cin >> n;
    // L: left, M: middle, R: right
    Hanoi(n, 'L', 'M', 'R');
    return 0;
}
