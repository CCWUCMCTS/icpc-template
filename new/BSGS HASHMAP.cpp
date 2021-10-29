// B^L == N (mod P) 
// Code by KSkun, 2018/4
#include <cstdio>
#include <cmath>
#include <cstring>

#include <algorithm>

typedef long long LL;

inline LL fpow(LL n, LL k, LL p) {
    LL res = 1; n %= p;
    while(k) {
        if(k & 1) res = res * n % p;
        n = n * n % p;
        k >>= 1;
    }
    return res;
}

const int MO = 611977, MAXN = 1000005;

struct HashMap {
    int head[MO + 5], key[MAXN], value[MAXN], nxt[MAXN], tot;
    inline void clear() {
        tot = 0;
        memset(head, -1, sizeof(head));
    }
    HashMap() {
        clear();
    }
    inline void insert(int k, int v) {
        int idx = k % MO;
        for(int i = head[idx]; ~i; i = nxt[i]) {
            if(key[i] == k) {
                value[i] = v;
                return;
            }
        }
        key[tot] = k; value[tot] = v; nxt[tot] = head[idx]; head[idx] = tot++;
    }
    inline int operator[](const int &k) const {
        int idx = k % MO;
        for(int i = head[idx]; ~i; i = nxt[i]) {
            if(key[i] == k) return value[i];
        }
        return -1;
    }
} x;

inline LL bsgs(LL a, LL b, LL p) {
    a %= p; b %= p;
    if(a == 0) return b == 0 ? 1 : -1;
    if(b == 1) return 0;
    LL m = ceil(sqrt(p - 1)), inv = fpow(a, p - m - 1, p);
    x.clear();
    x.insert(1, 0);
    for(LL i = 1, e = 1; i < m; i++) {
        e = e * a % p;
        if(x[e] == -1) x.insert(e, i);
    }
    for(LL i = 0; i < m; i++) {
        if(x[b] != -1) {
            LL res = x[b];
            return i * m + res;
        }
        b = b * inv % p;
    }
    return -1;
}

LL p, b, n;

int main() {
    while(scanf("%lld%lld%lld", &p, &b, &n) != EOF) {
        LL res = bsgs(b, n, p);
        if(res != -1) printf("%lld\n", res); else puts("no solution");
    }
    return 0;
}
