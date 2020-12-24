#include <bits/stdc++.h>
using namespace std;
int bfs(int **arr,bool **visited,int row,int col,int rareElements,int n,int m)
{
    queue<pair<pair<int,int>,int> > q;
    q.push({{row,col},0});
    int maxdis = 0;
    int elecount = 0;
    while(!q.empty())
    {
        pair<pair<int,int>,int> p = q.front();
        q.pop();
        int row = p.first.first;
        int col = p.first.second;
        int dis = p.second;
        if(arr[row][col]==2)
        {
            elecount++;
            maxdis = max(dis,maxdis);
        }
        if((row+1)<n && visited[row+1][col]==false && arr[row+1][col]!=0)
        {
            visited[row+1][col] = true;
            q.push({{row+1,col},dis+1});
        }
        if((col+1)<m && visited[row][col+1]==false && arr[row][col+1]!=0)
        {
            visited[row][col+1] = true;
            q.push({{row,col+1},dis+1});
        }
        if((row-1)>=0 && visited[row-1][col]==false && arr[row-1][col]!=0)
        {
            visited[row-1][col] = true;
            q.push({{row-1,col},dis+1});
        }
        if((col-1)>=0 && visited[row][col-1]==false && arr[row][col-1]!=0)
        {
            visited[row][col-1] = true;
            q.push({{row,col-1},dis+1});
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            visited[i][j] = false;
    if(elecount==rareElements)
        return maxdis;
    else
        return INT_MAX;
}
int main()
{
    int n,m,q,x,y;
    cin>>n>>m;
    int **arr = new int *[n];
    bool **visited = new bool *[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = new int [m];
        visited[i] = new bool [m];
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            visited[i][j] = false;
        }
    }
    cin>>q;
    int answer = INT_MAX;
    for(int i=0;i<q;i++)
    {
        cin>>x>>y;
        arr[x][y] = 2;
    }
    int locationX,locationY;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]!=0)
            {
                int ans = bfs(arr,visited,i,j,q,n,m);
                if(ans<answer){
                    answer = ans;
                    locationX = i;
                    locationY = j;
                }
            }
        }
    }
    cout<<answer<<" "<<locationX<<" "<<locationY<<endl;
	return 0;
}
