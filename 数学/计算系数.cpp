//luogu1313
#include<iostream>
#include<cstdio>
using namespace std;
int f[1020][1020];
int a,b,k,n,m;
int speedm(int x,int c,int p){
    int cur=1,k=x;
    while(c){
        if(c&1){
            cur=cur*k%p;
        }
        k=k*k%p;
        c>>=1;
    }
    return cur;
}
int dfs(int h,int l){
    if(h<l) return 0;
    if(h==0) return 0;
    if(h==l||l==0) return f[h][l]=1;
    if(l==1||l==h-1) return f[h][l]=h;
    int a=(f[h-1][l]==0?f[h-1][l]=dfs(h-1,l):f[h-1][l]);
    int b=(f[h-1][l-1]==0?f[h-1][l-1]=dfs(h-1,l-1):f[h-1][l-1]);
    return f[h][l]=a+b%10007;
}
int main(){
    int luck=10007;
    scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
    int a1=speedm(b%luck,m,10007),a2=speedm(a%luck,n,10007);
    int a3=dfs(k,n)%luck;
    //cout<<a1<<a2<<a3;
    cout<<(((a3*a2)%luck)*a1)%luck;
    return 0;
}
