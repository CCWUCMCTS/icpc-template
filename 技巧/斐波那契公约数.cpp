//luogu1306
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long n,m,c,d,p=100000000;
struct jz{
    long long a[40][40];
};
long long gcd(long long a,long long b){
    return b==0?a:gcd(b,a%b);
}
jz s;
jz fz(jz x){
    memset(x.a,0,sizeof(x.a));
    for(long long i=1;i<=n;i++){
        x.a[i][i]=1;
    }
    return x;
}
jz cf(jz x,jz y){
    jz neww;
    memset(neww.a,0,sizeof(neww.a));
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            for(long long k=1;k<=n;k++){
                neww.a[i][j]=((x.a[i][k]*y.a[k][j])%p+neww.a[i][j])%p;
            }
        }
    }
    return neww;
}
jz speed(jz x,long long b){
    if(b==1) return x;
    jz cur,ans;
    ans=fz(ans);
    cur=x;
    while(b){
        if(b&1){
            ans=cf(ans,cur);
        }
        cur=cf(cur,cur);
        
        b>>=1;
    }
    return ans;
}
int main(){
    
    s.a[1][1]=1;
    s.a[1][2]=1;
    s.a[2][1]=1;
    s.a[2][2]=0;
    n=2;
    //scanf("%d",&m);
    scanf("%lld%lld",&c,&d);
    long long e=gcd(c,d);
    jz x=speed(s,e-1);
    printf("%lld\n",x.a[1][1]%p);
    return 0;
}
