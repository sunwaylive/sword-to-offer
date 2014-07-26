#include <cstdio>
#include <cstring>

int nxt[10000];
char txt[10000], pat[10000];

void getNext(char* pat, int next[]){
    const int plen = strlen(pat);
    next[0] = -1;
    int j = -1;
    for(int i = 1; i < plen; ++i){
        while(j > -1 && pat[j+1] != pat[i]) j = next[j];
        if(pat[j+1] == pat[i]) j++;
        next[i] = j;
    }
}

int kmp(char* txt, char* pat, int next[]){
    getNext(pat, next);//!! call getNext
    const int tlen = strlen(txt);
    const int plen = strlen(pat);
    int cnt = 0;
    int j = -1;
    for(int i = 0; i < tlen; ++i){
        while(j > -1 && pat[j+1] != txt[i]) j = next[j];
        if(pat[j+1] == txt[i]) j++;
        if(j == plen - 1) {//attention
            cnt++;
            j = next[plen - 1];
        }
    }
    return cnt;
}

int main()
{
    int t;
    scanf("%d", &t);

    while(t--){
        scanf("%s", pat);
        //printf("%s\n", pat);
        scanf("%s", txt);
        //printf("%s\n", txt);
        printf("%d\n", kmp(txt, pat, nxt));
    }
    return 0;
}
