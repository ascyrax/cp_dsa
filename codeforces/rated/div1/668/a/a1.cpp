// @author: ascyrax

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define int long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;
using lld = long double;

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

void suraj();

signed main()
{

    fastio();

#ifndef ONLINE_JUDGE
    clock_t startTime = clock();
#endif

    // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

    // cout << setprecision(15) << fixed;

    int t = 1;

    cin >> t;

    for (int i = 1; i <= t; i++)
    {

        // cout<<"Case #"<<i<<": ";

        suraj();

        debug("---");
    }

#ifndef ONLINE_JUDGE
    cerr << "Execution Time : " << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;
#endif

    return 0;
}

void suraj()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // the character at index k+i must be equal to index i

    // check if this is not true, then the answer is NO
    // for (int i = k; i < n; i++)
    // {
    //     if (s[i] == '?')
    //     {
    //         s[i] = s[i - k]; // no matter s[i-k] is ? or 0 or 1
    //     }
    //     else if (s[i] != '?')
    //     {
    //         s[i] = s[i - k];
    //     }
    // }
    debug(s);

    for (int i = 0; i < k; i++)
    {
        // int flagValue = -1; // -1 means not set, 0 means 0, 1 means 1
        set<int> flagValue;
        for (int j = i; j < n; j += k)
        {
            if (s[j] == '0')
                flagValue.insert(0);
            else if (s[j] == '1')
                flagValue.insert(1);
        }
        if (flagValue.size() > 1)
        {
            cout << "NO" << endl;
            return;
        }
        else if (flagValue.size() == 1)
        {
            for (int j = i; j < n; j += k)
            {
                // cout << "*flagValue.begin(): " << *flagValue.begin() << endl;
                s[j] = *flagValue.begin() + '0';
            }
        }
        else if (flagValue.size() == 0)
        {
            // do nothing, we can set it to either 0 or 1
        }
    }
    // debug(s);

    int cnt0 = 0, cnt1 = 0, cntqm = 0;
    for (int i = 0; i < k; i++)
    {
        if (s[i] == '0')
            cnt0++;
        else if (s[i] == '1')
            cnt1++;
        else
            cntqm++;
    }
    if (cnt0 > k / 2 || cnt1 > k / 2)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}
