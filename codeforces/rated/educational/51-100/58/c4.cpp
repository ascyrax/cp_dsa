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
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll

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
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> ranges; // < l, <r, index> >
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        ranges.push_back(make_pair(l, make_pair(r, i)));
    }
    sort(ranges.begin(), ranges.end());
    debug(ranges);

    vector<int> grp(n, -1);
    set<int> st;

    int r0 = ranges[0].second.first;
    int index = ranges[0].second.second;
    grp[index] = 1;
    st.insert(r0);
    debug(st);
    debug(grp);

    int prevGrp = 1;

    for (int i = 1; i < n; i++)
    {
        int l = ranges[i].first;
        int r = ranges[i].second.first;
        int index = ranges[i].second.second;
        auto itl = st.lower_bound(l);
        // debug(itl);

        st.erase(st.begin(), itl);
        // debug(st);
        int lenSt = st.size();

        if (lenSt >= 1)
        {
            // only same grp will do
            grp[index] = prevGrp;
        }
        else if (lenSt == 0)
        {
            // any grp will do
            // but we will take the other grp :) cz we want the two grps to be non-empty :)
            // in fact we can always take the other grp now :)
            prevGrp = 2;
            grp[index] = prevGrp;
        }
        st.insert(r);

        debug(st);
        debug(grp);
    }

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (grp[i] == 1)
            cnt1++;
        else if (grp[i] == 2)
            cnt2++;
    }
    if (cnt1 == 0 || cnt2 == 0)
    {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < n; i++)
        cout << grp[i] << " ";
    cout << endl;
}
