#include<iostream>
#include<cstdio>
#include<algorithm>//!! 
using namespace std;
int b[102];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		b[i]=i;
	}
	for(int i=1;i<=n;i++){
		printf("%5d",b[i]);
	}
	cout<<endl;
	while(next_permutation(b+1,b+1+n)==true){
		for(int i=1;i<=n;i++){
			printf("%5d",b[i]);
		}
		cout<<endl;
	}
	return 0;
}
