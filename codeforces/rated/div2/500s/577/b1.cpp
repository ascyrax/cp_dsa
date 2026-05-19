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

void suraj()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int totSum = 0;
    for (int &i : a)
    {

        cin >> i;
        totSum += i;
    }
    if (totSum % 2 == 1)
    {
        cout << "NO" << endl;
        return;
    }
    if (n == 2)
    {
        if (a[0] == a[1])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return;
    }

    sort(a.begin(), a.end());
    debug(a);

    int pr = n - 1, pl = n - 2;
    int valr = a[pr];
    int vall = a[pl];
    debug(vall);
    debug(valr);
    while (1)
    {
        if (valr == vall)
        {
            vall = 0;
            valr = 0;
            // pr -= 2;
            pl -= 2;
            pr = pl + 1;
            if (pr < 0 || pl < 0)
                break;
            vall = a[pl];
            valr = a[pr];
        }
        else if (valr > vall)
        {
            valr -= vall;
            vall = 0;
            pl--;
            if (pr < 0 || pl < 0)
                break;
            vall = a[pl];
        }
        else if (valr < vall)
        {
            valr = vall - valr;
            vall = 0; // for now
            // update for future
            pr = pl;
            pl = pl - 1;
            if (pr < 0 || pl < 0)
                break;
            vall = a[pl];
        }
        debug(pl);
        debug(vall);
        debug(pr);
        debug(valr);
    }
    debug(pl);
    debug(vall);
    debug(pr);
    debug(valr);

    if (vall == 0 && valr == 0)
        cout << "YES" << endl;
    else
    {
        int index = -1;
        if (vall > 0)
        {
            index = pl;
            int total = a[pl];
            int diff = total - vall;
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (i == index)
                    continue;
                sum += a[i];
            }
            sum -= diff;
            if (sum >= vall)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else if (valr > 0)
        {
            index = pr;
            int total = a[pr];
            int diff = total - valr;
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (i == index)
                    continue;
                sum += a[i];
            }
            sum -= diff;
            if (sum >= valr)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}
