#include<iostream>
using namespace std;
int strlen(char str[])
{
    int k=0;
    while(str[k])
        k++;
    return k;
}
int main()
{
    char str[1001];
    cin>>str;
    int n = strlen(str);
    int k,sum=0,open=0,close=0;
    cin>>k;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')
            open++;
        else if(str[i]==')')
            close++;
        else
        {
            int diff = open-close;
            if(diff==k+1)
                sum+=str[i]-'0';
        }
    }
    cout<<sum<<endl;
}
