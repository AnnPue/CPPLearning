/*
本程序读取用户输入的一行句子, 以空格为分隔符将其分割成若干单词
并逐行输出每个单词, 同时统计单词的总数
*/
#include <stdio.h>
#include <string.h>

int main(){
    char line[256];
    int count = 0, j = -1, leap = -1;
    printf("本程序会将输入的一行英文句子，分成若干单词每行输出，并统计单词个数。\n");
    fgets(line, sizeof(line), stdin);
    
    for(int i = 0; line[i] != '\n'; i += leap){

        if (line[i] == ' '){
            leap = 1;
            continue;
        }

        ++count;
        printf("第%d个单词：", count);

        for(j = i; line[j] != ' ' && line[j] != '\n'; ++j){
            printf("%c", line[j]);
        }

        leap = j - i;
        printf("\n");
    }

    printf("一共%d个单词。\n", count);
    return 0;
}