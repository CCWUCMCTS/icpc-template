#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int a[500020],tree[500020];
int lowbit(int k){
	return k&-k;
}
void add(int k,int num){
	while(k<=n){
		tree[k]+=num;
		k+=lowbit(k);
	}
}
int read(int k){
	int sum=0;
	while(k){
		sum+=tree[k];
		k-=lowbit(k);
	}
	return sum;
}
int main(){
	scanf("%d%d",&n,&m);
	int last=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		add(i,a[i]-last);
		//这里运用了差分思想，假设原本的数据存在a数组中，
		//那么c数组储存的就是c[i]=a[i]-a[i-1]，如果c[1]=a[1]，那么很明显
		//a[i]=c[i]+c[i-1]+c[i-2]+...+c[2]+c[1].
		//这样我们每次单点查询的时候只要加上c数组的前缀就可以了。
		last=a[i];
	}
	int command,x,y,l;
	for(int i=1;i<=m;i++){
		scanf("%d",&command);
		if(command==1){
			scanf("%d%d%d",&x,&y,&l);
			add(x,l);
			add(y+1,-l);
		}
		else{
			scanf("%d",&x);
			printf("%d\n",read(x));
		}
	}
	return 0;
}
