#include<bits/stdc++.h>
using namespace std;
void quickSort(int s[], int l, int r)
{
	if (l< r)
	{      
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while(i < j && s[j]>= x) // 从右向左找第一个小于x的数
				j--; 
			if(i < j)
				s[i++] = s[j];
			while(i < j && s[i]< x) // 从左向右找第一个大于等于x的数
				i++; 
			if(i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quickSort(s, l, i - 1); // 递归调用
		quickSort(s, i + 1, r);
	}
}
int main()
{
    
    int n;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    int len=sizeof(num)/sizeof(int);
    quickSort(num,0,len-1);
    int j=0;
    for(int i=0;i<n;i++)
    {
        for(int j=n;j<n;j++)
        {
            for(int m=j;m<n;m++)
            {
                if(num[m]+num[j]==num[i])
                {
                    j++;
                }
            }
        }
    }
    cout<<j;
}
/*bool prime(int x)
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
/*int main()
{
    int n,fish[101],cute[101]={0};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>fish[i];
    }
    int h=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(fish[i]>fish[j])
            {
                cute[i]+=1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<cute[i]<<" ";
    }
}
*/