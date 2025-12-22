/*
读取一行字符串，统计串中每个字母出现的次数，
大小写不区分，然后按照出现次数从大到小输出，相同次数按字母表顺序排列。
输入END程序结束。
*/
// 用结构体数组存储26个字母及其计数
// 使用归并排序

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

const int ALPHABET_SIZE = 26;   // 26个英文字母
const int MAX_LEN = 2000;       // 字符串最大长度

// 定义结构体：封装字母及其出现次数
typedef struct {
    char ch;         // 英文字母（a-z）
    int count;       // 对应字母的出现次数
} LetterCount;

void LowerStr(char *);                      // 字符串转小写
void InitLetterCount(LetterCount *);        // 初始化结构体数组
void CountLetter(char *, LetterCount *);    // 统计字母出现次数
void Merge(LetterCount *, int, int, int);   // 归并函数：合并两个有序结构体子数组
void MergeSort(LetterCount *, int, int);    // 归并排序的递归函数
void PrintCounts(LetterCount *);            // 输出统计结果

int main(){
    printf("读取一行字符串，统计串中每个字母出现的次数，");
    printf("大小写不区分，然后按照出现次数从大到小输出。\n");
    printf("输入END程序结束。\n");

    LetterCount letterArr[ALPHABET_SIZE];   // 结构体数组：存储26个字母及其计数
    char str[MAX_LEN];                      // 输入字符串
    while(1){
        // 初始化结构体数组，避免上一次统计残留
        InitLetterCount(letterArr);

        // 读取输入并处理退出条件
        fgets(str, MAX_LEN, stdin);
        if (strcmp(str, "END\n") == 0) {
            system("pause");
            return 0;
        }

        // 去除换行符并处理超长输入
        char *newline = strchr(str, '\n');
        if (newline == NULL) while(getchar() != '\n');
        str[strcspn(str, "\n")] = '\0';

        // 回显输入字符串
        printf("字符串s1的长度是%d，内容是：%s\n", strlen(str), str);

        // 转小写 → 统计 → 排序 → 输出
        LowerStr(str);
        CountLetter(str, letterArr);
        MergeSort(letterArr, 0, ALPHABET_SIZE - 1);
        PrintCounts(letterArr);
    }
}

// 将字符串全部转换为小写
void LowerStr(char *str){
    int i, len = strlen(str);
    for(i = 0; i < len; i++){
        str[i] = tolower(str[i]);
    }
}

// 初始化结构体数组：赋值字母(a-z)，计数置0
void InitLetterCount(LetterCount *letterArr){
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        letterArr[i].ch = 'a' + i;     // 字母赋值：a, b, ..., z
        letterArr[i].count = 0;        // 计数初始化：0
    }
}

// 统计字母出现次数
void CountLetter(char *str, LetterCount *letterArr){
    int i, len = strlen(str);
    for(i = 0; i < len; i++){
        // 仅统计字母
        if(str[i] >= 'a' && str[i] <= 'z'){
            letterArr[str[i] - 'a'].count++;  // 对应结构体的计数自增
        }
    }
}

// 归并函数：合并两个有序结构体子数组，按count降序
void Merge(LetterCount *letterArr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int i, j;

    // 临时结构体数组：存储左右子数组
    LetterCount L[n1], R[n2];

    // 拷贝数据到临时结构体数组
    for (i = 0; i < n1; i++) {
        L[i] = letterArr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = letterArr[mid + 1 + j];
    }

    i = j = 0;

    // k用于将合并后的结果写回原结构体数组letterArr的索引，指向当前待写入的位置
    // 每次从L或R子数组选择一个元素放入letterArr[k]处
    // 然后k自增，始终保证下一个写入位置是正确的。
    int k = left;   // k初始化为left，代表原数组的合并起始位置

    // 降序合并左右子数组
    while (i < n1 && j < n2) {
        // 按count字段降序排序
        if (L[i].count >= R[j].count) {
            letterArr[k] = L[i];
            i++;
        } else {
            letterArr[k] = R[j];
            j++;
        }
        k++;
    }

    // 拷贝左子数组剩余元素
    while (i < n1) {
        letterArr[k] = L[i];
        i++;
        k++;
    }

    // 拷贝右子数组剩余元素
    while (j < n2) {
        letterArr[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序的递归函数
void MergeSort(LetterCount *letterArr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        // 递归排序左右子数组
        MergeSort(letterArr, left, mid);
        MergeSort(letterArr, mid + 1, right);
        // 合并有序子数组
        Merge(letterArr, left, mid, right);
    }
}

// 输出结构体数组中的字母及计数
void PrintCounts(LetterCount *letterArr){
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        printf("%c出现的次数是%d次。\n", letterArr[i].ch, letterArr[i].count);
    }
}
