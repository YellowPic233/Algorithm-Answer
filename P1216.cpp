#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN=1001;
const int INF=1e9;
int n,a[MAXN][MAXN],dp[MAXN][MAXN],ans=-INF;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++) scanf("%d",&a[i][j]);
    dp[1][1]=a[1][1];
    ans=max(ans,a[1][1]);
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++) dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i-1][j-1]),ans=max(ans,dp[i][j]);
    printf("%d",ans);
    return 0;
}