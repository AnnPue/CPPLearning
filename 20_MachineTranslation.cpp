/*
牛牛的电脑上安装了一个机器翻译软件，它依次将每个英文单词替换为对应的中文含义。
软件内部有 M 个缓存单元，每个单元存放一个单词和译义。翻译某个单词时：
∙ ∙如果缓存中已有该单词，则直接使用（缓存命中）；
∙ ∙否则需要到外存词典查找（缓存未命中），并将该单词及译义插入缓存：若缓存未满，则占用一个空闲单元；
∙ ∙若缓存已满，则清除最早进入缓存的单词后插入新单词。
给定长度为 N 的文章（由 N 个整数编码表示单词），初始缓存为空，统计翻译过程中需要查词典的次数。
输入描述：
第一行输入两个整数 M,N（1≦M≦100，1≦N≦1000），分别表示缓存容量和文章单词数。
第二行输入 N 个整数 w1,w2,…,wN​（0≦wi≦1000），表示文章中按顺序出现的单词编码。
输出描述：
输出一个整数，表示翻译过程中缓存未命中（查词典）的总次数。
*/

#include <iostream>
#include <queue>
using namespace std;


bool find(queue <int> q, int x) {//在队列里找x，不影响原队列
    while (!q.empty()) {
        if (q.front() == x) {//检查首项，与x相等则是找到了，返回true
            return true;
        } else {
            q.pop();//还未找到就删除首项
        }
    }
    return false;//遍历完所有项都没找到，返回false
}
int main() {
    int m, n, no = 0, wi;//no：缓存未命中（查词典）的总次数
    queue <int> cache;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> wi;
        if (!find(cache, wi)) {//若没找到
            cache.push(wi);//存入缓存
            no++;//计数
            if (cache.size() > m) {//若缓存空间不足，则先进先出
                cache.pop();//本题要求先进来的缓存先出，用queue最方便
            }
        }
    }
    cout << no << endl;
    return 0;
}