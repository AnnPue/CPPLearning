/*
本程序可以根据输入在原字符串中查找子串，并将原串中的子串替换为新串。
对各种异常情况，如、输入过长字符串等做了一些处理。
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

const int MAX_LEN = 2000;// 字符串最大长度
const int STR_COUNT = 3;

int Find(char*, char*, int*);//找子串
void ClearIn();//清空输入流
void FreeMemory(char **);
bool Alloc(char **);
void Solve(char **);

int main(){
    printf("=====================================\n");
    printf("       字符串综合查找替换应用\n");
    printf("=====================================\n");
    char *str[STR_COUNT];
    if (!Alloc(str)) {
        return -1; // 内存分配失败，退出程序
    }
    Solve(str);
    return 0;
}

//找子串
int Find(char* str, char* sub, int *i){//从*i索引开始找子串
    if (strlen(str) < strlen(sub)) return -1;//原字符串短于子串，不可能找到，返回-1
    int j;
    for (; *i <= strlen(str) - strlen(sub); ++ *i){//从*i开始遍历字符串
        for (j = *i; j < strlen(sub) + *i; ++j){//循环一个子串的长度
            if (str[j] != sub[j - *i]){//发现一个字符不同就退出循环再找
                break;
            }
            return *i;//找到了返回对应索引
        }
    }
    return -1;//未找到返回-1
}

void ClearIn(){
    while (getchar() != '\n');
}

// 释放字符串内存
void FreeMemory(char *str[]){
    int i = STR_COUNT;
    while (i--) {
        free(str[i]);
        str[i] = NULL;
    }
}

// 分配字符串内存
bool Alloc(char *str[]){
    int i = STR_COUNT;
    // 初始化字符串内存
    while (i--){
        str[i] = (char*)malloc(MAX_LEN * sizeof(char));// 分配足够内存，每个字符串最大长度1999
        if (str[i] == NULL){
            printf("内存分配失败，程序退出!\n");
            FreeMemory(str);
            return false;
        }
        memset(str[i], 0, MAX_LEN * sizeof(char));// 清零,防止垃圾值干扰
    }
    return true;
}

void Replace(char* str, char* oldSub, char* newSub){
    char buffer[MAX_LEN];// 临时缓冲区
    char *insertPoint = &buffer[0];// 插入点
    const char *temp = str;// 临时指针
    size_t oldLen = strlen(oldSub);// 旧子串长度
    size_t newLen = strlen(newSub);// 新子串长度

    while (1) {
        const char *p = strstr(temp, oldSub);
        if (p == NULL) {
            strcpy(insertPoint, temp);
            break;
        }
        memcpy(insertPoint, temp, p - temp);
        insertPoint += p - temp;
        memcpy(insertPoint, newSub, newLen);
        insertPoint += newLen;
        temp = p + oldLen;
    }
    strcpy(str, buffer);
}

void Solve(char **str){
    while (1){
        int i = 0;
        for (; i < STR_COUNT; ++i){
            if (i == 0){
                printf("请输入原串s1，输入\"END\"时，程序退出\n");
            }
            else{
                printf("请输入查找串s%d\n", i + 1);
            }
            fgets(str[i], MAX_LEN, stdin);
            if (strcmp(str[0], "END\n") == 0){
                FreeMemory(str);
                system("pause");
                return;
            }
            char *newline = strchr(str[i], '\n');// 查找换行符，strchr返回指向换行符的指针
            if (newline == NULL) ClearIn();// 找不到换行符，说明输入超过最大长度，清空输入流
            str[i][strcspn(str[i], "\n")] = '\0'; // 去除换行符
            printf("原串s%d的长度是%zu，内容是：%s\n", i + 1, strlen(str[i]), str[i]);
        }
        int index = 0;//索引置0
        while (Find(str[0], str[1], &index) + 1){//当函数返回-1时退出循环
            Replace(str[0], str[1], str[2]);
            index += strlen(str[1]);//从找到的子串后面开始再找
        }
        printf("替换后s1的长度是%zu，内容是：%s\n", strlen(str[0]), str[0]);
    }
}
