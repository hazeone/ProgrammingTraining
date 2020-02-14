#include <bits/stdc++.h>
using namespace std;
#define ll long long
using namespace std;
const int N = 1e4+4;
int T,n;
int w1,w2;
int a[N];
int main()
{
    while(cin>>T)
    {
        for(int cas=1;cas<=T;cas++)
        {
            cin>>w1>>w2>>n;
            for(int i=1;i<n;i++)
                scanf("%d",a+i);
            int s1=1,s2=0;
            a[0]=-1;
            for(int i=1;i<n;i++)
            {
                if(a[a[i]]==-1)
                {
                    s2++;
                    a[i]=-2;
                }
                else
                {
                    s1++;
                    a[i]=-1;
                }
            }
            printf("Case #%d: ",cas);
            cout<<min(s1*w1+s2*w2,s1*w2+s2*w1)<<endl;
        }
    }
    return 0;
}