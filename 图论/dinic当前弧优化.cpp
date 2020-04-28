 #include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
#define inf 2147483647
using namespace std;
typedef pair<int,int> pii;
const int N=210,M=210;
struct edge
{
	int v,w,next;
};
edge e[M*2];
int n,m,x,y,z,h[N],cur[N],dep[N],top,st,ed,num;//num为节点数 
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
bool bfs()
{
	int head;
	queue<int> q;
	memset(dep,0,sizeof(dep));
	q.push(st);
	dep[st]=1;
	while(!q.empty())
	{
		head=q.front();
		q.pop();
		if(head==ed)
			return true;
		for(int i=h[head];i>0;i=e[i].next)
			if(dep[e[i].v]==0 && e[i].w>0)
			{
				q.push(e[i].v);
				dep[e[i].v]=dep[head]+1;
			}
	}
	return false;
}
int dfs(int now,int f)
{
	if(now==ed)
		return f;
	int ff=0,temp;
	for(int &i=cur[now];i>0;i=e[i].next)//? 
	{
		if(e[i].w>0 && dep[e[i].v]==dep[now]+1)
		{
			temp=dfs(e[i].v,min(e[i].w,f-ff));
			e[i].w-=temp;
			e[((i-1)^1)+1].w+=temp;
			ff+=temp;
			if(f==ff) return f;
		}
	}
	return ff;
}
int max_flow()
{
	int flow=0,ff;
	while(bfs()){
		for(int i=1;i<=num;i++)
			cur[i]=h[i];
		ff=dfs(st,inf);
		if(ff==0)
			break;
		flow+=ff;
	}
	return flow;
}
int main()
{
	memset(h,0,sizeof(h));
	top=0;
	scanf("%d%d",&m,&n);
	num=n; 
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add_edge(x,y,z);
	}
	printf("%d\n",max_flow());
	return 0;
}
