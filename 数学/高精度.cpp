#include<iostream>
#include<sstream>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<vector>
#include<cmath>
#include<ctime>
#include<stack>
using namespace std;
struct Wint:vector<int>//�ñ�׼��vector�����࣬�������λ�����⣬ͬʱ������ʵ��
{
    //���;���ת�߾��ȵĳ�ʼ���������Զ�������������
    //������赥��д�߾������͵;����������㺯����ʮ�ַ���
    Wint(int n=0)//Ĭ�ϳ�ʼ��Ϊ0����0�ı�����ʽΪ��
    {
        push_back(n);
        check();
    }
    Wint& check()//�ڸ��������о����õ��Ľ�λС��������������
    {
        while(!empty()&&!back())pop_back();//ȥ�����λ���ܴ��ڵ�0
        if(empty())return *this;
        for(int i=1; i<size(); ++i)//�����λ 
        {
            (*this)[i]+=(*this)[i-1]/10;
            (*this)[i-1]%=10;
        }
        while(back()>=10)
        {
            push_back(back()/10);
            (*this)[size()-2]%=10;
        }
        return *this;//Ϊʹ�÷��㣬����λ�������������
    }
};
//�������
istream& operator>>(istream &is,Wint &n)
{
    string s;
    is>>s;
    n.clear();
    for(int i=s.size()-1; i>=0; --i)n.push_back(s[i]-'0');
    return is;
}
ostream& operator<<(ostream &os,const Wint &n)
{
    if(n.empty())os<<0;
    for(int i=n.size()-1; i>=0; --i)os<<n[i];
    return os;
}
//�Ƚϣ�ֻ��Ҫд������������ֱ�Ӵ��뼴��
//�������õ����������⿽������Ч
bool operator!=(const Wint &a,const Wint &b)
{
    if(a.size()!=b.size())return 1;
    for(int i=a.size()-1; i>=0; --i)
        if(a[i]!=b[i])return 1;
    return 0;
}
bool operator==(const Wint &a,const Wint &b)
{
    return !(a!=b);
}
bool operator<(const Wint &a,const Wint &b)
{
    if(a.size()!=b.size())return a.size()<b.size();
    for(int i=a.size()-1; i>=0; --i)
        if(a[i]!=b[i])return a[i]<b[i];
    return 0;
}
bool operator>(const Wint &a,const Wint &b)
{
    return b<a;
}
bool operator<=(const Wint &a,const Wint &b)
{
    return !(a>b);
}
bool operator>=(const Wint &a,const Wint &b)
{
    return !(a<b);
}
//�ӷ�����ʵ��+=������������Ч
Wint& operator+=(Wint &a,const Wint &b)
{
    if(a.size()<b.size())a.resize(b.size());
    for(int i=0; i!=b.size(); ++i)a[i]+=b[i];
    return a.check();
}
Wint operator+(Wint a,const Wint &b)
{
    return a+=b;
}
//���������ز�ľ���ֵ�����ں����н������ʲ�����������
Wint& operator-=(Wint &a,Wint b)
{
    if(a<b)swap(a,b);
    for(int i=0; i!=b.size(); a[i]-=b[i],++i)
        if(a[i]<b[i])//��Ҫ��λ
        {
            int j=i+1;
            while(!a[j])++j;
            while(j>i)
            {
                --a[j];
                a[--j]+=10;
            }
        }
    return a.check();
}
Wint operator-(Wint a,const Wint &b)
{
    return a-=b;
}
//�˷�������ʵ��*=��ԭ���Լ���
Wint operator*(const Wint &a,const Wint &b)
{
    Wint n;
    n.assign(a.size()+b.size()-1,0);
    for(int i=0; i!=a.size(); ++i)
        for(int j=0; j!=b.size(); ++j)
            n[i+j]+=a[i]*b[j];
    return n.check();
}
Wint& operator*=(Wint &a,const Wint &b)
{
    return a=a*b;
}
//������ȡģ��ʵ��һ�������������
Wint divmod(Wint &a,const Wint &b)
{
    Wint ans;
    for(int t=a.size()-b.size(); a>=b; --t)
    {
        Wint d;
        d.assign(t+1,0);
        d.back()=1;
        Wint c=b*d;
        while(a>=c)
        {
            a-=c;
            ans+=d;
        }
    }
    return ans;
}
Wint operator/(Wint a,const Wint &b)
{
    return divmod(a,b);
}
Wint& operator/=(Wint &a,const Wint &b)
{
    return a=a/b;
}
Wint& operator%=(Wint &a,const Wint &b)
{
    divmod(a,b);
    return a;
}
Wint operator%(Wint a,const Wint &b)
{
    return a%=b;
}
Wint pow(Wint n,Wint k)
{
	Wint cur=n,ans=1;
	while(k!=0){
		if(k%2==1) ans*=cur;
		cur*=cur;
		k=k/2;
	}
	return ans;
}
int main()
{
	Wint p;
	cin>>p;
	Wint ans=pow(Wint(2),p)-1;
	cout<<ans.size()<<endl;
	cout<<ans<<endl;
	return 0;
}
