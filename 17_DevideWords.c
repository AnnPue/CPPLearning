#include <stdio.h>
#include <string.h>

int main() {
    char str[256];
    int i = 0;
    printf("本程序会将输入的一行英文句子，分成若干单词每行输出，并统计单词个数。\n");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        i++;
        printf("第%d个单词：%s\n", i, token);
        token = strtok(NULL, " ");
    }
    printf("一共%d个单词。\n", i);
    printf("请按任意键继续. . .\n");
    getchar();
    return 0;
}


/*
 * 17_DevideWords.c
 *
 *  Created on: 2025年11月14日
 * 
 * Almost made by AI. I have to figure out how it works.
 */