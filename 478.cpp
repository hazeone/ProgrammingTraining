#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 80010;
const int INF = 0x3f3f3f3f;
#define ll long long
int n, m;

int vcube[10][10],vrow[10][10],vline[10][10];
int a[10][10];
inline int tran(int i,int j)
{
    return 3*((i-1)/3)+(j-1)/3+1;
}
void dfs(int x,int y)
{
    if(x>9)
    {
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            {
                if(j>1)printf(" ");
                printf("%d",a[i][j]);
            }
            puts("");
        }
        return;
    }
    int nx=x,ny=y+1;
    if(ny>9)
    {
        ny=1;
        nx=x+1;
    }
    if(a[x][y])
    {
        dfs(nx,ny);
    }
    else
    {
        for(int i=1;i<=9;i++)
        {
            if(!vline[y][i]&&!vrow[x][i]&&!vcube[tran(x,y)][i])
            {
                vline[y][i]=1;vrow[x][i]=1;vcube[tran(x,y)][i]=1;
                a[x][y]=i;
                dfs(nx,ny);
                a[x][y]=0;
                vline[y][i]=0;vrow[x][i]=0;vcube[tran(x,y)][i]=0;
            }
        }
    }
}
int main()
{
    for(int i=1;i<=9;i++)
    for(int j=1;j<=9;j++)
    {
        cin>>a[i][j];
        vrow[i][a[i][j]]=1;
        vline[j][a[i][j]]=1;
        vcube[tran(i,j)][a[i][j]]=1;
    }
    dfs(1,1);
    return 0;
}