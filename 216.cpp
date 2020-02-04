#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
#define ll long long
int n;
ll a[]={2,3,5,7};
ll b[]={1,3,5,7,9};
bool check(ll x)
{
	ll m = sqrt(x);
	for(int i=2;i<=m;i++)
	{
		if(x%i==0)return false;
	}
	return true;
}
void dfs(ll x,int d)
{
	if(d==n)
	{
		if(check(x))
		printf("%lld\n",x);
		return;
	}
	if(!check(x))return;
	for(int i=0;i<5;i++)
	{
		dfs(x*10+b[i],d+1);
	}
}
int main()
{
	while(cin>>n)
	{
		for(int i=0;i<4;i++)
		{
			dfs(a[i],1);
		}
	}
	return 0;
}

