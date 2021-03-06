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
    int N,ans=0;
    cin >> N;
    vector<int> mileage(N);
    for(int i=0;i<N;++i){
        cin >> mileage[i];
    }
    for (int i=0;i<N;++i){
        for (int j=0;j<N;++j){
            for (int k=0;k<N;++k){
                if (i!=j&&i!=k&&j!=k){
                    if (((mileage[i]|mileage[j])&mileage[k])==(mileage[i]|(mileage[j]&mileage[k]))){
                        ans++;
                    }
                }
            }
        }
    }
    print(ans);
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