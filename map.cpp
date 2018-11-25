#include<bits/stdc++.h>
using namespace std;
map<int, int> mp;
int main(){
	mp[1] = 100;
	cout << mp.size() << endl;
	mp[2] = 1;
	cout << mp.size() << endl;
	mp[2] = 10;
	cout << mp.size() << endl;
	for(int i = 1; i <= 10; i ++)
		mp[i];
	cout << mp.size() << endl;
	
	for(int i = 1; i <= 20; i ++){
		if(mp.find(i) != mp.end())
			mp[i];
	}
	cout << mp.size() << endl;
	
}
