#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 80010;
const int INF = 0x3f3f3f3f;
#define ll long long
int n, m;
bool check(int x)
{
    while(x)
    {
        if(x%10==m)return false;
        x/=10;
    }
    return true;
}
int main()
{
    while(cin>>n>>m)
    {
        int cnt=0,x;
        for(x=1;cnt<=n;x++)
        {
            if(check(x))cnt++;
            if(cnt==n)break;
        }
        cout<<x<<endl;
    }
    return 0;
}