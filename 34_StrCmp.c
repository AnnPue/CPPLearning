#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 函数声明（抽离独立功能）
void ClearIn();            // 清空输入流
void PrintMenu();          // 打印操作菜单
void InputStrings(char *str[]); // 输入三个字符串
void CompareStrings(char *str[]);// 比较并输出最大/最小字符串
void FreeMemory(char *str[]);   // 释放内存

int main(){
    printf("=====================================\n");
    printf("       字符串综合比较应用\n");
    printf("=====================================\n");
    
    char command[8];
    char *str[3];
    int flag = 0, i = 3;

    // 初始化字符串内存
    while (i--){
        str[i] = (char*)malloc(2000 * sizeof(char));// 分配足够内存，每个字符串最大长度1999
        if (str[i] == NULL){
            printf("内存分配失败，程序退出!\n");
            return -1;
        }
        memset(str[i], 0, 2000 * sizeof(char));// 清零
    }

    while (1){
        PrintMenu();
        scanf(" %7s", command);
        ClearIn();

        if (strcmp(command, "Compare") == 0){
            flag ? CompareStrings(str) : printf("请先通过菜单1，Input三个字符串的值。\n");
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
    while ((ch = getchar()) != '\n' && ch != EOF);
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
    for(i = 0; i < 3; i++){
        printf("请输入字符串s%d：\n", i + 1);
        scanf(" %1999s", str[i]);
        ClearIn();
        printf("字符串s%d的长度是%d，内容是：%s\n", i + 1, strlen(str[i]), str[i]);
    }
}

// 比较字符串并输出结果
void CompareStrings(char *str[]){
    int i;
    char *big = str[0], *small = str[0];
    for(i = 1; i < 3; i++) {
        if(strcmp(str[i], big) > 0) big = str[i];
        if(strcmp(str[i], small) < 0) small = str[i];
    }
    printf("\n比较结果：\n最大的字符串是:\n%s", big);
    printf("\n最小的字符串是:\n%s\n", small);
}

// 释放字符串内存
void FreeMemory(char *str[]){
    int i = 3;
    while (i--) free(str[i]);
}
