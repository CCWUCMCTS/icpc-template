#include<iostream>
#include<cstdio>
using namespace std;
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
int n,m,s,t;
const int MAXN=10020;
const int MAXM=500020;
struct Edge{
    int u,v,w,next;
}e[MAXM];
int g[MAXN];
int inq[MAXN],d[MAXN];
void spfa(int s){
    queue<int>q;
    q.push(s);
    inq[s]=1;
    memset(d,0x3f,sizeof(d));
    d[s]=0;
    while(!q.empty()){
        int uu=q.front();inq[uu]=0;
        q.pop();
        for(int i=g[uu];i>0;i=e[i].next){
            int vv=e[i].v,ww=e[i].w;
            if(d[uu]+ww<d[vv]){
                d[vv]=d[uu]+ww;
                if(!inq[vv]){
                    q.push(vv);
                    inq[vv]=1;
                }
            }
        }
    }
    return;
}
int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++){
        int xx,yy,ww;
        scanf("%d%d%d",&xx,&yy,&ww);
        e[i]=(Edge){xx,yy,ww,g[xx]};g[xx]=i;
    }
    spfa(s);
    for(int i=1;i<=n;i++){
        if(d[i]>1000000000) printf("2147483647 ");
        else{
            printf("%d ",d[i]);
        }
    }
    return 0;
}
