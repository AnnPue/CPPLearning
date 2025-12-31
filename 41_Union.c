#include <stdio.h>

struct MyStruct {
    char  ch; // 1字节
    char  ch2;  // 1字节
    int   num;// 4字节
    char  ch3;  // 1字节
    char  ch4;  // 1字节
    //char  ch5;  // 1字节
};

union Data {
    char  ch;  // 1字节
    int   num; // 4字节
};

int main() {
    union Data u;
    // 第1步：给字符成员赋值
    u.ch = 'A'; // 'A'的ASCII码值是 65
    printf("【赋值u.ch后】 u.ch = %c , u.num = %d\n", u.ch, u.num);
    
    // 第2步：给整型成员赋值 → 覆写内存，ch的值被覆盖失效
    u.num = 1234;
    printf("【赋值u.num后】u.ch = %c , u.num = %d\n", u.ch, u.num);
    // 第2步：给整型成员赋值 → 覆写内存，ch的值被覆盖失效
    u.num = 0;
    printf("【赋值u.num后】u.ch = %c , u.num = %d\n", u.ch, u.num);
    // 第1步：给字符成员赋值
    u.ch = 'A'; // 'A'的ASCII码值是 65
    printf("【赋值u.ch后】 u.ch = %c , u.num = %d\n", u.ch, u.num);

    // 内存对齐补位：每一部分对齐4字节
    // 结构体的大小等于各成员大小之和加上补位字节
    printf("结构体 struct 总大小：%zu 字节\n", sizeof(struct MyStruct));
    // 联合体的大小等于其最大成员的大小
    printf("联合体 union 总大小：%zu 字节\n", sizeof(union Data));
    return 0;
}
