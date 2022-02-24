#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()

void solve(){
	int k;
	cin >>k;
	vector<int> v;
	for(int i = 1;i<(int)(1e4);++i){
		if(i%3 == 0)continue;
		if((i%10) == 3)continue;
		v.push_back(i);
	}
	cout << v[k-1] << endl;
}

int32_t main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin >> t;
	while(t--)solve();
	

}
