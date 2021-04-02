#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
#define ll long long
#define io_opt ios::sync_with_stdio(false);cin.tie(0);cout.tie(0) 
int n,m; 
map<char,int>mp;
struct E{
	string name;
	int r,c;
}e[30];
int f[300][300];
int cal(string s){
	int len=s.size();
	vector<int>v;
	v.push_back(e[mp[s[0]]].r);
	for(int i=1;i<s.size();i++){
		if(e[mp[s[i-1]]].c!=e[mp[s[i]]].r){
			return -1;
		}
		v.push_back(e[mp[s[i]]].r);
	}
	v.push_back(e[mp[s[s.size()-1]]].c);
	memset(f,0,sizeof(f));
	for(int i=2;i<=s.size();i++){
		for(int l=1,r=l+i-1;r<=len;l++,r++){
			f[l][r]=f[l][l]+f[l+1][r]+v[l-1]*v[l]*v[r];
			for(int k=l+1;k<r;k++){
				f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+v[l-1]*v[k]*v[r]);
			}
		}
	}
	return f[1][len];
}
int main(){
	io_opt;
	while(cin>>n>>m){
		mp.clear();
		for(int i=1;i<=n;i++){
			cin>>e[i].name>>e[i].r>>e[i].c;
			mp[e[i].name[0]]=i;
		}
		string s;
		for(int i=1;i<=m;i++){
			cin>>s;
			int t=cal(s);
			if(t==-1){
				cout<<"MengMengDa"<<endl;
			}
			else{
				cout<<t<<endl;
			}
		}
	}
    return 0;
}
