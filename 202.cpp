#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <stack>
using namespace std;
typedef long long ll;
#define uint unsigned int
const ll inf = (1LL<<60)+233;
const double pi = acos(-1.0);
const int N=2000002;
int n,m;
ll a[N];
int main()
{
    scanf("%d",&n);
    n = n<<1|1;
    for(int i=0;i<n;i++)
        scanf("%lld",a+i);
    sort(a,a+n);
    int x=0;
    ll ans=a[n-1];
    for(int i=0;i<n;i++)
    {
        if(x==0)
        {
            x=1;
            continue;
        }
        if(x==1)
        {
            if(a[i]!=a[i-1])
            {
                ans=a[i-1];
                break;
            }
            else x--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
