#include<iostream>
using namespace std;
long long int mini = 1000000;
struct wormhole
{
    int x1,y1,x2,y2,cost;
};
bool visited[10000]={false};
int abs(int x,int y)
{
    if(x>y)
        return x-y;
    return y-x;
}
int distance(int x1,int y1,int x2,int y2)
{
    int num = abs(x1,x2)+abs(y1,y2);
    return num;
}
void dfs(wormhole arr[],int x1,int y1, int x2, int y2,int cost,int n)
{
    int ans = cost + distance(x1,y1,x2,y2);
    if(ans<mini)
        mini = ans;
    for(int i=0;i<n;i++)
    {
        if(visited[i])
            continue;
        visited[i]=true;
        int cost1 = distance(x1,y1,arr[i].x1,arr[i].y1)+cost+arr[i].cost;
        dfs(arr,arr[i].x2,arr[i].y2,x2,y2,cost1,n);
        int cost2 = distance(x1,y1,arr[i].x2,arr[i].y2)+cost+arr[i].cost;
        dfs(arr,arr[i].x1,arr[i].y1,x2,y2,cost2,n);
        visited[i]=false;
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    wormhole arr[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        cin>>arr[i].x1>>arr[i].y1>>arr[i].x2>>arr[i].y2>>arr[i].cost;
    }
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    dfs(arr,x1,y1,x2,y2,0,n);
    cout<<mini<<endl;
}
