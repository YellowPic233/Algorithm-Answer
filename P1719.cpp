#include <iostream>
#include <cstdio>
using namespace std;
const int INF=1e9;
int n,a[121][121],sum[121][121];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            scanf("%d",&a[i][j]);
            sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    
    return 0;
}