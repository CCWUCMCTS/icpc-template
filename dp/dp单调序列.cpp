/*
1��b(I,1)��ʾ��I��������ֵ����
2��b(I,2)��ʾ��Iλ�õ���N������½����г���
3��b(I,3)��ʾ��Iλ�ÿ�ʼ����½����е���һ��λ��
*/
#include<iostream>
#include<cstdio>
using namespace std;
int n,i,j,l,k,b[200][10]; 
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		cin>>b[i][1];
		b[i][2]=1;b[i][3]=0;
	}
	for (i=n-1;i>=1;i--){
		l=0;k=0;
		for (j=i+1;j<=n;j++)
			if ((b[j][1]>b[i][1])&&(b[j][2]>l)){
				l=b[j][2];
				k=j;
			}
		if (l>0){
			b[i][2]=l+1;b[i][3]=k;
		}  
     }
	k=1;
	for (j=1;j<=n;j++)                        
	if (b[j][2]>b[k][2]) k=j;
	cout<<"max="<<b[k][2]<<endl;             
	while (k!=0){
		cout<<' '<<b[k][1];
		k=b[k][3];   
	} 
	return 0;
}

