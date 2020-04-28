# DP
## dp单调序列
```
/*
1·b(I,1)表示第I个数的数值本身；
2·b(I,2)表示从I位置到达N的最长不下降序列长度
3·b(I,3)表示从I位置开始最长不下降序列的下一个位置
*/
#include<iostream>
#include<cstdio>
using namespace std;
int n,i,j,l,k,b[200][10]; 
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		cin>>b[i][1];
		b[i][2]=1;b[i][3]=0;
	}
	for (i=n-1;i>=1;i--){
		l=0;k=0;
		for (j=i+1;j<=n;j++)
			if ((b[j][1]>b[i][1])&&(b[j][2]>l)){
				l=b[j][2];
				k=j;
			}
		if (l>0){
			b[i][2]=l+1;b[i][3]=k;
		}  
     }
	k=1;
	for (j=1;j<=n;j++)                        
	if (b[j][2]>b[k][2]) k=j;
	cout<<"max="<<b[k][2]<<endl;             
	while (k!=0){
		cout<<' '<<b[k][1];
		k=b[k][3];   
	} 
	return 0;
}

```
## 01背包
```
#include<iostream>
#include<cstdio>
using namespace std;
int m,n;
int w[352000],val[352000],f[352000];
int main(){
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&w[i],&val[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            f[j]=max(f[j],f[j-w[i]]+val[i]);
        }
    }
    printf("%d\n",f[m]);
    return 0;
}
```
## 完全背包
```
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
//完全背包 
int n,V;
int f[100020];
int v[20000],w[20000];
int main(){
	scanf("%d%d",&n,&V);
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
		scanf("%d",&w[i]);
		
	}
	for(int i=1;i<=n;i++){
		for(int j=v[i];j<=V;j++){
			f[j]=max(f[j],f[j-v[i]]+w[i]);
		}
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,f[i]);
	}
	printf("%d",maxn);
	
	return 0;
}
```