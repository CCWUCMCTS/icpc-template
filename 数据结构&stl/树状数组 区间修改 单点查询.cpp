#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int a[500020],tree[500020];
int lowbit(int k){
	return k&-k;
}
void add(int k,int num){
	while(k<=n){
		tree[k]+=num;
		k+=lowbit(k);
	}
}
int read(int k){
	int sum=0;
	while(k){
		sum+=tree[k];
		k-=lowbit(k);
	}
	return sum;
}
int main(){
	scanf("%d%d",&n,&m);
	int last=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		add(i,a[i]-last);
		//���������˲��˼�룬����ԭ�������ݴ���a�����У�
		//��ôc���鴢��ľ���c[i]=a[i]-a[i-1]�����c[1]=a[1]����ô������
		//a[i]=c[i]+c[i-1]+c[i-2]+...+c[2]+c[1].
		//��������ÿ�ε����ѯ��ʱ��ֻҪ����c�����ǰ׺�Ϳ����ˡ�
		last=a[i];
	}
	int command,x,y,l;
	for(int i=1;i<=m;i++){
		scanf("%d",&command);
		if(command==1){
			scanf("%d%d%d",&x,&y,&l);
			add(x,l);
			add(y+1,-l);
		}
		else{
			scanf("%d",&x);
			printf("%d\n",read(x));
		}
	}
	return 0;
}
