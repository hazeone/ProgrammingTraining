//wa
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 80010;
const int INF = 0x3f3f3f3f;
#define ll long long
int n, m;
double ax[301],ay[301];
double cha(double x,double y, double X,double Y)
{
    return x*Y-X*y;
}
bool check(int i,int j,int k)
{
    return cha(ax[j]-ax[i],ay[j]-ay[i],ax[k]-ax[i],ay[k]-ay[i])<0.000000001;
}
int main()
{
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
            scanf("%lf%lf",ax+i,ay+i);
        int tot=n>1?2:n,mx=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++){
                mx=2;
                for(int k=j+1;k<=n;k++)
                {
                    if(check(i,j,k))mx++;
                }
                tot=max(mx,tot);
            }
        cout<<tot<<endl;
    }
    return 0;
}