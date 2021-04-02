#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
int T,n;

int main(){
	
	while(cin>>n&&n){
		int ans=0;
		while(n>2){
			ans+=n/3;
			n=n%3+n/3;
		}
		if(n==2){
			ans++;
		}
		printf("%d\n",ans);
	}
    
    return 0;
}
