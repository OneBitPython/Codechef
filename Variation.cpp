#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long N, K;
    cin >> N >> K;
    vector<int> nums(N);
    for (int i = 0; i < N; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    long long ans=0;
    for (int i=0;i<N;++i){
        for (int j=i+1;j<N;++j){
            if (abs(nums[i]-nums[j])>=K){
                ans+=N-j;
                break;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    solve();
}