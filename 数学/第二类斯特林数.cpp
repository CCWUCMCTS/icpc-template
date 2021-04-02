//S(n,m)=1/m!*sum(k:[0,m],(-1)^k*C(m,k)*(m-k)^n)
//n^k=sum(i:[0,k],S(k,i)*i!*C(n,i))
#include<stdio.h>
//using namespace std;
#define ll long long
const int mod=1e9+7;
const int MAXN=1e6;
int n,m;
ll jc[MAXN+20]={1};
int inv[MAXN+20]={1,1};
ll mo(ll x,int p){
	return x<0?(x+p)%p:x<p?x:x%p;
}
ll speed(ll a,ll b,int p){
	ll cur=a,ans=1;
	while(b){
		if(b&1) ans=ans*cur%p;
		cur=cur*cur%p;
		b>>=1;
	}
	return ans%p;
}
inline void init(){
	for(int i=2;i<=m;i++){
		inv[i]=((mod-mod/i)*1LL*inv[mod%i])%mod;
	}
	for(int i=1;i<=m;i++){
		inv[i]=inv[i-1]*1LL*inv[i]%mod;
		jc[i]=jc[i-1]*i%mod;
	}
	
}
inline ll C(ll m,ll n){
	return jc[m]*inv[n]%mod*inv[m-n]%mod;
}
int main(){
	ll ans=0;
	scanf("%d%d",&n,&m);
	init();
	ll f=-1;
	for(int i=0;i<=m;i++){
		f=-f;
		ans=mo(ans+f*C(m,i)*speed(m-i,n,mod),mod);
	}
	//ans=mo(ans*njc[m],mod);
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}
