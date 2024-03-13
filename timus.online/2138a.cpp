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

int bad_b(int val_at_b)
{
    int digi_max = 256;
    // a sent A:B:C:D
    // b interpreted A*0 + B*digi_max + C*digi_max*digi_max + D*digi_max*digi_max*digi_max;

    int D = val_at_b / (digi_max * digi_max * digi_max);
    debug(D);
    int rem = val_at_b % (digi_max * digi_max * digi_max);
    debug(rem);

    int C = rem / (digi_max * digi_max);
    rem %= (digi_max * digi_max);
    int B = rem / digi_max;
    int A = rem % digi_max;

    debug(A);
    debug(B);
    debug(C);
    debug(D);

    int val_at_a = A * (digi_max * digi_max * digi_max) + B * (digi_max * digi_max) + C * (digi_max) + D;

    debug(val_at_a);

    return val_at_a;
}

int good_b(int val_at_b)
{
    int digi_max = 256;
    // a sent A:B:C:D
    // b interpreted D*0 + C*digi_max + B*digi_max*digi_max + A*digi_max*digi_max*digi_max;

    int A = val_at_b / (digi_max * digi_max * digi_max);
    int rem = val_at_b % (digi_max * digi_max * digi_max);
    int B = rem / (digi_max * digi_max);
    rem %= (digi_max * digi_max);
    int C = rem / digi_max;
    int D = rem % digi_max;

    debug(A);
    debug(B);
    debug(C);
    debug(D);

    int val_at_a = D * (digi_max * digi_max * digi_max) + C * (digi_max * digi_max) + B * (digi_max) + A;
    debug(val_at_a);

    return val_at_a;
}

void suraj()
{
    string type_a;
    int val_at_b;

    while (cin >> type_a)
    {
        cin >> val_at_b;
        debug(type_a);
        debug(val_at_b);

        if (type_a == "GOOD")
        {
            // int val_at_a = bad_b(val_at_b);
            // debug(val_at_a);
            cout << bad_b(val_at_b) << endl;
        }
        else if (type_a == "BAD")
        {
            cout << good_b(val_at_b) << endl;
            // int val_at_a = good_b(val_at_b);
            // debug(val_at_a);
        }
        else
            break;
    }
}

// 4294967295