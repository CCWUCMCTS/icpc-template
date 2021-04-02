#include<bits/stdc++.h>
using namespace std;
int LIS(int num[],int l,int r,bool dec=false,bool equ=false){
	if(l>=r) return 0;
	vector<int>vdp;
	if(dec){
		for(int i=l;i<=r;i++){
			num[i]=-num[i];
		}
	}
	for(int i=l;i<=r;i++){
		vector<int>::iterator iter;
		if(!equ) iter=lower_bound(vdp.begin(),vdp.end(),num[i]);
		else iter=upper_bound(vdp.begin(),vdp.end(),num[i]);
		if(iter==vdp.end()) vdp.push_back(num[i]);
		else *iter=num[i];
	}
	if(dec){
		for(int i=l;i<=r;i++){
			num[i]=-num[i];
		}
	}
	return vdp.size();
}
int n,ans;
int a[100020];
int main(){
	while(scanf("%d",&a[++n])!=EOF);
	n--;
	printf("%d\n",LIS(a,1,n,true,true));
	printf("%d\n",LIS(a,1,n));
	return 0;
}
