// @author: ascyrax

#include <bits/stdc++.h>

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

void _print(int t)
{
    cerr << t;
}
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
    int pos;
    cin >> pos;

    int cntNDigitNums = 9;

    int nDigit = 1; // ( 9 * 1 -> 90 * 2 -> 900*3 -> 9000*4)

    while (1)
    {
        // debug(pos);
        // debug(nDigit);
        // debug(cntNDigitNums);
        int q = pos / (cntNDigitNums * nDigit);
        // int r = pos % (cntNDigi tNums * nDigit);

        if (!q)
            break;

        pos -= cntNDigitNums * nDigit;

        nDigit++;
        cntNDigitNums *= 10;
    }
    // debug(nDigit);
    // debug(pos);
    int lastNumber = 0;
    //  + (int)pow(10, (nDigit - 1)) - 1;
    int tenFact = 1;
    for (int i = 1; i < nDigit; i++)
        tenFact *= 10;
    lastNumber += tenFact;
    lastNumber--;
    // debug((int)pow(10, (nDigit - 1)));
    if (lastNumber < 0)
        lastNumber = 0;
    // debug(lastNumber);
    int q = pos / nDigit;
    int r = pos % nDigit;
    // debug(q);
    // debug(r);
    lastNumber += q;

    // debug(lastNumber);
    if (!r)
        cout << lastNumber % 10 << endl;
    else
    {
        lastNumber++;
        // print the rth digit from the left
        // = (nDigit - r + 1) from right
        for (int i = 1; i < nDigit - r + 1; i++)
        {
            lastNumber /= 10;
        }
        cout << lastNumber % 10 << endl;
    }
}
