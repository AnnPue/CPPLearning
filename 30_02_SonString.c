//读取一行原串，读取一行子串，在原串中查找子串出现的所有位置。

#include<stdio.h>
#include<stdbool.h>//for bool type
const int LEN = 2000;

int GetLine(char s[], int len){ //整行最多拿到len-1个字符
	char c;
	int i=0;//单词个数
	c=getchar();
	while(c!='\n'){//读到行尾结束，最多拿len-1个字符
		if(i<=len-2)s[i++]=c;
		c=getchar();
	}
	s[i]='\0';//字符串结束符
	return i;//返回字符串读到的长度
}


void StrFind(char s1[], char s2[]){
	int i,k;
	int flag;//匹配旗帜，1表示匹配中，0表示不匹配
	i=0;//从字符串索引0位置开始扫描
	while(s1[i]){//一直做到原字符串s1的结束符
		k=0;//s2的索引0位置开始扫描
		flag=1;//初始为匹配中
		while(flag && s2[k]){//做到不匹配，或者s2尾部，退出循环
			if(s1[i+k]==s2[k])flag=1;//匹配中
			else flag=0;//不匹配
			k++;//依次往后做
		}
		if(flag)printf("在原串的%d位置找到子串\n", i);//跳出内循环时，一直匹配，找到匹配点进行输出
		i++;//原字符串开始位置，向后位移1位
	}
}


void main()
{
    char s1[LEN];//原字符串
	char s2[LEN];//子串
	int len1=0;//原字符串长度
	int len2=0;//子串长度
    printf("=====================================\n");
    printf("       字符串查找匹配应用\n");
    printf("=====================================\n");
    int choice=-1;//菜单选择项目
    bool isSet=false;//是否通过菜单1设置过初始值
    do {
        printf("\n请选择操作:\n");
        printf("1. 输入原字符串和子串：\n");
        printf("2. 输出子串在原字符串中所有出现的位置索引：\n");
        printf("3. 退出\n");
        printf("请输入选项 (1-3): ");
        while(scanf("%d", &choice)!=1 || choice!=1 && choice!=2 && choice!=3){
            printf("请您输入选项 (1-3)，为正整数，请重新来！\n");
            while(getchar()!='\n');//过滤掉后面所有输入缓存
        }
        while(getchar()!='\n');//过滤掉后面所有输入缓存
        switch (choice) {
            case 1:
                isSet=true;//已经设置过字符串
                printf("请输入一行原串：\n");
                len1=GetLine(s1,LEN);//获得原字符串
                printf("原串s1的长度是%d，内容是：%s\n", len1, s1);//信息回显
                printf("请输入一行子串：\n");
                len2=GetLine(s2,LEN);//获得子串
                printf("子串s2的长度是%d，内容是：%s\n", len2, s2);//信息回显
                break;
            case 2:
                if(!isSet){printf("请先通过菜单1设置两个字符串的值。\n");break;}//未通过菜单1设置过字符串初始值
                printf("\n查找结果：\n");
                StrFind(s1,s2);//获得所有匹配点结果，并输出
                break;
            case 3:
                printf("感谢使用字符串查找匹配应用!\n");
                break;
            default:
                printf("无效选项，请重新选择!\n");
                break;
        }
    } while (choice != 3);
    system("pause");
}

//written by teacher Bao Yu