/*
本程序可以根据输入的字串在原字符串中查找，并输出所有存在子串的索引
*/
#include<stdio.h>
#include<string.h>

int find(char*, char*, int*);//找子串
void ClearIn();//清空输入流
int main(){
    printf("=====================================\n");
    printf("       字符串查找匹配应用\n");
    printf("=====================================\n");
    
    char str[256], son[256];//原字符串和子串
    int status = 0;//记录状态，未输入字符串时取0
    int command = -1;//指令
    int index = -1;//索引
    while(1){
        if (status == -2) break;//flag为-2则退出
        
        printf("\n请选择操作:\n1. 输入原字符串和子串：\n");
        printf("2. 输出子串在原字符串中所有出现的位置索引：\n3. 退出\n");
        printf("请输入选项 (1-3):");
        
        while (scanf(" %d", &command) !=1 || command < 1 || command > 3){//检查输入指令
            printf("请您输入选项 (1-3)，为正整数，请重新来！\n");
            ClearIn();
        }

        ClearIn();
        switch (command){
            case 1:
                printf("请输入一行原串：\n");
                scanf("%s", &str);//获得原字符串
                ClearIn();
                printf("原串s1的长度是%d，内容是：%s\n", strlen(str), str);

                printf("请输入一行子串：\n");
                scanf("%s", &son);//获得子串
                ClearIn();
                printf("子串s2的长度是%d，内容是：%s\n", strlen(son), son);

                status = 1;//已输入字符串
                break;
            case 2:
                if(status == 1){//输入了字符串
                    index = 0;//索引置0
                    printf("\n查找结果：\n");
                    while (find(str, son, &index) + 1){//当函数返回-1时退出循环
                        printf("在原串的%d位置找到子串\n", index);
                        index ++;//从找到索引的下一位开始再找
                    }
                }
                else{//未输入字符串
                    printf("请先通过菜单1设置两个字符串的值。\n");
                }
                break;
            case 3:
                status = -2;//退出程序
                break;
        }
    }
    printf("感谢使用字符串查找匹配应用!\n");
    //system("pause");
    return 0;
}

int find(char* str, char* son, int *i){//从*i索引开始找子串
    int j;
    for (; *i <= strlen(str) - strlen(son); ++ *i){//从*i开始遍历字符串
        for (j = *i; j < strlen(son) + *i; ++j){//循环一个子串的长度
            if (str[j] != son[j - *i]){//发现一个字符不同就退出循环
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
