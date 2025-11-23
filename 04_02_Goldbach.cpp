//输入一个偶数n(4<=n<=10000)，输出从4到n的所有偶数的哥德巴赫猜想表达式。
//哥德巴赫猜想：每个大于2的偶数都可以表示为两个素数之和。
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>//为了使用find函数

static std::vector<int> prime_cache = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};  // 初始存入较小素数

// 判断一个数是否为素数（复用缓存，无二次判断）
bool IsPrime(int n) {
    // 优化1：先检查是否已在缓存中（避免对同一数重复判断）
    if (std::find(prime_cache.begin(), prime_cache.end(), n) != prime_cache.end()) {
        return true;
    }
    // 优化2：仅用缓存中 ≤ sqrt(n) 的素数判断（合数的因子必有素数）
    for (int p : prime_cache) {
        if (p > sqrt(n)) break;  // 超过平方根，无需继续
        if (n % p == 0) return false;  // 能被素数整除，不是素数
    }
    // 若为素数，加入缓存（供后续判断复用）
    prime_cache.push_back(n);
    return true;
}

int main(){
    int n;
    std::cin >> n;
    printf("4=2+2\n");//特殊情况
    int i = 6, j;
    for (; i<= n;i+=2){
        if (IsPrime(i-2)){//特殊情况 2 加上一个素数
            printf("%d=2+%d\n", i, i - 2);
            continue;
        }
        for(j = 3; j < i; j += 2){//从3开始找两个奇素数之和
            if (IsPrime(j) && IsPrime(i-j)){
                printf("%d=%d+%d\n", i, j, i - j);
                break;
            }
        }
    }
    return 0;
}