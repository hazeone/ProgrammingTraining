//wrong
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
#define ll long long
int a[N];
char s[N];
int n;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)
	{
		a[n-i]=s[i]-'0';
	}
	int m=(n+1)/2;
	int v=((n&1)==0);
	for(int i=0;i<m;i++)
	{
		if(a[m-i]<a[m+i+v])
		{
			for(int j=m-i;j>=1;j--)
			{
				a[j]=a[2*m+v-j];
			}
			break;
		}
		else if(a[m-i]>a[m+i+v])
		{
			a[m+i+v]=a[m-i];//=a[m+i+v]+1;
			for(int j=m-i-1;j>=1;j--)
			{
				a[j]=a[2*m+v-j];
			}
			for(int j=m-i+1;j<=m;j++)
			{
				a[j]=a[2*m+v-j]=0;
			}
			break;
		}
	}
	for(int i=1;i<=n;i++)
	printf("%d",a[i]);
	puts("");
	return 0;
}
