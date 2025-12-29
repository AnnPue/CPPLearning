/*
本程序实现对输入的字母串进行ASCII码排序，并将排序后的字母存入循环单链表中，最后输出链表内容并释放内存。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LEN = 2000;

typedef struct Node {
    int data;           // 存储字母的ASCII码值
    struct Node* next;  // 指向下一个节点
} Node;

typedef struct LinkedList {
    Node* head; // 指向循环单链表的头节点
} LinkedList;

void pcsLongInput(char *);          // 处理超长输入
void merge(char *, int, int, int);  // 排序与合并子数组
void mergeSort(char *, int, int);   // 归并排序的递归函数
LinkedList *createLinkedList();     // 创建循环单链表
void append(LinkedList *, int);     // 在循环单链表末尾添加节点
void display(LinkedList *);         // 输出循环单链表内容 
void freeLinkedList(LinkedList *);  // 释放循环单链表内存


int main() {
    char str[MAX_LEN];
    int i;
    while(1) {
        printf("请输入一行连续无空格的字母串，输入END程序结束。\n");
        fgets(str, MAX_LEN, stdin);
        if (strcmp(str, "END\n") == 0) {    // 输入END时退出
            system("pause");
            return 0;
        }

        pcsLongInput(str);
        size_t n = strlen(str);

        printf("字符串s1的长度是%zu，内容是：%s\n", n, str);    // 回显输入
        if (n > 1) mergeSort(str, 0, n - 1);                    // 若长度大于1则排序
        printf("按照ASCII码排好序的字母串是：\n%s\n", str);     // 输出排序后字符串

        LinkedList* list = createLinkedList();
        for (i = 0; i < n; i++){
            append(list, str[i]);
        }
        display(list);
        freeLinkedList(list);
    }
    return 0;
}

// 处理超长输入
void pcsLongInput(char *str) {
    str[MAX_LEN - 1] = '\0'; // 确保字符串以'\0'结尾
    char *newline = strchr(str, '\n');
    if (newline == NULL) while (getchar() != '\n');
    str[strcspn(str, "\n")] = '\0'; // 移除换行符
}

// 排序与合并子数组
void merge(char *str, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 将数据拷贝到临时子数组
    char L[n1], R[n2];
    int i, j;
    for (i = 0; i < n1; i++) {
        L[i] = str[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = str[mid + j + 1];
    }

    i = j = 0;
    int k = left;
    while (i < n1 && j < n2) {  // 排序合并两个子数组
        if (L[i] <= R[j]) {
            str[k] = L[i];
            i++;
        }
        else {
            str[k] = R[j];
            j++;
        }
        k++;
    }

    // 复制剩余元素
    while (i < n1) {
        str[k] = L[i];
        k++;
        i++;
    }
    while (j < n2) {
        str[k] = R[j];
        k++;
        j++;
    }
}

// 归并排序的递归函数
void mergeSort(char *str, int left, int right) {
    if (left < right){
        int mid = (left + right) / 2;
        mergeSort(str, left, mid);
        mergeSort(str, mid + 1, right);
        merge(str, left, mid, right);
    }
}

// 创建循环单链表
LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        fprintf(stderr, "内存分配失败！\n");
        exit(1);
    }
    list->head = NULL;  // 初始化头指针为空
    return list;
}

// 在循环单链表末尾添加节点
void append(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "节点创建失败！\n");
        exit(1);
    }
    newNode->data = data;   // 设置节点数据
    newNode->next = NULL;   // 初始化下一个节点指针为空

    if (list->head == NULL) {   // 链表为空，添加第一个节点
        list->head = newNode;
        newNode->next = list->head;  // 形成循环
    }
    else {
        Node* temp = list->head;
        while (temp->next != list->head) {
            temp = temp->next;      // 找到最后一个节点
        }
        temp->next = newNode;       // 将新节点添加到末尾
        newNode->next = list->head; // 形成循环
    }
}

// 输出循环单链表内容
void display(LinkedList* list) {
    printf("以下根据排好序的字符串，进行构建循环单链表，并输出:\n");
    Node* temp = list->head;
    int i = 1;
    do {
        printf("The data of %d node is \"%c\"。\n", i, temp->data);
        temp = temp->next;
        i++;
    } while (temp != list->head);
}

// 释放循环单链表内存
void freeLinkedList(LinkedList* list) {
    Node* current = list->head;
    Node* nextNode;
    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != list->head);

    list->head = NULL;  // 避免野指针
    free(list);
    printf("进行free释放循环单链表的每个节点。\n"); // 提示内存已释放
}
