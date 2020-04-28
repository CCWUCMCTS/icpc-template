//can be overed
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
const int MAXN=1000020;
char s[MAXN],p[MAXN];
ll nex[MAXN];//you can add 1 to get normal next
void getNext(char strp[],ll nextt[]){
	ll las,pl=strlen(strp);
	nextt[0]=las=-1;
	for(ll i=1;i<pl;i++){
		while(las>-1&&strp[i]!=strp[las+1]){
			las=nextt[las];
		}
		if(strp[i]==strp[las+1]){
			las++;
		}
		nextt[i]=las;
	}
}
ll KMP(char strp[],char strs[],ll nextt[]){
	ll las=-1,pl=strlen(strp),sl=strlen(strs),ans=0;
	getNext(strp,nextt);
	for(ll i=0;i<sl;i++){
		while(las>-1&&strs[i]!=strp[las+1]){
			las=nextt[las];
		}
		if(strs[i]==strp[las+1]) las++; 
		if(las+1==pl){
			ans++;
			las=nextt[las];
			//printf("%d\n",i-pl+2);//output the start
		}
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%s%s",p,s);
		printf("%lld\n",KMP(p,s,nex));
	}
	return 0;
}

