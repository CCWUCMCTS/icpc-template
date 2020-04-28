#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
struct jz{
	int a[40][40];
};
jz s;
jz fz(jz x){
	memset(x.a,0,sizeof(x.a));
	for(int i=1;i<=n;i++){
		x.a[i][i]=1;
	}
	return x;
}
jz cf(jz x,jz y){
	jz neww;
	memset(neww.a,0,sizeof(neww.a));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				neww.a[i][j]+=x.a[i][k]*y.a[k][j];
			}
		}
	}
	return neww;
}
jz speed(jz x,int b){
	if(b==1) return x;
	jz cur,ans;
	ans=fz(ans);
	cur=x;
	while(b){
		if(b&1){
			ans=cf(ans,cur);
		}
		cur=cf(cur,cur);
		
		b>>=1;
	}
	return ans;
}
int main(){
	
	s.a[1][1]=1;
	s.a[1][2]=1;
	s.a[2][1]=1;
	s.a[2][2]=0;
	n=2;
	scanf("%d",&m);
	jz x=speed(s,m-1);
	printf("%d\n",x.a[1][1]);
	return 0;
}
