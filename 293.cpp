#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 10;
const int M = 80010;
const int INF = 0x3f3f3f3f;
#define ll long long
int a[N][N];
int x,n;
void dfs(int p,int q,int c, int l)
{
    if(p<0)return;
    a[p][q]=c;
    p++;
    q++;
    if(p>10)
    {
        dfs(10-l,1,++c,l+1);
    }
    else
    {
        dfs(p,q,++c,l);
    }
    
}
int main()
{
    dfs(10,1,0,1);
    while(cin>>x>>n)
    {
        if(!x&&!n)break;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                int out=a[10-n+i][j]+x;
                printf("%2d ",out);
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}