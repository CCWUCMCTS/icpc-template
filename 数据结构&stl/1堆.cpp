#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int n,m;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		if(m==1){
			scanf("%d",&m);
			q.push(m);
		}
		else if(m==2){
			printf("%d\n",q.top());
		}
		else{
			q.pop();
		}
	}
	return 0;
}
