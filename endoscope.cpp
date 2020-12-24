#include<iostream>
using namespace std;
int arr[1000][1000];
int mat[8][4]={{0,0,0,0},
    {1,1,1,1},
    {0,0,1,1},
    {1,1,0,0},
    {0,1,1,0},
    {0,1,0,1},
    {1,0,0,1},
    {1,0,1,0}
    };
int dp[1000][1000];
bool isValid(int i,int j,int n,int m)
{
    if(i<0 || j<0 || i>=n || j>=m || (arr[i][j]==0))
        return false;
    return true;
}
void dfs(int n,int m,int r,int c,int l)
{
    dp[r][c]=1;
    if(l==0)
    {
        return;
    }
    int type = arr[r][c];
    for(int i=0;i<4;i++)
    {
       if(mat[type][i])
       {
           if(i==0)
            {
                if(isValid(r,c-1,n,m))
                {
                    int type = arr[r][c-1];
                    if(mat[type][1] && dp[r][c-1]==0)
                    {
                        dfs(n,m,r,c-1,l-1);
                    }
                }
            }
            if(i==1)
            {
                if(isValid(r,c+1,n,m))
                {
                    int type = arr[r][c+1];
                    if(mat[type][0] && dp[r][c+1]==0)
                    {
                        dfs(n,m,r,c+1,l-1);
                    }
                }
            }
            if(i==2)
            {
                if(isValid(r-1,c,n,m))
                {
                    int type = arr[r-1][c];
                    if(mat[type][3] && dp[r-1][c]==0)
                    {
                        dfs(n,m,r-1,c,l-1);
                    }
                }
            }
            if(i==3)
            {
                if(isValid(r+1,c,n,m))
                {
                    int type = arr[r+1][c];
                    if(mat[type][2] && dp[r+1][c]==0)
                    {
                        dfs(n,m,r+1,c,l-1);
                    }
                }
            }
       }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,r,c,l;
        cin>>n>>m>>r>>c>>l;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                {
                    dp[i][j]=0;
                    cin>>arr[i][j];
                }
        }
        if(arr[r][c]==0)
            cout<<"0\n";
        else
           {
             dfs(n,m,r,c,l-1);
             int count=0;
             for(int i=0;i<n;i++)
             {
                 for(int j=0;j<m;j++)
                 {
                     if(dp[i][j]==1)
                        count++;
                 }
             }
             cout<<count<<endl;
           }
    }
}
