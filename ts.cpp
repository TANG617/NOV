#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,C[10000000],max=0,maxn=0;  
    cin>>n; 
    for(int i=1;i<n;i++)
    {
        cin>>C[i]; 
        if(C[i]>C[i-1]) max++; 
        else if(max>maxn)
        {
        maxn=max; 
        max=0;
        }
             else max=0; 
    }
    cout<<maxn+1; 
        return 0; 
}