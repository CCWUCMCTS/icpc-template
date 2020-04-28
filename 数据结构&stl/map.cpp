#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
map<string,int>mp;
char a[200]="aaaaa";
char b[220]="aaaaa";
struct Edge{
	int u,v,w,next;
	bool operator<(const Edge &x)const{return w<x.w;}
};
int main(){
	mp[a]=1;
	printf("%d",mp.size());
	mp.erase("aaaaa");
	//sort,swap,clear,empty,insert
	return 0;
}
