#include<bits/stdc++.h>
#include<random>
#include<chrono>
using namespace std;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
// 生成随机字符串的函数
string generateRandomString(int len) {
    string str = "";
    for (int i = 0; i < len; ++i) {
        char ch = 'a' + rng() % 2; // 生成随机小写字母
        str += ch;
    }
    return str;
}

int main() {
    // 生成随机长度的S和T
    int lenS = rng() % 1000 + 1; // S的长度为1到1000
    int lenT = rng() % 10 + 1; // T的长度为1到1000

    string S = generateRandomString(lenS);
    string T = generateRandomString(lenT);

    // 输出生成的字符串S和T
    cout << S << endl;
    cout << T << endl;

    return 0;
}