#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LEN = 2000;

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

void processLongInput(char *);      // 处理超长输入
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

        processLongInput(str);
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
void processLongInput(char *str) {
    str[MAX_LEN - 1] = '\0'; // 确保字符串以'\0'结尾
    char *newline = strchr(str, '\n');
    if (newline == NULL) while (getchar() != '\n');
    str[strcspn(str, "\n")] = '\0';
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
    list->head = NULL;
    return list;
}

// 在循环单链表末尾添加节点
void append(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "节点创建失败！\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = list->head;  // 形成循环
    }
    else {
        Node* temp = list->head;
        while (temp->next != list->head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = list->head;  // 形成循环
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
    printf("进行free释放循环单链表的每个节点。\n");
}
