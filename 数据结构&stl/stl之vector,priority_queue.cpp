//empty,size,swap,clear
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;

vector<int>a[22];
int main(){
	int b=5;
	a[1].push_back(b);
	cout<<a[1][0];
	a[1].pop_back();
	return 0;
} 
