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

    // cin>>t;

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

int nSteps = 0;
vector<pair<int, int>> ans;
void solve(int left, int right)
{
    if (left == right)
    {
        nSteps++;
        ans.push_back(make_pair(left, right));
        return;
    }

    // int del = right - left;
    solve(left + 1, right);
    nSteps++;
    ans.push_back(make_pair(left, right));

    return;
}

void suraj()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    int mxSum = 0;
    int bestBitVal = 0;

    int mxBitVal = pow(2, n) - 1;
    debug(mxBitVal);
    for (int current = 0; current <= mxBitVal; current++)
    {
        vector<int> temp;
        int cnt = 0;
        int sum = 0;
        debug(current);
        for (int i = 0; i < n; i++)
        {
            if ((int)pow(2, i) & current)
            {
                debug("if");
                sum += v[i];
                if (cnt)
                    temp.push_back(cnt);
                cnt = 0;
            }
            else
            {
                debug("else");
                cnt++;
            }
        }
        if (cnt)
            temp.push_back(cnt);
        cnt = 0;
        debug(temp);
        for (int el : temp)
        {
            sum += el * el;
        }
        debug(sum);
        if (sum > mxSum)
        {
            mxSum = sum;
            bestBitVal = current;
        }
    }

    debug(mxSum);
    debug(bestBitVal);
    // cout << mxSum << endl;
    vector<pair<int, int>> temp;
    int left = 0, right = left;
    for (int i = 0; i < n; i++)
    {
        if ((int)pow(2, i) & bestBitVal)
        {
            debug("if");
            right--;
            if (left <= right)
                temp.push_back(make_pair(left, right));
            left = i + 1;
            right = left;
        }
        else
        {
            debug("else");
            right++;
        }
    }
    if (right >= n)
        right--;

    if (left <= right)
        temp.push_back(make_pair(left, right));

    debug(temp);

    for (pair<int, int> range : temp)
    {
        int left = range.first;
        int right = range.second;
        for (int i = left; i <= right; i++)
        {
            if (v[i] != 0)
            {
                nSteps++;
                ans.push_back(make_pair(i, i));
            }
        }
        solve(range.first, range.second);
    }

    cout << mxSum << " " << nSteps << endl;
    for (auto el : ans)
        cout << el.first + 1 << " " << el.second + 1 << endl;
}
