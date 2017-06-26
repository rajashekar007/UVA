#include <bits/stdc++.h>
using namespace std;
#define ITEMS_IND 1000007
#define COMBO_MX 15
#define INT_MAX 10000000
int price[COMBO_MX],ar[COMBO_MX],nc;
int mem[COMBO_MX][ITEMS_IND];
int fun(int ind,int req)
{
	if(req==0)
		return 0;
	if(ind==nc)
		return INT_MAX;
	int &res = mem[ind][req];
	if(res!=-1)
		return res;
	int tk=INT_MAX,dntk,cp_req=req,cp_ar=ar[ind],dig_rq,dig_ar;
	bool can_be_taken=true;
	while(cp_req)
	{
		dig_rq=cp_req%10;
		dig_ar=cp_ar%10;
		if(dig_ar>dig_rq || cp_req<cp_ar)
		{
			can_be_taken=false;
			break;
		}
		cp_req/=10;
		cp_ar/=10;
	}
	if(can_be_taken)
		tk = fun(ind,req-ar[ind])+price[ind];
	dntk = fun(ind+1,req);
	res = min(tk,dntk);
	return res;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		nc=0;
		int i,num_combo,ind=0,cnt;
		for(i=0;i<n;i++)
		{
			ind = pow(10,n-i-1);
			scanf("%d", &price[nc]);
			ar[nc++]= ind;
		}
		scanf("%d",&num_combo);
		while(num_combo--)
		{
			ind = 0;
			for(i=0;i<n;i++)
			{
				scanf("%d",&cnt);
				ind=ind*10+cnt;
			}
			scanf("%d\n",&price[nc]);
			ar[nc++]=ind;
		}
		scanf("%d",&num_combo);
		memset(mem,-1,sizeof(mem));
		while(num_combo--)
		{
			ind = 0;
			for(i=0;i<n;i++)
			{
				scanf("%d",&cnt);
				ind=ind*10+cnt;
			}
			printf("%d\n", fun(0,ind));
		}
	}
	return 0;
}
