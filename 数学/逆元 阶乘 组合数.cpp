#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define mod 10007
const int MAXN=3e6;
ll n,_inv[MAXN+20];
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
ll speed(ll a,ll b,ll p){//若mod为质数，逆元speed(b,mod-2,mod) 
	ll cur=a,ans=1;
	while(b){
		if(b&1) ans=ans*cur%p;
		cur=cur*cur%p;
		b>>=1;
	}
	return ans%p;
}
void exgcd(ll a,ll b,ll &x,ll &y){
    if (!b) return (void)(x=1,y=0);
    exgcd(b,a%b,x,y);
    ll tmp=x;x=y;y=tmp-a/b*y;
}
inline ll INV(ll a,ll p){
    ll x,y;
    exgcd(a,p,x,y);
    return (x%p+p)%p;
}
ll exgcd_0(ll a,ll b,ll &x,ll &y){//扩展欧几里得算法，使用时注意+mod再%mod 
    if(b==0){//递归边界 
        x=1;y=0;
        return a;
    }
    ll ret=exgcd_0(b,a%b,x,y);
    ll tmp=y;//求解原x,y     
    y=x-a/b*y;
    x=tmp;
    return ret;//返回gcd      
}
void pre(ll p){
	_inv[0]=_inv[1]=1;
	for(int i=2;i<=MAXN;i++){
		_inv[i]=((p-p/i)*_inv[p%i])%p;
	}
}
ll Scomb(ll _n,ll _m,ll p){//SmallCombination n,m可以线性求出 
	if(_m==0) return 1;
	ll ans=1,tmp=1;
	for(ll i=_m+1;i<=_n;i++){
		ans=(ans*i)%p;
	}
	for(ll i=1;i<=_n-_m;i++){
		tmp=(tmp*i)%p;
	}
	//cout<<tmp<<endl;
	return ans*INV(tmp%p,p)%p;
}
ll Bcomb(ll _n,ll _m,ll p){//BigCombination
	if(_n<p&&_m<p) return Scomb(_n,_m,p)%p;
	return Bcomb(_n/p,_m/p,p)*Scomb(_n%p,_m%p,p)%p;
}
int main(){
	pre(mod);
	freopen("a.txt","w",stdout);
	int len=1e9;
	printf("{");
	ll cur=1,p=1e9+7;
	for(ll i=1;i<=len;i++){
		cur=(cur*i)%p;
		if(i%(len/100)==0){
			printf("%lld",cur);
			if(i!=len) printf(",");
		}
	}
	printf("};");
	return 0;
}
