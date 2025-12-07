#include <stdio.h>

const int BEGIN = 1;
const int END = 0;

int main(){
    char c;
    int status = END;
    printf("本程序会将输入的一行英文句子，分成若干单词每行输出，并统计单词个数。\n");
    int i = 0;
    c = getchar();
    while (c != '\n'){
        if (c == ' ' || c == '\t'){
            if (status == BEGIN){
                status = END;
                putchar('\n');
            }
        }
        else if(status == END){
            status = BEGIN;
            i++;
            printf("第%d个单词：", i);
            putchar(c);
        }
        else{
            putchar(c);
        }
        c = getchar();
    }
    printf("\n单词个数：%d\n", i);
    return 0;
}

/*
written by teacher
*/