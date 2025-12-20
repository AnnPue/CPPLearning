/*
读取输入字符串中字母（不区分大小写）的出现次数，并按次数从多到少输出
*/
// 使用归并排序。
#include <stdio.h>
#include <ctype.h>  // for tolower
#include <string.h>
#include <stdlib.h> // for malloc

const int ALPHABET_SIZE = 26;   // 字母表大小
const int MAX_LEN = 2000;       // 字符串最大长度

void LowerStr(char *);                      // 将字符串全部转换为小写
void CountLetter(char *, int *);            // 统计字母出现次数
void Merge(int *, char *, int, int, int);   // 归并函数：合并两个有序子数组
void MergeSort(int *, char *, int, int);    // 归并排序的递归函数
void PrintCounts(int *, char *);            // 输出结果

int main(){
    printf("读取一行字符串，统计串中每个字母出现的次数，");
    printf("大小写不区分，然后按照出现次数从大到小输出。\n");
    printf("输入END程序结束。\n");
    int i;

    char alphabet[ALPHABET_SIZE];   // 字母表
    int count[ALPHABET_SIZE];       // 对应出现次数
    char str[MAX_LEN];             // 输入的字符串
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
        MergeSort(count, alphabet, 0, ALPHABET_SIZE - 1);
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

// 归并函数：合并两个有序子数组
void Merge(int *count, char *alphabet, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 临时数组存储左右子数组（计数+字母）
    int L_count[n1], R_count[n2];
    char L_alpha[n1], R_alpha[n2];

    // 拷贝数据到临时数组
    int i, j;
    for (i = 0; i < n1; i++) {
        L_count[i] = count[left + i];
        L_alpha[i] = alphabet[left + i];
    }
    for (j = 0; j < n2; j++) {
        R_count[j] = count[mid + 1 + j];
        R_alpha[j] = alphabet[mid + 1 + j];
    }

    // 合并临时数组到原数组（降序）
    i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L_count[i] >= R_count[j]) {
            count[k] = L_count[i];
            alphabet[k] = L_alpha[i];
            i++;
        } else {
            count[k] = R_count[j];
            alphabet[k] = R_alpha[j];
            j++;
        }
        k++;
    }

    // 拷贝剩余元素
    while (i < n1) {
        count[k] = L_count[i];
        alphabet[k] = L_alpha[i];
        i++;
        k++;
    }
    while (j < n2) {
        count[k] = R_count[j];
        alphabet[k] = R_alpha[j];
        j++;
        k++;
    }
}

// 归并排序的递归函数
void MergeSort(int *count, char *alphabet, int left, int right) {
    if (left < right) { // 递归终止条件：左边界不小于右边界（子数组长度为1）
        int mid = left + (right - left) / 2;        // 等价于(left+right)/2，避免超出int范围导致溢出
        MergeSort(count, alphabet, left, mid);      // 递归排序左子数组
        MergeSort(count, alphabet, mid + 1, right); // 递归排序右子数组
        Merge(count, alphabet, left, mid, right);   // 合并两个有序子数组
    }
}

void PrintCounts(int *count, char *alphabet){    // 输出结果
    int i;
    for(i = 0; i < ALPHABET_SIZE; i++){
        printf("%c出现的次数是%d次。\n", alphabet[i], count[i]);
    }
}
