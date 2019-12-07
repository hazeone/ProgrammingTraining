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
using namespace std;
typedef long long ll;
#define uint unsigned int
const int N = 3e5+10;
const int M = 31;
int T,n;
int f[N];
struct point{
    int l,r;
}a[N];
bool cmp(point A, point B)
{
    return A.r<B.r;
}
int main() {
    while(cin>>n){
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i].l,&a[i].r);
        }
        memset(f,0,sizeof(f));
        sort(a+1,a+1+n,cmp);
        int l=0;
        for(int i=1;i<=n;i++)
        {
            if(l!=a[i].r)
            {
                for(int j=l+1;j<=a[i].r;j++)
                {
                    f[j]=max(f[j],f[j-1]);
                }
                l = a[i].r;
            }
            f[a[i].r]=max(f[a[i].r],f[a[i].l-1]+a[i].r-a[i].l+1);
        }
        cout<<f[l]<<endl;
    }
    return 0;
}
