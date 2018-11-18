#include<bits/stdc++.h>
using namespace std;
bool prime(int x)
{
    for(int n=2;n<sqrt(x);n++)
    {
        if(x%n==0) return 0;

    }
    return 1;
}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=2;i<n-k;i++)
    {
        if(prime(i)&&prime(i+k))
        {
            cout<<i<<" "<<k+i<<endl;
        }
    }
}