#include <iostream>
#include <random>
#include <chrono>
using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int main(){
    int n = rnd() % 6 + 5;
    int k = 1<<n;
    cout << n << endl;
    vector<vector<char>> s(k, vector<char>(k, '.'));
    int x = rnd() % k;
    int y = rnd() % k;
    s[x][y] = 'X';
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            cout << s[i][j];
        }
        cout << endl;
    }
}