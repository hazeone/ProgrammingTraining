//#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
int v[31][31][2];
int sx,sy,Tx,Ty;
struct point
{
    int x,y,b;
};
int a[31][31];
int T,n;
char S[50];
queue<point> Q;
#define pb push
int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
int main()
{
    while(cin>>T)
    {
        while(T--)
        {
            cin>>n;
            for(int i=1;i<=n;i++)
            {
                scanf("%s",S+1);
                for(int j=1;j<=n;j++)
                {
                    if(S[j]=='a')
                    {
                        Tx=i;Ty=j;
                        a[i][j]=0;
                    }
                    if(S[j]=='r')
                    {
                        a[i][j]=0;
                    }
                    if(S[j]=='p')
                    {
                        sx=i;sy=j;
                        a[i][j]=0;
                    }
                    if(S[j]=='d')
                    {
                        a[i][j]=1;
                    }
                    if(S[j]=='k')
                    {
                        a[i][j]=2;
                    }
                }
            }
            memset(v,0,sizeof(v));
            while(!Q.empty())Q.pop();
            v[sx][sy][0]=1;
            Q.pb((point){sx,sy,0});
            while(!Q.empty())
            {
                int nx,ny,b;
                nx=Q.front().x;
                ny=Q.front().y;
                b=Q.front().b;
                Q.pop();
                for(int i=0;i<4;i++)
                {
                    int tx=nx+dx[i],ty=ny+dy[i];
                    if(tx<1||ty<1||tx>n||ty>n)continue;
                    if(a[tx][ty]+b>=2)continue;
                    int tb=b+a[tx][ty];
                    if(v[tx][ty][tb])continue;
                    v[tx][ty][tb]=1;
                    Q.pb((point){tx,ty,tb});
                }
            }
            if(v[Tx][Ty][0]||v[Tx][Ty][1])
            {
                puts("Yes");
            }
            else puts("No");
        }
    }
    return 0;
}
