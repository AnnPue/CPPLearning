#include <stdio.h>
#include <string.h>

int main(){
    printf("请输入key值（整数【1，10】之间：\n");
    int key;
    while (scanf(" %d", key) != 1 || key < 1 || key > 10){
        while (getchar() != '\n');
        printf("输入的数值不对，【1，10】之间，key为10时，程序退出。\n"); 
    }
    printf("key值是：%d\n", key);
    printf("请输入明文字符串：\n");
    string plaintext;
    scanf("%s", plaintext);

    return 0;
}