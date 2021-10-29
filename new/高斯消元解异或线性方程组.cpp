#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int a[N][N];
int gauss()
{
    int c,r;
    for(c=0,r=0;c<n;c++)
    {
        // ����Ԫ
        int t=-1;
        for(int i=r;i<n;i++)
            if(a[i][c])
            {
                t=i;
                break;
            }
        if(t==-1) continue;
        // ������Ԫ��
        for(int j=c;j<=n;j++) swap(a[r][j],a[t][j]);
        // ���½���
        for(int i=r+1;i<n;i++)
            if(a[i][c])//©��
                for(int j=n;j>=c;j--)//©��
                    a[i][j] ^= a[r][j];
        r++;
    }
    // �ж�
    if(r<n)
    {
        for(int i=r;i<n;i++)//i=r
            if(a[i][n])
                return 2;
        return 1;
    }
    // �����Ͻ�
    for(int i=n-1;i>=0;i--)
        for(int j=i+1;j<n;j++)
        //�����0 �Ͳ��������a[j][j] ��^a[i][j]��
        //�������0 ����Ҫ�õ�j�е�j��a[j][j]��^��i�е�j��a[i][j] 
        //������������row[i]^row[j] ��ӵ��� a[i][n]^a[j][n]
            if(a[i][j])
                a[i][n]^=a[j][n];
    return 0;
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<=n;j++)
            cin >> a[i][j];
    int t = gauss();
    if(t==0)
    {
        for(int i=0;i<n;i++) cout << a[i][n] << endl;
    }
    else if(t==1) puts("Multiple sets of solutions");
    else puts("No solution");
    return 0;
}

