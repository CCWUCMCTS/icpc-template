#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e7; 
bool ipr[MAXN+20];
int cnt,pri[MAXN/5];
void prime(){//°£Ê½É¸·¨ 
	int N=sqrt(MAXN)+0.5,mul;
	memset(ipr,true,sizeof(ipr));
	ipr[1]=false;	
	for(int i=2;i<=N;i++){
		if(ipr[i]==true){
			i==2?mul=1:mul=2;
			for(int j=i*i;j<=MAXN;j+=i*mul){
				ipr[j]=false;
			}
		}
	}
	for(int i=2;i<=MAXN;i++){
		if(ipr[i]==true){
			pri[++cnt]=i;
		}
	}
}
int main(){
	//freopen("stdout.in","w",stdout);
	prime();
	/*clock_t start = clock();
	prime();
	clock_t ends = clock();
	cout <<"Running Time : "<<(double)(ends - start)/ CLOCKS_PER_SEC << endl;
	//cout<<cnt<<endl;
	cout<<"int pri[1020]={";
	for(int i=1;i<=1020;i++){
		cout<<pri[i]<<",";
	}
	cout<<"};\n";*/
	cout<<cnt<<endl;
	return 0;
}
