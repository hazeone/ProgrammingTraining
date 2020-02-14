#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
const int M = 80010;
const int INF = 0x3f3f3f3f;
#define ll long long
int n, m;
int mp[N];
int main()
{
    int cas=0;
    while(cin>>n)
    {
        cas++;
        if(n==-1)break;
        mp[0]=cas;
        int x=0;
        for(int i=1;i<=n;i++)
        {
            if(x-i>0&&mp[x-i]!=cas)
                x-=i;
            else x+=i;
            mp[x]=cas;
            //cout<<i<<" "<<cas<<" "<<x<<endl;
        }
        cout<<x<<endl;
    }
    return 0;
}