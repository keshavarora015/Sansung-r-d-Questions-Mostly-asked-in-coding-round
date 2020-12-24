#include<iostream>
using namespace std;
int arr[12][12];
bool visited[12][12];
int dp[12][12];
int maxi = 0;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool isValid(int i,int j,int n)
{
    if(i<0 || j<0 || i>=n || j>=n)
        return false;
    return true;

}
void dfs(int i,int j,int cost,int n)
{
    if(i==n-1 && j==n-1)
    {
        if(cost>maxi)
        {
            maxi=cost;
            for(int x=0;x<n;x++)
            {
                for(int y=0;y<n;y++)
                {
                    if(visited[x][y])
                        dp[x][y]=3;
                    else if(arr[x][y]==1)
                        dp[x][y]=1;
                    else
                        dp[x][y]=0;
                }
            }
        }
        return;
    }
    for(int k=0;k<4;k++)
    {
        if(isValid(i+dx[k],j+dy[k],n))
        {
            if(visited[i+dx[k]][j+dy[k]] || arr[i+dx[k]][j+dy[k]]==1)
                continue;
            visited[i+dx[k]][j+dy[k]]=true;
            if(arr[i+dx[k]][j+dy[k]]==2)
                dfs(i+dx[k],j+dy[k],cost+1,n);
            if(arr[i+dx[k]][j+dy[k]]==0)
                dfs(i+dx[k],j+dy[k],cost,n);
            visited[i+dx[k]][j+dy[k]]=false;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        maxi=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                visited[i][j]=false;
                cin>>arr[i][j];
            }
        }
        visited[0][0]=true;
        dfs(0,0,0,n);
        cout<<maxi<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
    }
}
