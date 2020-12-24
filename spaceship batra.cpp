#include <bits/stdc++.h>
using namespace std;
int maxcost = 0;
int arr[1000][5];
void dfs(int i,int j,int bomb,int cost,int step)
{
    if(cost>maxcost)
        maxcost=cost;
    if(i==-1)
        return;
    if(step>0)
        step--;
    if(arr[i-1][j]==1)
        dfs(i-1,j,bomb,cost+1,step);
    else if(arr[i-1][j]==0)
        dfs(i-1,j,bomb,cost,step);
    else if(step>0)
        dfs(i-1,j,bomb,cost,step);
    if((j-1)>=0)
    {
        if(arr[i-1][j-1]==1)
            dfs(i-1,j-1,bomb,cost+1,step);
        else if(arr[i-1][j-1]==0)
            dfs(i-1,j-1,bomb,cost,step);
        else if(step>0)
            dfs(i-1,j-1,bomb,cost,step);
    }
    if((j+1)<5)
    {
        if(arr[i-1][j+1]==1)
            dfs(i-1,j+1,bomb,cost+1,step);
        else if(arr[i-1][j+1]==0)
            dfs(i-1,j+1,bomb,cost,step);
        else if(step>0)
            dfs(i-1,j+1,bomb,cost,step);
    }
    if(bomb==1)
    {
        dfs(i,j,0,cost,6);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>arr[i][j];
        }
    }
    dfs(n,2,1,0,0);
    cout<<maxcost;
}
