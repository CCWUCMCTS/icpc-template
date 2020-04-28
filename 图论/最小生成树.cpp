#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int f[5020];
struct Edge{
	int u,v,w;
}e[200020]; 
int cmp(Edge a,Edge b){
	return a.w<b.w;
}
int find(int x){
	return f[x]==0?x:f[x]=find(f[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	int x,y,z;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		e[i]=(Edge){x,y,z};
	}
	sort(e+1,e+1+m,cmp);
	int cnt=0,sum=0;
	for(int i=1;i<=m;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x!=y){
			f[x]=y;
			cnt++;
			sum+=e[i].w;
		}
		if(cnt==n-1){
			printf("%d\n",sum);
			return 0;
		}
	}
	printf("orz\n");
	return 0;
}
