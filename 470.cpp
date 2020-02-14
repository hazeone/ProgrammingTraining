#include <bits/stdc++.h>
using namespace std;
#define ll long long
using namespace std;
const int mod=11;
struct Mat
{
    int a[3][3];
}c[20],ans;
ll n,nn;
void init()
{
    ans.a[0][0]=ans.a[1][1]=ans.a[2][2]=1;
    c[1].a[0][0]=10;
    c[1].a[1][0]=c[1].a[2][0]=c[1].a[1][1]=c[1].a[2][1]=c[1].a[2][2]=1;
    for(int i=2;i<20;++i)
    {
        c[i]=c[i-1];
        c[i].a[0][0]*=10;
        c[i].a[0][0]%=mod;
    }
}
Mat muliti(Mat x,Mat y)
{
    Mat ret;
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
        {
            ret.a[i][j]=0;
            for(int k=0;k<3;++k)
            {
                ret.a[i][j]+=(x.a[i][k]*y.a[k][j])%mod;
                ret.a[i][j]%=mod;
            }
        }
    return ret;
}
Mat cal(Mat x,ll k)
{
    Mat ret;
    memset(ret.a,0,sizeof(ret.a));
    ret.a[0][0]=ret.a[1][1]=ret.a[2][2]=1;
    if(k==0) return ret;
    if(k==1) return x;
    if(k%2==0)
    {
        ret=cal(x,k/2);
        return muliti(ret,ret);
    }
    else
    {
        ret=cal(x,k-1);
        return muliti(ret,x);
    }
}
int main()
{
    while(~scanf("%lld",&n))
    {
       memset(ans.a,0,sizeof(ans.a));
       nn=n;
       int len=0;
       while(nn)
       {
         nn/=10;
         len++;
       }
       init();
       ll k=1;
       for(int i=1;i<len;++i)
       {
          ans=muliti(ans,cal(c[i],k*9));
          k*=10;
       }
       ans=muliti(ans,cal(c[len],n-k+1));
       printf("%d\n",ans.a[2][0]);
    }
	return 0;
}