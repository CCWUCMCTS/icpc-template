#include<iostream>
#include<cstdio>
using namespace std;
int n;
double a[200];
double l,r;
double speed(double a,int b){
	double cur=a,ans=1;
	while(b){
		if(b&1) ans*=cur;
		cur*=cur;
		b>>=1;
	}
	return ans;
}
double num(double x){
	double sum=0;
	for(int i=0;i<=n;i++){
		sum=sum+speed(x,i)*a[i]; 
	}
	return sum;
}
double abs(double c){
	if(c<0) return -c;
	return c;
}
int main(){
	scanf("%d%lf%lf",&n,&l,&r);
	for(int i=1;i<=n+1;i++){
		scanf("%lf",&a[n-i+1]);
	}
	while(abs(r-l)>0.000001){
		double x=(2*l+r)/3.0,y=(2*r+l)/3.0;
		if(num(x)>num(y)){
			r=y;
		}
		else{
			l=x;
		}
		
	}
	printf("%.5lf",l);
	return 0;
}
