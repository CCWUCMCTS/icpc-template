#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stack>
#include<cstring>
#include<vector>
#define io_opt ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int MAXN=500020;
const int MAXM=500020;
int n,m,idx,cnt,mm;
int g[MAXN],dfn[MAXN],low[MAXN],p2p[MAXN];
bool instack[MAXN];
stack<int>s;
vector<int>belong[MAXN];
struct E{
	int u,v,nex;
	bool operator<(const E x)const{
		if(u==x.u) return v<x.v;
		return u<x.u;
	}
	bool operator==(const E x)const{
		return u==x.u&&v==x.v&&nex==x.nex;
	}
}e[MAXM];
void Tarjan(int u){
	dfn[u]=low[u]=++idx;
	s.push(u);
	instack[u]=true;
	for(int i=g[u];i>0;i=e[i].nex){
		int v=e[i].v;
		if(!dfn[v]){
			Tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(instack[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		++cnt;
		int cur;
		do{
			cur=s.top();s.pop();
			instack[cur]=false;
			belong[cnt].push_back(cur);
			p2p[cur]=cnt;
		}while(cur!=u);
	}
}
int main(){
	io_opt;
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		e[i]=(E){x,y,g[x]};g[x]=i;
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) Tarjan(i);	
	}
	
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		if(!p2p[u]||!p2p[v]||p2p[u]==p2p[v]){
			e[i].u=e[i].v=1000000;
			e[i].nex=1000000;
		}
		else{
			e[i].u=p2p[u];
			e[i].v=p2p[v];
			e[i].nex=0;
		}
	}
	sort(e+1,e+1+m);
	mm=unique(e+1,e+1+m)-(e+1);
	while(e[mm].nex==1000000) mm--;
	memset(g,0,sizeof(g));
	for(int i=1;i<=mm;i++){
		e[i].nex=g[e[i].u];
		g[e[i].u]=i;
	}
	
	return 0;
}
