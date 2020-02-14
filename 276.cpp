//wa
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
const int M =120010;
const int INF = 0x3f3f3f3f;
#define ll long long
int n;
int a[N];
int main()
{
	while(cin>>n)
	{
		if(n==0)break;
		int l=0;
		cout<<n<<"******* ";
		memset(a,0,sizeof(a));
		while(n)
		{
			if(n&(1<<l))
			{
				a[l]=1;
				n-=(n&(1<<l));
			}
			cout<<a[l];
			if(n) l++;
		}
		cout<<endl;
		int ans=l;
		int tmp=0;
		a[l+1]=0;
		for(int i=0;i<=l+1;i++)
		{
			if(a[i]==1)
			{
				tmp++;
			}
			else
			{
				if(tmp&&l)
				{
					ans++;
					if(i==l+1&&tmp==1)
					ans--;
					if(tmp>=2)
						ans++;
					tmp=0;
				}
			}
		}
		for(int i=2;i<=l-2;i++)
		{
			if(a[i]==0&&a[i-1]==a[i-2]&&a[i+1]==a[i+2]&&a[i-1]&&a[i+1])
				ans--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
