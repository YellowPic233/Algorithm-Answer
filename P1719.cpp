#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF=1e9;
int n,a[121][121],sum[121][121],col[121][121],dp[121],ans=-INF;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            scanf("%d",&a[i][j]);
            col[i][j]=col[i-1][j]+a[i][j];
        }
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++) {
            for(int i=1;i<=n;i++) dp[i]=-INF;
            dp[1]=col[j][1]-col[i-1][1];
            ans=max(ans,dp[1]);
            for(int k=2;k<=n;k++) {
                dp[k]=max(col[j][k]-col[i-1][k],dp[k-1]+col[j][k]-col[i-1][k]);
                ans=max(dp[k],ans);
            }
        }
    }
    printf("%d",ans);
    return 0;
}