/*
 * +--------------+
 * |�㷨��ȷ��֤��|          <=����������Ӧ�ý����
 * +--------------+
 *   ��ԭ�����iλ��ֵΪa[i],��d[i]=a[i]-a[i-1]
 *   ���Զ�a��ǰxλ��ͣ��õ�ʽ��
 *    x       x   i
 *    ��a[i]= ��  ��d[j]
 *   i=1     i=1 j=1
 *   Ȼ��ͨ��һЩ������Ȼ�ı��Σ����Դ���͵�������⣩���õ�
 *    x      x
 *    ��a[i]=��(x-i+1)d[i]
 *   i=1    i=1
 *   Ȼ��ͨ����һ������õ�
 *    x      x            x
 *    ��a[i]=��(x+1)*d[i]-��i*d[i]
 *   i=1    i=1          i=1
 *   �������ǿ���ά��������״���飬һ������delta�����d[i]��һ������deltai�����i*d[i]
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
