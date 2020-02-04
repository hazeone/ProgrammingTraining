#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
#define ll long long
int n;
ll a[N];
ll gcd(ll x,ll y)
{
	return y==0?x:gcd(y,x%y);
}
int main()
{
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
			scanf("%lld",a+i);
		if(n<2){
			puts("Yes");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(i==2)continue;
			a[2]/=gcd(a[2],a[i]);
		}
		puts(a[2]==1?"Yes":"No");
	}
	return 0;
}
