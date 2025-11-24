/*
本程序读取用户输入的一行句子, 以空格为分隔符将其分割成若干单词
并逐行输出每个单词, 同时统计单词的总数
*/
#include <stdio.h>
#include <string.h>

int main() {
    char str[256];//定义一个字符数组用于存储输入的字符串
    int i = 0;
    printf("本程序会将输入的一行英文句子，分成若干单词每行输出，并统计单词个数。\n");

    //fgets函数用于从标准输入(stdin)读取一行字符串
    //str是存储字符串的数组, sizeof(str)是数组的大小, 防止缓冲区溢出
    fgets(str, sizeof(str), stdin);

    // 读取输入并处理可能的超长情况
    if (fgets(line, sizeof(line), stdin) == NULL) {
        printf("输入读取失败\n");
        return 1;
    }
    
    // 移除输入末尾的换行符（如果存在）
    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '\0';
    } else if (len == sizeof(line) - 1) {
        // 提示用户输入可能被截断
        printf("警告：输入可能过长，已截断处理\n");
    }


    //strcspn函数用于计算字符串中从起始位置到第一个匹配字符之间的字符数。
    //它常用于查找字符串中不包含特定字符的连续部分。
    //将换行符替换为字符串结束符, 相当于去掉输入的换行符
    str[strcspn(str, "\n")] = 0;

    //strtok函数用于分割字符串, 第一个参数是要分割的字符串, 第二个参数是分隔符
    //strtok返回第一个分割出来的子字符串的首地址
    //用变量token接收返回值
    char *token = strtok(str, " ");
    
    while (token != NULL) {//strtok分割结束时, 返回NULL, 被token接收, 循环结束
        i++;
        printf("第%d个单词：%s\n", i, token);
        token = strtok(NULL, " ");//继续分割字符串, 传入NULL表示继续上一次的分割
    }

    printf("一共%d个单词。\n", i);
    printf("请按任意键继续. . .\n");
    getchar();
    return 0;
}


/*
 * 17_01_DevideWords.c
 *
 * Created on: 2025.11.14 Fri.
 * 
 * Almost made by AI. I have to figure out how it works.
 * 
 * Thanks to copilot and doubao.
 */