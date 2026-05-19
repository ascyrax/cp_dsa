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
bool allEmpty(map<int, int> &cnt)
{
    for (auto it : cnt)
    {
        if (it.second > 0)
            return false;
    }
    return true;
}

bool allEqual(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] != v[0])
            return false;
    }
    return true;
}

bool check(int d, vector<int> &bitCnt, vector<int> &a)
{
    debug(d);
    debug(bitCnt);
    debug(a);
    // no of elements in the final vector is d,
    // => each impBit should be its cnt/d times in each element :)
    map<int, int> cnt;
    int n = a.size();
    vector<int> impBits;
    for (int i = 0; i < 31; i++)
    {
        impBits.push_back(i);
        cnt[i] = bitCnt[i] / d;
    }
    debug(cnt);
    vector<int> shrinkedVector;
    int i = 0;
    int val = 0;

    while (i < n)
    {
        val = val ^ a[i];
        for (int j = 0; j < impBits.size(); j++)
        {
            if (val & (1 << impBits[j]))
                cnt[impBits[j]]--;
        }
        // if any is <0, => this cannot be the answer
        for (int j = 0; j < impBits.size(); j++)
        {
            if (cnt[impBits[j]] < 0)
                return false;
        }
        if (allEmpty(cnt))
        {
            shrinkedVector.push_back(val);
            val = 0;
            // repopulate the cnt map for the next element in the shrinked vector
            for (int i = 0; i < 31; i++)
                cnt[i] = bitCnt[i] / d;
        }
        i++;
    }
    debug(shrinkedVector);
    if (allEqual(shrinkedVector))
        return true;
    else
        return false;
}

// 1
// 3
// 37844378 1042455423 1013182181

void suraj()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    bool flag = true;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> bitCnt(31, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            if (a[i] & (1 << j))
                bitCnt[j]++;
        }
    }
    int gcd = 0;
    for (int i = 0; i < 31; i++)
    {
        if (bitCnt[i] > 0)
        {
            // debug(gcd);
            gcd = __gcd(gcd, bitCnt[i]);
            // debug(gcd);
        }
    }
    // debug(bitCnt);
    // debug(gcd);
    if (gcd == 1)
    {
        // flag = false :)
        cout << "NO" << endl;
        return;
    }

    // first find the divisors of the gcd and store it in a vector
    vector<int> divisors;
    for (int i = 2; i * i <= gcd; i++)
    {
        if (gcd % i == 0)
        {
            if (i != 1)
                divisors.push_back(i);
            if (i != gcd / i)
                divisors.push_back(gcd / i);
        }
    }
    divisors.push_back(gcd);

    debug(divisors);
    // now for the gcd and all the divisors of the gcd, we can check if they are valid or not

    for (int i = 0; i < divisors.size(); i++)
    {
        int d = divisors[i];
        flag = check(d, bitCnt, a);
        if (flag)
            break;
    }

    cout << (flag ? "YES" : "NO") << endl;
}
