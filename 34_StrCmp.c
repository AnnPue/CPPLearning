/*
本程序可以将输入的字串按字典序比较大小，并输出字典序最大的和最小的字符串。
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const int MAX_LEN = 2000;// 字符串最大长度
const int STR_COUNT = 3;// 字符串个数
const int CMD_LEN = 8;// 命令串最大长度

void ClearIn();            // 清空输入流
void PrintMenu();          // 打印操作菜单
void InputStrings(char *str[]); // 输入三个字符串
void CompareStrings(char *str[]);// 比较并输出最大/最小字符串
void FreeMemory(char *str[]);   // 释放内存
void Warn_NoInput();        // 提示未输入字符串

int main(){
    printf("=====================================\n");
    printf("       字符串综合比较应用\n");
    printf("=====================================\n");
    
    char command[CMD_LEN];
    command[CMD_LEN - 1] = '\0'; // 确保字符串以null结尾
    char *str[STR_COUNT];
    int flag = 0, i = STR_COUNT;

    // 初始化字符串内存
    while (i--){
        str[i] = (char*)malloc(MAX_LEN * sizeof(char));// 分配足够内存，每个字符串最大长度1999
        if (str[i] == NULL){
            printf("内存分配失败，程序退出!\n");
            return -1;
        }
        memset(str[i], 0, MAX_LEN * sizeof(char));// 清零,防止垃圾值干扰
    }

    while (1){
        PrintMenu();
        scanf(" %7s", command);// 获取命令串，最多读取7个字符，防止缓冲区溢出
        ClearIn();
        printf("您输入的命令是：%s\n", command);// 回显命令
        if (strcmp(command, "Compare") == 0){
            flag ? CompareStrings(str) : Warn_NoInput();
        }
        else if (strcmp(command, "Input") == 0){
            InputStrings(str);
            flag = 1;
        }
        else if (strcmp(command, "Exit") == 0){
            FreeMemory(str);
            printf("感谢使用字符串综合比较应用!\n");
            return 0;
        }
        else{
            printf("无效选项，请重来!\n");
        }
    }
    return 0;
}

// 清空输入流
void ClearIn(){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);// 清空输入流，防止输入缓冲区残留影响后续输入
}

// 打印操作菜单
void PrintMenu(){
    printf("\n请输入命令串，进行操作:\n");
    printf("1.\"Input\"--- 输入s1,s2,s3三个字符串：\n");
    printf("2.\"Compare\"--- 比较s1,s2,s3三个字符串字典序大小：\n");
    printf("3.\"Exit\"--- 退出。\n");
}

// 输入三个字符串
void InputStrings(char *str[]){
    int i;
    for(i = 0; i < STR_COUNT; i++){
        printf("请输入字符串s%d：\n", i + 1);
        fgets(str[i], MAX_LEN - 1, stdin);
        //ClearIn();
        str[i][MAX_LEN - 1] = '\0'; // 确保字符串以null结尾
        printf("字符串s%d的长度是%d，内容是：%s\n", i + 1, strlen(str[i]) - 1, str[i]);
    }
}

// 比较字符串并输出结果
void CompareStrings(char *str[]){
    int i;
    char *big = str[0], *small = str[0];
    for(i = 1; i < STR_COUNT; i++) {
        if(strcmp(str[i], big) > 0) big = str[i];// 找到最大的字符串
        if(strcmp(str[i], small) < 0) small = str[i];// 找到最小的字符串
    }
    printf("\n比较结果：\n最大的字符串是:\n%s", big);
    printf("\n最小的字符串是:\n%s\n", small);
}

// 释放字符串内存
void FreeMemory(char *str[]){
    int i = STR_COUNT;
    while (i--) free(str[i]);
}

void Warn_NoInput(){
    printf("请先通过菜单1，Input三个字符串的值。\n");
}