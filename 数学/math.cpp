#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
//#define io_opt ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#ifdef io_opt
#define scanf sb
#define printf sb
#endif
typedef long long ll;
#define lll __int128
typedef double db;
using namespace std;
#define eps 0.000000001
int mod=1e9+7;
const int PN = 100020;
int pn;
bool ipr[PN + 10];
int pri[PN / 5];
int phi[PN + 10];
void prime() {
    memset(ipr, true, sizeof(ipr));
    ipr[1] = false;
    int N = sqrt(PN) + 0.5;
    for (int i = 2; i <= N; i++) {
        if (ipr[i]) {
            int d = i == 2 ? i : 2 * i;
            for (int j = i * i; j <= PN; j += d) {
                ipr[j] = false;
            }
        }
    }
    for (int i = 1; i <= PN; i++) {
        if (ipr[i]) pri[++pn] = i;
    }
}
int ct[PN/5];
void fj(int t){
    for(int i=1;i<=pn&&pri[i]*pri[i]<=t;i++){
        int cnt=0;
        while(t%pri[i]==0){
            t/=pri[i];
            cnt++;
        }
        ct[pri[i]]=max(ct[pri[i]],cnt);
    }
    if(t>1) ct[t]=max(ct[t],1);
}
void eprime() { //not verify
    memset(ipr, true, sizeof(ipr));
    ipr[1] = false;
    phi[1] = 1;
    for (int i = 2; i <= PN; i++) {
        if (ipr[i]) pri[++pn] = i, phi[i] = i - 1;
        for (int j = 1; j <= pn && pri[j] * i <= PN; j++) {
            ipr[pri[j] * i] = false;
            if (i % pri[j]) phi[i * pri[j]] = phi[i] * phi[pri[j]];
            else {
                phi[i * pri[j]] = phi[i] * pri[j];
                break;
            }
        }
    }
}

int euler_phi(int n) {
    int ans = n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}

ll speed(ll a, ll b, ll p) {
    ll cur = a, ans = 1;
    while (b) {
        if (b & 1) ans = ans * cur % p;
        cur = cur * cur % p;
        b >>= 1;
    }
    return ans % p;
}
inline ll mm(ll k,ll p){
    return k<p?k:k%p;
    return k>=p?k%p:(k>=0?k:k%p+p);
}
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}
ll exgcd(ll &x,ll &y,ll a,ll b){
    if(!b)
    {
        x=1;
        y=0;
        return a;
    }
    ll gd=exgcd(x,y,b,a%b);
    ll t=x;
    x=y;
    y=t-a/b*y;
    return gd;
}
ll inv(ll a,ll b){
    ll x,y;
    exgcd(x,y,a,b);
    return mm(x,b);
}
const int MatrixSize=20;
struct Mat{
    int m,n;
    ll a[MatrixSize][MatrixSize];
    Mat(int mm=0,int nn=0,int init=-1):m(mm),n(nn){
        if(mm==0||nn==0){
            m=n=2;
            a[0][0]=1;
            a[0][1]=1;
            a[1][0]=1;
            a[1][1]=0;
            return;
        }
        if(init==-1) return;
        else if(init==0){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    a[i][j]=0;
                }
            }
        }
        else if(m==n){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    a[i][j]=i==j?1:0;
                }
            }
        }
    }

};
Mat operator+(Mat x,Mat y){
    for(int i=0;i<x.m;i++){
        for(int j=0;j<x.n;j++){
            x.a[i][j]=mm(x.a[i][j]+y.a[i][j],mod);
        }
    }
    return x;
}
Mat operator*(Mat x,Mat y){
    Mat ret(x.m,y.n);
    ll t;
    for(int i=0;i<x.m;i++){
        for(int j=0;j<y.n;j++){
            t=0;
            for(int k=0;k<x.n;k++){
                t=mm(t+x.a[i][k]*y.a[k][j],mod);
            }
            ret.a[i][j]=t;
        }
    }
    return ret;
}
Mat speed(Mat cur,ll b,ll p){
    Mat ans(cur.m,cur.n,1);
    while (b) {
        if (b & 1) ans = ans*cur;
        cur = cur*cur;
        b >>= 1;
    }
    return ans;
}
ll getFib(ll x,ll p){
    Mat t;
    return speed(t,x,p).a[0][1];
}
int T,n;
const int CTN=1000000;
ll f[2*CTN+10]={1};
ll ivs[CTN+10]={1};
ll iv[CTN+10]={1};
ll h[CTN+10]={1};
void CTL(){
	for(int i=1;i<=CTN+1;i++){
		f[i]=mm(f[i-1]*i,mod);
		iv[i]=speed(i,mod-2,mod);
		ivs[i]=mm(ivs[i-1]*iv[i],mod);
	}
	for(int i=CTN+2;i<=CTN*2;i++){
		f[i]=mm(f[i-1]*i,mod);
	}
	for(int i=1;i<=CTN;i++){
		h[i]=mm(f[2*i]*mm(ivs[i]*mm(ivs[i]*iv[i+1],mod),mod),mod);
	}
}
int main(){
	mod=1000000007;
	CTL();
	scanf("%d",&T);
    for(int I=1;I<=T;I++){
    	scanf("%d",&n);
    	ll ans=0;
    	
    	for(int i=0;i<=n/2;i++){
    		ans=mm(ans+mm(h[i]*mm(f[n]*mm(ivs[2*i]*ivs[n-2*i],mod),mod),mod),mod);
    	}
    	printf("%lld\n",ans);
    }
    return 0;
}
