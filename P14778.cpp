#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll n,k,C[5010],dp[5010][5010];
int main()
{
    scanf("%lld%lld",&n,&k);
    C[1]=1;
    for(int i=2;i<=n;i++) C[i]=(C[i-1]*i)%mod;
    for(int i=1;i<=n;i++) dp[i][1]=C[i-1];
    dp[1][1]=1;
    for(int i=2;i<=n;i++) 
        for(int j=1;j<=i;j++) dp[i][j]=(dp[i-1][j-1]%mod+(i-1)%mod*dp[i-1][j]%mod)%mod; 
    printf("%lld",dp[n][k]);
    return 0;
}