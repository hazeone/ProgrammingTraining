#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 10;
const int M = 80010;
const int INF = 0x3f3f3f3f;
#define ll long long
int a[200];
int f[N][N];
int dp[N][N];
int n;
int dfs(int l,int r)
{
    if(dp[l][r]!=-1)return dp[l][r];
    if(l==r)
    {
        dp[l][r]=0;
    }
    else
    {
        dp[l][r]=INF;
        for(int i=l;i<r;i++)
        {
            dp[l][r]=min(dfs(l,i)+dfs(i+1,r)+f[l][r],dp[l][r]);
        }
    }
    return dp[l][r];
}
int main()
{
    while(~scanf("%d",&n)&&n)
    {
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        memset(f,0,sizeof(f));
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                for(int k=i;k<=j;k++)
                    f[i][j]+=a[k];
            }
        }
        cout<<dfs(0,n-1)<<endl;
    }
    return 0;
}