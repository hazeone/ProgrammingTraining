#include<bits/stdc++.h>
using namespace std;
int n;
double mn,t;
int a1,a2;
int a,b,c;
#define D double
int main()
{
	while(cin>>n)
	{
		while(n--){
			scanf("%d%d%d",&a,&b,&c);
			t = (D)a/(D)b;
			mn=9999999.9;
			for(int i=1;i<=c;++i)
			{
				int tmp=i*t;
				if(1.0*(t-mn)*i<tmp)
				{
					mn=t-(D)tmp/(D)i;
					a1=tmp;
					a2=i;
				}
				++tmp;
				if(1.0*tmp<1.0*(mn+t)*i)
				{
					mn=(D)tmp/(D)i-t;
					a1=tmp;
					a2=i;
				}
			}
			printf("%d %d\n",a1,a2);
		}
	}
	return 0;
}
