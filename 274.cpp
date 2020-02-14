#include<bits/stdc++.h>
using namespace std;
const int N = 1121;
const int M =120010;
const int INF = 0x3f3f3f3f;
#define ll long long
ll f[1121][188][15];
bool v[1121][188][15];
int isprime[M],prime[M],cnt=0;
void init()//这段求出了N内的所有素数
{
    isprime[1]=1;
    for(int i=2;i<N;i++)
    {
        if(!isprime[i])
            prime[++cnt]=i;
        for(int j=1;j<=cnt && i*prime[j]<N;j++)
        {
            isprime[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
struct point
{
	point(int _x,int _k, int _las)
	{
		x=_x;
		k=_k;
		las=_las;
	}
	int x,k,las;
};
queue<point> Q;
int main()
{
	init();
	Q.push(point(0,0,0));
	v[0][0][0]=1;
	f[0][0][0]=1;
	while(!Q.empty())
	{
		int x=Q.front().x,k=Q.front().k,las=Q.front().las;
		Q.pop();
		if(k==14)continue;
		for(int i=las+1;x+prime[i]<=1120&&i<=cnt;i++)
		{
			f[prime[i]+x][i][k+1]+=f[x][las][k];
			if(v[prime[i]+x][i][k+1]==0)
			{
				v[prime[i]+x][i][k+1]=1;
				Q.push(point(prime[i]+x,k+1,i));
			}
		}
	}
	int p,q;
	while(cin>>p>>q)
	{
		if(p&&q)
		{
			ll ans=0;
			for(int i=1;i<188;i++)
				ans+=f[p][i][q];
			printf("%lld\n",ans);
		}
		else break;
	}
	return 0;
}
