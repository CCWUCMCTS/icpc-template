#include<cstdio>
#define maxn 110
#define r register
using namespace std;
typedef long long ll;
int n,p,maxi;
ll tmp,ans[maxn],a[maxn][maxn];
int read()
{
	r char ch=getchar();r int in=0;
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') in=(in<<3)+(in<<1)+ch-'0',ch=getchar();
	return in;
}
ll ksm(r ll x,r int y)
{
	if(!y) return 1;
	r ll ret=ksm(x,y>>1);
	if(y&1) return ret*ret%p*x%p;
	return ret*ret%p;
}
int main()
{
	n=read(),p=read();
	for(r int i=1;i<=n;i++)
		for(r int j=1;j<=n+1;j++)
			a[i][j]=read();
	for(r int i=1;i<=n;i++)
	{
		if(!a[i][i])//主元不能为0
		{
			maxi=0;
			for(r int j=i+1;j<=n&&!maxi;j++)
				if(a[j][i]) maxi=j;
			if(!maxi) continue;//如果一整列都为0，不需要消元
			for(r int j=i;j<=n+1;j++)
				tmp=a[maxi][j],a[maxi][j]=a[i][j],a[i][j]=tmp;
		}
		for(r int j=i+1;j<=n;j++)
		{
			tmp=a[j][i];
			if(!tmp) continue;//已经为0，不需要消元
			for(r int k=i;k<=n+1;k++)
				a[j][k]=((a[j][k]*a[i][i]-a[i][k]*tmp)%p+p)%p;
		}
	}
	for(r int i=n;i;i--)
	{
		for(r int j=i+1;j<=n;j++)
			a[i][n+1]=((a[i][n+1]-ans[j]*a[i][j])%p+p)%p;
		ans[i]=a[i][n+1]*ksm(a[i][i],p-2)%p;
	}
	for(r int i=1;i<=n;i++) printf("%lld ",ans[i]);
	return 0;
}

