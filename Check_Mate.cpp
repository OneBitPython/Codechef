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

bool check_contains(vector<pair<int,int>>&all_covered, vector<pair<int,int>>&other_rookx, vector<pair<int,int>>&other_rooky, vector<pair<int,int>>&curr_rookx, vector<pair<int,int>>&curr_rooky,vector<pair<int,int>>&adjacent){
    all_covered.insert(all_covered.end(), other_rookx.begin(), other_rookx.end());
    all_covered.insert(all_covered.end(), other_rooky.begin(), other_rooky.end());
    all_covered.insert(all_covered.end(), curr_rookx.begin(), curr_rookx.end());
    all_covered.insert(all_covered.end(), curr_rooky.begin(), curr_rooky.end());
    for (auto king_pos : adjacent)
    {
        bool b = true;
        for (auto covered : all_covered)
        {
            if (king_pos == covered)
            {
                b = false;
                break;
            }
        }
        if (b)
        {
            return true;
        }
    }
    return false;
}

string solve()
{
    int kx, ky, x1, x2, y1, y2;
    read(kx, ky, x1, y1, x2, y2);

    // getting kings adjacent
    vector<pair<int, int>> first_rookx, first_rooky, second_rookx, second_rooky;
    for (int i = 1; i < 9; ++i)
    {
        first_rooky.pb({x1, i});
        first_rookx.pb({i, y1});
        second_rooky.pb({x2, i});
        second_rookx.pb({i, y2});
    }
    vector<pair<int, int>> adjacent;
    if (kx > 1)
    {
        adjacent.pb({kx - 1, ky});
    }
    if (kx < 8)
    {
        adjacent.pb({kx + 1, ky});
    }
    if (ky > 1)
    {
        adjacent.pb({kx, ky - 1});
    }
    if (ky < 8)
    {
        adjacent.pb({kx, ky + 1});
    }
    if (kx < 8 && ky < 8)
    {
        adjacent.pb({kx + 1, ky + 1});
    }
    if (kx < 8 && ky > 1)
    {
        adjacent.pb({kx + 1, ky - 1});
    }
    if (kx > 1 && ky < 8)
    {
        adjacent.pb({kx - 1, ky + 1});
    }
    if (kx > 1 && ky > 1)
    {
        adjacent.pb({kx - 1, ky - 1});
    }
    adjacent.pb({kx, ky});

    // move first rook to king x
    vector<pair<int, int>> new_coords,all_covered={};
    for (int i = 1; i < 8; ++i)
    {
        new_coords.pb({i, ky});
    }
    
    if(check_contains(all_covered, second_rookx, second_rooky, new_coords, first_rooky, adjacent)){
        return "YES";
    }else{
        all_covered.clear();
        // changing first rook y
        new_coords.clear();
        for (int i = 1; i < 8; ++i)
        {
           
        }
    }
}

int32_t main()
{
    int T;
    read(T);
    while (T--)
    {
        cout << solve() << endl;
    }
}