#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
ll mod=((1LL<<62)-1)|(1LL<<62);//位运算求long long上限 
ll mul_mod(ll a,ll b,ll p){//快速乘，这里用不到 
	ll ret=a*b-(ll)(a*(ld)b/p+0.5)*p;
	return ret>=0?ret:(ret+p)%p;
}
ll lowspeed(ll a,ll b,ll p){
	ll cur=a,ans=0;
	while(b){
		if(b&1) ans=(ans+cur)%p;
		cur=(cur+cur)%p;
		b>>=1;
	}
	return ans%p;
}
ll speed(ll a,ll b,ll p){
	ll cur=a,ans=1;
	while(b){
		if(b&1) ans=lowspeed(ans,cur,p)%p;
		cur=lowspeed(cur,cur,p)%p;
		b>>=1;
	}
	return ans%p;
}
int main(){
	cout<<mod<<endl;
	cout<<mul_mod(1000000000,1555555555555,1000000007)<<endl;
	cout<<speed(2,61,mod)<<endl;
	return 0;
}
