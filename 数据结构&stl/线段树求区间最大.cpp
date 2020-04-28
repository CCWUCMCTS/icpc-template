#include<cstdio>
#include<iostream>
using namespace std;
const int MAX_N=1<<17;//1e5
const int INT_MIN=-1;
int n,dat[2*MAX_N-1],x,y;
void update(int k,int a){
	k+=n-1;
	dat[k]=a;
	while(k>0){
		k=(k-1)/2;
		dat[k]=max(dat[k*2+1],dat[k*2+2]);
	}
}
void init(int n_){
	n=1;
	while(n<n_){
		n*=2;
	}
	for(int i=0;i<2*n-1;i++){
		dat[i]=INT_MIN;
	}
	for(int i=0;i<n_;i++){
		scanf("%d",&x);
		update(i,x);
	}
}

int query(int a,int b,int k,int l,int r){
	if(r<=a||b<=l){
		return INT_MIN;
	}
	if(a<=l&&r<=b){
		return dat[k];
	}
	else{
		int vl=query(a,b,k*2+1,l,(l+r)/2);
		int vr=query(a,b,k*2+2,(l+r)/2,r);
		return max(vl,vr);
	}
}
int main(){
	cin>>n;
	init(n);
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",query(x,y+1,0,0,n));
	}
	
	return 0;
}
