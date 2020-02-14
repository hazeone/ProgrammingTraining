#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int M =120010;
const int INF = 0x3f3f3f3f;
#define ll long long
struct point
{
	int to,next;
	ll w;
}e[2020];
int g[1010];
int n,tot;
void add(int x,int y,ll z)
{
	e[++tot].to=y;
	e[tot].next=g[x];
	e[tot].w=z;
	g[x]=tot;
}
ll dfs(int x,int pre,ll dis)
{
	ll re=dis;
	for(int tmp=g[x];tmp;tmp=e[tmp].next)
	{
		int y=e[tmp].to;
		if(y==pre)continue;
		re=max(re,dfs(y,x,dis+e[tmp].w));
	}
	//cout<<x<<" "<<re<<endl;
	return re;
}
int main()
{
	while(cin>>n) {
		memset(g,0,sizeof(g));
		tot=0;
		ll ans = 100000000000000000L;
		for(int i=1;i<n;i++)
		{
			int x,y;
			ll z;
			scanf("%d%d%lld",&x,&y,&z);
			add(x,y,z);
			add(y,x,z);
		}
		for(int i=1;i<=n;i++)
		{
			ans=min(ans,dfs(i,i,0));
		}
		cout<<ans<<endl;
	}
	return 0;
}
