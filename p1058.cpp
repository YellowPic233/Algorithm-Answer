#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,a[51][51],x,y,N,M;
char ch[3501][3501];
void full(int x,int y)
{
	ch[x][y]=ch[x-3][y]=ch[x][y+4]=ch[x-3][y+4]=ch[x-5][y+2]=ch[x-5][y+6]=ch[x-2][y+6]='+';
	ch[x-1][y]=ch[x-2][y]=ch[x-1][y+4]=ch[x-2][y+4]=ch[x-3][y+6]=ch[x-4][y+6]='|';
	ch[x-4][y+1]=ch[x-4][y+5]=ch[x-1][y+5]='/';
	ch[x][y+1]=ch[x][y+2]=ch[x][y+3]=ch[x-3][y+1]=ch[x-3][y+2]=ch[x-3][y+3]=ch[x-5][y+3]=ch[x-5][y+4]=ch[x-5][y+5]='-';
	ch[x-1][y+1]=ch[x-1][y+2]=ch[x-1][y+3]=' ';
	ch[x-2][y+1]=ch[x-2][y+2]=ch[x-2][y+3]=' ';
	ch[x-4][y+2]=ch[x-4][y+3]=ch[x-4][y+4]=' ';
	ch[x-2][y+5]=ch[x-3][y+5]=' ';
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) cin>>a[i][j];
	N=6+(n-1)*2;
	M=7+(m-1)*4+(n-1)*2;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			N=max(N,(n-i)*2+6+(a[i][j]-1)*3);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++) ch[i][j]='.';
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=a[i][j];k++) {
				x=N-(n-i)*2-(k-1)*3;
				y=(n-i)*2+(j-1)*4+1;
				full(x,y);
			}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) cout<<ch[i][j];
		cout<<endl; 
	}
	return 0;
}