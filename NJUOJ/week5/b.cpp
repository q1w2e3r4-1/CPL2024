#include<bits/stdc++.h>
using namespace std;

int n, a[2005];
int main(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    next_permutation(a+1, a+1+n);

    for(int i=1;i<=n;i++) cout << a[i] << " ";
}