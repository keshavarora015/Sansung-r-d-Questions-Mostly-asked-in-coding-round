/*
88 81
6
19 22
31 15
27 29 30 10 20 26 5 14
85 80

Sample output : 304
*/

#include<iostream>
using namespace std;
struct point{
    int x,y;
}office,customer[102],home;
bool visited[1001]={false};
int mincost=9999;
int abs(int x)
{
    if(x<0)
        return -1*x;
    return x;
}
int findDistance(point x1,point y1)
{
    return abs(x1.x-y1.x)+abs(y1.y-x1.y);
}
void cost(int count,point parent,int i,int n,int cst)
{
    if(count==n)
    {
        int temp = findDistance(parent,home);
        cst = cst+temp;
        if(cst<mincost)
            mincost=cst;
        return;
    }
    visited[i]=true;
    for(int j=0;j<n;j++)
    {
        if(!visited[j])
        {
            int temp = findDistance(parent,customer[j]);
            cost(count+1,customer[j],j,n,cst+temp);
        }
    }
    visited[i]=false;
}
int main()
{
    cin>>office.x>>office.y;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>customer[i].x>>customer[i].y;
    }
    cin>>home.x>>home.y;
    cost(0,office,n+1,n,0);
    cout<<mincost<<endl;
}
