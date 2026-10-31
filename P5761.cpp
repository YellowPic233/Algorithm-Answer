#include <iostream>
#include <cstdio>
using namespace std;
const int INF=1e9;
int m,n,a[101][20010],dp[101][20010],maxn[20010],ans=-INF;
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n-1;j++) scanf("%d",&a[i][j]);
    for(int i=i;i<=n-1;i++) maxn[i]=-INF;
    for(int i=1;i<=m;i++) 
        maxn[1]=max(maxn[1],a[i][1]);
    for(int j=2;j<=n-1;j++) 
        for(int i=1;i<=m;i++) 
            maxn[j]=max(maxn[j],max(maxn[j-1]+a[i][j],a[i][j]));
    for(int i=1;i<=n-1;i++) ans=max(ans,maxn[i]);
    printf("%d",ans);
    return 0;
}