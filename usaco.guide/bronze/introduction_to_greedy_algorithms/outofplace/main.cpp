#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

// using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define endl "\n"
#define ioss                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define pb push_back
#define eb emplace_back

double startTime;
double gct() // get_current_time
{
    return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

void suraj()
{

    int n;
    cin >> n;

    vector<int> v(n), x;
    for (int &i : v)
        cin >> i;

    x = v;
    sort(x.begin(), x.end());

    // for(int i:x)cout<<i<<" ";cout<<endl;
    int bessi = -1;
    int val = -1;
    for (int i = 0; i < n - 1; i++)
    {
        // find bessi
        if (v[i] <= v[i + 1])
        {
            continue;
        }
        else
        {
            int a = v[i];
            int b = v[i + 1]; // cout<<a<<" "<<b<<endl;
            auto ita = abs(lower_bound(x.begin(), x.end(), a) - (x.begin() + i));
            auto itb = abs(lower_bound(x.begin(), x.end(), b) - (x.begin() + i + 1));
            // cout<<ita<<" "<<itb<<endl;
            if (ita > itb)
            {
                bessi = i;
                val = v[i];
            }
            else
            {
                bessi = i + 1;
                val = v[i + 1];
            }
        }
    }
    // cout<<bessi<<" "<<val<<endl;
    if (bessi == -1)
        cout << 0 << endl;
    else
    {
        int ans = 0;
        auto it = lower_bound(x.begin(), x.end(), val) - x.begin();
        // cout<<it<<endl;
        if (it < bessi)
        {
            auto ptr = unique(v.begin() + it, v.begin() + bessi);
            v.resize(ptr - v.begin());
            ans = v.size() - 1;
        }
        else if (it > bessi)
        {
            auto ptr = unique(v.begin() + bessi, v.begin() + it);
            v.resize(ptr - v.begin());
            ans = v.size() - 1;
        }
        else
            ans = 0;
        cout << ans << endl;
    }

} //

int main()
{
    startTime = (double)clock();
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    // ioss
    // int t;cin>>t;while(t--)
    suraj();
    // suraj2();
    // suraj3();
    // suraj4();
    return 0;
}
