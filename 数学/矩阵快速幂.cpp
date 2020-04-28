#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
long long n,mod=1000000007;
long long m;
struct jz{
	long long a[120][120];
};
jz s;
jz fz(jz &x){
	memset(x.a,0,sizeof(x.a));
	for(int i=1;i<=n;i++){
		x.a[i][i]=1;
	}
	return x;
}
jz cf(jz x,jz y,ll p){
	jz neww;
	memset(neww.a,0,sizeof(neww.a));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				neww.a[i][j]=(x.a[i][k]*y.a[k][j])%p+neww.a[i][j];
				neww.a[i][j]%=p;
			}
		}
	}
	return neww;
}
jz speed(jz x,ll b,ll p){
	jz cur=x,ans=fz(ans);
	while(b){
		if(b&1){
			ans=cf(ans,cur,p);
		}
		cur=cf(cur,cur,p);
		b>>=1;
	}
	return ans;
}
int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%lld",&s.a[i][j]);
		}
	}
	jz x=speed(s,m,mod);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%lld ",x.a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
