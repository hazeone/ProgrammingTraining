#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 80010;
const int INF = 0x3f3f3f3f;
#define ll long long
int n, m;
ll a[1000];
int main()
{
    ll k;
    while(cin>>k)
    {
        if(k==0)break;
        memset(a,0,sizeof(a));
        ll s = 1,ok=0;
        for(int i=1;;i++)
        {
            s*=k;
            if(s>=1000)ok=1;
            if(ok)
            {
                s%=1000;
                if(a[s])
                {
                    printf("%lld\n",a[s]+i);
                    break;
                }
                else a[s]=i;
            }
        }
    }
    return 0;
}