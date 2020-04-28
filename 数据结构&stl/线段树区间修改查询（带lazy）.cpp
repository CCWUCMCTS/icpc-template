#include<iostream>
#include<cstring>
using namespace std;
struct tree
{
	int start,end;
	long long value,lazy;
};
int n,q,x,ss,ee,l,r,v;
tree a[800010];
void make_tree(int start,int end,int now)
{
	int mid;
	a[now].start=start;
	a[now].end=end;
	a[now].value=0;
	a[now].lazy=0;
	mid=(start+end)/2;
	if (start!=end)
	{
		make_tree(start,mid,now*2);
		make_tree(mid+1,end,now*2+1);
	}
}
void add(int s,int e,int num,int now)
{
	int mid;
	mid=(a[now].start+a[now].end)/2;
	if ((s==a[now].start)&&(e==a[now].end))
	{
		a[now].lazy+=num;
		return;
	}
	if ((s<=mid)&&(e<=mid))
	{
		a[now].value+=(e-s+1)*num;
		if (a[now].lazy==0)
			add(s,e,num,now*2);
		else
		{
			a[now].value+=(a[now].end-a[now].start+1)*a[now].lazy;
			a[now*2+1].lazy+=a[now].lazy;
			a[now*2].lazy+=a[now].lazy;
			a[now].lazy=0;
			add(s,e,num,now*2);
		}
	}
	if ((s>mid)&&(e>mid))
	{
		a[now].value+=(e-s+1)*num;
		if (a[now].lazy==0)
			add(s,e,num,now*2+1);
		else
		{
			a[now].value+=(a[now].end-a[now].start+1)*a[now].lazy;
			a[now*2].lazy+=a[now].lazy;
			a[now*2+1].lazy+=a[now].lazy;
			a[now].lazy=0;
			add(s,e,num,now*2+1);
		}
	}
	if ((s<=mid)&&(e>mid))
	{
		a[now].value+=(e-s+1)*num;
		if (a[now].lazy==0)
		{
			add(s,mid,num,now*2);
			add(mid+1,e,num,now*2+1);
		}
		else
		{
			a[now].value+=(a[now].end-a[now].start+1)*a[now].lazy;
			a[now*2].lazy+=a[now].lazy;
			a[now*2+1].lazy+=a[now].lazy;
			a[now].lazy=0;
			add(s,mid,num,now*2);
			add(mid+1,e,num,now*2+1);
		}
	}
}
long long find(int s,int e,int now)
{
	int mid;
	mid=(a[now].start+a[now].end)/2;
	if ((s==a[now].start)&&(e==a[now].end))
		if (a[now].lazy==0)
			return (a[now].value);
		else
			return (a[now].value+a[now].lazy*(e-s+1));
	if ((s<=mid)&&(e<=mid))
		if (a[now].lazy==0)
			return (find(s,e,now*2));
		else
			return (find(s,e,now*2)+(e-s+1)*a[now].lazy);
	if ((s>mid)&&(e>mid))
		if (a[now].lazy==0)
			return (find(s,e,now*2+1));
		else
			return (find(s,e,now*2+1)+(e-s+1)*a[now].lazy);
	if ((s<=mid)&&(e>mid))
		if (a[now].lazy==0)
			return (find(s,mid,now*2)+find(mid+1,e,now*2+1));
		else
			return (find(s,mid,now*2)+find(mid+1,e,now*2+1)+(e-s+1)*a[now].lazy);
}
int main()
{
	cin>>n;
	make_tree(1,n,1);
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		add(i,i,x,1);
	}
	cin>>q;
	for (int i=1;i<=q;i++)
	{
		cin>>x;
		if (x==1)
		{
			cin>>l>>r>>v;
			add(l,r,v,1);
		}
		if (x==2)
		{
			cin>>l>>r;
			cout<<find(l,r,1)<<endl;
		}
	}
	return 0;
}
