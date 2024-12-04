#include "testlib.h"
#include <cmath>
#include<bits/stdc++.h>
using namespace std;

string s[2005];
int d[4][3][2] = {
    {{0,0}, {-1,0}, {0,1}},
    {{0,0}, {1,0}, {0,1}},
    {{0,0}, {-1,0}, {0,-1}},
    {{0,0}, {1,0}, {0,-1}}
};

int main(int argc, char *argv[]) {
    /*
    * inf：输入
    * ouf：选手输出
    * ans：标准输出
    */
    registerTestlibCmd(argc, argv);
    int k = inf.readInt();
    for(int i=0;i<(1<<k);i++){
        s[i] = inf.readToken();
    }

    int expect_n = (((1<<k) * (1<<k) - 1) / 3);
    int n = ouf.readInt();
    if(n != expect_n)
        quitf(_wa, "wrong number of Ls: Expected %d, found %d\n", expect_n, n);

    for(int i=1;i<=n;i++){
        int id = ouf.readInt();
        int x = ouf.readInt();
        int y = ouf.readInt();
        if(id < 1 || id > 4)
            quitf(_wa, "invalid id: %d\n", id);
        
        x--; y--;
        for(int z=0;z<3;z++){
            int nx = x + d[id-1][z][0];
            int ny = y + d[id-1][z][1];
            if(nx < 0 || nx >= (1<<k) || ny < 0 || ny >= (1<<k))
                quitf(_wa, "Invalid L:(%d %d %d)\n", id, nx, ny);
            s[nx][ny] = id + '0';
        }
    }

    for(int i=0;i<(1<<k);i++){
        for(int j=0;j<(1<<k);j++){
            if(s[i][j] == '.')
                quitf(_wa, "Unfilled cell: (%d %d)\n", i, j);
        }
    }   
    quitf(_ok, "Correct: using %d Ls\n", n);
}