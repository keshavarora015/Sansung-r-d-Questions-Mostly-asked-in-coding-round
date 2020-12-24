//https://www.cnblogs.com/kingshow123/p/practicec1.html
#include<bits/stdc++.h>
using namespace std;
bool isValid(int x,int y,int n,int m,bool visited[][105],int a[][105])
{
    if(x>=0 && x<n && y>=0 && y<m && a[x][y] &&  !visited[x][y])
        return true;
    return false;
}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int bfs(int a[][105],int n,int m,int srcx,int srcy)
{
    bool visited[105][105];
    memset(visited,false,sizeof visited);
    queue<pair<int,int> >Q;
    Q.push({srcx,srcy});
    visited[srcx][srcy]=true;
    int time=0;
    while(!Q.empty())
    {
        time++;
        int len = Q.size();
        for(int i=0;i<len;i++)
        {
            pair<int,int> P = Q.front();
            Q.pop();
            int x=P.first,y=P.second;
            cout<<x<<" "<<y<<"  ";
            for(int k=0;k<4;k++)
            {
                int x1=x+dx[k],y1=y+dy[k];
                if(isValid(x1,y1,n,m,visited,a))
                {
                    visited[x1][y1]=true;
                    Q.push({x1,y1});
                }
            }
        }
        cout<<endl;
    }
    return time;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a[105][105];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin>>a[i][j];
        }
        int srcx,srcy;
        cin>>srcx>>srcy;
        cout<<bfs(a,n,m,srcx,srcy)<<endl;
    }
}
