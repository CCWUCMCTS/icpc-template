// Code by KSkun, 2018/4
#include <cstdio>

typedef long long LL;

const int MAXN = 100005;

LL k, a[MAXN], r[MAXN];

inline LL exgcd(LL a, LL b, LL &x, LL &y) {
    if(!b) {
        x = 1; y = 0; return a;
    }
    LL res = exgcd(b, a % b, x, y);
    LL t = x; x = y; y = t - a / b * y;
    return res;
}

inline LL excrt() {
    LL A = a[1], R = r[1], x, y;
    for(int i = 2; i <= k; i++) {
        LL g = exgcd(A, a[i], x, y);
        if((r[i] - R) % g) return -1;
        x = (r[i] - R) / g * x; x = (x % (a[i] / g) + a[i] / g) % (a[i] / g);
        R = A * x + R;
        A = A / g * a[i]; R %= A;
    }
    return R;
}

int main() {
    while(scanf("%lld", &k) != EOF) {
        for(int i = 1; i <= k; i++) {
            scanf("%lld%lld", &a[i], &r[i]);
        }
        printf("%lld\n", excrt());
    }
    return 0;
}