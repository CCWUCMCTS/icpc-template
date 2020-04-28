#include<bits/stdc++.h>
#define ll long long
#define db double
#define ld long double
using namespace std;
int n,m;
int main(){
	//cut n to m
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		if(i!=1) printf(" ");
		cout<<ceil((n-i+1)/(db)m);
	}
	cout<<endl;
	return 0;
}
