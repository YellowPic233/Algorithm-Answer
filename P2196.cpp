#include <iostream>
#include <cstdio>
using namespace std;
const int INF=1e9;
int n,f[30][30],m[30],temp,dp[30],pre[30],ans=-INF,pos,len,list[30];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) { 
        scanf("%d",&m[i]); 
        dp[i]=m[i]; 
    }
    for(int i=1;i<=n-1;i++)
        for(int j=i+1;j<=n;j++) scanf("%d",&f[i][j]);
    for(int i=2;i<=n;i++) {
        for(int j=1;j<=i-1;j++) {
            if( f[j][i] )
                if( dp[j]+m[i]>dp[i] ) {
                    dp[i]=dp[j]+m[i];
                    pre[i]=j;
                }
        }
    }
    for(int i=1;i<=n;i++) {
        if( dp[i]>ans ) {
            ans=dp[i];
            pos=i;
        }
    }
    temp=pos;
    while( temp!=0 ) {
        list[++len]=temp;
        temp=pre[temp];
    }
    for(int i=len;i>=1;i--) printf("%d ",list[i]);
    printf("\n%d",ans);
    return 0;
}