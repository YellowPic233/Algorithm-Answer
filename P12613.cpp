#include <cstdio>
#include <iostream>
using namespace std;
const int INF=1e9;
int r,c,m,dp[20010],ans=-INF;
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
    for(int i=2;i<=r;i++)
        for(int j=1;j<=c;i++)
            dp[j]=cost(i,j)+min(dp[j-1],dp[j],dp[j+1]);
    for(int i=1;i<=c;i++) ans=max(ans,dp[i]);
    printf("%d",ans);
    return 0;
}