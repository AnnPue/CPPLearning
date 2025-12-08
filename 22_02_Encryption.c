#include "stdio.h"
const int MAX=2000;//明文字符串最大长度

int GetKey(){//获得秘钥
    int n=-1;
    printf("请输入key值(整数【1，10】之间):\n");
    while(scanf("%d", &n)!=1 || n<1 || n>10){
        printf("输入的数值不对，【1，10】之间，key为10时，程序退出。\n");
        while(getchar()!='\n');//过滤掉后面所有输入缓存
    }
    while(getchar()!='\n');//过滤掉后面所有输入缓存
    printf("key值是：%d\n", n);
    return n;
}

int GetLine(char s[], int len){ //整行最多拿到len-1个字符
	char c;
	int i=0;//单词个数
	c=getchar();//填充读
	while(c!='\n'){//读到行尾结束，最多拿len-1个字符。'\n'哨兵
		if(i<=len-2)s[i++]=c;
		c=getchar();
	}
	s[i]='\0';//字符串结束符
	return i;//返回字符串读到的长度
}

void GetString(char s[], int len){//输入明文字符串
    printf("请输入明文字符串:\n");
    GetLine(s,len);
    printf("明文字符串是：%s\n",s);
}


void PrintAnswer(const char s[], int key){//输出加密后的字符串，注意const的保护
    char c;
    int i=0;
    printf("加密后的密文字符串是：");
    while(s[i]){//遍历到字符串结束符
        c=s[i];
        if(isalpha(c))c=c-key;//如果是字母，就减少key
        putchar(c);//非字母，保持不变，并输出
        i++;
    }
    putchar('\n');
}


int main(){
    int key=-1;//初始化为非法值，防止数据污染
    char s[MAX];//明文字符串
    char tip[]="有一种加密算法，若明文是字母则将其减少一个整数key值(整数【1，10】之间，\
若不是则保持不变。\n请输入一段明文，根据key，加密后并输出其密文。\n\
当输入key为10时，程序退出\n";
    printf("%s",tip);
    key=GetKey();//获得秘钥
    while(key!=10){//key为10时，程序退出
        GetString(s, MAX-1);//获得明文字符串
        PrintAnswer(s,key);//输出加密字符串
        key=GetKey();//获得秘钥
    }
    system("pause");//暂停程序的执行，等待用户按下任意键后继续执行。
    return 0;
}

/*
write by Bao Yu
*/