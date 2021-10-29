#include<bits/stdc++.h>
using namespace std;
#define MAXN 120
#define fabs(x) ((x)>0?(x):-(x))
#define eps 1e-10
//列主元gauss消去求解a[][]x[]=b[]
//返回是否有唯一解,若有解在b[]中
// a[N][N]是增广矩阵
int n;
double a[120][120],b[120];
int gauss()
{
    int c, r;
    for (c = 0, r = 0; c < n; c ++ )
    {
        int t = r;
        for (int i = r; i < n; i ++ )   // 找到绝对值最大的行
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;

        if (fabs(a[t][c]) < eps) continue;

        for (int i = c; i <= n; i ++ ) swap(a[t][i], a[r][i]);      // 将绝对值最大的行换到最顶端
        for (int i = n; i >= c; i -- ) a[r][i] /= a[r][c];      // 将当前行的首位变成1
        for (int i = r + 1; i < n; i ++ )       // 用当前行将下面所有的列消成0
            if (fabs(a[i][c]) > eps)
                for (int j = n; j >= c; j -- )
                    a[i][j] -= a[r][j] * a[i][c];

        r ++ ;
    }

    if (r < n)
    {
        for (int i = r; i < n; i ++ )
            if (fabs(a[i][n]) > eps)
                return 2; // 无解
        return 1; // 有无穷多组解
    }

    for (int i = n - 1; i >= 0; i -- )
        for (int j = i + 1; j < n; j ++ )
            a[i][n] -= a[i][j] * a[j][n];

    return 0; // 有唯一解
}


int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
		scanf("%d",&b[i]);
		
	}
	int res = gauss();
	if(res==0){
		for(int i=1;i<=n;i++){
			printf("%.2f\n",b[i]);
		}
	}
	else if(res==1){
		printf("Infinite group solutions\n");
	}
	else{
		printf("No solution\n");
	}
	return 0;
}
