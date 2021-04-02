#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
int T,n;
int a[10020];
int main(){
	scanf("%d",&T);
	while(T--){
		int mx=-1020;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mx=max(mx,a[i]);
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			sum=max(sum,0);
			sum+=a[i];
			mx=max(mx,sum);
		}
		printf("%d\n",mx);
	}
    
    return 0;
}
