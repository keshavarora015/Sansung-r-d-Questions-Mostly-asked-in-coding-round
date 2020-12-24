#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
int arr[101][101];
bool issafe(int i,int j,int n,int m)
{
    if(i<0 || j<0 || i>=n || j>=m)
        return false;
    return true;
}
void dfs(int x,int y,int n,int m,int cost)
{
    if(dp[x][y]>cost)
    {
        dp[x][y] = cost;
        if(issafe(x+1,y,n,m) && arr[x+1][y]==1)
            dfs(x+1,y,n,m,cost+1);
        if(issafe(x-1,y,n,m) && arr[x-1][y]==1)
            dfs(x-1,y,n,m,cost+1);
        if(issafe(x,y+1,n,m) && arr[x][y+1]==1)
            dfs(x,y+1,n,m,cost);
        if(issafe(x,y-1,n,m) && arr[x][y-1]==1)
            dfs(x,y-1,n,m,cost);
    }
}
int main()
{
    int n,m,homeX,homeY,desX,desY;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j] = INT_MAX;
            cin>>arr[i][j];
        }
    }
    cin>>homeX>>homeY;
    cin>>desX>>desY;
    dfs(homeX,homeY,n,m,0);
    cout<<dp[desX][desY]<<endl;
	return 0;
}
