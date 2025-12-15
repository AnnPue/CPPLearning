#include <stdio.h>
#include <string.h>
    /*
    函数功能：比较两个字符串的字典序大小。
    输入参数：
        str1: 指向第一个字符串的指针。
        str2: 指向第二个字符串的指针。
    返回值：
        如果str1 < str2，返回负值；
        如果str1 == str2，返回0；
        如果str1 > str2，返回正值。
    */
int StrCmp(const char* str1, const char* str2) {

    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

int StrCmp2(char *str1, char *str2){
    int i = -1;
    do{
        i++;
        if(str1[i] > str2[i]) return 1; // str1大于str2返回1
        else if(str1[i] < str2[i]) return -1; // str1小于str2返回-1
    }while (str1[i] && str2[i]);
    return 0; // 相等返回0
}