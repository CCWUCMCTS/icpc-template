#include<stdio.h>
#include<iostream>
using namespace std;
#include<stack>
#include<vector>
const int MAXN=10020;
const int MAXM=100020;
int n,m,idx,cnt,g[MAXN];
int dfn[MAXN],low[MAXN];
bool instack[MAXN];
struct E{
	int u,v,nex;
}e[MAXM];
stack<int>s;
vector<int>belong[MAXN];
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
		}while(cur!=u);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		e[i]=(E){x,y,g[x]};g[x]=i;
	}
	Tarjan(1);
	return 0;
}
