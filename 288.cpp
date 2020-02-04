#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
const int M =120010;
const int INF = 0x3f3f3f3f;
#define ll long long
int n;
char s[N],t[N];
int a[N];
int main()
{
	while(cin>>n)
	{
		while(n--)
		{
			int k;
			scanf("%s%s%d",s,t,&k);
			int l=strlen(s);
			for(int i=0;i<l;i++)
			{
				a[i]=abs(s[i]-t[i]);
			}
			sort(a,a+l);
			int ans=0;
			for(int i=0;i<l-k;i++)
			{
				ans+=a[i];
			}
			if(ans==0)
			{
				for(int i=l-k;i<l;i++)
					ans+=(a[i]==0);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
