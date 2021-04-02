#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e4; 
bool ipr[MAXN+20];
int cnt,pri[MAXN/5];
void prime(){//埃式筛法 
	int N=sqrt(MAXN)+0.5,mul;
	memset(ipr,true,sizeof(ipr));
	ipr[1]=false;	
	for(int i=2;i<=N;i++){
		if(ipr[i]==true){
			i==2?mul=1:mul=2;
			for(int j=i*i;j<=MAXN;j+=i*mul){
				ipr[j]=false;
			}
		}
	}
	for(int i=2;i<=MAXN;i++){
		if(ipr[i]==true){
			pri[++cnt]=i;
		}
	}
}
int c[MAXN+20];
int tmp[MAXN+20];
int main(){
	prime(); 
	/*
		分解质因数 
		n:要分解的数字 
		cnt:sqrt(n)以内素数的数量
		pri[]:素数表，下标从1开始 
		c[]:存分解结果 
		tmp:最后可能剩下的素数 
	*/
	int in;
	scanf("%d",&in);
	for(int k=2;k<=in;k++){
		int n=k;
		for(int i=1;i<=cnt&&pri[i]*pri[i]<=n;i++){
			while(n%pri[i]==0){
				c[i]++;
				n/=pri[i];
			}
			if(n==1) break;
		}
		if(n>1) tmp[n]++;
	}
	for(int i=1;i<=cnt;i++){
		int out=c[i]+tmp[pri[i]];
		if(out>0){
			printf("%d %d\n",pri[i],out);
		}
	}
	return 0;
}
