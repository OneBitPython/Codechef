#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long N;

    cin >> N;
    vector<long long>customers(N);
    for(int i=0; i<N; i++){
        cin >> customers[i];

    }
    sort(customers.begin(), customers.end());
    long long ans=0;
    for (int i=0; i<N; i++){
        long long remaining = N-i;
        ans=max(customers[i]*remaining, ans);
    }
    cout << ans << endl;
}

int main(){
    solve();
}