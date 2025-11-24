/*
本程序读取用户输入的一行句子, 以空格为分隔符将其分割成若干单词
并逐行输出每个单词, 同时统计单词的总数
*/
#include <stdio.h>
#include <string.h>

int main(){
    char line[256];
    int count = 0;
    printf("本程序会将输入的一行英文句子，分成若干单词每行输出，并统计单词个数。\n");
    
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

    int i = 0;
    while (line[i] != '\0') {
        // 跳过连续的空格
        while (line[i] == ' ') {
            i++;
        }
        
        // 如果已到达字符串末尾，退出循环
        if (line[i] == '\0') {
            break;
        }
        
        // 处理当前单词
        count++;
        printf("第%d个单词：", count);
        
        // 输出单词字符直到遇到空格或结束符
        int j = i;
        while (line[j] != ' ' && line[j] != '\0') {
            printf("%c", line[j]);
            j++;
        }
        printf("\n");
        
        // 移动到下一个单词的起始位置
        i = j;
    }

    printf("一共%d个单词。\n", count);
    return 0;
}
