//unique,lower_bound,sort,¿Î…¢ªØ 
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=10020;
int a[MAXN],b[MAXN]; 
int n,m;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	m=unique(b+1,b+1+n)-(b+1);
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+1+m,a[i])-b;
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}
	return 0;
}
