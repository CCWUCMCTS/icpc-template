/*
 * +--------------+
 * |算法正确性证明|          <=不不不，这应该叫题解
 * +--------------+
 *   设原数组第i位的值为a[i],设d[i]=a[i]-a[i-1]
 *   所以对a的前x位求和，得到式子
 *    x       x   i
 *    Σa[i]= Σ  Σd[j]
 *   i=1     i=1 j=1
 *   然后通过一些并不显然的变形（可以从求和的意义理解），得到
 *    x      x
 *    Σa[i]=Σ(x-i+1)d[i]
 *   i=1    i=1
 *   然后通过进一步推理得到
 *    x      x            x
 *    Σa[i]=Σ(x+1)*d[i]-Σi*d[i]
 *   i=1    i=1          i=1
 *   所以我们可以维护两个树状数组，一个名叫delta，针对d[i]，一个名叫deltai，针对i*d[i]
 * */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
const int maxn=200005;
typedef long long ull;
ull delta[maxn],deltai[maxn];
int a[maxn];
int n,q;
inline int lowbit(int x){
	return x&(-x);
}
inline void add(int x,ull y){
	for(int i=x;i<=n;i+=lowbit(i)){
		delta[i]+=y;
		deltai[i]+=x*y;
	}
}
inline ull sum(int x){
	ull ans=0;
	for(int i=x;i>0;i-=lowbit(i)){
		ans+=(x+1)*delta[i]-deltai[i];
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	int last=0;
	for(int i=1;i<=n;i++){
		int tmp;
		scanf("%d",&tmp);
		add(i,tmp-last);
		last=tmp;
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int cho;
		scanf("%d",&cho);
		if(cho==1){
			int t1,t2;
			long long t3;
			scanf("%d%d%d",&t1,&t2,&t3);
			add(t1,t3);
			add(t2+1,-t3);
		}
		else{
			int t1,t2;
			scanf("%d%d",&t1,&t2);
			cout<<sum(t2)-sum(t1-1)<<endl;
		}
	}
	return 0;
}
