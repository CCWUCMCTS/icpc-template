/*
1
5
she
he
say
shr
her
yasherhs
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
#define inf 2147483647
using namespace std;
typedef pair<int,int> pii;
const int K=26;//字符串中出现k种字符
const int Max_N=500100;
struct Node
{
	Node *ch[K],*fail;
	int match;
	void clear()
	{
		memset(this,0,sizeof(Node));
	}
};
Node *que[Max_N];
struct AC
{
	Node nodes[Max_N],*root,*superRoot,*cur;
	Node *newNode()//初始化节点 
	{
		cur->clear();
		return cur++;
	}
	void clear()//初始化字典树 
	{
		cur=nodes;
		superRoot=newNode();
		root=newNode();
		root->fail=superRoot;
		for(int i=0;i<K;i++)
			superRoot->ch[i]=root;
		superRoot->match=-1; 
	}
	void insert(char*s)
	{
		Node *t=root;
		for(;*s;s++)
		{
			int x=*s-'a';
			if(t->ch[x]==NULL)
				t->ch[x]=newNode();
			t=t->ch[x];
		}
		t->match++;
	}
	void build()
	{
		int p=0,q=0;
		que[q++]=root;
		while(p!=q)
		{
			Node *t=que[p++];
			for(int i=0;i<K;i++)
			{
				if(t->ch[i])
				{
					t->ch[i]->fail=t->fail->ch[i];
					que[q++]=t->ch[i];
				}
				else
					t->ch[i]=t->fail->ch[i];
			}
		}
	}
	int run(char*s)
	{
		int ans=0;
		Node *t=root;
		for(;*s;s++)
		{
			int x=*s-'a';
			t=t->ch[x];
			for(Node *u=t;u->match!=-1;u=u->fail)
			{
				ans+=u->match;
				u->match=-1; 
			}
		}
		return ans;
	} 
};
char s[1000100];
AC c;
int n;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		c.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			c.insert(s);
		}
		c.build();
		scanf("%s",s);
		printf("%d\n",c.run(s));
	}
	return 0;
}

