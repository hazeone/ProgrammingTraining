//wrong
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
#define ll long long
int n;
int a[N];
bool check(int x)
{
	int l=0,r=n-1;
	while(l<r)
	{
		int d=x-a[r];
		r--;
		while(d)
		{
			d-=a[l];
			l++;
			if(d<0)return false;
		}
	}
	return true;
}
int main()
{
	while(~scanf("%d",&n)&&n!=0)
	{
		int mx=0,sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",a+i);
			mx=max(a[i],mx);
			sum+=a[i];
		}
		sort(a,a+n);
		for(;;mx++)
		{
			if(sum%mx)continue;
			if(check(mx))
			{
				printf("%d\n",mx);
				break;
			}
		}
	}
	return 0;
}
