#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=205;
int n,a[MAXN],f1[MAXN][MAXN],f2[MAXN][MAXN],s[MAXN],ans1=INF,ans2=-INF;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++) {
        a[i+n]=a[i];
        s[i+n]=s[i+n-1]+a[i+n];
    }
    memset(f1,0x3f,sizeof(f1));
    for(int i=1;i<=2*n;i++) f1[i][i]=0;
    for(int i=2;i<=n;i++) {
        for(int l=1;l+i-1<=2*n;l++) {
            int r=l+i-1;
            for(int k=l;k<r;k++) f1[l][r]=min(f1[l][r],f1[l][k]+f1[k+1][r]);
            f1[l][r]+=s[r]-s[l-1];
        }
    }
    for(int i=1;i<=2*n;i++)
        for(int j=1;j<=2*n;j++) f2[i][j]=i==j?0:-INF;
    for(int i=2;i<=n;i++) {
        for(int l=1;l+i-1<=2*n;l++) {
            int r=l+i-1;
            for(int k=l;k<r;k++) f2[l][r]=max(f2[l][r],f2[l][k]+f2[k+1][r]);
            f2[l][r]+=s[r]-s[l-1];
        }
    }
    for(int i=1;i+n-1<=2*n;i++) ans1=min(ans1,f1[i][i+n-1]);
    for(int i=1;i+n-1<=2*n;i++) ans2=max(ans2,f2[i][i+n-1]);
    printf("%d\n%d",ans1,ans2);
    return 0;
}