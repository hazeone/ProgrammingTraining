#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 5;
const int INF = 0x3f3f3f3f;
#define ll long long
#define SIZE 102
int mat[SIZE][SIZE];  /*图矩阵*/
int dp[SIZE];
int mx,n;
int stk[SIZE][SIZE];
void dfs(int num,int step){
 
    if(num==0){
        if(step > mx){
            mx=step;
        }
        return ;
    }
 
    for(int i=0;i<num;i++){
        int k = stk[step][i];
        if(step+N-k<=mx) return ;
        if(step+dp[k]<=mx) return ;
        int cnt = 0;
        for(int j=i+1;j<num;j++)
            if(mat[k][stk[step][j]]){
                 stk[step+1][cnt++]=stk[step][j];
            }
        dfs(cnt,step+1);
    }
}
void run(){
    mx =0;
    for(int i=n-1;i>=0;i--){
        int sz =0;
        for(int j=i+1;j<n;j++)
            if(mat[i][j]) stk[1][sz++]=j;
        dfs(sz,1);
        dp[i]=mx;
    }
}
char s[SIZE];
int main()
{
    int T;
    while(cin>>T)
    {
        while(T--)
        {
            cin>>n;
            for(int i=0;i<n;i++)
            {
                scanf("%s",s);
                for(int j=0;j<n;j++)
                mat[i][j]=s[j]-'0';
            }
            run();
            cout<<dp[0]<<endl;
        }
    }
    return 0;
}
