#include <stdio.h>
//充分遵守One Screen
void Wall(int wid, int hei, char fill) {//画墙的函数
	int i, j;
	for (i = 0; i < hei; i++) {//重复height次
		for (j = 0; j < wid; j++) {//画一行
			printf("%c", fill);
		}
		printf("\n");//一行结束后换行
	}
}

void Triangle(int wid, int hei, char fill) {//画三角的函数
	int i = 1, j, big = (hei > wid) ? hei : wid;//取高度和宽度中的较大者
	for (; i <= big; i++) {//i递增
		for (j = 0; j < i; j++) {//每行执行i次
			printf("%c", fill);
		}
		printf("\n");//一行结束后换行
	}
}

void Frame(int wid, int hei, char fill) {//画框的函数
	int i = 0, j;
	for (; i < hei; i++) {
		for (j = 0; j < wid; j++) {
			if (i == 0 || i == hei - 1 || j == 0 || j == wid - 1) {//若为 首行or尾行or首列or尾列 才画
				printf("%c", fill);
			}
			else {//否则填空格
				printf(" ");
			}
		}
		printf("\n");//一行结束后换行
	}
}

int GetValid(){//获得合规数值作为高度or宽度
	int input;
	while (1) {
		while (getchar() != '\n');//清空输入流, 防止死循环或影响后续
		if (scanf(" %d", &input) != 1 || input < 1 || input > 3000) {//输入高度or宽度并检查
			printf("非法输入，需要[1, 3000]闭区间的正整数。\n");
			continue;//跳过return, 返回函数开头
		}
		return input;//若输入有问题就会跳过此行, 没问题就返回input值
	}
}

void Solve(int command, int wid, int hei, char fill){//根据command调用相应函数
	switch (command) {//其他输入已经被排除, 到这里command只能是1or2or3
		case 1: {
			Wall(wid, hei, fill);
			break;
		}
		case 2: {
			Frame(wid, hei, fill);
			break;
		}
		case 3: {
			Triangle(wid, hei, fill);
			break;
		}
	}
}

int main(){
	int command = 0, width = -1, height = -1;
	char fill;
	while(1){
		printf("请输入要绘制的图形：1-墙  2-框  3-三角， 输入-1结束。注意：对于所有输入我们采用能用则用，不行报错的原则。\n");

		if ((scanf(" %d", &command) != 1 || command < 1 || command > 3) && command != -1) {//输入指令并检查, 注意排除输入-1情况
			printf("类型不符合要求，请重新来！\n");
			while (getchar() != '\n');//清空输入流, 防止死循环或影响后续
			continue;//回到line70
		}else if (command == -1) break;//输入-1退出循环, 同时也是退出程序

		while (getchar() != '\n');//清空输入流, 防止死循环或影响后续
		printf("请输入图形的填充字母\n");
		scanf(" %c", &fill);//输入填充字符

		printf("请输入高度\n");
		height = GetValid();//获得高度
		printf("请输入宽度\n");
		width = GetValid();//获得宽度
		
		while (getchar() != '\n');//防止输入宽度时多输入影响下个循环
		Solve(command, width, height, fill);
	}
	return 0;
}