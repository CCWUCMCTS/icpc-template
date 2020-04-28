#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,s,g[10020],d[10020],vis[10020];
struct Edge{
	int u,v,w,next;
}e[500020];
struct ds{
	int d,u;
	bool operator<(const ds &x)const{return d>x.d;}
};
void dij(int s){
	memset(vis,0,sizeof(vis));
	priority_queue<ds>q;
	for(int i=1;i<=n;i++) d[i]=500000000;
	d[s]=0;
	q.push((ds){0,s});
	while(!q.empty()){
		ds x=q.top();q.pop();
		int u=x.u;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=g[u];i>0;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(d[u]+w<d[v]){
				d[v]=d[u]+w;
				q.push((ds){d[v],v});
			}
		}
	}
	
	
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	int x,y,z;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		e[i]=(Edge){x,y,z,g[x]};g[x]=i;
	}
	dij(s);
	for(int i=1;i<=n;i++){
		if(d[i]!=500000000) printf("%d ",d[i]);
		else{
			printf("2147483647 ");
		}
	}
	printf("\n");
	return 0;
}
