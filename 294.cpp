#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 10;
const int M = 80010;
const int INF = 0x3f3f3f3f;
#define ll long long
ll a[50];
ll f,h,n;
int main()
{
    f=0;
    h=1;
    a[0]=1;
    for(int i=1;i<=30;i++)
    {
        ll tmp=h;
        h=f*2;
        f+=tmp;
        a[i]=f+h;
    }
    int T;
    while(cin>>T)
    {
        while(T--)
        {
            cin>>n;
            cout<<a[n*2]<<endl;
        }
    }
    return 0;
}