#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 80010;
const int INF = 0x3f3f3f3f;
#define ll long long
int n,m;
struct point
{
    string name;
    int w,q;
}a[2000];
bool cmp(point A,point B)
{
    return A.name<B.name;
}
bool check(int x)
{
    int minw=0,totw=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i].name!=a[i-1].name)
        {
            if(i>1 && minw==INF)
                return false;
            totw+=minw;
            minw=INF;
        }
        if(a[i].q>=x)
            minw=min(minw,a[i].w);
    }
    if (minw == INF) return false;
    totw += minw;
    //cout<<"check: "<<x<<" "<<totw<<endl;
    return totw<=m;
}
int main() {
  int T;
  while (cin >> T) {
        while (T--) {
            cin>>n>>m;
            string fuck;
            for(int i=1;i<=n;i++)
            {
                cin>>a[i].name>>fuck>>a[i].w>>a[i].q;
            }
            sort(a+1,a+1+n,cmp);
            //for(int i=1;i<=n;i++)
            //    cout<<a[i].w<<" "<<a[i].q<<endl;
            int l=0,r=1e9,mid;
            while(l<r)
            {
                mid=(l+r+1)>>1;
                if(!check(mid))r=mid-1;
                else l=mid;
            }
            cout<<l<<endl;
        }
  }
  return 0;
}