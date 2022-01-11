#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz size
#define all(c) c.begin(), c.end()

int sum() { return 0; }
template<typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

void print(){cout << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cout << one << " ";
    print(rest...);
}

void read(){};
template<typename T, typename... Args>
void read(T& one, Args&... rest){
    cin >> one;
    read(rest...);
}

void solve()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    bool b=true;
    for(int i=1;i<N;++i){
        if (arr[i] < arr[i-1]){
            b=false;
        }
    }
    if (!b){

        cout << *max_element(all(arr))- *min_element(all(arr)) << endl;
    }else{
        cout << 0 << endl;
    }
    // if (N==1){
    //     cout << arr[0] << endl;
    //     return;
    // }
    // vector<int> dp = {arr[0]};
    // for(int i=1; i<arr.size();++i){
    //     dp.pb(min(dp.back(), arr[i]));
    // }
    
}

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    read(T);
    while (T--)
    {
        solve();
    }
}