#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void ClearIn();//清空输入流
int main(){
    printf("=====================================\n");
    printf("       字符串综合比较应用\n");
    printf("=====================================\n");
    char command[8], *big, *small;
    char *str[3];
    int flag = 0, i = 3;
    while (i--){
        str[i] = (char*)malloc(2000 * sizeof(char)); //分配内存
        if (str[i] == NULL){
            printf("内存分配失败，程序退出!\n");
            return -1;
        }
        memset(str[i], 0, 2000 * sizeof(char));//初始化为零，避免脏数据
    }
    while (1){
        printf("\n请输入命令串，进行操作:\n");
        printf("1.\"Input\"--- 输入s1,s2,s3三个字符串：\n");
        printf("2.\"Compare\"--- 比较s1,s2,s3三个字符串字典序大小：\n");
        printf("3.\"Exit\"--- 退出。\n");

        scanf(" %7s", command);
        ClearIn();

        if (strcmp(command, "Compare") == 0){
            if (flag == 1){//输入了字符串
                //找字典序最大和最小字符串
                big = str[0];
                small = str[0];
                for(i = 1; i < 3; i++) {
                    if(strcmp(str[i], big) > 0) {
                        big = str[i];
                    }
                    if(strcmp(str[i], small) < 0) {
                        small = str[i];
                    }
                }
                printf("\n比较结果：\n最大的字符串是:\n%s", big);
                printf("\n最小的字符串是:\n%s\n", small);
            }
            else {
                printf("请先通过菜单1，Input三个字符串的值。\n");
            }
        }
        else if (strcmp(command, "Input") == 0){
            flag = 1;
            for(i = 0; i < 3; i++){
                printf("请输入字符串s%d：\n", i + 1);
                scanf(" %1999s", str[i]);
                ClearIn();
                printf("字符串s%d的长度是%d，内容是：%s\n", i + 1, strlen(str[i]), str[i]);
                
            }
        }
        else if (strcmp(command, "Exit") == 0){
            i = 3;
            while (i--){
                free(str[i]); //释放内存
            }
            printf("感谢使用字符串综合比较应用!\n");
            return 0;
        }
        else{
            printf("无效选项，请重来!\n");
        }
    }
    return 0;
}

void ClearIn(){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);//
}