// @author: ascyrax

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <forward_list>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
// #define endl "\n"
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

void query(int a, int b)
{
    cout << "? " << a << " " << b << endl;
}

void printForwardList(const forward_list<int> &v)
{
    cout << "v: ";
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void suraj()
{
    int n;
    cin >> n;

    vector<int> parent(n);
    parent[1] = 0;

    forward_list<int> v;
    v.push_front(1);
    auto tail = v.begin();

    int i = 2;
    int res;
    for (; i < n; i++)
    {
        query(1, i);
        cin >> res;
        if (res == 1)
        {
            tail = v.insert_after(tail, i);
            parent[i] = 0;
        }
        else if (res == 0)
        {
            parent[i] = v.front();
            v.front() = i;
            i++;
            break;
        }
        else if (res == -1)
        {
            cout << "suraj loves games" << endl;
            return;
        }
    }

    auto it = v.begin();
    auto prev = v.begin();
    ++it;
    for (; i < n; i++)
    {
        if (it == v.end())
        {
            it = v.begin();
            prev = v.before_begin();
        }
        query(*it, i);
        cin >> res;
        if (res == 0)
        {
            parent[i] = *it;
            *it = i;
            prev = it;
            ++it;
        }
        else if (res == 1)
        {
            it = v.erase_after(prev);
            while (1)
            {
                if (it == v.end())
                {
                    it = v.begin();
                    prev = v.before_begin();
                }
                query(*it, i);
                cin >> res;

                if (res == 1)
                {
                    it = v.erase_after(prev);
                }
                else if (res == 0)
                {
                    parent[i] = *it;
                    *it = i;
                    prev = it;
                    ++it;
                    break;
                }
                else if (res == -1)
                {
                    cout << "suraj loves games" << endl;
                    return;
                }
            }
        }
        else if (res == -1)
        {
            cout << "suraj loves games" << endl;
            return;
        }
    }

    cout << "! ";
    for (int i = 1; i < n; i++)
        cout << parent[i] << " ";
    cout << endl;
}