//http://www.mamicode.com/info-detail-995985.html

#include<iostream>
using namespace std;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool isValid(int x,int y,int n,bool visited[100][100])
{
    if(x>=0 && x<n && y>=0 && y<n && (!visited[x][y]))
        return true;
    return false;
}
void jewel(int a[100][100],bool visited[100][100],int dp[100][100],int currx,int curry,int destx,int desty,int cost,int &maxcost,int n)
{
    if(currx==destx && curry==desty)
    {
        if(cost>maxcost)
            {
                maxcost=cost;
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        if(visited[i][j])
                            dp[i][j]=3;
                        else
                            dp[i][j]=a[i][j];
                    }
                }
            }
        return;
    }
    for(int k=0;k<4;k++)
    {
        if(isValid(currx+dx[k],curry+dy[k],n,visited))
        {
            int tempx = currx+dx[k],tempy = curry+dy[k];
            visited[tempx][tempy]=true;
            if(a[tempx][tempy]==0)
                jewel(a,visited,dp,tempx,tempy,destx,desty,cost,maxcost,n);
            else if(a[tempx][tempy]==2)
                jewel(a,visited,dp,tempx,tempy,destx,desty,cost+1,maxcost,n);
            visited[tempx][tempy]=false;
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
        cin>>n;
        int a[100][100];
        bool visited[100][100];
        int dp[100][100];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                visited[i][j]=false;
                cin>>a[i][j];
                dp[i][j]=a[i][j];
            }
        }
        int maxcost = 0;
        visited[0][0]=true;
        if(a[0][0]==0)
            jewel(a,visited,dp,0,0,n-1,n-1,0,maxcost,n);
        else if(a[0][0]==2)
            jewel(a,visited,dp,0,0,n-1,n-1,1,maxcost,n);
        visited[0][0]=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        cout<<maxcost<<endl;
    }
}
