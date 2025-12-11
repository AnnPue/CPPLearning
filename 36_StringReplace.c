/*
本程序可以根据输入在原字符串中查找子串，并将原串中的子串替换为新串。
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

const int MAX_LEN = 2000;           // 字符串最大长度
const int STR_COUNT = 3;            // 字符串个数

int Find(char*, char*, int*);       // 从*i索引开始找子串
void FreeMemory(char **);           // 释放字符串内存
bool Alloc(char **);                // 分配字符串内存
void Replace(char*, char*, char*);  // 字符串替换
void Solve(char **);                // 解决方案主函数

int main(){
    printf("=====================================\n");
    printf("       字符串综合查找替换应用\n");
    printf("=====================================\n");
    char *str[STR_COUNT];   // 存放字符串的指针数组，每个元素指向一个字符串
                            // str[0]: 原串，str[1]: 查找串，str[2]: 替换串
    if (!Alloc(str)) {
        return 1; // 内存分配失败，退出程序，返回1
    }
    str[0][0] = '\0'; // 初始化原串为空
    Solve(str);
    FreeMemory(str);
    system("pause");
    return 0;
}

// 从*i索引开始找子串
int Find(char* str, char* sub, int *i){
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

// 释放字符串内存
void FreeMemory(char *str[]){
    int i = STR_COUNT;
    while (i--) {
        free(str[i]);
        str[i] = NULL;// 防止悬空指针
    }
    return;
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

// 字符串替换
void Replace(char* str, char* oldSub, char* newSub){
    char buffer[MAX_LEN];// 临时缓冲区
    char *insertPoint = &buffer[0];// 插入点
    const char *temp = str;// 临时指针
    size_t oldLen = strlen(oldSub);// 旧子串长度
    size_t newLen = strlen(newSub);// 新子串长度

    while (1) {
        const char *p = strstr(temp, oldSub);// 查找子串
        if (p == NULL) {// 未找到子串，复制剩余部分并结束
            strcpy(insertPoint, temp);// 复制剩余部分
            break;
        }
        memcpy(insertPoint, temp, p - temp);// 复制找到子串前的部分
        insertPoint += p - temp;// 移动插入点
        memcpy(insertPoint, newSub, newLen);// 复制新子串
        insertPoint += newLen;// 移动插入点
        temp = p + oldLen;// 移动临时指针
    }
    strcpy(str, buffer);// 将结果复制回原字符串
    return;
}

// 解决方案主函数
void Solve(char **str){
    while (strcmp(str[0], "END\n") != 0){// 输入"END"时退出程序
        int i = 0;
        for (; i < STR_COUNT; ++i){
            if (i == 0){
                printf("请输入原串s1，输入\"END\"时，程序退出\n");
            }
            else{
                printf("请输入查找串s%d\n", i + 1);
            }
            fgets(str[i], MAX_LEN, stdin);// 获得字符串输入
            
            char *newline = strchr(str[i], '\n');// 查找换行符，strchr返回指向换行符的指针
            if (newline == NULL) while(getchar() != '\n');// 找不到换行符，说明输入超过最大长度，清空输入流
            str[i][strcspn(str[i], "\n")] = '\0'; // 去除换行符
            printf("原串s%d的长度是%zu，内容是：%s\n", i + 1, strlen(str[i]), str[i]);// 回显输入
        }
        int index = 0;//索引置0
        while (Find(str[0], str[1], &index) + 1){//当函数返回-1时退出循环
            Replace(str[0], str[1], str[2]);
            index += strlen(str[1]);//从找到的子串后面开始再找
        }
        printf("替换后s1的长度是%zu，内容是：%s\n", strlen(str[0]), str[0]);
    }
    return;
}
