// create a circular linked list of characters from a string, sort the string, and print the sorted characters in a loop
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // 必须包含：malloc/free/system的头文件
const int LEN = 2000;

// 字符串s1和s2的字典序大小比较函数
int StrCmp(char s1[], char s2[])
{
    int i = -1;
    do
    {
        i++;
        if (s1[i] > s2[i])
            return 1; // s1 > s2
        if (s1[i] < s2[i])
            return -1; // s1 < s2
    } while (s1[i] && s2[i]); // 到字符串末尾结束
    return 0; // s1 == s2
}

// 整行最多拿到len-1个字符，读取一行输入
int GetLine(char s[], int len)
{
    char c;
    int i = 0;
    c = getchar();
    while (c != '\n')
    {
        if (i <= len - 2)
            s[i++] = c;
        c = getchar();
    }
    s[i] = '\0';
    return i;
}

typedef char Node_entry;
struct Node
{
    Node_entry entry;
    struct Node *next;
};

// 修正1：C语言标准中，main函数必须返回int类型，不能是void
int main()
{
    char s[LEN];
    int len;
    char temp;
    int i, j;
    printf("请输入一行连续无空格的字母串，输入END程序结束。\n");
    len = GetLine(s, LEN);
    while (StrCmp(s, "END"))
    {
        printf("输入的字符串长度是%d，内容是：%s\n", len, s);
        // 选择排序：按ASCII从小到大排序字母
        for (i = 0; i < len - 1; i++)
            for (j = i + 1; j < len; j++) // 修正2：排序内层循环起始值，减少无效比较
                if (s[i] > s[j])
                {
                    temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
        printf("按照ASCII码排好序的字母串是：%s\n", s);
        printf("构建循环单链表并循环打印节点:\n");

        struct Node *phead = NULL, *p = NULL;
        if (len <= 0)
        { // 边界判断：空字符串直接跳过构建
            printf("输入为空，无需构建链表\n");
            goto nextInput;
        }
        // 构建循环链表首节点
        phead = p = (struct Node *)malloc(sizeof(struct Node));
        p->entry = s[0];
        // 循环构建后续所有节点
        for (i = 1; i < len; i++)
        {
            p->next = (struct Node *)malloc(sizeof(struct Node));
            p = p->next;
            p->entry = s[i];
        }
        p->next = phead; // 尾节点指向头节点，构成【循环链表】核心特征

        // 循环打印整个循环链表的所有节点
        p = phead;
        for (i = 0; i < len; i++)
        { // 修正3：删除无效的p&&判断，循环次数由len绝对控制
            printf("第%d个节点的数据是：\"%c\"\n", i + 1, p->entry);
            p = p->next;
        }

        // 修正4：核心修复→循环链表的内存释放（解决原代码的内存泄漏+野指针）
        printf("开始释放循环链表的每个节点内存...\n");
        struct Node *tempNode = NULL;
        p = phead;
        for (i = 0; i < len; i++)
        {
            tempNode = p->next; // 先保存下一个节点的地址
            free(p);            // 释放当前节点
            p = tempNode;       // 指针指向下一个节点
        }
        phead = NULL; // 释放后清空头指针，避免野指针

    nextInput:
        printf("\n请输入一行连续无空格的字母串，输入END程序结束。\n");
        len = GetLine(s, LEN);
    }
    system("pause");
    return 0; // 修正5：int main必须有返回值
}
