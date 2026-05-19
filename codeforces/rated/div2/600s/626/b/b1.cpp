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

vector<int> getDivisors(int n)
{
    vector<int> divisors;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
            if (i != n / i)
                divisors.push_back(n / i);
        }
    }
    return divisors;
}

int getRectCount(pair<int, int> rect, pair<int, int> target)
{
    int count = 0;
    if (rect.first >= target.first && rect.second >= target.second)
    {
        count += (rect.first - target.first + 1) * (rect.second - target.second + 1);
    }
    // reverse target
    // do this only if target is not a square, otherwise we will be counting the same rectangle twice
    if (target.first != target.second)
    {
        target = {target.second, target.first};
        if (rect.first >= target.first && rect.second >= target.second)
        {
            count += (rect.first - target.first + 1) * (rect.second - target.second + 1);
        }
    }
    debug(count);
    return count;
}

void suraj()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    // assuming a horizontal, and b vertical
    int prevCol = 0, prevRow = 0;

    // vector<int> deltaCols;
    map<int, int> deltaCols;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            if (i - prevCol > 0)
                // deltaCols.push_back(i - prevCol);
                deltaCols[i - prevCol]++;
            prevCol = i + 1;
        }
    }
    if (prevCol <= n - 1)
        // deltaCols.push_back(n - prevCol);
        deltaCols[n - prevCol]++;

    // vector<int> deltaRows;
    map<int, int> deltaRows;
    for (int i = 0; i < m; i++)
    {
        if (b[i] == 0)
        {
            if (i - prevRow > 0)
                // deltaRows.push_back(i - prevRow);
                deltaRows[i - prevRow]++;
            prevRow = i + 1;
        }
    }
    if (prevRow <= m - 1)
        // deltaRows.push_back(m - prevRow);
        deltaRows[m - prevRow]++;
    debug(deltaRows);
    debug(deltaCols);

    // vector<pair<int, int>> rectangles;
    map<pair<int, int>, int> rectangles;
    // for (int i = 0; i < deltaRows.size(); i++)
    for (auto elRow : deltaRows)
    {
        // for (int j = 0; j < deltaCols.size(); j++)
        for (auto elCol : deltaCols)
        {
            // rectangles.push_back({deltaRows[i], deltaCols[j]});
            // rectangles[{deltaRows[i], deltaCols[j]}]++;
            rectangles[{elRow.first, elCol.first}] += elRow.second * elCol.second;
        }
    }
    deltaRows.clear();
    deltaCols.clear();
    vector<int> divisors;
    divisors = getDivisors(k);
    sort(divisors.begin(), divisors.end());
    debug(divisors);
    vector<pair<int, int>> targetRectangles;
    for (int divisor : divisors)
    {
        if (divisor <= sqrt(k))
            targetRectangles.push_back({divisor, k / divisor});
        else
            break;
    }
    divisors.clear();

    debug(rectangles);
    debug(targetRectangles);

    int count = 0;
    for (auto target : targetRectangles)
    {
        for (auto rect : rectangles)
        {
            count += getRectCount(rect.first, target) * rect.second;
        }
    }
    cout << count << endl;
}
