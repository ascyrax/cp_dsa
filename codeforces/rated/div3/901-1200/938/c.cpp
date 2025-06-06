
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

    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    int shipsSanked = 0;
    int left = 0, right = n - 1;
    while (k && (left <= right))
    {
        // debug(k);
        // debug(v);
        // cout << left + 1 << " " << right + 1 << endl;
        // debug(left);
        // debug(right);
        int mn = min(v[left], v[right]);
        if (left == right)
        {
            if (k >= mn)
            {
                shipsSanked++;
                left++;
                right--;
            }
            break;
        }

        if (v[left] < v[right])
        {
            int reqAttacks = (mn - 1) * 2 + 1;
            if (k >= reqAttacks)
            {
                shipsSanked++;
                k -= reqAttacks;
                v[left] = 0;
                v[right] -= (mn - 1);
                left++;
                if (k > 0)
                {
                    v[right]--;
                    k--;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        else if (v[left] > v[right])
        {
            int reqAttacks = mn * 2;
            if (k >= reqAttacks)
            {
                shipsSanked++;
                k -= reqAttacks;
                v[right] = 0;
                v[left] -= mn;
                right--;
            }
            else
                break;
        }
        else if (v[left] == v[right])
        {
            int reqAttacks = (mn - 1) * 2 + 1;
            if (k >= reqAttacks)
            {
                shipsSanked++;
                k -= reqAttacks;
                v[left] = 0;
                v[right] -= (mn - 1);
                left++;
                if (k > 0)
                {
                    v[right]--;
                    k--;
                    if (v[right] == 0)
                    {
                        shipsSanked++;
                        right--;
                    }
                }
                else
                {
                    break;
                }
            }
            else
                break;
        }
    }
    // debug(k);
    // debug(v);
    cout << shipsSanked << endl;
}
