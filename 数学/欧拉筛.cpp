#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5;
bool ipr[MAXN+20];
int cnt,pri[MAXN/5];
void prime(){//Å·À­É¸ 
	memset(ipr,true,sizeof(ipr));
    ipr[1]=false;
    for(int i=2;i<=MAXN;i++){
        if(ipr[i])  pri[++cnt]=i;
        for(int j=1;j<=cnt&&pri[j]<=MAXN/i;j++){
            ipr[i*pri[j]]=false;
            if(!i%pri[j])  break;
        }
    }
}
int main(){
	freopen("stdout.in","w",stdout);
    clock_t start = clock();
	prime();
	clock_t ends = clock();
	cout<<"int pri[1020]={";
	for(int i=1;i<=1020;i++){
		cout<<pri[i]<<",";
	}
	cout<<"};\n";
	cout <<"Running Time : "<<(double)(ends - start)/ CLOCKS_PER_SEC << endl;
	return 0;
}
