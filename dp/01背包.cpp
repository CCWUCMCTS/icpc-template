#include<iostream>
#include<cstdio>
using namespace std;
int m,n;
int w[352000],val[352000],f[352000];
int main(){
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&w[i],&val[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            f[j]=max(f[j],f[j-w[i]]+val[i]);
        }
    }
    printf("%d\n",f[m]);
    return 0;
}
