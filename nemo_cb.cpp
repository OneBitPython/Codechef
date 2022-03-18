#include <bits/stdc++.h>
using namespace std;


void print(){cout << endl;}

template<typename T, typename... args>
void print(T one, args ... rest){
	cout << one << " ";
	print(rest...);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
}