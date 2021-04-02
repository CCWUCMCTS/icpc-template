#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll &y){//扩展欧几里得算法
    if(b==0){//递归边界 
        x=1;y=0;
        return a;
    }
    ll ret=exgcd(b,a%b,x,y);
    ll tmp=y;//求解原x,y     
    y=x-a/b*y;
    x=tmp;
    return ret;//返回gcd      
}
ll crt(ll a[],ll b[],int n)//a[]为除数，b[]为余数
{
    ll M=1,y,x=0;
    for(int i=0;i<n;++i)  //算出它们累乘的结果
        M*=a[i];
    for(int i=0;i<n;++i)
    {
        ll w=M/a[i];
        ll tw=0;
        exgcd(w,a[i],tw,y);  //计算逆元
        ll t=w*b[i]%M*tw%M; 
        x=(x+t)%M;
    }
    return (x+M)%M;
}
int n;
ll a[20],b[20];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		//cout<<a[i]<<' '<<b[i]<<endl;
	}
	cout<<crt(a,b,n)<<endl;
	return 0;
}

