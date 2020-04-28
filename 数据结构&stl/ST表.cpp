#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
//ST±í£¬¾²Ì¬RMQ 
int n,m,a[100020],f[100020][33];
void ST(){
	int k=log(n)/log(2);
	for(int i=1;i<=n;i++){
		f[i][0]=a[i];
	}
	for(int j=1;j<=k;j++){
		for(int i=1;i<=n;i++){
			if(i+(1<<j)-1<=n){
				f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			}
		}
	}
}
int RMQ(int L,int R){
	int k=log(R-L+1)/log(2);
	return max(f[L][k],f[R-(1<<k)+1][k]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ST();
	int l,r;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&l,&r);
		printf("%d\n",RMQ(l,r));
	}
	return 0;
} 
