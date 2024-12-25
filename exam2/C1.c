#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma GCC optimize(2)

int n;
char *s[405], *t[405];
int tp1[405], tp2[405];
int s_len[405], t_len[403];

char tmp[1000005];
char cur[1000005];
int fuck = 0;
int get_nxt(char *s, int idx, char c){
    while(s[idx] && s[idx] != c) idx ++;
    if(s[idx]) return idx;
    else return -1;
}

int f(char c){
    if(c == '.') return 1;
    else if(c == '^') return 2;
    else if(c == '$') return 3;
    return -1110103;
}

int cmp(char *s, char *t, int len){
    for(int i=0;i<len;i++){
        if(*s < *t) return -1;
        if(*s > *t) return 1;
        ++s;
        ++t;
    }
    return 0;
}

int check(char *sss, int idx){
    int len = fuck;
    char *t = s[idx];
    int l1 = s_len[idx];
    int type = tp1[idx];

    if(type == 2){
        if(cmp(sss, t, l1) == 0) return 0;
        return -1;
    }
    else if(type == 3){
        if(len < l1) return -1;
        int tail = len - l1;
        if(cmp(sss+tail, t, l1) == 0) return tail;
        return -1;
    }
    else{
        for(int i=0;i<len-l1+1;i++){
            if(cmp(sss, t, l1) == 0) return i;
            sss ++;
        }
        return -1;
    }
}

void sub(char *sss, int idx, int pos){
    int len = fuck;
    char *ttt = t[idx];
    int l1 = s_len[idx];
    int l2 = t_len[idx];
    int type = tp2[idx];
    
    int pos1 = pos;
    if(type == 1) pos1 = pos;
    else if(type == 2) pos1 = 0;
    else pos1 = len;

    char *ptr = tmp;
    for(int i=0;i<=len;i++){
        if(pos1 == i){
            memcpy(ptr, t[idx], l2);
            ptr += l2;
        }

        if(i == pos){
            i += l1 - 1;
            continue;
        }

        *ptr = sss[i];
        ptr ++;
    }
    
    *ptr = 0;
    int lll = strlen(tmp);
    memcpy(cur, tmp, lll+1);
}

int main(){
    // char s1[2000000];
    // scanf("%s", s1);
    // printf("%d\n", strlen(s1));
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%s", tmp);
        tp1[i] = f(tmp[0]);

        int l = get_nxt(tmp, 0, '[') + 1;
        int r = get_nxt(tmp, l, ']');
        s[i] = (char *)malloc(r - l + 100);
        for(int j=l;j<r;j++){
            s[i][j-l] = tmp[j];
        }
        s[i][r-l] = '\0';
        s_len[i] = strlen(s[i]);

        tp2[i] = f(tmp[r+1]);
        l = get_nxt(tmp, l, '[') + 1;
        r = get_nxt(tmp, l, ']');
        t[i] = (char *)malloc(r - l + 100);
        for(int j=l;j<r;j++){
            t[i][j-l] = tmp[j];
        }
        t[i][r-l] = '\0';
        t_len[i] = strlen(t[i]);
    }

    // for(int i=1;i<=n;i++){
    //     printf("%d %s %d %s\n", tp1[i], s[i], tp2[i], t[i]);
    // }
    scanf("%s", cur);
    while(1){
        fuck = strlen(cur);
        int flag = 0;
        for(int i=1;i<=n;i++){
            int idx = check(cur, i);
            if(idx == -1) continue;

            sub(cur, i, idx);
            flag = 1;
            // printf("!!!%d\n", i);
            break;
        }   
        // printf("!!!%s\n", cur);
        
        if(flag) continue;
        break;
    }

    printf("%s", cur);
}