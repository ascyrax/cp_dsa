// @author: ascyrax

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <unordered_map>

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

int choose_two_from(int n)
{

    // nC2 = n! / (2! * (n-2)!)
    // = n * (n-1) / 2
    return n + ((n * (n - 1)) / 2);
}

int find_desired_pairs(string a, string &b, set<char> &allowed)
{
    // unordered_map<char, int> mp;
    vector<int> alphabets(26, 0);
    for (char ch : allowed)
        alphabets[ch - 'a'] = 1;

    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (alphabets[a[i] - 'a'] == 1)
            a[i] = b[i];
    }

    int res = 0;

    // debug(allowed);
    // debug(a);
    // debug(b);
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            res += choose_two_from(len);
            len = 0;
            // debug(res);
        }
        else
        {
            len++;
            // debug(len);
        }
    }
    if (len > 0)
        res += choose_two_from(len);
    // debug(res);
    // cout << "returning ................" << endl;
    return res;
}

void suraj()
{
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;

    int ans = 0;

    set<char> st_a, st_b;
    for (char c : a)
        st_a.insert(c);

    // convert a -> b

    // brute force
    // st_a.size() < k => a will be fully convertible to b
    if (st_a.size() < k)
    {
        ans = choose_two_from(n); // n cz whole length of a or b
    }
    else // st_a.size() >= k
    {
        // code to iterate and choose all k combination of elements from a vector
        vector<char> chars(all(st_a));
        // debug(chars);
        int sz = chars.size();
        // debug(sz);
        vector<int> idx(sz, 0);
        // debug(idx);
        for (int i = 0; i < k; ++i)
            idx[i] = 1;
        // debug(idx);
        sort(idx.begin(), idx.end());
        // debug(idx);
        // int temp = 0;
        do
        {
            // temp++;
            set<char> allowed;
            for (int i = 0; i < sz; ++i)
            {
                if (idx[i])
                    allowed.insert(chars[i]);
            }
            // Now allowed contains one combination of k chars from a
            // debug(idx);
            // debug(chars);
            // debug(allowed);

            ans = max(ans, find_desired_pairs(a, b, allowed));

        } while (next_permutation(idx.begin(), idx.end()));
        // debug(temp);
    }

    cout << ans << endl;
}
