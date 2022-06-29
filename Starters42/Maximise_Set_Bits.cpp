#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "LINE(" << __LINE__ << ") -> " <<"[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

void print(){cerr << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cerr << one << " ";
    print(rest...);
}


int sum() { return 0; }
template<typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

string bin(long n){
    long i;
    string val = "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    {
      if((n & i) != 0)
      {
        val+="1";
      }
      else
      {
        val+="0";
      }
    }
    while(val.front()=='0'){
        val.erase(0,1);
    }
    return val;
}

int create_first_no(int n)
{
    // Length of the binary from
    int length = 0;

    // Number of set bits
    int freq_set_bits = 0;
    int ans = 0;
    while (n)
    {

        // Update the first number
        ans = ans << 1;
        ans = ans + 1;

        // Increment length
        length++;

        // Update the frequency
        if ((n & 1))
            freq_set_bits += 1;

        n = n >> 1;
    }
    // Check if n does not have all the
    // bits as set bits then make
    // the first as less than n
    if (length != freq_set_bits)
        ans = (ans >> 1);

    // Return the first value
    return ans;
}

// Function to calculate maximum
// set bit frequency sum
int maxSetBits(int n)
{
    // First value of pair
    int first = create_first_no(n);

    // Second value of pair
    int second = n - first;

    // __builtin_popcount() is inbuilt
    // function to count the number of set bits
    int freq_first = __builtin_popcountll(first);
    int freq_second = __builtin_popcountll(second);

    // Return the sum of freq of setbits
    return freq_first + freq_second;
}

void solve()
{
    int n,k;
    cin >> n >> k;
    if(n >= k){
        cout << k << endl;
        return;
    }
    if(n == 1){
        cout << __builtin_popcountll(k) << endl;
        return;
    }
    int took = 0;
    int res = 0;
    int sum = 0;
    for(int i = 0;i<=30;++i){
        if(took == n-1)break;
        if(k&(1ll<<i)){
            int val = (1ll<<i)-1;
            res+=(__builtin_popcountll(val));
            sum+=val;
            took++;
        }
    }
    int rem = k-sum;
    res+=(__builtin_popcountll(rem));
    cout << res << endl;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}