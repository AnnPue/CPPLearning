/*
本程序读取用户输入的一行句子, 以空格为分隔符将其分割成若干单词
并逐行输出每个单词, 同时统计单词的总数
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string str;
    int i = 0;
    cout << "本程序会将输入的一行英文句子，分成若干单词每行输出，并统计单词个数。" << endl;
    
    getline(cin, str);//读取一行输入存入字符串str，包括空格，直到遇到换行符为止

    stringstream ss(str);//字符串流, 用于分割字符串
    string word;//储存每个单词

    while (ss >> word){//按空格分割字符串，将ss中的每个单词依次读入word
        i++;
        cout << "第" << i << "个单词：" << word << endl;
    }
    printf("一共%d个单词。\n", i);
    
    printf("请按任意键继续. . .\n");
    cin.get();
    return 0;
}

/*
 * 17_02_DevideWords.cpp
 *
 * Created on: 2025.11.19 Wed.
 * 
 * Almost made by AI. I have to figure out how it works.
 * 
 * Thanks to copilot and doubao.
 */