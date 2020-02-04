#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
#define ll long long
int n;
ll x[N],y[N];
ll sum;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=x[i]*y[(i+1)%n]-y[i]*x[(i+1)%n];
	}
	if(sum&1)
	printf("%.1f\n",abs(1.0*sum/2.0));
	else printf("%lld\n",abs(sum/2));
	return 0;
}
