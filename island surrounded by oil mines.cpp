#include<bits/stdc++.h>
using namespace std;
int ans=9999;
void findMinDiff(int company[],int n)
{
    int mini = 9999;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        mini = min(mini,company[i]);
        maxi = max(maxi,company[i]);
    }
    if(ans>(maxi-mini))
        ans = maxi-mini;
}
void findAns(int end,int curr,int oil[],int company[],int m,int n,int num)
{
    if((curr+1)%m==end)
    {
        for(int j = num;j<n;j++)
        {
            company[j]+=oil[curr];
            findMinDiff(company,n);
            company[j]-=oil[curr];
        }
        return;
    }
    if(num==n)
        return;
    company[num]+=oil[curr];
    findAns(end,(curr+1)%m,oil,company,m,n,num);
    company[num]-=oil[curr];
    findAns(end,curr,oil,company,m,n,num+1);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ans=9999;
        int n,m;
        cin>>n>>m;
        int oil[m];
        for(int i=0;i<m;i++)
            cin>>oil[i];
        int company[n];
        for(int i=0;i<n;i++)
        {
            company[i]=0;
        }
        for(int i=0;i<m;i++)
        {
            findAns(i,i,oil,company,m,n,0);
        }
        cout<<ans<<endl;
    }
}
