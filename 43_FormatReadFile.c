#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct // 设置学生类型
{
    char name[10];
    int score;
} Student;

// 优先按分数降序排名，分数相同按名称升序排名
int cmp(const void *a, const void *b)
{
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b;
    if (s1->score < s2->score)
        return 1;
    if (s1->score > s2->score)
        return -1;
    else
        return strcmp(s1->name, s2->name);
}

int main()
{
    printf("从当前目录的info.txt中读取所有学生姓名及成绩分数，\
然后按照成绩分数从高到低的顺序写入info2.txt文件中。\n");
    FILE *fp1 = fopen("43_info.txt", "r"); // 读模式
    Student students[5] = {                // 初始化空数组
                           {"", 0},
                           {"", 0},
                           {"", 0},
                           {"", 0},
                           {"", 0}};
    int i;
    for (i = 0; i < 5; i++)
    {
        fscanf(fp1, "%s  %d\n", &students[i].name, &students[i].score); // 将源文件数据存入students
    }
    fclose(fp1);                              // 关闭文件
    qsort(students, 5, sizeof(Student), cmp); // 排序

    FILE *fp2 = fopen("43_info2.txt", "w"); // 写模式
    for (i = 0; i < 5; i++)
    {
        fprintf(fp2, "%s,%d\n", students[i].name, students[i].score); // 写入目标文件
    }
    fclose(fp2); // 关闭文件
    printf("程序结束，结果见当前目录的info2.txt中。\n");
    system("pause");
    return 0;
}
