#include<bits/stdc++.h>
using namespace std;
const int maxn = 101010;
int lowbit(int x) {
	return x & (-x); 
}
int main(){
	int x, y;
	// while(1){
	// 	int cnt = 0;
	// 	scanf("%d%d", &x, &y);
	// 	if(x > y) swap(x, y);
		for(int i = x; i < maxn; i += lowbit(i))
			for(int j = y; j > 0; j -= lowbit(j))
				if(i == j)
	// 				cnt ++;
	// 	printf("%d\n", cnt);
	cin>>x;
	cout<<lowbit(x);
	}
} 
