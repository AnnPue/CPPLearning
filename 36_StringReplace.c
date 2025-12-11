/*
本程序可以根据输入在原字符串中查找子串，并将原串中的子串替换为新串。
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

const int MAX_LEN = 2000;           // 字符串最大长度
const int STR_COUNT = 3;            // 字符串个数

int Find(const char*, const char*, int*);       // 从*i索引开始找子串
void FreeStr(char **);                          // 释放字符串内存
bool AllocStr(char **);                         // 分配字符串内存
bool Replace(char*, const char*, const char*);  // 字符串替换
void Solve(char **);                            // 解决方案主函数

int main(){
    printf("=====================================\n");
    printf("       字符串综合查找替换应用\n");
    printf("=====================================\n");
    char *str[STR_COUNT];   // 存放字符串的指针数组，每个元素指向一个字符串
                            // str[0]: 原串，str[1]: 查找串，str[2]: 替换串
    if (!AllocStr(str)) {
        return 1; // 内存分配失败，退出程序，返回1
    }
    str[0][0] = '\0'; // 初始化原串为空
    Solve(str);
    FreeStr(str);
    system("pause");
    return 0;
}

// 从*i索引开始找子串
int Find(const char* str, const char* sub, int *i){
    if (strlen(str) < strlen(sub)) return -1; // 原字符串短于子串，不可能找到，返回-1
    int j;
    for (; *i <= strlen(str) - strlen(sub); ++ *i){ // 从*i开始遍历字符串
        for (j = *i; j < strlen(sub) + *i; ++j){ // 循环一个子串的长度
            if (str[j] != sub[j - *i]){ // 发现一个字符不同就退出循环再找
                break;
            }
            return *i; // 找到了返回对应索引
        }
    }
    return -1; // 未找到返回-1
}

// 释放字符串内存
void FreeStr(char *str[]){
    int i = STR_COUNT;
    while (i--) {
        free(str[i]);
        str[i] = NULL; // 防止悬空指针
    }
    return;
}

// 分配字符串内存
bool AllocStr(char *str[]){
    int i = STR_COUNT;
    while (i--){
        str[i] = (char*)malloc(MAX_LEN * sizeof(char)); // 分配足够内存，每个字符串最大长度1999
        if (str[i] == NULL){
            fprintf(stderr, "内存分配失败，程序退出!\n");
            FreeStr(str);
            return false;
        }
        memset(str[i], 0, MAX_LEN * sizeof(char)); // 清零,防止垃圾值干扰
    }
    return true;
}

// 字符串替换
bool Replace(char* str, const char* oldSub, const char* newSub){
    // const char* 本身可以修改指针指向，但不能通过该指针修改所指向的内容
    const char *start = str; // 定位待处理的起始位置

    size_t oldLen = strlen(oldSub); // 旧子串长度
    size_t newLen = strlen(newSub); // 新子串长度

    const char *match = start; // match储存指向找到的oldSub子串位置

    size_t originalLen = strlen(start); // 原字符串长度
    size_t newTotalLen = originalLen; // 替换后字符串的总长度，初始为原字符串长度

    // strstr函数用于在start指向的字符串中查找oldSub子串，返回首次匹配的起始地址
    
    // 统计旧子串出现次数，计算最终需要的内存大小
    while ((match = strstr(match, oldSub)) != NULL) {
        newTotalLen += (newLen - oldLen); // 长度差值（可能正/负）
        match += oldLen; // 跳过已统计的子串，避免重复计数
    }
    newTotalLen += 1; // 预留字符串结束符'\0'的空间

    // 动态分配缓冲区
    char* buffer = (char*)malloc(newTotalLen);
    if (buffer == NULL) {
        // fprintf函数用于向指定的输出流写入格式化数据
        // stderr是标准错误输出流，通常用于输出错误信息
        fprintf(stderr, "错误：内存分配失败\n"); // 分配失败，输出错误信息
        return false;
    }
    char* insertPoint = buffer; // 指向缓冲区的插入点
    start = str; // 重置start指针，指向原字符串开头

    while (1) {
        match = strstr(start, oldSub); // 从start位置开始查找oldSub子串，match指向匹配位置
        if (match == NULL) { // 未找到剩余的oldSub，处理最后一段字符串
            strcpy(insertPoint, start); // 复制start到末尾的所有字符
            break;// 退出循环
        }
        // memcpy函数用于从源地址复制指定字节数的数据到目标地址
        // 复制start到oldSub匹配位置前的字符到buffer
        memcpy(insertPoint, start, match - start);
        insertPoint += match - start; // 移动插入点，指向刚复制内容的末尾

        // 复制新子串newSub到buffer（替换oldSub）
        memcpy(insertPoint, newSub, newLen);
        insertPoint += newLen; // 再次移动插入点，指向newSub的末尾

        // 移动start指针：跳过已处理的oldSub，继续查找下一个匹配
        start = match + oldLen;
    }
    strcpy(str, buffer); // 将替换后的完整字符串从buffer复制回原字符串str
    free(buffer); // 释放缓冲区内存
    return true;
}

// 解决方案主函数
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
            fgets(str[i], MAX_LEN, stdin); // 获得字符串输入

            if (strcmp(str[0], "END\n") == 0) {
                return; // 输入END时退出函数
            }
            char *newline = strchr(str[i], '\n'); // 查找换行符，strchr返回指向换行符的指针
            if (newline == NULL) while(getchar() != '\n'); // 找不到换行符，说明输入超过最大长度，清空输入流
            str[i][strcspn(str[i], "\n")] = '\0'; // 去除换行符
            printf("原串s%d的长度是%zu，内容是：%s\n", i + 1, strlen(str[i]), str[i]);// 回显输入
        }
        int index = 0; // 索引置0
        while (Find(str[0], str[1], &index) + 1){ // 当函数返回-1时退出循环
            if(Replace(str[0], str[1], str[2])){
                index += strlen(str[1]); // 从找到的子串后面开始再找
            }
            else{
                break; // 替换失败，退出循环
            }
        }
        printf("替换后s1的长度是%zu，内容是：%s\n", strlen(str[0]), str[0]);
    }
}
