#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
ll ct;
ll A[1020], B[1020];
ll POW(ll a, ll b, ll p) {
    ll cur = a, ans = 1;
    while (b) {
        if (b & 1) ans = ans * cur % p;
        cur = cur * cur % p;
        b >>= 1;
    }
    return ans % p;
}
void exGCD(ll a, ll b, ll &x, ll &y) {
    if (!b) return (void)(x = 1, y = 0);
    exGCD(b, a % b, x, y);
    ll tmp = x;
    x = y;
    y = tmp - a / b * y;
}
inline ll INV(ll a, ll p) {
    ll x, y;
    exGCD(a, p, x, y);
    return (x % p + p) % p;
}
// n个方程：x=a[i](mod m[i]) (0<=i<n)
ll CRT(int n, ll *a, ll *m) {
    ll M = 1, ret = 0;
    for (int i = 1; i <= n; i++) M *= m[i];
    for (int i = 1; i <= n; i++) {
        ll w = M / m[i];
        ret = (ret + w * INV(w, m[i]) * a[i]) % M;
    }
    return (ret + M) % M;
}

inline ll G(ll n, ll P) {
    if (n < P) return 0;
    return G(n / P, P) + (n / P);
}
inline ll F(ll n, ll p, ll pk) {
    if (n == 0) return 1;
    ll rou = 1;  //循环节
    ll rem = 1;  //余项
    for (ll i = 1; i <= pk; i++) {
        if (i % p) rou = rou * i % pk;
    }
    rou = POW(rou, n / pk, pk);
    for (ll i = pk * (n / pk); i <= n; i++) {
        if (i % p) rem = rem * (i % pk) % pk;
    }
    return F(n / p, p, pk) * rou % pk * rem % pk;
}
ll exC(ll n, ll m, ll p,ll pk) {
    ll fz=F(n,p,pk),fm1=INV(F(m,p,pk),pk),fm2=INV(F(n-m,p,pk),pk);
    ll mi=POW(p,G(n,p)-G(m,p)-G(n-m,p),pk);
    return fz*fm1%pk*fm2%pk*mi%pk;
}
ll exLucas(ll n, ll m, ll p) {
    ll tmp = p, ct = 0;
    for (ll i = 2; i * i <= tmp; i++) {
        if (tmp % i == 0) {
            ll s = 1;
            while (tmp % i == 0) {
                s *= i;tmp /= i;
            }
            B[++ct]=s;A[ct]=exC(n,m,i,s);
        }
    }
    if (tmp > 1){
        B[++ct]=tmp;
        A[ct]=exC(n,m,tmp,tmp);
    }
    return CRT(ct,A,B);
}

ll n, m, p;
int main() {
    scanf("%lld%lld%lld", &n, &m, &p);
    printf("%lld\n", exLucas(n, m, p));
    return 0;
}