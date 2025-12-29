#include <stdio.h>
#include <stdlib.h>
struct Node{
    char entry;
    struct Node *next;
};
int main(){
    int i = 0;
    struct Node *p1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p3 = (struct Node *)malloc(sizeof(struct Node));
    if(p1) p1->entry = 'A';
    if(p2) p2->entry = 'B';
    if(p3) p3->entry = 'C';
    p1->next = p2;
    p2->next = p3;
    p3->next = p1;   // 形成循环链表
    for (size_t i = 0; i < 9; i++)
    {
        printf("Node %d: %c\n", i%3 + 1, p1->entry);
        p1 = p1->next;
    }
    
}