#include <bits/stdc++.h>
using namespace std;
#define NMX 100
#define SC_MX 3009
#define SC_MN 1501
#define INT_MX 1000007
int ar[NMX][NMX],n;
int xc[]={-1,-1};
int yc[2][2]={{-1,0},{0,1}};
int mem[NMX][NMX][SC_MX],ans;
bool valid(int x,int y)
{
	if(x>=0 && x<(2*n-1))
	{
		if(x<n)
			return y>=0 && y<=x;
		else
			return y>=0 && y<=(2*n-x-1);
	}
	return false;
}
// int fun(int x,int y,int score)
// {
// 	if(x==0)
// 		return min(score-ar[0][0],score+ar[0][0]);
// 	int &res=mem[x][y][score+SC_MN],k=1,l,res1,res2;
// 	if(res!=-1)
// 		return res;
// 	res = INT_MX;
// 	if(x<n)
// 		k=0;
// 	for(int l=0;l<2;l++)
// 	{
// 		int nx = x+xc[l],ny=y+yc[k][l];
// 		if(valid(nx,ny))
// 		{
// 			// cout<<nx<<","<<ny<<endl;
// 			res1=score-fun(nx,ny,score+ar[nx][ny]+SC_MN)-SC_MN;
// 			res2=score-fun(nx,ny,score-ar[nx][ny]+SC_MN)-SC_MN;
// 			if(abs(res1)<abs(res2))
// 				res=min(res,res1);
// 			else
// 				res=min(res,res2);
// 		}
// 	}
// 	return res;
// }
void fun(int x,int y,int score)
{
	if(x==0)
	{
		if(ans>abs(score-ar[x][y]))
			ans=abs(score-ar[x][y]);
		if(ans>abs(score+ar[x][y]))
			ans=abs(score+ar[x][y]);
			// cout<<ans<<","<<score<<endl;
		return;
	}
	int k=1,l;
	if(mem[x][y][score+SC_MN]!=-1)
		return;
	mem[x][y][score+SC_MN]=1;
	if(x<n)
		k=0;
	for(l=0;l<2;l++)
	{
		int nx = x+xc[l],ny=y+yc[k][l];
		if(valid(nx,ny))
		{
			// cout<<nx<<","<<ny<<","<<score+ar[x][y]<<","<<score-ar[x][y]<<endl;
			fun(nx,ny,score+ar[x][y]);
			fun(nx,ny,score-ar[x][y]);
		}
	}
}
int main()
{
	int i,j;
	cin>>n;
	while(n)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
				cin>>ar[i][j];
		}
		for(;i<(2*n-1);i++)
		{
			for(j=0;j<(2*n-i-1);j++)
			cin>>ar[i][j];
		}
		ans=INT_MX;
		memset(mem,-1,sizeof(mem));
		fun(2*n-2,0,0);
		cout<<ans<<endl;
		cin>>n;
	}
	return 0;
}
