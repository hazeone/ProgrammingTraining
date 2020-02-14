//wa
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int M = 80010;
const int INF = 0x3f3f3f3f;
#define ll long long
int n, m;
ll c[N];
struct point
{
    int x,id;
}a[N];
bool cmp(point A,point B)
{
    return A.x<B.x;
}
inline int lowbit(int x)
{
    return x&-x;
}
ll getsum(int x)
{
    ll re=0;
    for(int i=x;i;i-=lowbit(i))
        re+=c[i];
    return re;
}
void add(int x)
{
    for(int i=x;i<=n;i+=lowbit(i))
        c[i]++;
}
int main()
{
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].x);
            a[i].id=i;
            c[i]=0;
        }
        c[0]=0;
        sort(a+1,a+1+n,cmp);
        ll ans=0;
        for(int i=n;i>=1;i--)
        {
            ans+=getsum(a[i].id-1);
            add(a[i].id);
        }
        cout<<ans<<endl;
    }
    return 0;
}