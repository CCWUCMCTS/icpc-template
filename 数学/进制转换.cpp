//luogu1017
#include<cstdio>
#include<iostream>
using namespace std;
int m,n;
void change(int a){
	int k;
	k=a%m;
	a=a/m;
	if(k<0){
		k-=m;
		a++;
	}
	if (a!=0) change(a);
	if(k>9) printf("%c",k-10+'A');
	else printf("%d",k);
}
int main()
{
	scanf("%d%d",&n,&m);
	printf("%d=",n);
	change(n);
	printf("(base%d)",m); 
	return 0;    
}
