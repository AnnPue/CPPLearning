/*
读取输入字符串中字母（不区分大小写）的出现次数，并按次数从多到少输出
*/
// 使用快速排序。缺点：不稳定，不能保证计数相同的字母顺序
#include <stdio.h>
#include <ctype.h>  // for tolower
#include <string.h>
#include <stdlib.h> // for malloc

const int ALPHABET_SIZE = 26;   // 字母表大小
const int MAX_LEN = 2000;       // 字符串最大长度

void LowerStr(char *);                  // 将字符串全部转换为小写
void CountLetter(char *, int *);        // 统计字母出现次数
int Partition(int *, char *, int, int); // 快速排序的分区函数，确定基准值位置，同步交换count和alphabet
void QuickSort(int *, char *, int, int);// 快速排序的递归函数
void PrintCounts(int *, char *);        // 输出结果

int main(){
    printf("读取一行字符串，统计串中每个字母出现的次数，");
    printf("大小写不区分，然后按照出现次数从大到小输出。\n");
    printf("输入END程序结束。\n");
    int i;

    char alphabet[ALPHABET_SIZE];
    int count[ALPHABET_SIZE];
    char str[MAX_LEN];
    
    while(1){
        for (i = 0; i < ALPHABET_SIZE; i++){
            alphabet[i] = 'a' + i; // 初始化字母表
        }
        for (i = 0; i < ALPHABET_SIZE; i++){
            count[i] = 0;   // 初始化字母计数数组为0
        }
        fgets(str, MAX_LEN, stdin);
        if (strcmp(str, "END\n") == 0) {
            system("pause");
            return 0; // 输入END时退出函数
        }
        char *newline = strchr(str, '\n'); // 查找换行符，strchr返回指向换行符的指针
        if (newline == NULL) while(getchar() != '\n'); // 找不到换行符，说明输入超过最大长度，清空输入流
        str[strcspn(str, "\n")] = '\0'; // 去除换行符
        printf("字符串s1的长度是%d，内容是：%s\n", strlen(str), str);   // 回显字符串
        LowerStr(str);
        CountLetter(str, count);
        QuickSort(count, alphabet, 0, ALPHABET_SIZE - 1);
        PrintCounts(count, alphabet);
    }
    return 0;
}

void LowerStr(char *str){   // 将字符串全部转换为小写
    int i, len = strlen(str);
    for(i = 0; i < len; i++){
        str[i] = tolower(str[i]);
    }
}

void CountLetter(char *str, int *count){    // 统计字母出现次数
    int i, len = strlen(str);
    for(i = 0; i < len; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            count[str[i] - 'a']++;
        }
    }
}

// 快速排序的分区函数，确定基准值位置，同步交换count和alphabet
int Partition(int *count, char *alphabet, int low, int high) {
    // 选择最右侧元素作为基准值（计数）
    int pivot = count[high];
    // i：小于基准值的元素的边界索引
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        // 降序排序：若当前元素计数 >= 基准值，交换到左侧
        if (count[j] >= pivot) {
            i++;
            // 交换count数组元素
            int tempCount = count[i];
            count[i] = count[j];
            count[j] = tempCount;
            // 同步交换alphabet数组元素，保证字母与计数对应
            char tempChar = alphabet[i];
            alphabet[i] = alphabet[j];
            alphabet[j] = tempChar;
        }
    }
    // 将基准值放到正确位置
    i++;
    int tempCount = count[i];
    count[i] = count[high];
    count[high] = tempCount;

    char tempChar = alphabet[i];
    alphabet[i] = alphabet[high];
    alphabet[high] = tempChar;

    return i; // 返回基准值的索引
}

// 快速排序的递归函数
void QuickSort(int *count, char *alphabet, int low, int high) {
    if (low < high) {
        // 获取分区点
        int pi = Partition(count, alphabet, low, high);
        // 递归排序左半部分
        QuickSort(count, alphabet, low, pi - 1);
        // 递归排序右半部分
        QuickSort(count, alphabet, pi + 1, high);
    }
}

void PrintCounts(int *count, char *alphabet){    // 输出结果
    int i;
    for(i = 0; i < ALPHABET_SIZE; i++){
        printf("%c出现的次数是%d次。\n", alphabet[i], count[i]);
    }
}