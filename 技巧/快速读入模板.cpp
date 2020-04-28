#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,a[1010];
int inline read()
{
	int num=0;
	char c;
	bool plus=true;
	while((c=getchar())==' '||c=='\n'||c=='\r');
	if(c=='-') plus=false;
	else num=c-'0';
	while(isdigit(c=getchar()))
		num=num*10+c-'0';
	return 	num*(plus?1:-1);
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
