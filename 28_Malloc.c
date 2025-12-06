#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main()
{   
    char r[100];
    printf("r: ");
    fgets(r, 100, stdin);
    printf("r: %s", r);

    char *s = r;
    printf("s: %s", s);

    size_t n = strlen(r);
    char *t = (char*)malloc((n + 1) * sizeof(char)); // 给t分配空间，长度为n+1（包括结尾\0）
    
    r[0] = toupper(r[0]);//将r的第一个字符转换为大写字母
    strcpy(t, r);//将r里面的字符串复制到t里面
    printf("t: %s", t);
    free(t);//释放t
    return 0;
}
