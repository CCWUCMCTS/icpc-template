//树状数组入门 
#include<iostream>
#include<cstdio>
using namespace std;
int a[100020],tree[1000020];
int n,m;
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
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		add(i,a[i]);
	}
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y-a[x]);
	}
	printf("%d",read(n));
	return 0;
}
