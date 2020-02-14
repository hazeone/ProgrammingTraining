#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int M =120010;
const int INF = 0x3f3f3f3f;
struct point
{
	int x,y,id;
}a[N];
int n;
vector<int> vec;
bool cmp1(point A,point B)
{
	return A.x<B.x;
}
bool cmp2(point A,point B)
{
	return A.y<B.y;
}
int tmp[N];
int main()
{
	while(cin>>n)
	{
		if(n==0)break;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i].x);
			a[i].id=i;
		}
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[j].y);
		}
		sort(a+1,a+1+n,cmp1);
		vec.clear();
		tmp[1]=a[1].y;
		vec.push_back(a[1].id);
		for(int i=2;i<=n;i++)
		{
			tmp[i]=min(tmp[i-1],a[i].y);
			if(tmp[i-1]>a[i].y)
				vec.push_back(a[i].id);
		}
		sort(a+1,a+1+n,cmp2);
		tmp[1]=a[1].x;
		vec.push_back(a[1].id);
		for(int i=2;i<=n;i++)
		{
			tmp[i] = min(tmp[i-1],a[i].x);
			if(tmp[i-1]>a[i].x)
				vec.push_back(a[i].id);
		}
		sort(vec.begin(),vec.end());
		int ans=0;
		for(int i=1;i<vec.size();i++)
		{
			if(vec[i]==vec[i-1])
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
