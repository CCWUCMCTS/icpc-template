// B^L == N (mod P) 
// Code by KSkun, 2018/4
#include <cstdio>
#include <cmath>

#include <map>

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

std::map<LL, LL> x;

inline LL bsgs(LL a, LL b, LL p) {
    a %= p; b %= p;
    if(a == 0) return b == 0 ? 1 : -1;
    if(b == 1) return 0;
    LL m = ceil(sqrt(p - 1)), inv = fpow(a, p - m - 1, p);
    x.clear();
    x[1] = m; // use m instead of 0
    for(LL i = 1, e = 1; i < m; i++) {
        e = e * a % p;
        if(!x[e]) x[e] = i;
    }
    for(LL i = 0; i < m; i++) {
        if(x[b]) {
            LL res = x[b];
            return i * m + (res == m ? 0 : res);
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
