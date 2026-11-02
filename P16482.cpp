#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int t,n,m;
ll dp[101][101];
int main()
{
    scanf("%d",&t);
    dp[1][1]=1;
    for(int i=2;i<=100;i++)
        for(int j=1;j<=i;j++) dp[i][j]=(j%mod*(dp[i-1][j-1]+dp[i-1][j])%mod)%mod;
    for(int i=1;i<=t;i++) {
        scanf("%d%d",&m,&n);
        printf("Case #%d: %lld\n",i,dp[n][m]);
    }
    return 0;
}