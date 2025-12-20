#include <stdio.h>
#include <ctype.h>  //
#include <string.h>
#include <stdlib.h> //

const int ALPHABET_SIZE = 26; // 字母表大小
const int MAX_LEN = 2000;    // 字符串最大长度

void LowerStr(char *);  // 将字符串全部转换为小写
void CountLetter(char *, int *); // 统计字母出现次数
void SortAndPrintCounts(int *, char *); // 排序并输出结果

int main(){
    printf("读取一行字符串，统计串中每个字母出现的次数，");
    printf("大小写不区分，然后按照出现次数从大到小输出。\n");
    printf("输入END程序结束。\n");
    int i;

    char *alphabet;
    alphabet = (char *)malloc(ALPHABET_SIZE * sizeof(char));
    if (alphabet == NULL){
        fprintf(stderr, "错误：内存分配失败\n");
        return 1;
    }
    
    int count[ALPHABET_SIZE];
    
    char *str;
    str = (char *)malloc(MAX_LEN * sizeof(char));
    if (str == NULL){
        free(alphabet);
        fprintf(stderr, "错误：内存分配失败\n");
        return 1;
    }
    while(1){
        for (i = 0; i < ALPHABET_SIZE; i++){
            alphabet[i] = 'a' + i; // 初始化字母表
        }
        for (i = 0; i < ALPHABET_SIZE; i++){
            count[i] = 0;   // 初始化字母计数数组为0
        }
        fgets(str, MAX_LEN, stdin);
        if (strcmp(str, "END\n") == 0) {
            free(str);
            free(alphabet);
            system("pause");
            return 0; // 输入END时退出函数
        }
        char *newline = strchr(str, '\n'); // 查找换行符，strchr返回指向换行符的指针
        if (newline == NULL) while(getchar() != '\n'); // 找不到换行符，说明输入超过最大长度，清空输入流
        str[strcspn(str, "\n")] = '\0'; // 去除换行符
        printf("字符串s1的长度是%d，内容是：%s\n", strlen(str), str);   // 回显字符串
        LowerStr(str);
        CountLetter(str, count);
        SortAndPrintCounts(count, alphabet);
    }
    free(str);
    free(alphabet);
    return 0;
}

void LowerStr(char *str){   // 将字符串全部转换为小写
    int i;
    for(i = 0; i < strlen(str); i++){
        str[i] = tolower(str[i]);
    }
}

void CountLetter(char *str, int *count){    // 统计字母出现次数
    int i;
    for(i = 0; i < strlen(str); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            count[str[i] - 'a']++;
        }
    }
}

void SortAndPrintCounts(int *count, char *alphabet){    // 排序并输出结果
    int i, j;
    // 冒泡排序
    for(i = 0; i < ALPHABET_SIZE - 1; i++){
        for(j = 0; j < ALPHABET_SIZE - i - 1; j++){
            if(count[j] < count[j + 1]){
                // 交换计数
                int tempCount = count[j];
                count[j] = count[j + 1];
                count[j + 1] = tempCount;
                // 交换对应的字母
                char tempChar = alphabet[j];
                alphabet[j] = alphabet[j + 1];
                alphabet[j + 1] = tempChar;
            }
        }
    }
    // 输出结果
    for(i = 0; i < ALPHABET_SIZE; i++){
        printf("%c出现的次数是%d次。\n", alphabet[i], count[i]);
    }
}