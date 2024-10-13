#include <iostream>
#include <random>
#include <chrono>
using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int n;
string s[4] = {"Perfect", "Great", "Good", "Miss"};
int w[5] = {0,10,5,3,1};
int sum[5];

int main() {
    n = rnd() % 100000 + 1;
    cout << n << endl;
    for(int i=1;i<=4;i++) sum[i] = sum[i-1] + w[i];
    for(int i=1;i<=n;i++){
        int x = rnd() % sum[4] + 1;
        for(int j=1;j<=4;j++){
            if(x > sum[j-1] && x <= sum[j]){
                cout << s[j-1] << endl;
                break;
            }
        }
    }
}