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
ll speed(ll a,ll b,ll p){//��modΪ��������Ԫspeed(b,mod-2,mod) 
	ll cur=a,ans=1;
	while(b){
		if(b&1) ans=ans*cur%p;
		cur=cur*cur%p;
		b>>=1;
	}
	return ans%p;
}
ll exgcd(ll a,ll b,ll &x,ll &y){//��չŷ������㷨��ʹ��ʱע��+mod��%mod 
    if(b==0){//�ݹ�߽� 
        x=1;y=0;
        return a;
    }
    ll ret=exgcd(b,a%b,x,y);
    ll tmp=y;//���ԭx,y     
    y=x-a/b*y;
    x=tmp;
    return ret;//����gcd      
}
void pre(ll p){
	_inv[0]=_inv[1]=1;
	for(int i=2;i<=MAXN;i++){
		_inv[i]=((p-p/i)*_inv[p%i])%p;
	}
}
ll Scomb(ll _n,ll _m,ll p){//SmallCombination n,m����������� 
	if(_m==0) return 1;
	ll ans=1,tmp=1;
	for(ll i=_m+1;i<=_n;i++){
		ans=(ans*i)%p;
	}
	for(ll i=1;i<=_n-_m;i++){
		tmp=(tmp*i)%p;
	}
	//cout<<tmp<<endl;
	return ans*inv(tmp%p,p)%p;
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
