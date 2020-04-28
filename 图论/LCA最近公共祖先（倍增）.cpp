//C++����ʵ�֣�
/*���� 
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
���
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
//�����ĺ���
void add(int x,int y){
    eg[cnt].v=y;//���� 
    eg[cnt].pre=head[x];//head��¼x���ӵı����ٽ���еı�š��� 
    head[x]=cnt++;
}
//dfs()��ʼ�����������d[1-n],p[1-n][j];
void dfs(int k){
    if (head[k]==0) return;
    int m,x,i,j;
    for(i=head[k];i!=0;i=eg[i].pre){
        x=eg[i].v;//�Ҷ��� 
        p[x][0]=k;//��¼x�İְ�(����) 
        m=k;
        d[x]=d[k]+1;//��¼��� 
        for(j=0;p[m][j]!=0;j++){
            p[x][j+1]=p[m][j];//���ù�ʽp[x][j]=p[p[x][j-1]][j-1],�����m����p[x][j-1];
            m=p[m][j];//��� 2^3=2^2*2; 
        }
    dfs(x);
    }
}
int find_lca(int x,int y){
    int m,k;
    if(x==y) return x;
    if(d[x]<d[y]){m=x;x=y;y=m;}//ʹx�����>y 
    m=d[x]-d[y];
    k=0;
    while(m){/*��x����ȵ�����y�����һ��*///������ k��¼2^k�η� 
        if(m&1) x=p[x][k];
        m>>=1;//m=m>>1; 
        k++; 
    }
    if(x==y)return x;
    k=0;/*���ϵ��ڣ�������������ȣ��㷨�ĺ��ģ��൱��һ�����ֲ��ҡ�*/
    while(x!=y){
        if (p[x][k]!=p[y][k]||p[x][k]==p[y][k]&&k==0){
		/*���p[x][k]������ȣ�˵���ڵ�p[x][k]�������������棬
		���Լ������ϵ���;�������ˣ����Ҿ������Ǹ��ڵ㣬���Ǹ��ڵ�һ����������㡣
		*/
            x=p[x][k];
            y=p[y][k];
            k++;
        }
    	else k--;
		/*���p[x][k]=p[y][k],����˵��p[x][k]һ����x��y�Ĺ����ȣ�����һ���������,
		���������ҿ�����û�и����Ĺ�������.*/
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
