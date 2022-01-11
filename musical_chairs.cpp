#include <iostream>
#include <vector>
// Switch DEBUG to false if you don't want to print the factors
#define DEBUG true
#define int long long
using namespace std;

int factors(int x)
{
    // We will store all factors in `result`
    vector<int> result;
    int i = 1;
    // This will loop from 1 to int(sqrt(x))
    while (i * i <= x)
    {
        // Check if i divides x without leaving a remainder
        if (x % i == 0)
        {
            result.push_back(i);
            // Handle the case explained in the 4th
            if (x / i != i)
            {
                result.push_back(x / i);
            }
        }
        i++;
    }
    return result.size();
}

int32_t main()
{
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        N--;
        cout << factors(N) << endl;
    }
}
