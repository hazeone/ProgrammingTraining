#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 5;
const int INF = 0x3f3f3f3f;
#define ll long long
int n, m;
char s[500],t[500];
char check(char x)
{
    if(x>='a'&&x<='z')
        x=x-'a'+'A';
    return x;
}
char check2(char x)
{
    if(x>='A'&&x<='Z')
        x=x-'A'+'a';
    return x;
}
int main()
{
    while(cin>>n)
    {
        while(n--)
        {
            scanf("%s%s",s,t);
            m=strlen(s);
            s[0]=check(s[0]);
            for(int i=1;i<m;i++)
            s[i]=check2(s[i]);
            m=strlen(t);
            t[0]=check(t[0]);
            for(int i=1;i<m;i++)
            t[i]=check2(t[i]);
            printf("%s %s\n",t,s);
        }
    }
    return 0;
}