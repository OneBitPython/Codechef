#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long N,cnt=0,fac;
    cin >> N;
    vector<long long> teams(N);
    for (long long i = 0; i < N;++i){
        cin >> teams[i];
        
    }
    long long rev = 0;
    sort(teams.begin(), teams.end());
    for (int i = N - 1; i >= 0; --i)
    {
        rev += teams[i] * (2 * i - N + 1);
    }
    cout << rev;
}

int main()
{
    solve();
}