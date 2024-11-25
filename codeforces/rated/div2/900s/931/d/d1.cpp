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
    int n, m;
    cin >> n >> m;

    int BIT_COUNT = 63;

    vector<int> bitsN(BIT_COUNT), bitsM(BIT_COUNT);
    int a = 1;
    int pos = 0;
    while (a <= n)
    {
        if (n & a)
            bitsN[pos] = 1;
        if (m & a)
            bitsM[pos] = 1;
        a *= 2;
        pos++;
    }

    // debug(bitsN);
    // debug(bitsM);

    int leftmostIndex = BIT_COUNT; // for the highest bit not same in n & m
    for (int i = BIT_COUNT - 1; i >= 0; i--)
    {
        if (bitsN[i] == 1)
        {
            leftmostIndex = i;
            break;
        }
    }

    for (int i = BIT_COUNT - 1; i >= 0; i--)
    {
        if (bitsN[i] != bitsM[i])
        {
            // debug(i);
            // debug(leftmostIndex);
            if (bitsN[i] == 0) // ie 0 -> 1
            {
                cout << -1 << endl;
                return;
            }
            else if (bitsN[i] == 1)
            {
                if (leftmostIndex == i)
                {
                    // this is the leftmost 1
                    // just think about y being less than x
                    int cntMidOnes = 0;
                    for (int j = i - 1; j >= 0; j--)
                    {
                        if (bitsN[j] != bitsM[j])
                        {
                            if (bitsN[j] == 0)
                            {
                                if (cntMidOnes > 0)
                                {
                                    cout << 1 << endl;
                                    cout << n << " " << m << endl;
                                }
                                else
                                    cout << -1 << endl;
                                return;
                            }
                            else // if (bitsN[j] == 1)
                            {
                                cout << 2 << endl;
                                cout << n << " ";
                                // n -> n xor y
                                // where, y = n with pos j having a 1, and all positions after it having the required bit
                                // viz. m with 1 bit for the index i
                                cout << m + (long long)pow(2ll, i) << " ";
                                cout << m << endl;
                                return;//
                            }
                        }

                        if (bitsN[j] == bitsM[j] && bitsN[j] == 1)
                        {
                            cntMidOnes++;
                        }
                    }
                    // ie if only one bit differ ie bit i
                    // n -> 1, and m -> 0
                    cout << 1 << endl;
                    cout << n << " " << m << endl;
                    return;
                }
                else
                {
                    // there is a 1 bit on left of this :)
                    cout << 1 << endl;
                    cout << n << " " << m << endl;
                    return;
                }
            }
        }
    }
}
