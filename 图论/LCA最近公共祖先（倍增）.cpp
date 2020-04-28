//C++代码实现：
/*输入 
12 5
1
1
1
2
2
5
5
6
6
10
10
3 11
7 12
4 8
9 12
8 10
输出
1
2
1
6
2
*/
#include<iostream>
#include<stdio.h>
#include<memory.h>
using namespace std;
#define max_size 1010
int d[max_size],p[max_size][10];
int head[max_size];
int cnt;
struct Edge{
    int v;
    int pre;
}eg[max_size];
//建树的函数
void add(int x,int y){
    eg[cnt].v=y;//儿子 
    eg[cnt].pre=head[x];//head记录x连接的边在临界表中的编号…… 
    head[x]=cnt++;
}
//dfs()初始整颗树，算出d[1-n],p[1-n][j];
void dfs(int k){
    if (head[k]==0) return;
    int m,x,i,j;
    for(i=head[k];i!=0;i=eg[i].pre){
        x=eg[i].v;//找儿砸 
        p[x][0]=k;//记录x的爸爸(祖先) 
        m=k;
        d[x]=d[k]+1;//记录深度 
        for(j=0;p[m][j]!=0;j++){
            p[x][j+1]=p[m][j];//利用公式p[x][j]=p[p[x][j-1]][j-1],这里的m就是p[x][j-1];
            m=p[m][j];//理解 2^3=2^2*2; 
        }
    dfs(x);
    }
}
int find_lca(int x,int y){
    int m,k;
    if(x==y) return x;
    if(d[x]<d[y]){m=x;x=y;y=m;}//使x的深度>y 
    m=d[x]-d[y];
    k=0;
    while(m){/*将x的深度调到和y的深度一样*///倍增法 k记录2^k次方 
        if(m&1) x=p[x][k];
        m>>=1;//m=m>>1; 
        k++; 
    }
    if(x==y)return x;
    k=0;/*向上调节，找最近公共祖先，算法的核心，相当于一个二分查找。*/
    while(x!=y){
        if (p[x][k]!=p[y][k]||p[x][k]==p[y][k]&&k==0){
		/*如果p[x][k]还不相等，说明节点p[x][k]还在所求点的下面，
		所以继续向上调节;如果相等了，并且就是他们父节点，则那个节点一定就是所求点。
		*/
            x=p[x][k];
            y=p[y][k];
            k++;
        }
    	else k--;
		/*如果p[x][k]=p[y][k],可以说明p[x][k]一定是x和y的共祖先，但不一定是最近的,
		所以向下找看还有没有更近的公共祖先.*/
    }
    return x;
}
int main(){
    int i,n,m,x,y;
    while(cin>>n>>m){
        memset(head,0,sizeof(head));
        memset(p,0,sizeof(p));
        memset(d,0,sizeof(d));
        cnt=1;
        for(i=2;i<=n;i++){
            scanf("%d",&x);
            add(x,i);
        }
        dfs(1);
        for(i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            printf("%d\n",find_lca(x,y));
        }
    }
    return 0;
}
