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
    int N, M;
    cin >> N >> M;
    vector<int> opponent(N);
    for(int i = 0; i <N;++i){
        cin >> opponent[i];
    }

    vector<int> team(M);
    for(int i = 0; i <M; ++i){
        cin >> team[i];
    }
    int max1 = *max_element(all(opponent));
    sort(all(team));
    int max2  = team.back();
    if (max1 > max2){
        cout << "NO" << endl;
    }else if (max2 > max1){
        cout << "YES" << endl;
        for(auto x : team){
            cout << x << " ";
        }
        cout << endl;
    }else{
        int largest = team.back();
        int idx = team.size()-1,idx_opponent = 0;
        int value = 0;
        while(idx_opponent < N){
            if (opponent[idx_opponent] > largest){
                idx--;
                if (idx<0){
                    cout << "NO" << endl;
                    return;
                }
                largest = team[idx];
                value++;
            }else if (opponent[idx_opponent]==largest){
                idx--;
                if (idx < 0)
                {
                    cout << "NO" << endl;
                    return;
                }
                largest = team[idx];
                idx_opponent++;
                value++;
            }else{
                idx_opponent++;

            }
        }
        value++;
        cout << "YES" << endl;
        for(int i =0 ; i<M-value;++i){
            cout << team[i] << " ";
        }
        for (int i = M-1; i>=M-value;--i){
            cout << team[i] << " ";
        }
        cout << endl;
    }
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