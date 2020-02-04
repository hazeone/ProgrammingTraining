//wa
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
const int M =120010;
const int INF = 0x3f3f3f3f;
#define ll long long
struct Edge
{
	int to,next,cap,flow;
}e[M];
int tot;
int g[N];
void init(){
	tot=1;
	memset(g,-1,sizeof(g));
}
void add(int u,int v,int w,int rw=0)
{
	e[++tot].to=v;e[tot].cap=w;e[tot].flow=0;
	e[tot].next=g[u];g[u]=tot;
	e[++tot].to=u;e[tot].cap=rw;e[tot].flow=0;
	e[tot].next=g[v];g[v]=tot;
}
int Q[N];
int dep[N],cur[N],sta[N];
bool bfs(int s,int t,int n)
{
	int head=0,tail=1;
	for(int i=0;i<=n;i++)
		dep[i]=-1;
	dep[s]=0;
	Q[tail]=s;
	while(head<tail)
	{
		int u=Q[++head];
		for(int i=g[u];i!=-1;i=e[i].next)
		{
			int v=e[i].to;
			if(e[i].cap>e[i].flow&&dep[v]==-1)
			{
				dep[v]=dep[u]+1;
				if(v==t)return true;
				Q[++tail]=v;
			}
		}
	}
	return false;
}
int dinic(int s,int t,int n)
{
	int maxflow = 0;
	while(bfs(s,t,n))
	{
		for(int i = 0;i < n;i++)
			cur[i] = g[i];
		int u = s, tail = 0;
		while(cur[s]!=-1) {
			if(u == t) {
				int tp = INF;
				for(int i = tail-1;i>=0;i--)
					tp = min(tp,e[sta[i]].cap-e[sta[i]].flow);
				maxflow += tp;
				for(int i = tail-1;i >= 0;i--) {
					e[sta[i]].flow += tp;
					e[sta[i]^1].flow -= tp;
					if(e[sta[i]].cap-e[sta[i]].flow == 0)
					tail=i;
				}
				u=e[sta[tail]^1].to;
			}
			else if(cur[u]!=-1 && e[cur[u]].cap>e[cur[u]].flow && dep[u]+1==dep[e[cur[u]].to])
			{
				sta[tail++]=cur[u];
				u=e[cur[u]].to;
			}
			else {
				while(u!=s && cur[u]==-1)
					u=e[sta[--tail]^1].to;
				cur[u]=e[cur[u]].next;
			}
		}
		cout<<"chekc 82"<<endl;
	}
	return maxflow;
}
int nn,ff,dd;
int main()
{
	init();
	cin>>nn>>ff>>dd;
	int s,t,n=(nn+ff+dd+1)*2;
	t=n;s=n-1;
	for(int i=1;i<=ff;i++)
	{
		add(s,i*2-1,1);
		add(i*2-1,i*2,1);
	}
	for(int i=1;i<=nn;i++)
	{
		add(ff*2+i*2-1,ff*2+i*2,1);
	}
	//cout<<nn<<" "<<ff<<" "<<dd<<endl;
	for(int i=1;i<=dd;i++)
	{
		add((nn+ff)*2+i*2,t,1);
		add((nn+ff)*2+i*2-1,(nn+ff)*2+i*2,1);
	}
	for(int i=1;i<=nn;i++)
	{
		int f,d;
		scanf("%d%d",&f,&d);
		for(int j=1;j<=f;j++)
		{
			int x;
			scanf("%d",&x);
			add(x*2,ff*2+j*2-1,1);
		}
		for(int j=1;j<=d;j++)
		{
			int x;
			scanf("%d",&x);
			add(ff*2+j*2,(nn+ff)*2+x*2-1,1);
		}
	}
	cout<<dinic(s,t,n)<<endl;
	return 0;
}
