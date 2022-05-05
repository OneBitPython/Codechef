#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

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




void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    vector<int>s = a;
    sort(all(s));
	if(n>=4&&s==a){
		cout << "NO" << endl;
		return;
	}
	vector<int>r = {1,2,3,4,5};
    set<vector<int>>ords;
    for(int b = 0;b<4;++b){
        for(int c = 0;c<4;++c){
            for(int d = 0;d<4;++d){
                    vector<int>order = {b,c,d};
                    bool pos = 0;
                    do{
                        vector<int>res;
                        for(int i = 0;i<3;++i){
                            int cnt = 0;
                            if(r[i] > r[i+1])cnt++;
                            if(r[i]>r[i+2])cnt++;
                            if(r[i+1]>r[i+2])cnt++;
                            res.pb(cnt);
                        }
                        vector<int>od;
                        for(int i = 0;i<3;++i)od.pb(order[i]);
                        if(res == od){
                            pos = 1;
                            break;
                        }
                    }while(next_permutation(all(r)));
                    sort(all(r));
                    if(!pos){
                        vector<int>ord;
                        for(int i = 0;i<3;++i)ord.pb(order[i]);

                        ords.insert(ord);
            }
            }
        }
    }
	ords.insert({0,3});
	ords.insert({3,0});
	
	for(int i= 0;i<n-3;++i){
		
		for(auto x : ords){
			if(a[i] == x[0] && a[i+1] == x[1] && a[i+2] == x[2]){
				cout << "NO" << endl;
				return;
			}
		}
	}
	if((a[n-1]==3 &&a[n-2]==0)||(a[n-2]==0&&a[n-1]==3)){
		cout << "NO" << endl;
		return;
	}
	for(int i = 0;i<n-4;++i){
		vector<int>k;
		vector<int>req={0,1,2,1,0};
		for(int j = i;j<i+5;++j)k.pb(a[j]);
		if(k==req){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES\n";
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
        solve();
    }
}