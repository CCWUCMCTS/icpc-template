#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=20,M=1010,inf=2147483647;
struct edge
{
	int v,w,next;
};
edge e[M*2];
int h[N],n,m,x,y,z,top,T;
bool vis[N];
void add_edge(int xx,int yy,int zz)
{
	top++;
	e[top]=(edge){yy,zz,h[xx]};
	h[xx]=top;
	top++;
	e[top]=(edge){xx,0,h[yy]};
	h[yy]=top;
	return ;
}
int dfs(int now,int f)
{
	if(now==n) return f;
	vis[now]=true;
	for(int i=h[now];i>0;i=e[i].next)
		if(!vis[e[i].v] && e[i].w>0)
		{
			int d=dfs(e[i].v,min(f,e[i].w));
			if(d>0)
			{
				e[i].w-=d;
				e[((i-1)^1)+1].w+=d;
				return d;
			}
		}
	return 0;
}
int max_flow()
{
	int flow,f;
	flow=0;
	for(;;)
	{
		memset(vis,false,sizeof(vis));
		f=dfs(1,inf);
		if(f==0) return flow;
		flow+=f;
	}
	return 0;
}
int main()
{
	scanf("%d",&T);
	for(int k=1;k<=T;k++)
	{
		memset(h,0,sizeof(h));
		top=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			add_edge(x,y,z);
		}
		printf("Case %d: %d\n",k,max_flow());
	}
	return 0;
}
