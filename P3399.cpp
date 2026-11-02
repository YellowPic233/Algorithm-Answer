#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m,c[1001],d[1001],dp[1001][1001];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=m;i++) scanf("%d",&d[i]);
    dp[1][1]=c[1]*d[1];
    for(int i=2;i<=m;i++) {
        for(int j=1;j<=i;j++) {
            if( j<i ) dp[j][i]=min(dp[j][i-1],dp[j-1][i-1]+c[j]*d[i]);
            else dp[j][i]=dp[j-1][i-1]+c[j]*d[i];
        }
    }
    printf("%d",dp[n][m]);
    return 0;
}