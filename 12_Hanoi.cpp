#include <iostream>
using namespace std;

void Hanoi(int n, char from, char assist, char to){
    if (n == 1){
        printf("move %d from %c to %c\n", n, from, to);
        return;
    }
    Hanoi(n - 1, from, to, assist);
    printf("move %d from %c to %c\n", n, from, to);
    Hanoi(n - 1, assist, from, to);

}

int main(){
    cout << "请输入汉诺塔层数" << endl;
    int n=4;
    //cin >> n;
    Hanoi(n, 'l', 'm', 'r');
    return 0;
}
