#include <iostream>
#include <random>
#include <chrono>
using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
    const int MOD = 1000;
    int a = rnd() % MOD;
    int b = rnd() % MOD;
    // int a = 0, b = 0;
    cout << a << " " << b;
    return 0;
}