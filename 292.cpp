#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 10;
const int M = 80010;
const int INF = 0x3f3f3f3f;
#define ll long long
struct point
{
    int to,next;
}e[M];
int g[N],tot;
void init()
{
    tot=0;
    memset(g,0,sizeof(g));
}
void addedge(int x,int y)
{
    e[++tot].to=y;
    e[tot].next=g[x];
    g[x]=tot;
}
int linker[N];
bool used[N];
bool dfs(int x)
{
    for(int tmp=g[x];tmp;tmp=e[tmp].next)
    {
        int y=e[tmp].to;
        if(!used[y])
        {
            used[y]=true;
            if(linker[y]==-1||dfs(linker[y]))
            {
                linker[y]=x;
                return true;
            }
        }
    }
    return false;
}
int n,m,s,v;
int hungary()
{
    int re=0;
    memset(linker,-1,sizeof(linker));
    for(int i=1;i<=n;i++)
    {
        memset(used,false,sizeof(used));
        if(dfs(i))re++;
    }
    return re;
}
int ax[N],ay[N],bx[N],by[N];
bool check(int x,int y)
{
    return 1L*x*x+1L*y*y<1L*s*s*v*v;
}
int main()
{
    while(cin>>n)
    {
        if(!n)break;
        init();
        cin>>m>>s>>v;
        for(int i=1;i<=n;i++)
            scanf("%d%d",ax+i,ay+i);
        for(int i=1;i<=m;i++)
            scanf("%d%d",bx+i,by+i);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(check(ax[i]-bx[j],ay[i]-by[j]))
                {
                    addedge(i,n+j);
                }
            }
        }
        cout<<n-hungary()<<endl;
    }
    return 0;
}
/*
2 2 5 10
1 1
2 2
100 100
20 20

*/