//char
#include<bits/stdc++.h>
#define ll long long
#define db double
#define ioss ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int MAXN=100020;
int n;
ll ext[MAXN],nex[MAXN];
char s[MAXN],p[MAXN];
void getNext(char strp[],ll nextt[]){
    nextt[0]=0;
    ll pl=strlen(strp);
    ll fir=0,las=0;
    for(ll i=1;i<pl;i++) {
        nextt[i] = min(las - i + 1, nextt[i - fir]);
        if (nextt[i] < 0) nextt[i] = 0;
        while (i+nextt[i]<pl && strp[nextt[i]] == strp[i + nextt[i]]) {
            nextt[i]++;
        }
        if (i + nextt[i] - 1 > las) {
            las = i + nextt[i] - 1;
            fir = i;
        }
    }
}
void exKMP(char strp[],char strs[],ll nextt[],ll extt[]){
    getNext(strp,nextt);
    ll pl=strlen(strp),sl=strlen(strs);
    ll fir=0,las=-1,mnl=min(sl,pl);
    while(las<mnl-1&&strp[las+1]==strs[las+1]){
        las++;
    }
    extt[0]=las+1;
    for(ll i=1;i<sl;i++){
        extt[i]=min(las-i+1,nextt[i-fir]);
        if(extt[i]<0) extt[i]=0;
        while(extt[i]<pl && i+extt[i]<sl && strp[extt[i]]==strs[i+extt[i]]){
            extt[i]++;
        }
        if(i+extt[i]-1>las){
            las=i+extt[i]-1;
            fir=i;
        }
    }
}
int main() {
    scanf("%s%s",s,p);
    exKMP(p,s,nex,ext);
    printf("%d",strlen(p));
    for(int i=0;i<strlen(p);i++){
    	printf(" %lld",nex[i]);
    }
    printf("\n");
    for(int i=0;i<strlen(s);i++){
    	if(i!=0) printf(" ");
    	printf("%lld",ext[i]);
    }
    printf("\n");
    return 0;
}
