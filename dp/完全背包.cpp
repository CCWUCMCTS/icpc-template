#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
//ÍêÈ«±³°ü 
int n,V;
int f[100020];
int v[20000],w[20000];
int main(){
	scanf("%d%d",&n,&V);
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
		scanf("%d",&w[i]);
		
	}
	for(int i=1;i<=n;i++){
		for(int j=v[i];j<=V;j++){
			f[j]=max(f[j],f[j-v[i]]+w[i]);
		}
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,f[i]);
	}
	printf("%d",maxn);
	
	return 0;
}
