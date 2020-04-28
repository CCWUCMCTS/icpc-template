#include<iostream>
#include<cstdio>
#include<algorithm>//!! 
using namespace std;
char b[102];
int main(){
	int n;
	scanf("%d",&n);
	char a;
	scanf("%c",&a);
	for(int i=1;i<=n;i++){
		scanf("%c",&a);
		b[i]=a;
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		printf("%c",b[i]);
	}
	cout<<endl;
	while(next_permutation(b+1,b+1+n)==true){//prev
		for(int i=1;i<=n;i++){
			printf("%c",b[i]);
		}
		cout<<endl;
	}
	return 0;
}
