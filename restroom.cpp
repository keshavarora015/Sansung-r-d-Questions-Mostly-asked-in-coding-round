#include<bits/stdc++.h>
using namespace std;
void restroom(int n)
{
    queue<pair<int ,int > >q;
    vector<pair<int,int> >V;
    q.push({0,n-1});
    q.push({-1,-1});
    while(!q.empty())
    {
        pair<int,int> P =q.front();
        q.pop();
        int low = P.first;
        int high = P.second;
        if(low==-1 && high==-1)
        {
            for(int i=0;i<V.size();i++)
            {
                q.push(V[i]);
            }
            V.clear();
            if(q.size()>0)
            q.push({-1,-1});
        }
        else
        {
            int mid = (low+high)/2;
            cout<<mid+1<<" ";
            if(high>=mid+1)
            q.push({mid+1,high});
            if(low<=(mid-1))
            V.push_back({low,mid-1});
        }
    }
}
int main()
{
    int n;
    cin>>n;
    restroom(n);
}
