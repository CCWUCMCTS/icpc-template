#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int edge[1010*2][1010*2],pei[1010*2];
bool vis[1010*2];
int n,m,ans,x,y,z;
bool findz(int x)
{
	int i;
	for (i=n+1;i<=m+n;i++)
		if(edge[x][i] && !vis[i])
		{
			vis[i]=true;
			if(!pei[i] || findz(pei[i]))
			{
				pei[i]=x;
				return true;
			}
		}
	return false;
}
void Hungary()
{
	ans=0;
	memset(pei,0,sizeof(pei));
	for (int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if (findz(i))
			ans++;
	}
	return ;
}
int main()
{
//	freopen("testdata.in","r",stdin); 
	cin>>n>>m>>z;
	memset(edge,0,sizeof(edge));
	for (int i=1;i<=z;i++)
	{
		cin>>x>>y;
		if(x>n||y>m)
			continue;
		edge[x][y+n]=1;
		
		edge[y+n][x]=1;
	}
	Hungary();
	cout<<ans<<endl;
	return 0;
}
