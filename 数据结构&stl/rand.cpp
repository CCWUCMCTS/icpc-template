#include<iostream>
#include<cstdio>
#include <stdlib.h> 
#include <time.h>  
using namespace std;
int a=7,b=20,n,m;
int main(){
	//freopen("flood.in","w",stdout);
	cin>>n>>m;
	cout<<n<<' '<<m<<endl;
    srand((unsigned)time(NULL));  
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<(rand()%(b-a+1))<<' ';//
		}
		cout<<endl;
	}
    cout<<endl;
    
    return 0;
}
