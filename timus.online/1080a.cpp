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

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

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

using std::cout;

void suraj()
{
    int n;
    cin >> n;

    map<int, int> mp;

    mp[1] = 0; // color the first country red :)

    map<int, vector<int>> todo;

    for (int i = 1; i <= n; i++)
    {
        int neigh;
        vector<int> neighs;
        while (cin >> neigh)
        {
            if (neigh == 0)
                break;
            neighs.pb(neigh);
        }

        if (!mp.count(i))
            for (auto neigh : neighs)
            {
                if (mp.count(neigh))
                {
                    mp[i] = mp[neigh] ^ 1;
                    break;
                }
            }

        if (!mp.count(i))
        {
            // mp[i] = 0; // it is not right to do so.
            todo[i] = neighs;
            continue;
        }

        for (int neigh : neighs)
        {
            if (mp.count(neigh) && (mp[neigh] == mp[i]))
            {
                std::cout << -1 << endl;
                return;
            }
            mp[neigh] = mp[i] ^ 1;
        }
        // debug(i);
        // debug(mp);
    }

    while (!todo.empty())
    {
        // debug(mp);
        for (map<int, vector<int>>::iterator itr = todo.begin(); itr != todo.end();)
        {
            int node = itr->first;
            vector<int> neighs = itr->second;
            debug(todo);
            debug(node);
            debug(neighs);
            debug(mp);

            if (!mp.count(node))
            {
                for (int neigh : neighs)
                {
                    if (mp.count(neigh))
                    {
                        mp[node] = mp[neigh] ^ 1;
                        break;
                    }
                }
            }

            if (!mp.count(node))
            {
                itr++;
                continue;
            }

            for (int neigh : neighs)
            {
                if (mp.count(neigh) && (mp[neigh] == mp[node]))
                {
                    std::cout << -1 << endl;
                    return;
                }
                mp[neigh] = mp[node] ^ 1;
            }
            itr = todo.erase(itr);
            // node = itr->first;
            // neighs = itr->second;
            // debug(node);
            // debug(neighs);
            // if (todo.empty())
            // break;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << mp[i];
    cout << endl;
}
