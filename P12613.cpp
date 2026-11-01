#include <cstdio>
#include <iostream>
using namespace std;
const int INF=1e9;
int r,c,m,dp[20010],ndp[20010],ans=INF;
int cost(int x,int y)
{
    int temp=(x-1)*c+y;
    return temp%m==0?m:temp%m;
}
int main()
{
    scanf("%d%d%d",&r,&c,&m);
    dp[0]=dp[c+1]=INF;
    for(int i=1;i<=c;i++) dp[i]=i%m==0?m:i%m;
    for(int i=2;i<=r;i++) {
        ndp[0]=ndp[c+1]=INF;
        for(int j=1;j<=c;j++)
            ndp[j]=cost(i,j)+min(dp[j],min(dp[j-1],dp[j+1]));
        for(int j=1;j<=c;j++) dp[j]=ndp[j];
    }
    for(int i=1;i<=c;i++) ans=min(ans,dp[i]);
    printf("%d",ans);
    return 0;
}