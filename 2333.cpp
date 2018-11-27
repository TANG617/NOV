#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
    using namespace std;
    int n,m,tree[2000010];
    
    // 第一行包含两个整数N、M，
    // 分别表示该数列数字的个数和操作的总个数。
    // 第二行包含N个用空格分隔的整数，其中第i个数字表示数列第i项的初始值。

    // 接下来M行每行包含3个整数，表示一个操作，具体如下：

    // 操作1： 格式：1 x k 含义：将第x个数加上k

    // 操作2： 格式：2 x y 含义：输出区间[x,y]内每个数的和
    int lowbit(int k)
    {
        return k & -k;
    }
    
    void add(int x,int k)
    {
        while(x<=n)
        {
            tree[x]+=k;
            x+=lowbit(x);
        }
    }
    int sum(int x)
    {
        int ans=0;
        while(x!=0)
        {
            ans+=tree[x];
            x-=lowbit(x);
        }
        return ans;
    }
    int main()
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);
            add(i,a);
        }
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(a==1)
                add(b,c);
            if(a==2)
                cout<<sum(c)-sum(b-1)<<endl;
        }
    }
// #include<bits/stdc++.h>
// using namespace std;
// const int maxn = 101010;
// int tree[maxn]={0,1,2,3,4,5,6,7,8,9,10};
// int lowbit(int x) {
// 	return x & (-x); 
// }
// int _sum(int x)
//     {
//         int ans=0;
//         while(x!=0)
//         {
//             ans+=tree[x];
//             x-=lowbit(x);
//         }
//         return ans+1;
//     }
// int main()
// {
//     int _min=3,_max=5,sum=0;
//     //cin>>_min>>_max;
//     // for(int i = _min; i < maxn; i += lowbit(i))
// 	// {
//     // 		for(int j = _max; j > 0; j -= lowbit(j))
// 	// 			{
//     //                 if(i == j)
//     //             {
//     //                 sum+=i;
//     //             }
//     //             }
//     // }   
//     // for(int i=_min;i<maxn;i+=lowbit(i))
//     // {
//     //     //tree[i]+=i;
//     //     for(int i=_max;i>0;i-=lowbit(i))
//     //     {
//     //         sum+=tree[i];
//     //     }
//     // }
//     cout<<_sum(6) <<endl;
// }