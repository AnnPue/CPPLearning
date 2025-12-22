# 指针

## 2025.12.22

指针是全局的

&：取变量首字节的地址

指针大小与指向的数据类型无关

32位：任何类型的指针都是4个字节；64位：8个字节

p + n == p + n * sizeof(type)

常量指针：
~~~
int n[10];  // n == &n[0]
~~~
变量指针：
~~~
int *p;
p = n;  // p == &n[0]
p++;    // *p == n[1]
~~~
~~~
char *massage1 = "How are you? ";   // 变量指针
char massage2[] = "How are you? ";  // 常量指针

massage1++; // *massage1 == 'o'
~~~

~~~
void(*sp)(int, int);    // 函数指针：将一个操作作为参数传递
sp = swap;
sp(a, b);
~~~
指向常量的指针：const int *p，可以改变指向，不能通过指针修改值


指针常量：不可以改变指向，能通过指针修改值
```
int a = 10;
int *const p = &a;
```