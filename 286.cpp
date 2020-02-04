//r=2S÷C
//R=abc/4S
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
const int M =120010;
const int INF = 0x3f3f3f3f;
#define ll long long
double a,b,c,r,R,S,C;
double t,y,u,i,o,p,j,k,l;
double dis(double x,double y,double z)
{
	return sqrt(x*x+y*y+z*z);
}
int main()
{
	while(cin>>t>>y>>u>>i>>o>>p>>j>>k>>l)
	{
		a=dis(t-i,y-o,u-p);
		b=dis(t-j,y-k,u-l);
		c=dis(i-j,o-k,p-l);
		C=a+b+c;
		p=C/2.0;
		S=sqrt(p*(p-a)*(p-c)*(p-b));
		r=2.0*S/C;
		R=a*b*c/(4.0*S);
		//cout<<a<<" "<<b<<" "<<c<<" "<<S<<" "<<r<<" "<<R<<endl;
		printf("%.3f\n",r*r/(R*R));
	}
	return 0;
}
