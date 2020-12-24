#include<bits/stdc++.h>
using namespace std;
//go for a little simpler aproach in batra code
int dp[105][105];
void dfs(int a[][105],int n,int m,int srcx,int srcy,int destx,int desty)
{
    if(srcx==destx && srcy==desty)
        return;
    if((srcx+1)<n && a[srcx+1][srcy] && dp[srcx+1][srcy]>1+dp[srcx][srcy])
    {
        dp[srcx+1][srcy] = 1+dp[srcx][srcy];
        dfs(a,n,m,srcx+1,srcy,destx,desty);
    }
    if((srcx-1)>=0 && a[srcx-1][srcy] && dp[srcx-1][srcy]>1+dp[srcx][srcy])
    {
        dp[srcx-1][srcy] = 1+dp[srcx][srcy];
        dfs(a,n,m,srcx-1,srcy,destx,desty);
    }
    if((srcy-1)>=0 && a[srcx][srcy-1] && dp[srcx][srcy-1]>(dp[srcx][srcy]))
    {
        dp[srcx][srcy-1] = dp[srcx][srcy];
        dfs(a,n,m,srcx,srcy-1,destx,desty);
    }
    if((srcy+1)<m && a[srcx][srcy+1] && dp[srcx][srcy+1]>(dp[srcx][srcy]))
    {
        dp[srcx][srcy+1] = dp[srcx][srcy];
        dfs(a,n,m,srcx,srcy+1,destx,desty);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a[105][105];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            dp[i][j]=9999;
        }
    }
    int srcx,srcy,destx,desty;
    cin>>srcx>>srcy>>destx>>desty;
    dp[srcx][srcy]=0;
    dfs(a,n,m,srcx,srcy,destx,desty);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<dp[destx][desty]<<endl;
}
