#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000000];
bool check(int t)
{
	if(!t)return true;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=(int)a[i]/t;
	}
	return sum>=k;
}
int main()
{
	while(cin>>n>>k)
	{
		if(!n&&!k)break;
		for(int i=1;i<=n;i++)
		{
			int x,y;
			scanf("%d.%d",&x,&y);
			a[i]=x*100+y;
		}
		int l=0,r=10000000;
		while(l<r)
		{
			int mid=(l+r+1)/2;
			if(!check(mid))
			{
				r=mid-1;
			}
			else l=mid;
		}
		float ans = l/100.0;
		printf("%.2lf\n",ans);
	}
	return 0;
}
