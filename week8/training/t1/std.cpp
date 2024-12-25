#include<bits/stdc++.h>
using namespace std;

string s, t;
int main(){
    cin >> s >> t;
    int n = s.length(), m = t.length();
    bool find = false;

    for(int i=0;i<n;i++){
        if(s.substr(i, m) == t){
            cout << i << " ";
            find = true;
        }
    }

    if(!find) cout << -1 << endl;
}