//输入t组数据, 每组4个字符串, 代表A,B,C,D四个选项
//三长一短选最短, 三短一长选最长, 否则C
#include<bits/stdc++.h>
using namespace std;

int t,Min,mini,Max,maxi,s[605];
char a[5][605];
int main(){
    scanf("%d",&t);
    while(t--){
        memset(s,0,sizeof (s));//s数组清零
        Min=605;
        mini=maxi=3;
        Max=0;
        for(int i=1;i<=4;++i){
            scanf("%s",a[i]);
            ++s[strlen(a[i])];//统计长度出现次数
            if (strlen(a[i])<=Min){Min=strlen(a[i]);mini=i;}//记录最短字符串
            if (strlen(a[i])>=Max){Max=strlen(a[i]);maxi=i;}//记录最长字符串
        }
        if((s[Min] > 1 && s[Max] > 1) || (s[Min] == 1 && s[Max] == 1))
            printf("C\n");
        else if (s[Min]==1)
            printf("%c\n",64+mini);//ASCII码转换
        else if (s[Max]==1)
            printf("%c\n",64+maxi);
    }
    return 0;
}