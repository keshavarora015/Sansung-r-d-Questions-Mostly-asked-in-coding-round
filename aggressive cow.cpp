#include <bits/stdc++.h>
using namespace std;
bool isPossible(long long a[],long long x,int k,int n)
{
	long long lastPos = a[0],count=1;
	for(int i=1;i<n;i++)
	{
		if((a[i]-lastPos)>=x)
		{
			count++;
			lastPos = a[i];
		}
		if(count>=k)
		return 1;
	}
	return 0;
}
long long agcow(long long a[],long long start,long long end,int k,int n)
{
	while(start<=end)
	{
		long long mid = start + (end-start)/2;
		if(isPossible(a,mid,k,n))
		start = mid+1;
		else
		end = mid-1;
	}
	return start-1;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		long long a[n+1];
		for(int i=0;i<n;i++)
		cin>>a[i];
		sort(a,a+n);
		cout<<agcow(a,0,a[n-1]-a[0]+1,k,n)<<endl;
	}
	return 0;
}
