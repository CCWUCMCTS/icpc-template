#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
ll mod=((1LL<<62)-1)|(1LL<<62);//2^63-1
ll mul_m(ll a,ll b,ll p){
	ll d=(ll)floor(a*(ld)b/p+0.5);
	ll ret=a*b-d*p;
	return ret<0?ret+p:ret;
}
ll mul_m2(ll a,ll b,ll p){
	ll cur=a,ans=0;
	while(b){
		if(b&1) ans=(ans+cur)%p;
		cur=(cur+cur)%p;
		b>>=1;
	}
	return ans%p;
}
ll pow_m(ll a,ll b,ll p){
	ll cur=a,ans=1;
	while(b){
		if(b&1) ans=ans*cur%p;
		cur=cur*cur%p;
		b>>=1;
	}
	return ans%p;
}
ll ex_pow_m(ll a,ll b,ll p){
	ll cur=a,ans=1;
	while(b){
		if(b&1) ans=mul_m(ans,cur,p)%p;
		cur=mul_m(cur,cur,p)%p;
		b>>=1;
	}
	return ans%p;
}
int main(){
	cout<<mod<<endl;
	cout<<mul_m(2,3,5)<<endl;
	cout<<pow_m(2,61,mod)<<endl;
	return 0;
}
