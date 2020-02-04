#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N];
int n;
int main()
{
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
		{
			scanf("%d",a+i);
		}
		int p=a[0],v=1;
		for(int i=1;i<n;i++)
		{
			if(v==0)
			{
				p=a[i];
				v++;
				continue;
			}
			if(a[i]==p)
			{
				v++;
			}
			else {
				v--;
			}
		}
		printf("%d\n",p);
	}
	return 0;
}
