#include<bits/stdc++.h>
using namespace std;
#define io_opt ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#if defined io_opt
#define scanf kdjfk
#define printf sfnjksdn
#endif 
#define ll long long
#define db double
const int maxn=500+20,maxm=3e5+20;
const int INF=1e9;
int n,m,s,t;
int num_peo[maxn],pth_cnt[maxn],pth[maxn];
int g[maxn],d[maxn],mx_peo[maxn],vis[maxn];
struct E{
	int u,v,w,nex;
}e[maxm];
struct ds{
	int d,u,sum;
	bool operator<(const ds x)const{
		if(d==x.d) return sum<x.sum;
		return d>x.d;
	}
};
void dijkstra(int s){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		d[i]=INF;
		mx_peo[i]=0;
		pth[i]=0;
	}
	priority_queue<ds>q;
	d[s]=0;
	mx_peo[s]=num_peo[s];
	pth_cnt[s]=1;
	q.push((ds){d[s],s,mx_peo[s]});
	while(!q.empty()){
		ds cur=q.top();q.pop();
		int u=cur.u;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=g[u];i>0;i=e[i].nex){
			int v=e[i].v,w=e[i].w;
			if(d[u]+w<d[v]){
				pth[v]=u;
				pth_cnt[v]=pth_cnt[u];
				d[v]=d[u]+w;
				mx_peo[v]=mx_peo[u]+num_peo[v];
				q.push((ds){d[v],v,mx_peo[v]});
			}
			else if(d[u]+w==d[v]){
				pth_cnt[v]+=pth_cnt[u];
				if(mx_peo[u]+num_peo[v]>mx_peo[v]){
					pth[v]=u;
					mx_peo[v]=mx_peo[u]+num_peo[v];
					q.push((ds){d[v],v,mx_peo[v]});
				}
			}
		}
	}
}
void dfs(int u){
	if(pth[u]){
		dfs(pth[u]);
	}
	cout<<u-1<<' ';
}
int main(){
	io_opt;
	cin>>n>>m>>s>>t;
	s++,t++;
	for(int i=1;i<=n;i++){
		cin>>num_peo[i];
	}
	int x,y,z;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		x++,y++;
		e[i]=(E){x,y,z,g[x]};g[x]=i;
		e[i+m]=(E){y,x,z,g[y]};g[y]=i+m;
	}
	dijkstra(s);
	//cout<<d[t]<<endl;
	cout<<pth_cnt[t]<<' '<<mx_peo[t]<<endl;
	dfs(pth[t]);
	cout<<t-1<<endl;
	return 0;
}
