#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN=150001;
int n,x,y,dp[MAXN],pref[MAXN];
struct ele {
    int x,y,len;
};
bool cmp(ele a,ele b)
{
    if( a.y==b.y ) return a.x<b.x;
    else return a.y<b.y;
}
vector<ele> a;
int pos(int k,int x)
{
    int l=0,r=k-1,mid;
    while( l<=r ) {
        int mid=l+(r-l)/2;
        if( a[mid].y<x ) l=mid+1;
        else r=mid-1;
    }
    return r;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&x,&y);
        a.push_back(ele{x,y,y-x+1});
    }
    sort(a.begin(),a.end(),cmp);
    dp[0]=a[0].len;
    pref[0]=a[0].len;
    for(int i=1;i<=n-1;i++) {
        int p=pos(i,a[i].x);
        if( p==-1 ) dp[i]=a[i].len;
        else dp[i]=pref[p]+a[i].len;
        pref[i]=max(pref[i-1],dp[i]);
    }
    printf("%d",pref[n-1]);
    return 0;
}