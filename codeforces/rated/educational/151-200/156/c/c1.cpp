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

        // debug("---");
    }
    cout << endl;

#ifndef ONLINE_JUDGE
    cerr << "Execution Time : " << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;
#endif

    return 0;
}

void suraj()
{
    string s;
    cin >> s;
    int pos;
    cin >> pos;

    int lens = s.size();

    // int removalNo = 1;
    int whenToRemove = 1;
    vector<int> vecWhenToRemove(lens, 0);

    vector<int> index_removed, index_notRemoved;

    for (int i = 0; i < lens - 1; i++)
    {
        // debug(i);
        // debug(index_removed);
        // debug(index_notRemoved);
        if (s[i + 1] < s[i])
        {
            vecWhenToRemove[i] = whenToRemove++;
            index_removed.push_back(i);
            while (index_notRemoved.size() > 0)
            {
                int latest = index_notRemoved.back();
                if (s[i + 1] < s[latest])
                {
                    index_notRemoved.pop_back();
                    vecWhenToRemove[latest] = whenToRemove++;
                    index_removed.push_back(latest);
                }
                else
                    break;
            }
        }
        else
        {
            index_notRemoved.push_back(i);
        }
    }
    index_notRemoved.push_back(lens - 1);
    // debug(index_removed);
    // debug(index_notRemoved);
    while (index_notRemoved.size() > 0)
    {
        int latest = index_notRemoved.back();
        vecWhenToRemove[latest] = whenToRemove++;
        index_notRemoved.pop_back();
    }

    // debug(vecWhenToRemove);

    int nRemovals = 0;
    int lenStr = lens;
    while (pos > lenStr)
    {
        nRemovals++;
        lenStr += (lens - nRemovals);
        // debug(pos);
        // debug(nRemovals);
        // debug(lenStr);
    }
    int diff = lenStr - pos;

    // debug(diff);

    for (int i = lens - 1; i >= 0; i--)
    {
        if (vecWhenToRemove[i] > nRemovals)
        {
            if (diff == 0)
            {
                cout << s[i];
                return;
            }
            else
                diff--;
        }
    }
}
