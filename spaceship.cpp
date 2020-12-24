#include<iostream>
using namespace std;
int a[100][5],maxcoin=0;
void spaceship(int row,int col,int n,int coin,int step,int flag)
{
    if(coin>maxcoin)
            maxcoin=coin;
    if(row==-1)
    {
        return;
    }
    if(step>0)
    step--;
    if(a[row-1][col]==1)
    spaceship(row-1,col,n,coin+1,step,flag);
    else if(a[row-1][col]==0)
        spaceship(row-1,col,n,coin,step,flag);
    else
    {
        if(step>0)
           spaceship(row-1,col,n,coin,step,flag);
    }
    if(col-1>=0)
    {
       if(a[row-1][col-1]==1)
        spaceship(row-1,col-1,n,coin+1,step,flag);
        else if(a[row-1][col-1]==0)
            spaceship(row-1,col-1,n,coin,step,flag);
        else
        {
            if(step>0)
               spaceship(row-1,col-1,n,coin,step,flag);
        }
    }
    if(col+1<5)
    {
       if(a[row-1][col+1]==1)
        spaceship(row-1,col+1,n,coin+1,step,flag);
        else if(a[row-1][col+1]==0)
            spaceship(row-1,col+1,n,coin,step,flag);
        else
        {
            if(step>0)
               spaceship(row-1,col+1,n,coin,step,flag);
        }
    }
    if(flag==0)
    {
        spaceship(row,col,n,coin,6,1);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
            cin>>a[i][j];
    }
    spaceship(n,2,n,0,0,0);
    cout<<maxcoin<<endl;
}
