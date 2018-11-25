#include<bits/stdc++.h>
using namespace std;
map<int,int> p;
int main()
{
    for(int i=0;i<10;i++)
    {
        int x;
        cin >> x;
        if(p.find(13-x) != p.end())
        {
            cout << "Yes";
            return 0;
        }
        p[x];//To protect been used,or no answer;
    }
    
}