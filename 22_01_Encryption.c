/*
本程序可获得字符串，并对其中字母做处理：将其减少一个整数key值*/
#include <stdio.h>
#include <string.h>

int main(){
    printf("有一种加密算法，若明文是字母则将其减少一个\
整数key值(整数【1，10】之间），若不是则保持不变。\n");
    printf("请输入一段明文，根据key，加密后并输出其密文。\n");
    printf("当输入key值为10时，程序退出\n");
    int key = -1;
    int i;
    char letters[10000];
    while(1){
        printf("请输入key值(整数【1，10】之间):\n");

        while (scanf(" %d", &key) != 1 || key < 1 || key > 10){//获得key并检查
            while (getchar() != '\n');
            printf("输入的数值不对，【1，10】之间，key为10时，程序退出。\n");
        }
        if (key == 10) break;

        printf("key值是：%d\n", key);//回显key值
        printf("请输入明文字符串：\n");
        while (getchar() != '\n');//清空缓存，防止干扰后面逻辑

        //从stdin获得一行字符，存入letters
        fgets(letters, sizeof(letters), stdin);
        printf("明文字符串是：%s", letters);//回显，以字符串格式输出字符数组
        for (i = 0; i < strlen(letters); i++){//strlen获得字符串中字符的个数，不包括结尾的\0
            if (('A' <= letters[i] && letters[i] <= 'Z')\
            || ('a' <= letters[i] && letters[i] <= 'z')) {//若是字母，则处理
                letters[i] -= key;//将字符减少一个整数key值
            }
        }
        printf("加密后的密文字符串是：%s", letters);
    }
    printf("key值是：10\n");
    //system("pause");
    return 0;
}
