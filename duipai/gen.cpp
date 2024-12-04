#include<bits/stdc++.h>
using namespace std;
#include<random>
mt19937_64 rng(time(0));

int main(){
    int T = 10;
    cout << T << endl;
    while(T--){
        string s,t;
        int n1 = rng() % 30 + 1, n2 = rng() % 30 + 1;
        for(int i=0;i<n1;i++){
            char c = 'a' + rng() % 26;
            s.push_back(c);
        }

        for(int i=0;i<n2;i++){
            char c = 'a' + rng() % 26;
            t.push_back(c);
        }
        cout << s <<";" << t << ";";
        int a = rng() % 10 + 1, b = rng() % 10 + 1;
        int len = rng() % (n1 + n2 + 5) + 1;
        cout << a << ";" << b << ";" << len << endl;
    }
}