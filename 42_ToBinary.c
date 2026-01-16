#include <stdio.h>

void ToBinary(int n);

int main(){
    int number;
    printf("请输入一个十进制整数: ");
    scanf("%d", &number);
    printf("该数的二进制表示为: ");
    ToBinary(number);
    printf("\n");
    return 0;
}

void ToBinary(int n){
    if (n > 1){
        ToBinary(n / 2);
    }
    else {
        printf("%d", n);
        return;
    }
    printf("%d", n % 2);
    //return;
}