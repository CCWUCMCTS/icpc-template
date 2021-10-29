// B^L == N (mod P) 
// Code by KSkun, 2018/4
#include <cstdio>
#include <cmath>
#include <cstring>

#include <algorithm>

typedef long long LL;

inline char fgc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF 
        : *p1++;
}

inline LL readint() {
    register LL res = 0, neg = 1;
    char c = fgc();
    while(c < '0' || c > '9') {
        if(c == '-') neg = -1;
        c = fgc();
    }
    while(c >= '0' && c <= '9') {
        res = res * 10 + c - '0';
        c = fgc();
    }
    return res * neg;
}

inline LL fpow(LL n, LL k, LL p) {
    LL res = 1; n %= p;
    while(k) {
        if(k & 1) res = res * n % p;
        n = n * n % p;
        k >>= 1;
    }
    return res;
}

inline LL exgcd(LL a, LL b, LL &x, LL &y) {
    if(!b) {
        x = 1; y = 0;
        return a;
    }
    LL res = exgcd(b, a % b, x, y);
    LL t = x; x = y; y = t - a / b * y;
    return res;
}

const int MO = 611977, MAXN = 1000005;

struct HashMap {
    LL head[MO + 5], key[MAXN], value[MAXN], nxt[MAXN], tot;
    inline void clear() {
        tot = 0;
        memset(head, -1, sizeof(head));
    }
    HashMap() {
        clear();
    }
    inline void insert(LL k, LL v) {
        int idx = k % MO;
        for(int i = head[idx]; ~i; i = nxt[i]) {
            if(key[i] == k) {
                value[i] = std::min(value[i], v);
                return;
            }
        }
        key[tot] = k; value[tot] = v; nxt[tot] = head[idx]; head[idx] = tot++;
    }
    inline LL operator[](const LL &k) const {
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
    LL m = ceil(sqrt(p - 1)), inv, y;
    exgcd(fpow(a, m, p), p, inv, y); inv = (inv % p + p) % p;
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

inline LL gcd(LL a, LL b) {
    if(!b) return a;
    return gcd(b, a % b);
}

inline LL exbsgs(LL a, LL b, LL p) {
    if(b == 1) return 0;
    LL tb = b, tmp = 1, k = 0;
    for(int g = gcd(a, p); g != 1; g = gcd(a, p)) {
        if(tb % g) return -1;
        tb /= g; p /= g; tmp = tmp * a / g % p;
        k++;
        if(tmp == tb) return k;
    }
    return bsgs(a, b, p);
}

LL a, b, p;

int main() {
    for(;;) {
        a = readint(); p = readint(); b = readint();
        if(!a && !b && !p) break;
        LL res = exbsgs(a, b, p);
        if(res != -1) printf("%lld\n", res); else puts("No Solution");
    }
    return 0;
}
