#include<bits/stdc++.h>
using namespace std;

int n,q;
int l = 1, r = 2;
int main(){
    cin >> n >> q;
    int ans = 0;
    while(q--){
        char c;
        int p;
        cin >> c >> p;
        if(c == 'L'){
            int tot = 0;
            int t = l;
            while(t != p){
                t ++;
                tot ++;
                if(t > n) t -= n;
                if(t == r){
                    tot = -1;
                    break;
                }
            }

            if(tot == -1){
                tot = 0;
                int t = l;
                while(t != p){
                    t --;
                    tot ++;
                    if(t == 0) t += n;
                }
            }

            ans += tot;
            l = p;
        }
        else{
            int tot = 0;
            int t = r;
            while(t != p){
                t ++;
                tot ++;
                if(t > n) t -= n;
                if(t == l){
                    tot = -1;
                    break;
                }
            }

            if(tot == -1){
                tot = 0;
                int t = r;
                while(t != p){
                    t --;
                    tot ++;
                    if(t == 0) t += n;
                }
            }

            ans += tot;
            r = p;
        }
    }
    cout << ans << endl;
}