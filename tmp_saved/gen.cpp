#include <iostream>
#include <random>
#include <chrono>
using namespace std;

mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
    const int MOD = 32768;
    int a = gen() % MOD;
    int b = gen() % MOD;
    cout << a << " " << b;
    return 0;
}