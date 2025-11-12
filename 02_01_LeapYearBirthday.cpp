#include<stdio.h>

int CountLeapYear(int year) {//计算闰年数量
	int count = 1;//2000为闰年, 故默认计数1
	for (; year > 2000; year--) {
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {//判断是否为闰年: 被4整除且不被100整除 或 被400整除
			count++;
		}
	}
	return count;
}

int main() {
	int year = -1;
	printf("小明是闰年2000年2月29日出生的。他有7个非常好的小伙伴，都不是2月份出生。\n");
	printf("小明生日时候，会收到每个小伙伴100个棒棒糖。小伙伴过生日时候，小明会送出20个棒棒糖。\n");
	printf("根据输入的结束年份，计算小明从出生年份年初，到该年份年尾一共过了几次生日，送出多少个棒棒糖，获得多少个棒棒糖。\n");
	printf("请输入结束的年份[2000,3000]之间的正整数，输入999时程序退出。\n");
	while (year != 999) {
		while ((scanf("%d", &year) != 1 || year < 2e3 || year > 3e3) && year != 999) {//当scanf("%d",&n)!=1时候，说明没有成功获得输入
			printf("非法输入，需要[2000,3000]闭区间的正整数，输入999时程序退出。\n");
			putchar('\a');
			while (getchar() != '\n');//过滤掉后面所有输入缓存
		}
		if (year == 999)break;//获得999，退出循环
		int leapYear = CountLeapYear(year);//闰年的数量
		int give = (year - 2000 + 1) * 140;//送出棒棒糖数量, 过年数乘7乘20
		int get = leapYear * 700;//获得棒棒糖数量, 闰年数乘7乘100
		printf("小明从出生年份年初，到%d年尾一共过了%d次生日。\n", year, leapYear);
		printf("小明从出生年份年初，到%d年尾\"理论上(棒棒糖可以其父母代送)\"一共送出%d个棒棒糖。\n", year, give);
		printf("小明从出生年份年初，到%d年尾\"理论上(棒棒糖可以其父母代送)\"一共收到小伙伴%d个棒棒糖。\n", year, get);
		printf("请输入结束的年份[2000,3000]之间的正整数，输入999时程序退出。\n");
	}
	
	return 0;
}
