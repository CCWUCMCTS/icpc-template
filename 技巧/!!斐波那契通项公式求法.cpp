#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long double n=0;
//int p;
//f[2*n]=f[2*n-1]+...+f[3]+f[1];
//f[2*n+1]-1=f[2*n]+...+f[4]+f[2];
//f[2*n]=f[n]*f[n]+2*f[n]*f[n-1];
int main(){
	//scanf("%d",&p);
	for(int i=1;i<=92;i++){
		n++;
		printf("%lld ",(long long)((pow(((1+sqrt(5))/2),n)-pow(((1-sqrt(5))/2),n))/sqrt(5)));
		if(i%5==0) cout<<endl;
	}
	return 0;
}
