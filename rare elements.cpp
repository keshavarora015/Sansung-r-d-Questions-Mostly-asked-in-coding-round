/*
5
0 1 1 0 1
1 0 0 1 0
0 0 1 1 1
1 1 0 1 1
1 1 1 1 1
3
2 2
3 3
4 0
pos 4 4
ans 4
*/

#include<iostream>
#include<queue>
using namespace std;
struct point{
int x,y;
};
void memset(int ans[][25],int n,int k)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            ans[i][j]=k;
    }
}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool isSafe(int x,int y,int n,int a[][25],bool visited[][25])
{
    if(x>=0 && x<n && y>=0 && y<n && a[x][y] && (!visited[x][y]))
        return true;
    return false;
}
void bfs(int ans[][25],int a[][25],int n,int x,int y)
{
    queue<point > q;
    q.push({x,y});
    bool visited[25][25]={false};
    visited[x][y]=true;
    ans[x][y]=0;
    while(!q.empty())
    {
        point p = q.front();
        q.pop();
        for(int k=0;k<4;k++)
        {
            int x1,y1;
            x1 = p.x+dx[k],y1=p.y+dy[k];
            if(isSafe(x1,y1,n,a,visited))
            {
                visited[x1][y1]=true;
                ans[x1][y1]=ans[p.x][p.y]+1;
                q.push({x1,y1});
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int a[25][25];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    int q;
    cin>>q;
    point rare[6];
    for(int i=0;i<q;i++)
    {
        int x,y;
        cin>>rare[i].x>>rare[i].y;
    }
    int qans=9999,ansx,ansy;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j])
            {
                int ans[25][25];
                memset(ans,n,9999);
                int mx=-1;
                bfs(ans,a,n,i,j);
                int flag=0;
                for(int k=0;k<q;k++)
                {
                    if(ans[rare[k].x][rare[k].y]==9999)
                    {
                        flag=1;
                        break;
                    }
                }
                if(!flag)
                {
                    for(int k=0;k<q;k++)
                    {
                        //cout<<ans[rare[k].x][rare[k].y]<<" ";
                        mx = max(mx,ans[rare[k].x][rare[k].y]);
                    }
                    if(qans>mx)
                    {
                        qans=mx;
                        ansx=i;
                        ansy=j;
                    }
                }
            }
        }
    }
    cout<<qans<<endl;
    cout<<ansx<<" "<<ansy<<endl;
}
