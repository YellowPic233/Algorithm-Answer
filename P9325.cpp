#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=5010;
int n,r,a[MAXN],f[MAXN][MAXN],ans[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(ans,0x3f,sizeof(ans));
    ans[1]=0;
    for(int i=1;i<=n-1;i++) {
        f[i][i+1]=abs(a[i]-a[i+1]);
        ans[2]=min(ans[2],f[i][i+1]);
    }
    for(int len=3;len<=n;len++) {
        for(int l=1;l+len-1<=n;l++) {
            r=l+len-1;
            f[l][r]=f[l+1][r-1]+abs(a[l]-a[r]);
            ans[len]=min(ans[len],f[l][r]);
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}