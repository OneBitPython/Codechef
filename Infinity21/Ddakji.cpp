#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz size
#define all(c) c.begin(), c.end()

int sum()
{
    return 0;
}
template <typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

void print() { cout << endl; };
template <typename T, typename... Args>
void print(T one, Args... rest)
{
    cout << one << " ";
    print(rest...);
}

void read(){};
template <typename T, typename... Args>
void read(T &one, Args &...rest)
{
    cin >> one;
    read(rest...);
}

void solve()
{
    int N;
    cin >> N;
    vector<int> arr(N),output;
    for(int i = 0; i < N;++i){
        cin >> arr[i];
    }
    sort(all(arr));
    
    for (int i = N-1; i>=1;--i){
        int curr = arr[i];
        int prev = arr[i-1];
        if (prev >0){
            output.pb(abs(curr-(prev*(curr/prev))));
        }else{
            output.pb(abs(curr));
        }
    }
    int curr = output[0];
    int prev = arr[0];
    if (curr <= prev){
        if(curr > 0){
            output.pb(abs(prev - (curr * (prev / curr))));
        }
        else{
            output.pb(abs(prev));
        }
    }else{
        output.pb(abs(prev));
    }
    cout << accumulate(all(output), 0) << endl;
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