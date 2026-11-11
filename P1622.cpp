#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF=0x3f3f3f3f;
int p,q,a[110],dp[110][110];
int main()
{
    scanf("%d%d",&p,&q);
    for(int i=1;i<=q;i++) scanf("%d",&a[i]);
    a[q+1]=p+1;
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<=q;i++) dp[i+1][i]=0;
    for(int len=1;len<=q;len++) {
        for(int l=1;l+len-1<=q;l++) {
            int r=l+len-1;
            for(int k=l;k<=r;k++) dp[l][r]=min(dp[l][r],dp[l][k-1]+dp[k+1][r]);
            dp[l][r]+=a[r+1]-a[l-1]-2;
        }
    }
    printf("%d",dp[1][q]);
    return 0;
}