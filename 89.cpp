#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 80010;
const int INF = 0x3f3f3f3f;
#define ll long long
const ll inf = 1e18L;
int n, m;
ll a[301][301];
int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
struct point
{
    point(int _x,int _y)
    {
        x=_x;y=_y;
    }
    int x,y;
};
queue<point> Q;
ll dis[301][301];
bool v[301][301];
int main()
{
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                scanf("%lld",&a[i][j]);
                dis[i][j]=inf;
                v[i][j]=0;
            }
        v[1][1]=1;
        dis[1][1]=a[1][1];
        Q.push(point(1,1));
        while(!Q.empty())
        {
            int x=Q.front().x,y=Q.front().y;
            Q.pop();
            v[x][y]=0;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i],ny=y+dy[i];
                if(nx<1||ny<1||nx>n||ny>m)continue;
                if(dis[x][y]+a[nx][ny]<dis[nx][ny])
                {
                    dis[nx][ny]=dis[x][y]+a[nx][ny];
                    if(!v[nx][ny])
                    {
                        v[nx][ny]=1;
                        Q.push(point(nx,ny));
                    }
                }
            }
            
        }
        cout<<dis[n][m]<<endl;
    }
    return 0;
}