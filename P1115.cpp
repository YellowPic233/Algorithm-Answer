#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll INF=1e12;
const int MAXN=200010;
int n,a[MAXN];
ll dp[MAXN],ans=-INF;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    dp[1]=a[1];
    for(int i=2;i<=n;i++) {
        if( dp[i-1]+a[i]<=a[i] ) dp[i]=a[i];
        else dp[i]=dp[i-1]+a[i];
    }
    for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
    printf("%lld",ans);
    return 0;
}