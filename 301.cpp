#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 80010;
const int INF = 0x3f3f3f3f;
#define ll long long
int n;
ll a[N];
ll s;
bool check(int l)
{
    int mx=0,sum=0;
    for(int i=1;i<=l;i++)
    {
        sum+=a[i];
    }
    mx=sum;
    for(int i=l+1;i<=n;i++)
    {
        sum-=a[i-l]-a[i];
        mx=max(sum,mx);
    }
    return mx>=s;
}
int main()
{
    int T;
    while(cin>>T)
    {
        while(T--){
            cin>>n>>s;
            for(int i=1;i<=n;i++)
                scanf("%lld",a+i);
            int l=1,r=n;
            while(l<r)
            {
                int mid=(l+r)>>1;
                if(!check(mid))l=mid+1;
                else r=mid;
            }
            if(!check(l))puts("0");
            else printf("%d\n",l);
        }
    }
    return 0;
}