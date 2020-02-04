#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
const int M =120010;
const int INF = 0x3f3f3f3f;
#define ll long long
char s[N],t[N];
int main()
{
	while(~scanf("%s",s))
	{
		if(s[0]=='#')break;
		scanf("%s",t);
		int l=strlen(s);
		int ans=0;
		for(int i=0;i<l;i++)
		{
			ans+=((s[i]=='A'&&t[i]!='T')||(s[i]=='C'&&t[i]!='G')||(s[i]=='G'&&t[i]!='C')||(s[i]=='T'&&t[i]!='A'));
		}
		cout<<ans<<endl;
	}
	return 0;
}
