#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,a[1010];
struct ios{
    inline char gc(){
        static const int IN_LEN=1<<18|1;
        static char buf[IN_LEN],*s,*t;
        return (s==t)&&(t=(s=buf)+fread(buf,1,IN_LEN,stdin)),s==t?-1:*s++;
    }
    template <typename _Tp> inline ios & operator >> (_Tp&x){
        static char ch,sgn; ch = gc(), sgn = 0;
        for(;!isdigit(ch);ch=gc()){if(ch==-1)return *this;sgn|=ch=='-';}
        for(x=0;isdigit(ch);ch=gc())x=x*10+(ch^'0');
        sgn&&(x=-x); return *this;
    }
}io;
int inline read(){
	int num=0;
	char c;
	bool plus=true;
	while((c=getchar())==' '||c=='\n'||c=='\r');
	if(c=='-') plus=false;
	else num=c-'0';
	while(isdigit(c=getchar()))
		num=num*10+c-'0';
	return 	num*(plus?1:-1);
}
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int _read(){
    char ch=nc();int sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
