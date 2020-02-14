#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 120010;
const int INF = 0x3f3f3f3f;
#define ll long long
char s[N];
int cnt[200];
int dp[N];
int main()
{
    while(~scanf("%s",s+1))
    {
        if(s[1]=='#')break;
        memset(cnt,0,sizeof(cnt));
        int l=strlen(s+1);
        int sum=0,mx=0,k;
        for(int i=1;i<=l;i++)
        {
            //cnt[s[i]]=1;
            for(int j=i+sum;j<=l;j++)
            {
                if(cnt[s[j]]==1)
                {
                    break;
                }
                else
                {
                    cnt[s[j]]=1;
                    sum++;
                }
            }
            dp[i]=sum;
            if(sum>mx)
            {
                mx=sum;
                k=i;
            }
            cnt[s[i]]=0;
            sum--;
        }
        printf("%d ",mx);
        for(int j=0;j<mx;j++)
        {
            printf("%c",s[k+j]);
        }puts("");
    }
    return 0;
}